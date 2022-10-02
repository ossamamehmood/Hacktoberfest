import java.util.Arrays;
import java.util.Scanner;

public class QuickSort {

    public static int partition(int[] arr, int si, int ei) {
        int pid, piv = arr[si], count = 0, i = si;
        for (i = si + 1; i <= ei; i++) {
            if (arr[i] <= piv) {
                count++;
            }
        }
        pid = count + si;
        arr[si] = (arr[pid] + arr[si]) - (arr[pid] = arr[si]);
        while (si < pid && ei > pid) {
            if (arr[si] < piv) {
                si++;
            } else if (arr[ei] > piv) {
                ei--;
            } else {
                arr[si] = (arr[ei] + arr[si]) - (arr[ei--] = arr[si++]);
            }
        }
        return pid;
    }

    public static void quickSort(int[] arr, int si, int ei) {
        if (si < ei) {
            int p = partition(arr, si, ei);
            quickSort(arr, si, p - 1);
            quickSort(arr, p + 1, ei);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in).useDelimiter(",");
        System.out.println("Hint: Enter Array -> 1,2,3,4,5,6 ");
        System.out.print("Enter Array -> ");
        String input = sc.nextLine();
        String[] split = input.split(",");
        int[] arr = new int[split.length];
        for (int i = 0; i < split.length; i++) {
            arr[i] = Integer.parseInt(split[i]);
        }
        quickSort(arr, 0, arr.length - 1);
        System.out.println("Sorted Array -> " + Arrays.toString(arr));
        sc.close();
    }
}
