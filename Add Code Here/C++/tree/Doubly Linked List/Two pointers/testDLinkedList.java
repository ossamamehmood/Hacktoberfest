class testDLinkedList{
	public static void main(String args[]){
		DLinkedList list = new DLinkedList();
		
		list.insertFirst(75);
		list.insertFirst(64);
		list.insertFirst(24);
		list.insertFirst(34);
		list.insertFirst(89);
		list.printDLL();
		
		list.insertLast(200);
		list.printDLL();
		
		list.insertAt(300, 3);
		list.printDLL();
		
		Node n1 = list.deleteFirst();
		System.out.println("Delete first: " + n1.data);
		list.printDLL();
		
		Node n2 = list.deleteLast();
		System.out.println("Delete last: " + n2.data);
		list.printDLL();
		
		list.deleteAt(3);
		list.printDLL();
		
		list.reverseDLL();
		list.printDLL();
	}
}