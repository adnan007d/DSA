#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int a[] = {1, 20, 40, 50, 0, 46};
    int length = sizeof(a) / sizeof(a[0]);

    int n;
    cout << "Enter number to be found: ";
    cin >> n;

    for (int i = 0; i < length; ++i)
    {
        if (a[i] == n)
        {
            cout << "Found at index " << i << endl;
            return 0;
        }
    }

    cout << "Not Found" << endl;
    return 1;
}