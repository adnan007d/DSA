#!/usr/bin/python3
def merge(a, l, mid, h):

    lenL = mid+1-l
    lenR = h - mid

    # Temp lists to store the two left and right list
    left = [a[l+i] for i in range(lenL)]
    right = [a[mid+1+i] for i in range(lenR)]

    # Staring index of left and right list
    i = j = 0

    # Starting index of the list which needs to be sorted
    k = l

    # Merging
    while i < lenL and j < lenR:
        if left[i] > right[j]:
            a[k] = left[i]
            i += 1
        else:
            a[k] = right[j]
            j += 1
        k += 1

    # Filling the reaming elements of  left and right lists
    while i < lenL:
        a[k] = left[i]
        k += 1
        i += 1

    while j < lenR:
        a[k] = right[j]
        k += 1
        j += 1


def mergeSort(a, l, h):
    # Terminating condition
    if l >= h:
        return
    mid = (l + h) // 2
    mergeSort(a, l, mid)
    mergeSort(a, mid+1, h)
    merge(a, l, mid, h)


if __name__ == '__main__':
    a = [10, 20, 15, 12, 40, 25, 18]
    print("Before Sort:", a)
    mergeSort(a, 0, len(a)-1)
    print("After Sort:", a)
