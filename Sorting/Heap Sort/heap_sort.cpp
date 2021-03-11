#include <iostream>
using namespace std;

void print(int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void maxHeapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && a[left] > a[largest])
        largest = left;
    if (right < n && a[right] > a[largest])
        largest = right;

    if (i != largest)
    {
        swap(a[i], a[largest]);
        maxHeapify(a, n, largest);
    }
}

void minHeapify(int a[], int n, int i)
{
    int smallest = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;

    if (left < n && a[left] < a[smallest])
        smallest = left;

    if (right < n && a[right] < a[smallest])
        smallest = right;

    if (i != smallest)
    {
        swap(a[i], a[smallest]);
        minHeapify(a, n, smallest);
    }
}

void heapSort(int a[], int n, bool reverse = false)
{
    for (int i = n / 2 - 1; i >= 0; --i)
    {
        if (reverse)
        {
            minHeapify(a, n, i);
        }
        else
        {
            maxHeapify(a, n, i);
        }
    }

    for (int i = n - 1; i > 0; --i)
    {
        swap(a[0], a[i]);
        if (reverse)
        {
            minHeapify(a, i, 0);
        }
        else
        {
            maxHeapify(a, i, 0);
        }
    }
}

int main()
{
    int a[] = {10, 20, 15, 12, 40, 25, 18};
    int length = sizeof(a) / sizeof(a[0]);
    heapSort(a, length);
    print(a, length);
    cout << endl;
    return 0;
}