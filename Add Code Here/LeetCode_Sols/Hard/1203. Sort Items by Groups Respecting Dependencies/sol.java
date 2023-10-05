import java.util.*;

public class sol {
    public static void main(String[] args) {
        // call your fn here
    }

    class Solution {
        public int[] sortItems(int n, int m, int[] group, List<List<Integer>> beforeItems) {
            int groupId = m;
            for (int i = 0; i < n; i++) {
                if (group[i] == -1) {
                    group[i] = groupId++;
                }
            }
            Map<Integer, List<Integer>> itemGraph = new HashMap<>();
            int[] itemIndegree = new int[n];
            for (int i = 0; i < n; ++i) {
                itemGraph.put(i, new ArrayList<>());
            }

            Map<Integer, List<Integer>> groupGraph = new HashMap<>();
            int[] groupIndegree = new int[groupId];
            for (int i = 0; i < groupId; ++i) {
                groupGraph.put(i, new ArrayList<>());
            }

            for (int i = 0; i < n; i++) {
                for (int prev : beforeItems.get(i)) {
                    itemGraph.get(prev).add(i);
                    itemIndegree[i]++;
                    if (group[i] != group[prev]) {
                        groupGraph.get(group[prev]).add(group[i]);
                        groupIndegree[group[i]]++;
                    }
                }
            }
            List<Integer> itemOrder = topologicalSort(itemGraph, itemIndegree);
            List<Integer> groupOrder = topologicalSort(groupGraph, groupIndegree);

            if (itemOrder.isEmpty() || groupOrder.isEmpty()) {
                return new int[0];
            }
            Map<Integer, List<Integer>> orderedGroups = new HashMap<>();
            for (Integer item : itemOrder) {
                orderedGroups.computeIfAbsent(group[item], k -> new ArrayList<>()).add(item);
            }

            List<Integer> answerList = new ArrayList<>();
            for (int groupIndex : groupOrder) {
                answerList.addAll(orderedGroups.getOrDefault(groupIndex, new ArrayList<>()));
            }

            return answerList.stream().mapToInt(Integer::intValue).toArray();
        }

        private List<Integer> topologicalSort(Map<Integer, List<Integer>> graph, int[] indegree) {
            List<Integer> visited = new ArrayList<>();
            Stack<Integer> stack = new Stack<>();
            for (int i = 0; i < indegree.length; i++) {
                if (indegree[i] == 0) {
                    stack.add(i);
                }
            }

            while (!stack.isEmpty()) {
                Integer curr = stack.pop();
                visited.add(curr);

                for (Integer n : graph.get(curr)) {
                    indegree[n]--;
                    if (indegree[n] == 0) {
                        stack.add(n);
                    }
                }
            }

            return visited.size() == graph.size() ? visited : new ArrayList<>();
        }
    }
}