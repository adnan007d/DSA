#!/usr/bin/python3
def maxHeapify(a, n, i):
    left = i * 2 + 1
    right = i * 2 + 2
    largest = i

    if left < n and a[left] > a[largest]:
        largest = left

    if right < n and a[right] > a[largest]:
        largest = right

    if i != largest:
        a[i], a[largest] = a[largest], a[i]
        maxHeapify(a, n, largest)


def minHeapify(a, n, i):
    left = i * 2 + 1
    right = i * 2 + 2
    smallest = i

    if left < n and a[left] < a[smallest]:
        smallest = left

    if right < n and a[right] < a[smallest]:
        smallest = right

    if i != smallest:
        a[i], a[smallest] = a[smallest], a[i]
        minHeapify(a, n, smallest)


def heapSort(a, n, reverse=False):
    for i in range(n//2, -1, -1):
        if reverse:
            minHeapify(a, n, i)
        else:
            maxHeapify(a, n, i)
    for i in range(n-1, 0, -1):
        a[0], a[i] = a[i], a[0]
        if reverse:
            minHeapify(a, i, 0)
        else:
            maxHeapify(a, i, 0)


if __name__ == '__main__':
    a = [10, 20, 15, 12, 40, 25, 18]
    print("Before Sort :", a)
    heapSort(a, len(a))
    print("After Sort:", a)
