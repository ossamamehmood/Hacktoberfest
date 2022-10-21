//allocate minimum number of pages problem - Given number of pages in n different books and m students. The books are arranged in ascending order of number of pages. Every student is assigned to read some consecutive books.
// The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum.
//For Ex - n=5 (Length of array), m = 2(no.of students), arr[] = [10, 20, 5, 15, 5]
//Possible allocations - 10 and (20,5,15,5)  -> Max - 45
//                     - (10, 20) and (5, 15, 5)     -> Max - 30
//                      - (10, 20, 5) and (15, 5)   -> Max - 35
//Minimum from all these maz is 30 so output -> 30
 import java.util.Scanner;

public class AllocateMinimunPages {
    public static void main(String[] args) {                         //main function
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();                                       //taking inputs
        int arr[] = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        System.out.println("Minimun number of pages " + findPages(arr, n, m));
    }

    public static int findPages(int arr[], int n, int m) {
        int sum = 0;
        if (n < m) return -1;               // return -1 if no. of books is less than no. of students
        for (int i = 0; i < n; i++) sum += arr[i];      // Count total number of pages
        int min = arr[n - 1];
        int max = sum;
        int result = Integer.MAX_VALUE;
        while (min <= max) {                            //Using Binary Search
            int mid = min + (max - min) / 2;            // check if it is possible to distribute books by using mid is current minimum
            if (isFeasible(arr, n, m, mid)) {
                result = mid;                   // update result to current distribution as it's the best we have found till now
                max = mid - 1;
            } else {
                min = mid + 1;
            }
        }
        return result;
    }

    static boolean isFeasible(int arr[], int n, int m, int curr_min) {      // method to check if current minimum value is feasible or not
        int studentsRequired = 1;
        int curr_sum = 0;
        for (int i = 0; i < n; i++) {
            curr_sum += arr[i];
            if (curr_sum > curr_min) {
                studentsRequired++;   // increment student count

                curr_sum = arr[i];    // update curr_sum
            }
        }

        return studentsRequired <= m;
    }
}

//Time Complexity - O(nlogn)
//Space Complexity - O(1)
