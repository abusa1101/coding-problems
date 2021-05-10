import sys
import time
import csv
import numpy as np

#Functions
def utime_now():
    return int(time.time()*1E6)

#Incorrect input arguments errors
if (len(sys.argv) != 5):
    sys.stderr.write("Error: Wrong number of arguments (Need 4)\n")
    exit()

for i in range(1,5):
    if (not sys.argv[i].isdigit()):
        sys.stderr.write("Error: Expected four integer arguments\n")
        exit()

if (sys.argv[2] != sys.argv[3]):
    sys.stderr.write("Error: Non-matched matrix dimensions\n")
    exit()

#Load input matrices
file_A = csv.reader(open("A.csv","r"))
list_A = list(file_A)
A_mat = np.matrix(list_A).astype(float)

file_B = csv.reader(open("B.csv","r"))
list_B = list(file_B)
B_mat = np.matrix(list_B).astype(float)

#Timed matrix multiplication
start_time = utime_now()
C_mat = np.dot(A_mat, B_mat)
total_time = utime_now() - start_time

#Save output matrix C to C.csv (Optional: Print total time taken)
np.savetxt("C.csv", C_mat, delimiter = ",")
print(total_time)
