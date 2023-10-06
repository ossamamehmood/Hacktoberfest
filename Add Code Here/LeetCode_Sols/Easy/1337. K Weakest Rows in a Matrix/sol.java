import java.util.*;

public class sol {
    public static void main(String[] args) {
        // call your fn here
    }
}

class Solution {
    public int[] kWeakestRows(int[][] matrix, int k) {
        PriorityQueue<int[]> soldierSums = new PriorityQueue<>((a, b) -> {
            if (a[0] != b[0]) {
                return Integer.compare(a[0], b[0]);
            } else {
                return Integer.compare(a[1], b[1]);
            }
        });

        for (int row = 0; row < matrix.length; row++) {
            int soldierCount = 0;
            for (int col = 0; col < matrix[row].length; col++) {
                soldierCount += matrix[row][col];
                if (matrix[row][col] == 0) {
                    break;
                }
            }
            soldierSums.offer(new int[] { soldierCount, row });
        }

        int[] weakestRows = new int[k];
        for (int i = 0; i < k; i++) {
            weakestRows[i] = soldierSums.poll()[1];
        }

        return weakestRows;
    }
}