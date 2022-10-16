
import java.io.*;

class GFG{
static class TreeNode
{
	int data;
	TreeNode left, right;
}

static TreeNode newNode(int data)
{
	TreeNode Node = new TreeNode();
	Node.data = data;
	Node.left = Node.right = null;
	return (Node);
}

static int sumofdepth(TreeNode root, int l)
{
	
	// Base Case
	if (root == null)
		return 0;
		

	return l + sumofdepth(root.left, l + 1) +
			sumofdepth(root.right, l + 1);
}

static int Noofnodes(TreeNode root)
{
	if (root == null)
		return 0;

	return Noofnodes(root.left) +
		Noofnodes(root.right) + 1;
}

public static int sum = 0;

static void distance(TreeNode root, int target,
					int distancesum, int n)
{

	if (root.data == target)
	{
		sum = distancesum;
		return;
	}
	if (root.left != null)
	{
		int nodes = Noofnodes(root.left);

		int tempsum = distancesum - nodes +
							(n - nodes);

		distance(root.left, target, tempsum, n);
	}

	if (root.right != null)
	{
		int nodes = Noofnodes(root.right);

		int tempsum = distancesum - nodes +
							(n - nodes);

		
		distance(root.right, target, tempsum, n);
	}
}

public static void main(String[] args)
{
	TreeNode root = newNode(1);
	root.left = newNode(2);
	root.right = newNode(3);
	root.left.left = newNode(4);
	root.left.right = newNode(5);
	root.right.left = newNode(6);
	root.right.right = newNode(7);
	root.left.left.left = newNode(8);
	root.left.left.right = newNode(9);

	int target = 3;
	int distanceroot = sumofdepth(root, 0);
	int totalnodes = Noofnodes(root);

	distance(root, target, distanceroot,
			totalnodes);
	System.out.println(sum);
}
}

