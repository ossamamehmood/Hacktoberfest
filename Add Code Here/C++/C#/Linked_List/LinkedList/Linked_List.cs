using System;

namespace LinkedList
{
    public class Linked_List {
        private Node _head;
        private int _count = 1;
        private Node _previousNode;
        public Node Creat(int number)
        {
            var node = new Node(number);
            return node;
        }
        public void Link(Node node)
        {
            if (_count == 1)
            {
                _head = node;
                
                _count++;
                
            }else if (_count == 2)
            {
                _head.Next = node;
                _previousNode = node;
                _count++;
            }
            else {
                _previousNode.Next = node;
                _previousNode = node;
            }
            
        }
        public void Traverse()
        {
            Node temp = _head;
            while (temp != null) {
                Console.WriteLine(temp.Data);
                temp = temp.Next;
            }
        }
        public void AddToLinkedList(int data, Node head, int position) {
            
            try
            {
                var newNumber = new Node(data);
                if (position == 0)
                {
                    newNumber.Next = _head;
                    _head = newNumber;
                    return;
                }
                Node previousNode = head;
                for (int i = 0; i < position - 1; i++)
                {
                    previousNode = previousNode.Next;
                }
                newNumber.Next = previousNode.Next;
                previousNode.Next = newNumber;

            }
            catch (Exception )
            {

                Console.WriteLine("Invalid Position or list is empty ");
            }

        }
        public void AddAtEnd(int data) {
            
            try
            {
                var newNumber = new Node(data);
                if (_head == null)
                {
                    _head = newNumber;
                }
                var lastNode = _head;
                

                while (lastNode.Next != null)
                {
                    lastNode = lastNode.Next;
                }
                lastNode.Next = newNumber;

            }
            catch (Exception )
            {

                Console.WriteLine("error");
            }

        }
        public void DeleteFromLinkedList(Node head, int position)
        {
            
            try
            {
                if (position == 0)
                {
                    head = null;
                    return;
                }
                Node previousNode = head;
                Node deleteNode = head;
                for (int i = 1; i < position - 1; i++)
                {
                    previousNode = previousNode.Next;
                }
                for (int i = 1; i < position; i++)
                {
                    deleteNode = deleteNode.Next;
                }
                previousNode.Next = deleteNode.Next;
                deleteNode.Next = null;

            }
            catch (Exception)
            {

                Console.WriteLine("Invalid Position or list is empty ");
            }

        }
        public int SizeOfLinkedList(Node head)
        {
            Node currentNode = head;
            var count = 0;
            while (currentNode != null)
            {
                currentNode = currentNode.Next;
                count += 1;
            }
            return count;
        }
        public void CenterNode(Node head)
        {
            var size=SizeOfLinkedList(head);
            var centerNode = head;
            for (int i = 0; i < size / 2; i++)
               {
                   centerNode = centerNode.Next;
               }
               Console.WriteLine(centerNode.Data);
        }
        public void DeleteFromLast(Node head)
        {
            var secondLastNode = head;
            var size = SizeOfLinkedList(head);
            for(int i = 0; i < size - 2; i++) {
                secondLastNode = secondLastNode.Next;
            }
            secondLastNode.Next = null;
        }
        public void ListIterator(int position) {
            var hasNext = true;
            var positionNode = _head;
            while (hasNext)
            {
                for (int i = 0; i < position-1; i++)
                {
                    positionNode = positionNode.Next;
                }
                while (positionNode != null)
                {
                    Console.WriteLine(positionNode.Data);
                    positionNode = positionNode.Next;
                }
                if (positionNode == null)
                {
                    hasNext = false;
                }

            }
            
            
        }

        public void Sort()
        {
            try
            {
                if (_head == null)
                {
                    throw new Exception("list is empty :");
                }
            }
            catch (Exception e)
            {

                Console.WriteLine(e.Message);
            }
            if (_head.Next == null) {
                return;
            }

                 var traverse = _head;
                int temp;
                while (traverse != null)
                {
                    var next = traverse.Next;
                    while (next != null)
                    {
                        int compare = traverse.Data.CompareTo(next.Data);
                        if (compare > 0)
                        {
                            temp = traverse.Data;
                            traverse.Data = next.Data;
                            next.Data = temp;
                        }
                        next = next.Next;
                    }
                    traverse = traverse.Next;
                }
        } 
        public Node Reverse()
        {
            try
            {
                Node perviousNode = null;

                var currentNode = _head;
                while (currentNode != null)
                {
                    var temp = currentNode.Next;
                    currentNode.Next = perviousNode;
                    perviousNode = currentNode;
                    currentNode = temp;

                }
                if (_head == null)
                {
                    throw new NullReferenceException();
                }
                _head = perviousNode;
                return _head;
                

            }
            catch (NullReferenceException)
            {

                Console.WriteLine("list is empty");
            }
            return null;
           
        }

    }
    
}
