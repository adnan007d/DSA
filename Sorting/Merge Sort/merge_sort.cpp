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

void merge(int a[], int l, int mid, int h)
{
    int lenL = mid + 1 - l;
    int lenR = h - mid;

    // Temp arrays to store the two left and right array
    int left[lenL];
    int right[lenR];

    // Filling the left and right Arrays
    for (int i = 0; i < lenL; ++i)
        left[i] = a[l + i];

    for (int i = 0; i < lenR; ++i)
        right[i] = a[mid + 1 + i];

    // Staring index of left and right array
    int i = 0;
    int j = 0;

    // Starting index of the array which needs to be sorted
    int k = l;

    // Merging
    while (i < lenL && j < lenR)
    {
        if (left[i] > right[j])
            a[k++] = left[i++];
        else
            a[k++] = right[j++];
    }

    // Filling the reaming elements of left and right arrays
    while (i < lenL)
        a[k++] = left[i++];

    while (j < lenR)
        a[k++] = right[j++];
}

void mergeSort(int a[], int l, int h)
{
    // Terminating condition
    if (l >= h)
        return;
    int mid = (l + h) / 2;
    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, h);
    merge(a, l, mid, h);
}

int main()
{
    int a[] = {10, 20, 15, 12, 40, 25, 18};
    int length = sizeof(a) / sizeof(a[0]);
    cout << "Before Sort: ";
    print(a, length);
    mergeSort(a, 0, length - 1);
    cout << "After Sort: ";
    print(a, length);
    return 0;
}