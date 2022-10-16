class testDLinkedList{
	public static void main(String args[]){
		DLinkedList list = new DLinkedList();
		
		list.insertFirst(10);
		list.insertFirst(20);
		list.insertFirst(30);
		list.insertFirst(70);
		list.insertFirst(80);
		list.insertFirst(90);
		
		list.insertEnd(40);
		
		list.printList();
		
		System.out.println();
		
		Node n1 = new Node(20); 
		
		list.insertAfter(n1, 100);
		
		list.printList();
		
		System.out.println();
		
		Node n2 = new Node(30);
		
		
	
		list.printFrom(n2);
		
		System.out.println();
		Node n3 = list.removeFirst();
		System.out.println(n3.data);
		list.printList();
		
		System.out.println();
		Node n4 = list.removeLast();
		System.out.println(n4.data);
		System.out.println();
		
		list.printList();
		
		System.out.println();
		
		list.removeAfter(n1);
		list.printList();
		
		
	}
}