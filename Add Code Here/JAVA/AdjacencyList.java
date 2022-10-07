import java.util.ArrayList;

public class AdjacencyList {
    public static void main(String[] args) {
        int n=3,m=3;
        ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>();

        //n+1
        for(int i=0;i<=n;i++)
        {
            adj.add(new ArrayList<Integer>());
        }
        //edge 1---2
        adj.get(1).add(2);
        adj.get(2).add(1);

        // adj.get(u).add(v);
        // adj.get(v).add(u);

        //edge 2---3
        adj.get(2).add(3);
        adj.get(3).add(2);

        //edge 1--3
        adj.get(1).add(3);
        adj.get(3).add(1);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<adj.get(i).size();j++)
            {
                System.out.println(adj.get(i).get(j)+" ");
            }
            System.out.println();
        }
    }
}
