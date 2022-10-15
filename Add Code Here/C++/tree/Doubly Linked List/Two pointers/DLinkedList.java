class Node{
	public int data;
	public Node next;
	public Node prev;
	
	public Node(int data){
		this.data = data;
	}
}

class DLinkedList{
	Node head;
	Node tail;
	
	public DLinkedList(){
		head = tail = null;
	}
	
	public void insertFirst(int data){
		Node newNode = new Node(data);
		
		if(head == null){
			head = tail = newNode;
		} 
		else{
			head.prev = newNode;
			newNode.next = head;
			head = newNode;
		}
	}
	
	public void insertLast(int data){
		Node newNode = new Node(data);
		
		if(head == null){
			head = tail = newNode;
		}
		else{
			tail.next = newNode;
			newNode.prev = tail;
			tail = newNode;
		}
		
	}
	
	public int nodeCount(){
		int count = 0;
		Node current = head;
		while(current != null){
			current = current.next;
			count++;
		}
		return count;
	}
	
	public void insertAt(int data, int pos){
		int count = nodeCount();
		
		if(pos<0 || pos>count){
			System.out.println("Invalid position");
		}
		else if(pos == 1){
			insertFirst(data);
		}
		else{
			Node newNode = new Node(data);
			Node current = head;
			
			for(int i=0; i< pos-1; i++){
				current = current.next;
			}
			newNode.prev = current;
			newNode.next = current.next;
			current.next = newNode;
			newNode.next.prev = newNode;
		}
	}
	
	public Node deleteFirst(){
		Node temp = head;
		head = head.next;
		head.prev = null;
		
		return temp;
	}
	
	public Node deleteLast(){
		Node temp = tail;
		tail = tail.prev;
		tail.next = null;
		
		return temp;
	}
	
	public void deleteAt(int pos){
		int count = nodeCount();
		
		if(pos == 1){
			deleteFirst();
		}
		else if(pos == count){
			deleteLast();
		}
		else{
			Node current = head;
			
			for(int i=0; i<pos; i++){
				current = current.next;
			}
			current.prev.next = current.next;
			current.next.prev = current.prev;
		}	
	}
	
	public void reverseDLL(){
		Node currNode = head;
		Node nextNode = null;
		
		while(currNode != null){
			nextNode = currNode.next;
			currNode.next = currNode.prev;
			currNode.prev = nextNode;
			currNode = nextNode;
		}
		currNode = head;
		head = tail;
		tail = currNode;
	}
	
	public void printDLL(){
		Node current = head;
		while(current != null){
			System.out.print(current.data + " ");
			current = current.next;
		}
		System.out.println();
	}
}
