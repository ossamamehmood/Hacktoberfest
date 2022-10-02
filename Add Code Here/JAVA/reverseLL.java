//Reverse a Linked list

public class LinkedList
{
    //To create a Linked List
	static Node head;
    static class Node
    {
        int val;
        Node next;
        
        public Node(int val)
        {
            this.val = val;
            this.next = null;
        }
    }

	//Reverse Method
	Node reverseList(Node node) 
	{
		Node curr = node, next = null, prev = null;
		while(curr!=null)
		{
			next=curr.next;
			curr.next=prev;
			prev=curr;
			curr=next;
		}
		node = prev;
		return prev;
	}
	
	//To display the Linked List
	void display(Node data)  
	{  
        while (data != null)   
        {  
            System.out.print(data.val + " ");  
            data = data.next;  
        }  
    }  
	
    //Main Method
    public static void main(String argvs[])  
    {  

        LinkedList list = new LinkedList();  
  
        list.head = new Node(4);  
        list.head.next = new Node(2);  
        list.head.next.next = new Node(3);  
        list.head.next.next.next = new Node(5);
        list.head.next.next.next.next = new Node(7);
  
        System.out.println("Original Linked list : ");  
        list.display(head);  
        head = list.reverseList(head);  
        System.out.println("\n");  
        System.out.println("Reversed Linked list : ");  
        list.display(head);  
    }  
}

/*
Output:

Original Linked list : 
4 2 3 5 7 

Reversed Linked list : 
7 5 3 2 4 

*/