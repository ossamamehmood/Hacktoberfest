using System;

namespace LinkedList
{
    class Program
    {
        static void Main(string[] args)
        {
            var linkedList = new Linked_List();
            var node1 = linkedList.Creat(50);
            linkedList.Link(node1);
            var node2 = linkedList.Creat(30);
            linkedList.Link(node2);
            var node3 = linkedList.Creat(20);
            linkedList.Link(node3);
            var node4 = linkedList.Creat(10);
            linkedList.Link(node4);
            var node5 = linkedList.Creat(40);
            linkedList.Link(node5);
            // Sort
            linkedList.Sort();
            // to display elements in linkedlist
            linkedList.Traverse();
            // delete from a position
            Console.WriteLine("after delete");
            linkedList.DeleteFromLinkedList(node1, 3);
            linkedList.Traverse();
            //size of the linkedlist
            Console.WriteLine("size of the list : ");
            Console.WriteLine(linkedList.SizeOfLinkedList(node1));
            Console.WriteLine("center element is : ");
            //center element of the list
            linkedList.CenterNode(node1);
            //delete last node
            Console.WriteLine("after removing last element : ");
            linkedList.DeleteFromLast(node1);
            linkedList.Traverse();
            //add at a position
            Console.WriteLine("adding number in between : ");
            linkedList.AddToLinkedList(60, node1, 0);
            linkedList.Traverse();
            // add at last 
            Console.WriteLine("adding element at the last : ");
            linkedList.AddAtEnd(70);
            linkedList.Traverse();
            //list iterator
            Console.WriteLine("printing data after position : ");
            linkedList.ListIterator(2);
            // Reverse
            Console.WriteLine("Reverse of the list :");
            linkedList.Reverse();
            linkedList.Traverse();
            
        }
    }
}
