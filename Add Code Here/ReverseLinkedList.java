import java.util.*;

public class ReverseLinkedList {
    public static Lcheck head = null;
    public static class Lcheck {
        int data;
        Lcheck next;
    }
    public static void get(int value) {
        Lcheck temp = new Lcheck();
        temp.data = value;
        temp.next = null;
        if (head == null) {
            head = temp;
        }
        else {
            Lcheck last_check = head;
            while (last_check.next != null) {
                last_check = last_check.next;
            }
            last_check.next = temp;
        }
    }
    public static void print(Lcheck temp) {
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
    }

    public static void reverseLinkedlist() {

        Stack<Lcheck> t = new Stack<>();
        Lcheck temp = head;
        while (temp.next != null) {
            t.add(temp);
            temp = temp.next;
        }
        head = temp;
        while (!t.isEmpty()) {
            temp.next = t.peek();
            t.pop();
            temp = temp.next;
        }
        temp.next = null;
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        System.out.println("Enter 5 elements  for Reverse linked list");
        for (int i = 0; i < 5; i++) {
            int e = in.nextInt();
            get(e);
        }
        System.out.print("linked list Before Reverse\n");
        print(head);
        reverseLinkedlist();
        System.out.print("\nlinked list After Reverse\n");
        print(head);
    }
}

