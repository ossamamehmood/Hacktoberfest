import java.util.Arrays;
import java.util.PriorityQueue;

public class sol {
    public static void main(String[] args) {
        // call the fn here
    }

    class Solution {
        private int[][] effort = new int[105][105]; // Store effort for each cell
        private int[] dx = { 0, 1, -1, 0 }; // Changes in x coordinate for each direction
        private int[] dy = { 1, 0, 0, -1 }; // Changes in y coordinate for each direction

        // Dijkstra's Algorithm to find minimum effort
        private int dijkstra(int[][] heights) {
            int rows = heights.length;
            int cols = heights[0].length;

            // Priority queue to store {effort, {x, y}}
            PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> Integer.compare(-a[0], -b[0]));
            pq.add(new int[] { 0, 0, 0 }); // Start from the top-left cell
            effort[0][0] = 0; // Initial effort at the starting cell

            while (!pq.isEmpty()) {
                int[] current = pq.poll();
                int cost = -current[0]; // Effort for the current cell

                int x = current[1];
                int y = current[2];

                // Skip if we've already found a better effort for this cell
                if (cost > effort[x][y])
                    continue;

                // Stop if we've reached the bottom-right cell
                if (x == rows - 1 && y == cols - 1)
                    return cost;

                // Explore each direction (up, down, left, right)
                for (int i = 0; i < 4; i++) {
                    int new_x = x + dx[i];
                    int new_y = y + dy[i];

                    // Check if the new coordinates are within bounds
                    if (new_x < 0 || new_x >= rows || new_y < 0 || new_y >= cols)
                        continue;

                    // Calculate new effort for the neighboring cell
                    int new_effort = Math.max(effort[x][y], Math.abs(heights[x][y] - heights[new_x][new_y]));

                    // Update effort if a lower effort is found for the neighboring cell
                    if (new_effort < effort[new_x][new_y]) {
                        effort[new_x][new_y] = new_effort;
                        pq.add(new int[] { -new_effort, new_x, new_y });
                    }
                }
            }
            return effort[rows - 1][cols - 1]; // Minimum effort for the path to the bottom-right cell
        }

        // Function to find the minimum effort path
        public int minimumEffortPath(int[][] heights) {
            int rows = heights.length;
            int cols = heights[0].length;

            // Initialize effort for each cell to maximum value
            for (int i = 0; i < rows; i++) {
                Arrays.fill(effort[i], Integer.MAX_VALUE);
            }

            return dijkstra(heights); // Find minimum effort using dijkstra
        }
    }
}
