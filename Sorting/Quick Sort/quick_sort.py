#!/usr/bin/python3
from random import randint


def swap(a, i, j):
    a[i], a[j] = a[j], a[i]


def partition(a, l, h):
    pivot = a[h]
    pivotIndex = l
    for i in range(l, h):
        if a[i] <= pivot:
            swap(a, i, pivotIndex)
            pivotIndex += 1
    swap(a, h, pivotIndex)
    return pivotIndex


def randomPartition(a, l, h):
    pivotIndex = randint(l, h)
    swap(a, h, pivotIndex)
    return partition(a, l, h)


def midPartition(a, l, h):
    pivot = (l+h)//2
    swap(a, h, pivot)
    return partition(a, l, h)


def quickSort(a, l, h):
    if l >= h:
        return
    pivot = randomPartition(a, l, h)
    quickSort(a, l, pivot-1)
    quickSort(a, pivot+1, h)


if __name__ == "__main__":
    a = [10, 20, 15, 40, 12, 25, 18]
    print("Before Sort:", a)
    quickSort(a, 0, len(a)-1)
    print("After Sort:", a)
