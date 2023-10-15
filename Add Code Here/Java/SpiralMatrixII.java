package Java.Leetcode;

//      Q : 59. Spiral Matrix II

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class SpiralMatrixII {
    public static void main(String[] args) {
//        int[][] arr = generateMatrix(4);
//        System.out.println(Arrays.toString(arr[0]));
//        System.out.println(Arrays.toString(arr[1]));
//        System.out.println(Arrays.toString(arr[2]));
//        System.out.println(Arrays.toString(arr[3]));
        List<String> list = new ArrayList<>();
        list.add("baa");
        list.add("bac");
        list.add("bca");
        Collections.sort(list);
        System.out.println(list);
    }
    public static int[][] generateMatrix(int n) {
        int[][] ans = new int[n][n];
        boolean[][] valid = new boolean[n][n];
        int i = 1;
        int max = n * n;
        int r = 0;
        int c = 0;
        ans[r][c] = i;
        valid[r][c] = true;
        i = i + 1;
        while (i <= max) {
            while (c < n - 1) {
                c++;
                if (isRight(valid,r, c)) {
                    ans[r][c] = i;
                    valid[r][c] = true;
                    i = i + 1;
                } else {
                    c--;
                    break;
                }
            }
            while (r < n - 1) {
                r++;
                if (isDown(valid, r, c)) {
                    ans[r][c] = i;
                    valid[r][c] = true;
                    i = i + 1;
                } else {
                    r--;
                    break;
                }
            }
            while (c > 0) {
                c--;
                if (isLeft(valid, r, c)) {
                    ans[r][c] = i;
                    valid[r][c] = true;
                    i = i + 1;
                }else {
                    c++;
                    break;
                }
            }
           while (r > 0) {
               r--;
               if (isUp(valid, r, c)) {
                   ans[r][c] = i;
                   valid[r][c] = true;
                   i = i + 1;
               }else {
                   r++;
                   break;
               }
           }
        }
        return ans;
    }
    private static boolean isRight(boolean[][] arr, int r, int c) {
        if (!arr[r][c]) {
            return true;
        }
        return false;
    }
    private static boolean isDown(boolean[][] arr, int r, int c) {
        if (!arr[r][c]) {
            return true;
        }
        return false;
    }

    static boolean isLeft(boolean[][] arr, int r, int c) {
        if (!arr[r][c]) {
            return true;
        }
        return false;
    }

    private static boolean isUp(boolean[][] arr, int r, int c) {
        if (!arr[r][c]) {
            return true;
        }
        return false;
    }
}
