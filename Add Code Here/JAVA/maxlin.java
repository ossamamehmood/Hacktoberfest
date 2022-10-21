class LinkedList
{
    Node head;
  
    class Node
    {
        int data;
        Node next;
        Node(int d)
        {
            data = d;
            next = null;
        }
    }
  
    // Method to adjust pointers and print final list
    void finalMaxSumList(Node a, Node b)
    {
        Node result = null;
  
        /* assigning pre and cur to head
           of the linked list */
        Node pre1 = a, curr1 = a;
        Node pre2 = b, curr2 = b;
  
        /* Till either of current pointers is not null
           execute the loop */
        while (curr1 != null || curr2 != null)
        {
            // Keeping 2 local variables at the start of every
            // loop run to keep track of the sum between pre
            // and cur reference elements.
            int sum1 = 0, sum2 = 0;
  
            // Calculating sum by traversing the nodes of linked
            // list as the merging of two linked list.  The loop
            // stops at a common node
            while (curr1 != null && curr2 != null &&
                   curr1.data != curr2.data)
            {
  
                if (curr1.data<curr2.data)
                {
                    sum1 += curr1.data;
                    curr1 = curr1.next;
                }
                else
                {
                    sum2 += curr2.data;
                    curr2 = curr2.next;
                }
            }
  
            // If either of current pointers becomes null
            // carry on the sum calculation for other one.
            if (curr1 == null)
            {
                while (curr2 != null)
                {
                    sum2 += curr2.data;
                    curr2 = curr2.next;
                }
            }
            if (curr2 == null)
            {
                while(curr1 != null)
                {
                    sum1 += curr1.data;
                    curr1 = curr1.next;
                }
            }
  
            // First time adjustment of resultant head based on
            // the maximum sum.
            if (pre1 == a && pre2 == b)
                result = (sum1 > sum2) ? pre1 : pre2;
  
            // If pre1 and pre2 don't contain the head references of
            // lists adjust the next pointers of previous pointers.
            else
            {
                if (sum1 > sum2)
                    pre2.next = pre1.next;
                else
                    pre1.next = pre2.next;
            }
  
            // Adjusting previous pointers
            pre1 = curr1;
            pre2 = curr2;
  
            // If curr1 is not NULL move to the next.
            if (curr1 != null)
                curr1 = curr1.next;
  
            // If curr2 is not NULL move to the next.
            if (curr2 != null)
                curr2 = curr2.next;
        }
  
        while (result != null)
        {
            System.out.print(result.data + " ");
            result = result.next;
        }
        System.out.println();
    }
  
    /*  Inserts a node at start of linked list */
    void push(int new_data)
    {
        /* 1 & 2: Allocate the Node &
                  Put in the data*/
        Node new_node = new Node(new_data);
  
        /* 3. Make next of new Node as head */
        new_node.next = head;
  
        /* 4. Move the head to point to new Node */
        head = new_node;
    }
  
  
    /* Driver program to test above functions */
    public static void main(String args[])
    {
        LinkedList llist1 = new LinkedList();
        LinkedList llist2 = new LinkedList();
  
        //Linked List 1 : 1->3->30->90->110->120->NULL
        //Linked List 2 : 0->3->12->32->90->100->120->130->NULL
  
        llist1.push(120);
        llist1.push(110);
        llist1.push(90);
        llist1.push(30);
        llist1.push(3);
        llist1.push(1);
  
        llist2.push(130);
        llist2.push(120);
        llist2.push(100);
        llist2.push(90);
        llist2.push(32);
        llist2.push(12);
        llist2.push(3);
        llist2.push(0);
  
        llist1.finalMaxSumList(llist1.head, llist2.head);
    }
}
