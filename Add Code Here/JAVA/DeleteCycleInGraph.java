class Solution {
    // Function to detect cycle in a directed graph.
    public boolean isCyclic(int V, ArrayList<ArrayList<Integer>> adj) {
        int []inDegree=new int[V];
        for(int i=0;i<inDegree.length;i++)
            for(int j:adj.get(i))
                inDegree[j]++;
            
        ArrayDeque<Integer> mq=new ArrayDeque<>();
        for(int i=0;i<inDegree.length;i++)
            if(inDegree[i]==0)
                mq.add(i);
        List<Integer> ts=new ArrayList<>();
        
        while(mq.size()!=0)
        {
            int rem=mq.remove();
            ts.add(rem);
            
            for(int i:adj.get(rem))
            {
                inDegree[i]--;
                if(inDegree[i]==0)
                    mq.add(i);
            }
        }
        return ts.size()==V?false:true;
    }
}
