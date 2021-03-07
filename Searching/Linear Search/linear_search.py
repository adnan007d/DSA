#!/usr/bin/python3
a = [1, 20, 40, 50, 0, 46]
n = int(input("Enter number to be found: "))

for i, x in enumerate(a):
    if n == x:
        print("Found at index", i)
        break
else:
    print("Not found")
