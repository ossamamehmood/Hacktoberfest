import java.util.*;


public class CheckBST 
{
		
static Node root;

CheckBST()

{
			
root=null;
		
}
	
	
static class Node

{
		
	int data;

	Node left,right;

	Node(int d)

	{
		
data=d;
		
		left=right=null;

	}
		
}


static Vector v=new Vector();
	
static void Inorder(Node r)
	
{
	

	if(r!=null)

	{   
Inorder( r.left);

	     v.add(r.data);

	     Inorder( r.right);


	}

			
		
}

		
	
static void checkBst(Vector v)

{
  
    int m,n,count=0;

    for(int i=0;i<v.size()-1;i++)

       {

	   m=(int)v.get(i);

	   n=(int)v.get(i+1);

	   if(m<n)
	
	   {
		
		   i++;
			
   		   count=1;
	
	   }

	   else
 	{
	
	   count=0;

	   break;

         	 }
	
        }

	  if(count==1)

	{
System.out.println("It is a binary tree");
  }

	else {
  System.out.println("It is not a binary tree");

}


}


public static void main(String arg[])	
{
	
	CheckBST tree=new CheckBST();
		

		tree.root =new Node(50);
		

		tree.root.left =new Node(30);
		
		tree.root.right =new Node(60);
		

		tree.root.left.left =new Node(20);
	
		tree.root.left.right =new Node(40);
		

		Inorder(root);
	
		checkBst(v);

		

}



}
