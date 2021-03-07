#include <iostream>
using namespace std;

int binarySearchRecursion(int a[], int l, int h, int x)
{
    if (l > h)
        return -1;

    int mid = (l + h) / 2;
    if (a[mid] == x)
        return mid;
    else if (a[mid] > x)
        return binarySearchRecursion(a, l, mid - 1, x);
    else
        return binarySearchRecursion(a, mid + 1, h, x);
}

int binarySearchIterative(int a[], int l, int h, int x)
{
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (a[mid] == x)
            return mid;
        else if (a[mid] > x)
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int main()
{
    int a[] = {-100, -10, 1, 3, 10, 40, 100};
    int length = sizeof(a) / sizeof(a[0]);

    int n;
    cout << "Enter Number to be found: ";
    cin >> n;

    int result = binarySearchIterative(a, 0, length - 1, n);

    if (result >= 0)
    {
        cout << "Found at Index " << result << endl;
        return 0;
    }

    cout << "Not Found" << endl;
    return 1;
}