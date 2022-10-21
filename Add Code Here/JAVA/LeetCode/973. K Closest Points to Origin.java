class Solution {
    public int[][] kClosest(int[][] points, int k) {
        PriorityQueue<Integer> temp = new PriorityQueue<>((a,b)->{
            int d1 = points[a][0]*points[a][0] + points[a][1]*points[a][1];
            int d2 = points[b][0]*points[b][0] + points[b][1]*points[b][1];
            
            return d2-d1;
        }
        );
        
        for(int i=0; i<points.length; ++i){
            temp.add(i);
            if(temp.size() > k) temp.remove();
        }
        
        int[][] sol = new int[k][];
        int i=0;
        
        while(temp.size()!=0){
            int index=temp.remove();
            sol[i++]=points[index];
        }
        
        return sol;
        
    }
}