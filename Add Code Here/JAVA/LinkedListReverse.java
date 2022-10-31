package LinkedList;
import java.util.*;

public class LinkedListReverse
{	
	Node head;
	static class Node
	{
		Node next;
		int data;
		Node(int d)
		{	data=d;	}		
	}
	
	public static LinkedListReverse insert(LinkedListReverse list,int data)
	{
		Node newNode=new Node(data);
		newNode.next=null;
		if(list.head==null)
		{	list.head=newNode;	}
		else
		{	Node last=list.head;
			while(last.next!=null)
			{	last=last.next;		}
			last.next=newNode;
		}
		return list;
	}
	
	public static void display(Node node)
	{ 
		while (node != null) 
		{ 	System.out.print(node.data+"  "); 
			node = node.next; 	} 
	}
	
	public static Node reverse(Node head)
	{
		if(head==null || head.next==null)
		{	return head;	}				
		Node newHeadNode=reverse(head.next);
		head.next.next=head;
		head.next=null;
		
		return newHeadNode;
	}
	
	public static void main(String[] args)
	{
		Scanner sc=new Scanner(System.in);
		System.out.print("Enter no of nodes:");
		int n=sc.nextInt();
		LinkedListReverse list=new LinkedListReverse();
		System.out.print("Enter elements:");
		for(int i=0;i<n;i++)
		{
			int x=sc.nextInt();
			insert(list,x);
		}
		System.out.print("LinkedList: ");
		display(list.head);
		Node list1=reverse(list.head);
		System.out.print("\nReverse LinkedList: ");
		display(list1);
	}
}
