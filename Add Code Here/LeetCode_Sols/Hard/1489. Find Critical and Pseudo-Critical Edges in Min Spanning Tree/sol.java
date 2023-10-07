import java.util.*;

public class sol {
    public static void main(String[] args) {
        // call the fn here
    }

    class UnionFind {
        private int[] parent;

        public UnionFind(int n) {
            parent = new int[n];
            for (int i = 0; i < n; i++)
                parent[i] = i;
        }

        public int findParent(int p) {
            return parent[p] == p ? p : (parent[p] = findParent(parent[p]));
        }

        public void union(int u, int v) {
            int pu = findParent(u), pv = findParent(v);
            parent[pu] = pv;
        }
    }

    class Solution {
        public List<List<Integer>> findCriticalAndPseudoCriticalEdges(int n, int[][] edges) {
            List<Integer> critical = new ArrayList<>();
            List<Integer> pseudoCritical = new ArrayList<>();

            for (int i = 0; i < edges.length; i++) {
                int[] edge = edges[i];
                edge = Arrays.copyOf(edge, edge.length + 1);
                edge[3] = i;
                edges[i] = edge;
            }

            Arrays.sort(edges, (a, b) -> Integer.compare(a[2], b[2]));

            int mstwt = findMST(n, edges, -1, -1);

            for (int i = 0; i < edges.length; i++) {
                if (mstwt < findMST(n, edges, i, -1))
                    critical.add(edges[i][3]);
                else if (mstwt == findMST(n, edges, -1, i))
                    pseudoCritical.add(edges[i][3]);
            }

            List<List<Integer>> result = new ArrayList<>();
            result.add(critical);
            result.add(pseudoCritical);
            return result;
        }

        private int findMST(int n, int[][] edges, int block, int e) {
            UnionFind uf = new UnionFind(n);
            int weight = 0;

            if (e != -1) {
                weight += edges[e][2];
                uf.union(edges[e][0], edges[e][1]);
            }

            for (int i = 0; i < edges.length; i++) {
                if (i == block)
                    continue;

                if (uf.findParent(edges[i][0]) == uf.findParent(edges[i][1]))
                    continue;

                uf.union(edges[i][0], edges[i][1]);
                weight += edges[i][2];
            }

            for (int i = 0; i < n; i++) {
                if (uf.findParent(i) != uf.findParent(0))
                    return Integer.MAX_VALUE;
            }

            return weight;
        }
    }
}