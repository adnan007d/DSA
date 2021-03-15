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

int partition(int a[], int l, int h)
{
    int pivot = a[h];
    int pivotIndex = l;
    for (int i = l; i < h; ++i)
    {
        if (a[i] <= pivot)
        {
            swap(a[i], a[pivotIndex]);
            ++pivotIndex;
        }
    }
    swap(a[h], a[pivotIndex]);
    return pivotIndex;
}

int randomPartition(int a[], int l, int h)
{
    int pivotIndex = (random() % (h - l)) + l;
    swap(a[h], a[pivotIndex]);
    return partition(a, l, h);
}

int midPartition(int a[], int l, int h)
{
    int pivotIndex = (l + h) / 2;
    swap(a[h], a[pivotIndex]);
    return partition(a, l, h);
}

void quickSort(int a[], int l, int h)
{
    if (l >= h)
        return;
    int pivot = randomPartition(a, l, h);
    quickSort(a, l, pivot - 1);
    quickSort(a, pivot + 1, h);
}

int main()
{
    int a[] = {10, 20, 15, 40, 12, 25, 18};
    int length = sizeof(a) / sizeof(a[0]);
    cout << "Before Sort: ";
    print(a, length);
    quickSort(a, 0, length - 1);
    cout << "After Sort: ";
    print(a, length);
}