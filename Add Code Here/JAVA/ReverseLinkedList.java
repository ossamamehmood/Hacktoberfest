import java.util.*;

public class ReverseLinkedList 
{
        public static LinkedList<Integer> reverseLinkedList(LinkedList<Integer> MyLinkedList)
	      {
		        for (int i = 0; i < MyLinkedList.size() / 2; i++) 
		        {
			          Integer temp = MyLinkedList.get(i);
			          MyLinkedList.set(i, MyLinkedList.get(MyLinkedList.size() - i - 1));
			          MyLinkedList.set(MyLinkedList.size() - i - 1, temp);
		        }
		      return MyLinkedList;
	      }
	      public static void main(String[] args)
        {   
            // Creates LinkedList object
            LinkedList<Integer> MyLinkedList = new LinkedList<Integer>();

            //Initiates Scanner
            Scanner sc = new Scanner(System.in);

            //Takes input of how many elements we want to insert initially
            System.out.println("Enter the initial size of the linked list");
            int initialSize = sc.nextInt();

            //Inserts elements into LinkedList by taking elements as an input from user
            for (int i = 0; i < initialSize; i++) 
            {
                    System.out.print("Enter element at index " + (i) + ": ");
                    int element = sc.nextInt();
                    MyLinkedList.add(new Integer(element));

            }
            
            System.out.println("Linked list before reversing: " + MyLinkedList);
            
            //calls reverseLinkedList function which returns reversed linkedList
            //and will store them in original linkedList
	          MyLinkedList = reverseLinkedList(MyLinkedList);
	          System.out.println("Linked list after reversing: " + MyLinkedList);
	    }
	
}
