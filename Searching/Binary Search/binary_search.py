#!/usr/bin/python3
def binarySearchRecursion(a, l, h, x):

    if l <= h:

        mid = (l + h) // 2
        if a[mid] == x:
            return mid
        elif x < a[mid]:
            return binarySearchRecursion(a, l, mid-1, x)
        else:
            return binarySearchRecursion(a, mid+1, h, x)
    else:
        return -1


def binarySearchIterative(a, l, h, x):

    while l <= h:
        mid = (l + h) // 2
        if a[mid] == x:
            return mid
        elif a[mid] < x:
            l = mid + 1
        else:
            h = mid - 1
    return -1


if __name__ == '__main__':
    a = [-200, -100, -10, 1, 3, 10, 40, 100]
    n = int(input("Enter Number to be found: "))

    result = binarySearchRecursion(a, 0, len(a)-1, n)

    print(result)
    if result >= 0:
        print("Found at Index", result)
    else:
        print("Not Found")
