import java.util.*;

// Linked List Node
class Node {
	int data;
	Node next;
	Node(int a)
	{
		data = a;
		next = null;
	}
}

class GFG {
	// utility function to insert node in the list
	static Node push(Node head, int val)
	{
		Node newNode = new Node(val);
		if (head == null) {
			head = newNode;
			return head;
		}

		Node temp = head;
		while (temp.next != null)
			temp = temp.next;

		temp.next = newNode;
		return head;
	}

	// utility function to reverse k nodes in the list
	static Node reverse(Node head, int k)
	{
		// If head is NULL or K is 1 then return head
		if (head == null || head.next == null)
			return head;

		// creating dummy node
		Node dummy = new Node(-1);
		dummy.next = head;

		// Initializing three points prev, curr, next
		Node prev = dummy;
		Node curr = dummy;
		Node next = dummy;

		// Calculating the length of linked list
		int count = 0;
		while (curr != null) {
			count++;
			curr = curr.next;
		}

		// Iterating till next is not NULL
		while (next != null) {
			curr = prev.next; // Curr position after every
							// reverse group
			next = curr.next; // Next will always next to
							// curr
			int toLoop
				= count > k
					? k
					: count - 1; // toLoop will set to
								// count - 1 in case of
								// remaining element

			for (int i = 1; i < toLoop; i++) {
				// 4 steps as discussed above
				curr.next = next.next;
				next.next = prev.next;
				prev.next = next;
				next = curr.next;
			}
			prev = curr; // Setting prev to curr
			count -= k; // Update count
		}
		return dummy.next; // dummy -> next will be our new
						// head for output linked
		// list
	}
	// utility function to print the list
	static void print(Node head)
	{
		while (head.next != null) {
			System.out.print(head.data + " ");
			head = head.next;
		}
		System.out.println(head.data);
	}

	public static void main(String args[])
	{
		Node head = null;
		int k = 3;
		head = push(head, 1);
		head = push(head, 2);
		head = push(head, 3);
		head = push(head, 4);
		head = push(head, 5);
		head = push(head, 6);
		head = push(head, 7);
		head = push(head, 8);
		head = push(head, 9);

		System.out.println("Given Linked List");
		print(head);
		System.out.println("Reversed list");
		Node newHead = reverse(head, k);
		print(newHead);
	}
}
// This code is contributed by Rishabh Joshi
