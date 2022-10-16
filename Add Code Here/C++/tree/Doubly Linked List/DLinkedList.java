class Node{
	public int data;
	public Node prev;
	public Node next;
	
	public Node(int data){
		this.data = data;
	}
}

class DLinkedList{
	Node head;
	
	public DLinkedList(){
		head = null;
	}
	
	public void insertFirst(int data){
		Node newNode = new Node(data);
		
		newNode.next = head;
		newNode.prev = null;
		
		if(head != null){
			head.prev = newNode;
		}
		
		head = newNode;
		
	}
	
	public void insertEnd(int data){
		Node newNode = new Node(data);
		
		if(head == null){
			insertFirst(data);
			return;
		}
		
		Node last = head;
		
		while(last.next != null){
			last = last.next;
		}
		
		newNode.next = null;
		last.next = newNode;
		newNode.prev = last;
	}
	
	public void insertAfter(Node prevNode, int data){
		Node newNode = new Node(data);
		Node current = head;
		
		while(prevNode.data != current.data){
			current = current.next;
		}
		
		newNode.next = current.next;
		current.next = newNode;
		newNode.prev = current;
		
		if(newNode.next != null){
			current.next.prev = newNode;
			}
		
	}
	
	public Node removeFirst(){
		Node current = head;
		head = head.next;
		return current;
	}
	
	public Node removeLast(){
		Node current = head;
		Node previous = null;;
		
		while(current.next != null){
			previous = current;
			current = current.next;
		}
		
		previous.next = null;
		
		return current;
	}
	
	public Node removeAfter(Node node){
		Node current = head;
		
		
		while(current.data != node.data){
			current = current.next;
		}
		
		Node removeNode = current;
		
		if(current.next != null)
			current.next = current.next.next;
		if(current.prev != null)
			current.next.prev = current;
			
		return removeNode;
	}
	
	public void printList(){
		Node current = head;
		
		if(head == null){
			System.out.println("List is Empty");
			return;
		}
		
		System.out.println("Nodes of doubly linked list: ");
		
		while(current != null){
			System.out.print(current.data + " ");  
            current = current.next;  
		}
	}
	
	
	public void printFrom(Node node){
		Node forward = head;
		Node backword = null;
		while(forward.data != node.data){
			backword = forward;
			forward = forward.next;
		}
		
		System.out.println("Traversal in forward Direction");
		while(forward != null){
			System.out.print(forward.data + " ");
			forward = forward.next;
		}
		
		System.out.println();
        System.out.println("Traversal in reverse direction");
		while(backword != null){
			System.out.print(backword.data + " ");
			backword = backword.prev;
		}
	}
}