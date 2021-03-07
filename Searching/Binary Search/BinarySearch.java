import java.util.Scanner;

public class BinarySearch {

    private static int binarySearchRecursion(int a[], int l, int h, int x) {
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

    @SuppressWarnings({ "unused" })
    private static int binarySearchIterative(int a[], int l, int h, int x) {

        while (l <= h) {
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

    public static void main(String[] args) {
        int a[] = { -100, -10, 1, 3, 10, 40, 100 };

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter Number to be found: ");
        int n = sc.nextInt();

        sc.close();
        int result = binarySearchRecursion(a, 0, a.length - 1, n);

        if (result >= 0)
            System.out.println("Found at Index " + result);
        else
            System.out.println("Not Found");
    }
}
