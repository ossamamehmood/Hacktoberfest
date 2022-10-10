import java.util.Currency;
import java.util.LinkedList;


public class linklist_reversal_using_recursion {
    public void reverseList(head){
        if(head == null || head.next== null){
            return head;
        }
        reverseList(head.next);
        head.next.next = head;
        head.next = null;

        return newHead;
    }
    public static void main(String[] args) {
        LinkedList<Integer> list = new LinkedList<>();
        list.add(1);
        list.add(2);
        list.add(3);
        list.add(4);
        list.add(5);
        list.add(6);
        System.out.println(list);
        reverseList(list);
        System.out.println(list);

    }
}
