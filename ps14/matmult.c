#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <sys/time.h>

int64_t utime_now (void){
    struct timeval tv;
    gettimeofday (&tv, NULL);
    return (int64_t) tv.tv_sec * 1000000 + tv.tv_usec;
}

double* readMatrixFromFile(char* fileName, int height, int width) {
  FILE* fp = fopen(fileName, "r");
  if (fp == NULL) {
    fprintf(stderr, "Can't open %s.\n", fileName);
    return NULL;
  }
  double val;
  double* M = (double*) malloc(height * width * sizeof(double));
  for(int i = 0; i < height; i++) {
    for(int j = 0; j < width; j++) {
      if (fscanf(fp, " %lf", &val) != 1) {
        fprintf(stderr, "Couldn't read value.\n");
        return NULL;
      }
      // Discard the comma without checking.
      fgetc(fp);
      M[i * width + j] = val;
    }
  }
  fclose(fp);
  return M;
}

int writeMatrixToFile(char* fileName, double* matrix, int height, int width) {
  FILE* fp = fopen(fileName, "w");
  if (fp == NULL) {
    return 1;
  }

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (j > 0) {
        fputc(',', fp);
      }
      fprintf(fp, "%lf", matrix[i * width + j]);
    }
    fputs("\r\n", fp);
  }
  fclose(fp);
  return 0;
}

int main(int argc, char **argv) {
    if (argc != 5) {
        fprintf(stderr, "Error: Wrong number of arguments (Need 4)\n");
        exit(1);
    }

    for (int i = 1; i < 5; i++) {
        if (isdigit(argv[i][0]) == 0) {
            fprintf(stderr, "Error: Enter ONLY integer values\n");
            exit(1);
        }
    }

    int A_row = atoi(argv[1]);
    int A_col = atoi(argv[2]);
    int B_row = atoi(argv[3]);
    int B_col = atoi(argv[4]);

    if (A_col != B_row) {
        fprintf(stderr, "Error: Non-matched matrix dimensions\n");
        exit(1);
    }

    int C_row = A_row;
    int C_col = B_col;

    double* A_mat = readMatrixFromFile("A.csv", A_row, A_col);
    double* B_mat = readMatrixFromFile("B.csv", B_row, B_col);

    double* C_mat = (double*) malloc(C_row * C_col * sizeof(double));
    int64_t start_time = utime_now();
    for (int i = 0; i < C_row; i++) {
        for (int j = 0; j < C_col; j++) {
            for (int k = 0; k < A_col; k++) {
                C_mat[i * C_col + j] += A_mat[i * A_col + k] * B_mat[k * B_col + j];
            }
        }
    }
    int64_t total_time = utime_now() - start_time;
    printf("%ld\n", total_time);

    writeMatrixToFile("C.csv", C_mat, C_row, C_col);

    free(C_mat);
    free(B_mat);
    free(A_mat);
    return 0;
}
