import java.util.ArrayList;
import java.util.Collections;

public class Solution {
    public static int findPages(ArrayList<Integer> arr, int n, int m) {
        // If the number of students is greater than the number of books, it's not possible.
        if (m > n) return -1;

        // Initialize the search space boundaries.
        int low = Collections.max(arr); // The minimum number of pages in a book.
        int high = arr.stream().mapToInt(Integer::intValue).sum(); // The sum of all pages in all books.

        // Perform binary search to find the minimum maximum number of pages a student can read.
        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Count how many students are needed to read the books with the given maximum pages.
            int numberOfStudents = countStudents(arr, n, m, mid);

            if (numberOfStudents > m) {
                // If more students are needed, increase the maximum pages allowed.
                low = mid + 1;
            } else {
                // If fewer or equal students are needed, decrease the maximum pages allowed.
                high = mid - 1;
            }
        }
        return low; // The minimum maximum pages a student can read.
    }

    public static int countStudents(ArrayList<Integer> arr, int n, int m, int pages) {
        int students = 1; // Initialize with 1 student.
        int minPages = 0;

        for (int i = 0; i < n; i++) {
            if (minPages + arr.get(i) <= pages) {
                // If the current book can be read by the current student, add its pages.
                minPages += arr.get(i);
            } else {
                // If the current book can't be read by the current student, assign it to a new student.
                students++;
                minPages = arr.get(i);
            }
        }
        return students; // Return the total number of students needed for the given maximum pages.
    }
}