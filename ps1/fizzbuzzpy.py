#!/usr/bin/python3
import sys
fizzbuzz = 0;
while (fizzbuzz < 100):
    if fizzbuzz % 15 == 0:
        print("fizzbuzz")
    elif fizzbuzz % 3 == 0:
        print("fizz")
    elif fizzbuzz % 5 == 0:
        print("buzz")
    else:
        print(fizzbuzz)
    fizzbuzz = fizzbuzz + 1
