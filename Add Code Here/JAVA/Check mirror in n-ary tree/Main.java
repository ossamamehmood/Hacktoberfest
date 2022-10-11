// Java program to check if two n-ary trees are mirror.
import java.util.*;
public class Main
{
	static boolean checkMirrorTree(int M, int N, int[] u1, int[] v1, int[] u2, int[] v2)
	{
		
		// Map to store nodes of the tree
		HashMap<Integer, Stack<Integer>> mp = new HashMap<>();
	
		// Traverse first tree nodes
		for (int i = 0 ; i < N ; i++ )
		{
		if(!mp.containsKey(u1[i]))
		{
			mp.put(u1[i], new Stack<Integer>());
		}
		else{
			mp.get(u1[i]).push(v1[i]);
		}
		}
		
		// Traverse second tree nodes
		for (int i = 0 ; i < N ; i++)
		{
			if(mp.containsKey(u2[i]) && mp.get(u2[i]).size() > 0)
			{
				if(mp.get(u2[i]).peek() != v2[i])
				return false;
				mp.get(u2[i]).pop();
			}
		}
	
		return true;
	}
	
// Driver code
	public static void main(String[] args) {
		int M = 7, N = 6;
	
		// Tree 1
		int[] u1 = { 1, 1, 1, 10, 10, 10 };
		int[] v1 = { 10, 7, 3, 4, 5, 6 };
		
		// Tree 2
		int[] u2 = { 1, 1, 1, 10, 10, 10 };
		int[] v2 = { 3, 7, 10, 6, 5, 4 };
	
		if(checkMirrorTree(M, N, u1, v1, u2, v2))
		System.out.print("Yes");
		else
		System.out.print("No");
	}
}
