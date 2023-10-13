package Java.Leetcode;

//      Q : 54. Spiral Matrix

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class SpiralMatrix {

    public static void main(String[] args) {
        int[][] arr = {
                {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}
        };
//        [1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10]
//        System.out.println(arr.length);
//        System.out.println(arr[0].length);
        System.out.println(spiralOrder(arr));
    }
    public static List<Integer> spiralOrder(int[][] matrix) {
        boolean[][] arr = new boolean[matrix.length][matrix[0].length];
        return helper(matrix,arr);
    }
    static List<Integer> helper(int[][] num, boolean[][] valid) {
        List<Integer> list = new ArrayList<>();
        int r = 0;
        int c = 0;
        int i = 1;
        int max = num.length * num[0].length;
        list.add(num[r][c]);
        valid[r][c] = true;
        i++;
        while (i <= max) {
            while (c < num[0].length - 1) {
                c++;
                if (isRight(valid, r, c)) {
                    list.add(num[r][c]);
                    valid[r][c] = true;
                    i++;
                } else {
                    c--;
                    break;
                }
            }
            while (r < num.length - 1) {
                r++;
                if (isDown(valid, r, c)) {
                    list.add(num[r][c]);
                    valid[r][c] = true;
                    i++;
                } else {
                    r--;
                    break;
                }
            }
            while (c > 0) {
                c--;
                if (isLeft(valid, r, c)) {
                    list.add(num[r][c]);
                    valid[r][c] = true;
                    i++;
                } else {
                    c++;
                    break;
                }
            }
            while (r > 0) {
                r--;
                if (isUp(valid, r, c)) {
                    list.add(num[r][c]);
                    valid[r][c] = true;
                    i++;
                } else {
                    r++;
                    break;
                }
            }
        }
        return  list;
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
