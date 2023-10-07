class Solution {
    Set<Integer> set = new HashSet<Integer>();
    boolean exists = false;
    public boolean findTarget(TreeNode root, int k) {
        search(root, k);
        return exists;
    }
    
    public void search(TreeNode root, int k){
        if(root == null || exists) return;
        if(set.contains(k - root.val)){
            exists = true;
            return;
        }
        set.add(root.val);
        search(root.left, k);
        search(root.right, k);
    }
}
