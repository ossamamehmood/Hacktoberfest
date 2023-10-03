public class UnionFind{
    private int[] id;
    private int[] sz;
    public UnionFind(int N){
        id = new int[N];
        sz = new int[N];
        for (int i = 0; i < N; i++){ //set id of each object to itself
            id[i] = i;
        }
    }

    private int root(int i){
        //chase parent pointers until reach root
        while(i != id[i]){
            id[i] = id[id[i]];
            i = id[i];
        }
        return i;
    }
    
    // connected is there a path connecting the two object ?
    public boolean connected(int p, int q){
        // check if p and q have same root
        return root(p) == root(q); 
    }

    // union : connect two object
    public void union(int p, int q){
        // change root of p to point to root of q
        int i = root(p);
        int j = root(q);
        if (i == j) return;
        if (sz[i] < sz[j]) {
            id[i] = j; 
            sz[j] += sz[i];
        }else{ 
            id[j] = i; 
            sz[i] += sz[j]; 
        }
    }
}