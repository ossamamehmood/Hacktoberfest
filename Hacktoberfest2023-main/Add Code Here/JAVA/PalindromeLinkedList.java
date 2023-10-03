import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Node<T> {
    T data;
    Node<T> next;
    
    public Node(T data) {
        this.data = data;
    }
}

public class PalindromeLinkedList {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    public static Node<Integer> takeInput() throws IOException {
        Node<Integer> head = null, tail = null;

        String[] datas = br.readLine().trim().split("\\s");

        int i = 0;
        while(i < datas.length && !datas[i].equals("-1")) {
            int data = Integer.parseInt(datas[i]);
            Node<Integer> newNode = new Node<Integer>(data);
            if(head == null) {
                head = newNode;
                tail = newNode;
            }
            else {
                tail.next = newNode;
                tail = newNode;
            }
            i += 1;
        }

        return head;
    }
    
    public static void print(Node<Integer> head){
        while(head != null) {
            System.out.print(head.data + " ");
            head = head.next;
        }
        
        System.out.println();
    }
    
    public static void main(String[] args) throws NumberFormatException, IOException {
        int t = Integer.parseInt(br.readLine().trim());

        while (t > 0) {

            Node<Integer> head = takeInput(); 

            boolean ans = isPalindrome(head);
            System.out.println(ans);

            t -= 1;

        }
        
    }
    public static boolean isPalindrome(Node<Integer> head) {
		if (head == null || head.next == null) {
        return true; 
    }

   
    Node<Integer> slow = head;
    Node<Integer> fast = head;
    while (fast.next != null && fast.next.next != null) {
        slow = slow.next;
        fast = fast.next.next;
    }

    
    Node<Integer> secondHalf = reverseList(slow.next);

    
    Node<Integer> firstHalf = head;
    while (secondHalf != null) {
        if (!firstHalf.data.equals(secondHalf.data)) {
            return false;
        }
        firstHalf = firstHalf.next;
        secondHalf = secondHalf.next;
    }

    return true;

	}
	    public static Node<Integer> reverseList(Node<Integer> head) {
        Node<Integer> prev = null;
        Node<Integer> current = head;
        Node<Integer> next = null;

        while (current != null) {
            next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }
}

