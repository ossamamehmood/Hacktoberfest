import java.util.*;
public class nov17 {
	static Node head;
	static class Node{
		int data;
		Node next;
		Node(int item){
			data=item;
			next=null;
		}
	}

	public void insert(int new_data) 
	{
	    Node new_node = new Node(new_data);
	    if (head == null) 
	    { 
	        head = new Node(new_data); 
	        return; 
	    }
	    new_node.next = null; 
	    Node last = head;  
	    while (last.next != null) 
	        last = last.next; 
	    last.next = new_node; 
	    return; 
	}

	static void remove() {
		Node cuurent = null, nextCur = null, dup = null; 
        cuurent = head; 

        while (cuurent != null && cuurent.next != null) { 
            nextCur = cuurent;
            while (nextCur.next != null) {
                if (cuurent.data == nextCur.next.data) {
                    dup = nextCur.next; 
                    nextCur.next = nextCur.next.next;
                } else{ 
                    nextCur = nextCur.next; 
                } 
            } 
            cuurent = cuurent.next; 
        }
	}



	public static void main(String args[]) {
		Scanner s = new Scanner(System.in);
		nov17 list = new nov17();
        int n = s.nextInt();

        for(int i=0;i<n;i++)
        list.insert(s.nextInt());

        list.remove();
        while (head != null) { 
            System.out.print(head.data + " "); 
            head = head.next; 
        }
	}
}
