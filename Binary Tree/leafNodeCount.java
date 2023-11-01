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

    public int getHeight(TreeNode node) {
        if (node == null) {
            return 0;
        }

        int leftHeight = getHeight(node.left);
        int rightHeight = getHeight(node.right);

        return Math.max(leftHeight, rightHeight) + 1;
    }

    public void inOrderTraversal(TreeNode node) {
        if (node == null) {
            return;
        }

        inOrderTraversal(node.left);
        System.out.print(node.data + " ");
        inOrderTraversal(node.right);
    }

    public int countNodes(TreeNode node) {
        if (node == null) {
            return 0;
        }

        int leftCount = countNodes(node.left);
        int rightCount = countNodes(node.right);

        return leftCount + rightCount + 1;
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

        System.out.println("Number of leaves in the binary tree: " + tree.countLeaves(tree.root));
        System.out.println("Height of the binary tree: " + tree.getHeight(tree.root));

        System.out.print("In-order traversal of the binary tree: ");
        tree.inOrderTraversal(tree.root);
        System.out.println();

        System.out.println("Total nodes in the binary tree: " + tree.countNodes(tree.root));
    }
}

