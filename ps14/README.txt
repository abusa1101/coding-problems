Benchmark code using time functions on below matrices:
    1. A and B are 10 x 10 matrices
    2. A and B are 100 x 100 matrices
    3. A and B are 1000 x 1000 matrices

Results:  Total time taken for each case is given below

    1. 10 x 10
        i. matmult.c = 18 microseconds
        ii. matmult_pure.py = 776 microseconds
        iii. matmult_npy.py = 31 microseconds

    2. 100 x 100
        i. matmult.c = 4,175 microseconds
        ii. matmult_pure.py = 546,684 microseconds
        iii. matmult_npy.py = 181 microseconds

    3. 1000 x 1000
        i. matmult.c = 7,881,869 microseconds
        ii. matmult_pure.py = 960,833,071 microseconds
        iii. matmult_npy.py = 26,846 microseconds

Explanation:
    Overall, Python with Numpy is the fastest program when computing
    with large data structures. The C Program is faster than the Numpy program
    for case 1, potentially because Numpy has computational overhead,
    the costs for which are overcome when working with large data. Numpy is
    significantly faster than the C program for cases 2 and 3.
    Lastly, Pure Python is the slowest, and significantly so compared to C or
    Numpy, and the least efficient.

    In conclusion,
    1. Python Numpy is FASTEST for large datasets (cases 2,3)
    2. C is FASTEST for small datasets (case 1)
    3. Pure Python is SLOWEST overall!
