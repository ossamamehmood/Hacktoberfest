import java.util.ArrayList;

class Node {
    int data;
    Node next;
    Node(int x) {
        this.data = x;
        this.next = null;
    }
}
class TestLinkedList {
    public static void main(String[] args) {
        TestLinkedList obj = new TestLinkedList();
        Node head = new Node(10);
        Node temp1 = new Node(20);
        Node temp2 = new Node(30);
        Node temp3 = new Node(40);
        Node temp4 = new Node(50);
        head.next = temp1;
        temp1.next = temp2;
        temp2.next = temp3;
        temp3.next = temp4;
        //getElements(head);
        //System.out.println();
        //System.out.println(searchLinkedList(head, 30));
        //System.out.println(recSearch(head, 40));
        //head = insertBeginning(head, 5);
        //head = insertBeginning(head, 1);
        //insertEnd(head, 60);
        //getElements(head);
        //deleteHead(head);
        //deleteTail(head);
        sortedInsert(head, 45);
        //getElements(head);
        //deleteAtPosNode(head, 3);
        //middleNodeData(head);
        //int ans = obj.getMiddle(head);
        //System.out.println(ans);
        //getElements(head);
    }

    static void getElements(Node head) {
        Node current = head;
        while(current != null) {
            System.out.print(current.data + "=>");
            current = current.next;
        }
    }

    // Searching a LinkedList - Iterative
    static int searchLinkedList(Node head, int x) {
        int position = 1;
        Node current = head;
        while(current != null) {
            if(current.data == x) {
                return position;
            }
            else {
                position++;
                current = current.next;
            }
        }
        return -1;
    }

    // Searching a LinkedList - Recursive
    static int recSearch(Node head, int x) {
        if(head == null) {
            return -1;
        }
        if(head.data == x) {
            return 1;
        }
        else {
            int res = recSearch(head.next, x);
            if(res == -1) {
                return -1;
            }
            else {
                return res+1;
            }
        }
    }

    // Insertion at the beginning
    static Node insertBeginning(Node head, int x) {
        Node temp = new Node(x);
        temp.next = head;
        return temp;
    }

    // Insertion at the end 
    static Node insertEnd(Node head, int x) {
        Node temp = new Node(x);
        if(head == null) {
            return temp;
        }
        while(head.next != null) {
            head = head.next;
        }
        head.next = temp;
        return temp;
    }

    // Delete First Node 
    static Node deleteHead(Node head) {
        if(head == null) {
           return null;
        }
        else {
           return head.next;
        }
    }

    // Delete Last Node
    static Node deleteTail(Node head) {
        if(head == null) {
            return null;
        }
        if(head.next == null) {
            return null;
        }
        Node current = head;
        while(current.next.next != null) {
            current = current.next;
        }
        current.next = null;
        return head;
    }

    // Sorted Insertion in LinkedLists
    static Node sortedInsert(Node head, int data) {
        Node temp = new Node(data);
        Node current = head;
        if(data < head.data) {
            temp.next = head;
            return temp;
        }
        while(current.next != null && current.next.data < data) {
            current = current.next;
        }
        temp.next = current.next;
        current.next = temp;
        return head;
    }

    // Delete at a given position
    static Node deleteAtPosNode(Node head, int pos) {
        Node current = head;
        if(pos==1) {
            current.next = head;
            return head;
        }
        for(int i=1; current != null && i<pos-1; i++) {
            current = current.next;
        }
        if(current == null || current.next == null) {
            return null;
        }
        Node next = current.next.next;
        current.next = next;
        return head;
    }

    // Middle of a linked list

    // Two Pointers Approach
    static int middleNodeData(Node head) {
        if(head == null) {
            return 0;
        }
        Node slow = head;
        Node fast = head;
        while(fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow.data;
    }

    // Naive Solution
    static int getMiddle(Node head)
    {
         if(head == null) {
             return 0;
         }
         int count = 0;
         Node current;
         for(current = head; current != null; current = current.next) {
             count++;
         }
         current = head;
         for(int i=0; i<count/2; i++) {
             current = current.next;
         }
         return current.data;
    }

    // Nth node from end of LinkedList
    // Two Pointers
    static int getNthFromLast(Node head, int n)
    {
    	if(head == null) {
    	    return -1;
    	}
    	Node first = head;
    	for(int i=0; i<n; i++) {
    	    if(first == null) {
    	        return -1;
    	    }
    	    first = first.next;
    	}
    	Node second = head;
    	while(first != null) {
    	    first = first.next;
    	    second = second.next;
    	}
    	return second.data;
    }

    // Length method
    static int getNthFromLastNode(Node head, int n)
    {
    	int length = 0;
    	for(Node current = head; current != null; current = current.next) {
    	    length++;
    	}
    	if(length < n) {
    	    return -1;
    	}
    	Node current = head;
    	for(int i=1; i<length-n+1; i++) {
    	    current = current.next;
    	}
    	return current.data;
    }

    // Reverse a LinkedList
    // Naive Solution
    static Node reverseLL(Node head) {
        ArrayList<Integer> arr = new ArrayList<Integer>();
        for(Node current = head; current != null; current = current.next) {
            arr.add(current.data);
        }
        for(Node current = head; current != null; current = current.next) {
            current.data = arr.remove(arr.size() - 1);
        }
        return head;
    }
    
    // Single iteration
    static Node reverseList(Node head)
    {
        Node current = head;
        Node previous = null;
        while(current != null) {
            Node next = current.next;
            current.next = previous;
            previous = current;
            current = next;
        }
        return previous;
    }

    // Recursive Approach
    static Node recursiveReverse(Node head)
    {
        if(head == null || head.next == null) {
            return head;
        }
        Node rest_head = reverseList(head.next);
        Node rest_tail = head.next;
        rest_tail.next = head;
        head.next = null;
        return rest_head;
    }

    // Remove Duplicates
    static Node removeDuplicates(Node head)
    {
	  Node current = head;
	  while(current != null && current.next != null) {
	      if(current.data == current.next.data) {
	          current.next = current.next.next;
	      }
	      else {
	          current = current.next;
	      }
	  }
	  return head;
    }
}
