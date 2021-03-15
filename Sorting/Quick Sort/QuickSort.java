public class QuickSort {

    private static void swap(int a[], int i, int j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    private static int partition(int a[], int l, int h) {
        int pivot = a[h];
        int pivotIndex = l;

        for (int i = l; i < h; ++i) {
            if (a[i] <= pivot) {
                swap(a, i, pivotIndex);
                ++pivotIndex;
            }
        }

        swap(a, h, pivotIndex);
        return pivotIndex;
    }

    private static int midPartition(int a[], int l, int h) {
        int pivotIndex = (l + h) / 2;
        swap(a, h, pivotIndex);
        return partition(a, l, h);
    }

    @SuppressWarnings("unused")
    private static int randomPartition(int a[], int l, int h) {
        int pivotIndex = (int) Math.random() * (h - l + 1) + l;
        swap(a, h, pivotIndex);
        return partition(a, l, h);
    }

    private static void quickSort(int a[], int l, int h) {
        if (l >= h)
            return;
        int pivot = midPartition(a, l, h);
        quickSort(a, l, pivot - 1);
        quickSort(a, pivot + 1, h);
    }

    private static void print(int a[]) {
        for (int x : a) {
            System.out.print(x + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int a[] = { 10, 20, 15, 40, 12, 25, 18 };
        System.out.print("Before Sort: ");
        print(a);
        quickSort(a, 0, a.length - 1);
        System.out.print("After Sort: ");
        print(a);
    }
}