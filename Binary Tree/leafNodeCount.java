class TreeNode {
    int data;
    TreeNode left;
    TreeNode right;

    public TreeNode(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}

public class BinaryTree {
    TreeNode root;

    public int countLeaves(TreeNode node) {
        if (node == null) {
            return 0;
        }

        if (node.left == null && node.right == null) {
            return 1; // Leaf node
        }

        int leftLeaves = countLeaves(node.left);
        int rightLeaves = countLeaves(node.right);

        return leftLeaves + rightLeaves;
    }

    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();
        tree.root = new TreeNode(1);
        tree.root.left = new TreeNode(2);
        tree.root.right = new TreeNode(3);
        tree.root.left.left = new TreeNode(4);
        tree.root.left.right = new TreeNode(5);
        tree.root.right.left = new TreeNode(6);
        tree.root.right.right = new TreeNode(7);

        int leaves = tree.countLeaves(tree.root);
        System.out.println("Number of leaves in the binary tree: " + leaves);
    }
}
