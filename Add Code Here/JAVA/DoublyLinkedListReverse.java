import java.util.*;

class DoublyLinkedListReverse
{   
    static Node head; 

     static class Node 
     { 
        int data; 
        Node next, prev; 
        Node(int d) 
        { 
            data = d; 
            next = prev = null; 
        } 
    } 

    public static void reverse() 
    { 
        Node temp = null; 
        Node current = head; 

        while (current != null) 
        { 
            temp = current.prev; 
            current.prev = current.next; 
            current.next = temp; 
            current = current.prev; 
        } 

        if (temp != null) 
        { 
            head = temp.prev; 
        } 
    } 

    public static void insert(int data) 
    { 
        Node newNode = new Node(data); 
        newNode.prev = null; 
        newNode.next = head; 

        if (head != null) { 
            head.prev = newNode; 
        } 
        head = newNode; 
    } 

   public static void print(Node node) 
    { 
        while (node != null) 
        { 
            System.out.print(node.data + " "); 
            node = node.next; 
        } 
    } 

    public static void main(String[] args)
    { 
        DoublyLinkedListReverse dllr = new DoublyLinkedListReverse(); 
        Scanner sc=new Scanner(System.in);

        System.out.println("Enter no of elements:");
        int n=sc.nextInt();

        System.out.println("Enter elements:");
        for(int i=0;i<n;i++)
        {
        	int x=sc.nextInt();
        	insert(x);
        } 

        reverse(); 

        System.out.println("Reversed Linked List: "); 
        print(head); 
    } 
} 
