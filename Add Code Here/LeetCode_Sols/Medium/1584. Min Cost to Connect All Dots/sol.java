import java.util.LinkedList;
import java.util.Queue;

public class sol {
    public static void main(String[] args) {
        // call the fn here
    }

    class Solution {
        public int minCostConnectPoints(int[][] points) {
            int n = points.length;
            int[][] matrix = new int[n][n];
            boolean[] visited = new boolean[n];
            Queue<Integer> queue = new LinkedList<>();
            int distance = 0;
            // get all distance
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    matrix[i][j] = Math.abs(points[i][0] - points[j][0]) + Math.abs(points[i][1] - points[j][1]);
                }
                ;
            }

            // first
            queue.add(0);
            visited[0] = true;
            while (queue.size() < n) {
                int sizes = queue.size();
                int len = Integer.MAX_VALUE;
                int choosen = 0;
                int nextPoint = 0;
                for (int ss = 0; ss < sizes; ss++) {
                    int connect = queue.poll();
                    for (int next = 0; next < n; next++) {
                        if (!visited[next]) {
                            if (matrix[connect][next] < len) {
                                choosen = connect;
                                nextPoint = next;
                                len = matrix[connect][next];
                            }
                        }

                    }
                    queue.add(connect);
                }
                visited[nextPoint] = true;
                queue.add(nextPoint);
                distance += len;

            }

            return distance;

        }
    }
}
