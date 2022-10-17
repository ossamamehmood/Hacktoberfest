class GfG
{
	boolean isCompleteBT(Node root)
    {
        if(root == null) return true;
        
        Queue<Node> q = new LinkedList<>();
        
        q.offer(root);
        
        boolean nullFlag = false;
        
        while(!q.isEmpty()){
            int size=  q.size();
            while(size-- > 0){
                
                Node current = q.poll();
                
                if(current.left == null){
                    if(!nullFlag){
                        nullFlag = true;
                    }
                }
                else{
                    if(nullFlag) return false;
                    q.offer(current.left);
                }
                
                
                if(current.right == null){
                    if(!nullFlag){
                        nullFlag = true;
                    }
                }
                else{
                    if(nullFlag) return false;
                    q.offer(current.right);
                }
                
            }
        }
        
        return true;
        
	} 
}
