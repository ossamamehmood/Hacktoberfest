package Java.Youtube.Binary_Search;

import java.util.Arrays;

public class SortedMatrix {
    public static void main(String[] args) {
        int[][] arr = {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9},
//                {13, 14, 15, 16}
        };
        System.out.println(Arrays.toString(search(arr, 9)));
    }


    // search in the row provided between the cols provided
    static int[] binarySearch(int[][] matrix, int rows, int cStart, int cEnd, int target) {
        while (cStart <= cEnd) {
            int mid = cStart + (cEnd - cStart) / 2;
            if (matrix[rows][mid] == target) {
                return new int[]{rows, mid};
            }
            if (matrix[rows][mid] < target) {
                cStart = mid + 1;
            }else {
                cEnd = mid - 1;
            }
        }
        return new int[]{-1, -1};
    }
    static int[] search(int[][] matrix, int target) {
        int row = matrix.length;
        int col = matrix[0].length;  // be cautious, matrix may be empty

        if (row == 1) {
            return binarySearch(matrix, 0, 0, col - 1, target);
        }


        int rStart = 0;
        int rEnd = row - 1;
        int cMid = col / 2;
        // run the loop till 2 rows are remaining
        while (rStart < (rEnd - 1)) { //while this is true it will have more  than 2 rows
            int mid = rStart + (rEnd - rStart) / 2;
            if (matrix[mid][cMid] == target) {
                return new int[]{mid, cMid};
            }
            if (matrix[mid][cMid] < target) {
                rStart = mid;
            } else {
                rEnd = mid;
            }
        }
        // now we have two rows
        // check whether the  target is in the col of 2 rows
        if (matrix[rStart + 1][cMid] == target) {
            return new int[]{rStart + 1, cMid};
        }

        // search in 1st half
        if (target <= matrix[rStart][cMid - 1]) {
            return binarySearch(matrix, rStart, cMid + 1, col - 1, target);
        }
        // search in 2nd half
        if (target >= matrix[rStart][cMid + 1] && target <= matrix[rStart][col - 1]) {
            return binarySearch(matrix, rStart, cMid + 1, col - 1, target);
        }
        // search in 3rd half
        if (target <= matrix[rStart + 1][cMid - 1]) {
            return binarySearch(matrix, rStart + 1, cMid + 1, col - 1, target);
        }
        // search in 4th half
        else {
            return binarySearch(matrix, rStart + 1, cMid + 1, col - 1, target);
        }
    }
}
