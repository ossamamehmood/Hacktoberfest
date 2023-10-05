class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        List<TreeNode> pathP = findPath(root, p);
        List<TreeNode> pathQ = findPath(root, q);
        
        // Check if either path is empty, indicating that p or q is not in the tree
        if (pathP.isEmpty() || pathQ.isEmpty()) {
            return null;
        }

        int i = 0;
        while (i < pathP.size() && i < pathQ.size() && pathP.get(i) == pathQ.get(i)) {
            i++;
        }

        // The last common node before they diverge is the lowest common ancestor
        return pathP.get(i - 1);
    }

    private List<TreeNode> findPath(TreeNode root, TreeNode target) {
        List<TreeNode> path = new ArrayList<>();
        findPathRecursive(root, target, path);
        return path;
    }

    private boolean findPathRecursive(TreeNode current, TreeNode target, List<TreeNode> path) {
        if (current == null) {
            return false;
        }

        path.add(current);

        if (current == target) {
            return true;
        }

        if (findPathRecursive(current.left, target, path) || findPathRecursive(current.right, target, path)) {
            return true;
        }

        path.remove(path.size() - 1);
        return false;
    }
}
