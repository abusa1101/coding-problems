#!/usr/bin/python3
import sys
import numpy as np

if (not sys.argv[1].isdigit()) or (not sys.argv[2].isdigit()):
    sys.stderr.write("Error: expected two integer arguments\n")
    exit()

row = int(sys.argv[1])
col = int(sys.argv[2])
mat = np.random.randn(row,col)
list = mat
for i in range(row):
    for j in range(col + 1):
        if (j == col):
            j = j - 1
            print(list[i][j], end = '')
            print('')
        elif (j < col - 1):
            print(list[i][j], end = '')
            print(",", end = '')
            continue
