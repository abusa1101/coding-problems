import sys
import time
import csv

#Functions
def utime_now():
    return int(time.time()*1E6)

#Incorrect input arguments errors
if (len(sys.argv) != 5):
    sys.stderr.write("Error: Wrong number of arguments (Need 4)\n")
    sys.exit()

for i in range(1, 5):
    if (not sys.argv[i].isdigit()):
        sys.stderr.write("Error: Expected four integer arguments\n")
        sys.exit()

if (sys.argv[2] != sys.argv[3]):
    sys.stderr.write("Error: Non-matched matrix dimensions\n")
    sys.exit()

#Load input matrices
file_A = csv.reader(open("A.csv","r"))
A_mat = list(file_A)

file_B = csv.reader(open("B.csv","r"))
B_mat = list(file_B)

#Timed matrix multiplication
C_row = int(sys.argv[1]) #Equals A_row
C_col = int(sys.argv[4]) #Equals B_col
A_col = int(sys.argv[2]) #A_col = B_row (i.e, argv[2] or argv[3])

C_mat = []
for x in range(C_row): #set C_mat m rows
    C_val = [0] * C_col #set C_mat n rows
    C_mat.append(C_val)

start_time = utime_now()

for i in range(C_row):
    for j in range(C_col):
        for k in range(A_col):
            A_mat[i][k] = float(A_mat[i][k])
            B_mat[k][j] = float(B_mat[k][j])
            C_mat[i][j] += A_mat[i][k] * B_mat[k][j]

total_time = utime_now() - start_time

#Save output matrix C to C.csv (Optional: Print total time taken)
with open('new_test.csv', 'w') as csvfile_C:
    file_C = csv.writer(csvfile_C, delimiter = ',')
    file_C.writerows(C_mat)

print(total_time)
