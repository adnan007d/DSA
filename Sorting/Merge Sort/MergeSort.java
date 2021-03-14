public class MergeSort {

    private static void merge(int a[], int l, int mid, int h) {
        int lenL = mid + 1 - l;
        int lenR = h - mid;

        // Temp arrays to store the two left and right array
        int left[] = new int[lenL];
        int right[] = new int[lenR];

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
        while (i < lenL && j < lenR) {
            if (left[i] < right[j])
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

    private static void mergeSort(int a[], int l, int h) {
        // Terminating condition
        if (l >= h)
            return;
        int mid = (l + h) / 2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, h);
        merge(a, l, mid, h);
    }

    private static void print(int a[]) {
        for (int x : a) {
            System.out.print(x + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int a[] = { 10, 20, 15, 12, 40, 25, 18 };
        System.out.print("Before Sort: ");
        print(a);
        mergeSort(a, 0, a.length - 1);
        System.out.print("After Sort: ");
        print(a);
    }
}