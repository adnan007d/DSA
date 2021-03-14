#!/usr/bin/python3
def merge(left, right):
    i = j = 0
    c = []

    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            c.append(left[i])
            i += 1
        else:
            c.append(right[j])
            j += 1

    for i in range(i, len(left)):
        c.append(left[i])

    for j in range(j, len(right)):
        c.append(right[j])
    return c


def mergeSort(a):
    if len(a) <= 1:
        return a
    mid = len(a)//2
    left = a[:mid]
    right = a[mid:]
    left = mergeSort(left)
    right = mergeSort(right)
    return merge(left, right)


if __name__ == '__main__':
    a = [10, 20, 15, 12, 40, 25, 18]
    print("Before Sort:", a)
    print("After Sort:",  mergeSort(a))
