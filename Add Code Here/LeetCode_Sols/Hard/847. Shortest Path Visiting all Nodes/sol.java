import java.util.*;

public class sol {
    public static void main(String[] args) {
        // enter your sol here
    }

    class Solution {
        public int shortestPathLength(int[][] graph) {
            List<List<Integer>> adjacentList = new ArrayList<>();
            PriorityQueue<Integer> queue = new PriorityQueue<>((a, b) -> adjacentList.get(a).size() -
                    adjacentList.get(b).size());
            int n = graph.length;

            for (int i = 0; i < n; i++) {
                List<Integer> list = new ArrayList<>();
                for (int node : graph[i]) {
                    list.add(node);
                }
                adjacentList.add(list);
                queue.add(i);
            }
            int minLen = Integer.MAX_VALUE;
            while (!queue.isEmpty()) {
                int start = queue.poll();
                int[] visited = new int[n];
                getLen(adjacentList, visited, start);
                if (!isValid(visited))
                    continue;
                minLen = Math.min(calLen(visited), minLen);
            }

            return minLen != Integer.MIN_VALUE ? minLen : -1;

        }

        private int calLen(int[] visited) {
            int len = 0;
            for (int curr : visited) {
                len += curr;
            }
            return len - 1;
        }

        private boolean isValid(int[] visited) {
            for (int curr : visited) {
                if (curr == 0)
                    return false;
            }
            return true;
        }

        private void getLen(List<List<Integer>> adjacentList, int[] visited, int index) {
            visited[index]++;
            if (isValid(visited))
                return;
            PriorityQueue<Integer> queue = new PriorityQueue<>((a, b) -> adjacentList.get(a).size() -
                    adjacentList.get(b).size());
            queue.addAll(adjacentList.get(index));

            int len = 0;
            while (!queue.isEmpty()) {
                int curr = queue.poll();
                if (queue.size() > 0 && visited[curr] > 0) {
                    continue;
                }
                if (!isValid(visited) && visited[curr] < adjacentList.get(curr).size()) {
                    getLen(adjacentList, visited, curr);
                }
            }
        }
    }
}