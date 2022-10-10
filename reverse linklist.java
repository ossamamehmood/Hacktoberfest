public class LinkedListRecursive   
{  
static LinkedListNode head;   
  
static class LinkedListNode   
{  
 
int val;  
  

LinkedListNode next;  
  
  
LinkedListNode(int d)  
{  
  
val = d;  
next = null;  
}  
}  
  

public LinkedListNode reverseList(LinkedListNode head)  
{  

if (head == null || head.next == null)  
{  
return head;  
}  
  

LinkedListNode r = reverseList(head.next);  
head.next.next = head;  
  
  
head.next = null;  
  
// fixing the head pointer  
return r;  
}  
  

public void printList(LinkedListNode h)  
{  
LinkedListNode t = h;  
while (t != null)   
{  
System.out.print(t.val + " ");  
  

t = t.next;  
}  
  
System.out.println();  
}  
  
  

public static void main(String argvs[])  
{  

LinkedListRecursive listObj = new LinkedListRecursive();  
  

listObj.head = new LinkedListNode(4);  
  
 
listObj.head.next = new LinkedListNode(6);  
  
 
listObj.head.next.next = new LinkedListNode(7);  
  
 
listObj.head.next.next.next = new LinkedListNode(1);  
  

listObj.head.next.next.next.next = new LinkedListNode(5);  
  

listObj.head.next.next.next.next.next = new LinkedListNode(8);  
   
listObj.head.next.next.next.next.next.next = new LinkedListNode(3);  
  

listObj.head.next.next.next.next.next.next.next = new LinkedListNode(2);  
  
  
System.out.println("The Linked list before reversal is: ");  
listObj.printList(head);  
head = listObj.reverseList(head);  
System.out.println(" ");  
System.out.println("After reversal, the linked list is: ");  
listObj.printList(head);  
}  
}  
