import java.util.Scanner;

public class LinearSearch {

    public static void main(String[] args) {
        int a[] = { 1, 20, 40, 50, 0, 46 };

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number to be found: ");
        int n = sc.nextInt();
        sc.close();

        for (int i = 0; i < a.length; ++i) {
            if (a[i] == n) {
                System.out.println("Found at index " + i);
                return;
            }
        }

        System.out.println("Not Found");
    }
}