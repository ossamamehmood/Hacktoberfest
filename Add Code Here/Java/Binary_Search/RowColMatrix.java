package Java.Youtube.Binary_Search;

import java.util.Arrays;

public class RowColMatrix {
    public static void main(String[] args) {
        int[][] arr = {
                {12, 16, 20},
                {17, 18, 26},
                {19, 36, 69}
        };
        int target = 69;

        int[] ans = search(arr, target);
        System.out.println(Arrays.toString(ans));
    }

    static int[] search (int[][] matrix, int target){
        int r = 0;
        int c = matrix.length - 1;
        while (r < matrix.length && c >= 0){
            if (matrix[r][c] == target) {
                return new int[]{r, c};
            }
            if (matrix[r][c] < target){
                r++;
            }else {
                c--;
            }
        }
        return new int[]{-1, -1};
    }
}
