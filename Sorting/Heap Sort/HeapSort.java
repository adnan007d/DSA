public class HeapSort {

    @SuppressWarnings("unused")
    private static void maxHeapify(int a[], int n, int i) {

        int largest = i;
        int left = i * 2 + 1;
        int right = i * 2 + 2;

        if (left < n && a[left] > a[largest])
            largest = left;
        if (right < n && a[right] > a[largest])
            largest = right;

        if (i != largest) {
            int temp = a[i];
            a[i] = a[largest];
            a[largest] = temp;
            maxHeapify(a, n, largest);
        }

    }

    @SuppressWarnings("unused")
    private static void minHeapify(int a[], int n, int i) {

        int smallest = i;
        int left = i * 2 + 1;
        int right = i * 2 + 2;

        if (left < n && a[left] < a[smallest])
            smallest = left;
        if (right < n && a[right] < a[smallest])
            smallest = right;

        if (i != smallest) {
            int temp = a[i];
            a[i] = a[smallest];
            a[smallest] = temp;
            minHeapify(a, n, smallest);
        }

    }

    // if reverse is true array will be sorted in descending order
    private static void heapSort(int a[], boolean reverse) {
        int n = a.length;
        for (int i = n / 2 - 1; i >= 0; --i) {
            if (reverse) {
                minHeapify(a, n, i);
            } else {
                maxHeapify(a, n, i);
            }
        }

        for (int i = n - 1; i > 0; --i) {
            int temp = a[i];
            a[i] = a[0];
            a[0] = temp;
            if (reverse) {
                minHeapify(a, i, 0);
            } else {
                maxHeapify(a, i, 0);
            }
        }
    }

    private static void print(int a[]) {
        for (int x : a) {
            System.out.print(x + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int a[] = { 10, 20, 15, 12, 40, 25, 18 };
        heapSort(a, true);
        print(a);
    }
}