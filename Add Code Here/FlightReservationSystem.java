/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author ossamamehood
 */

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author ossamamehmood
 */

public class FlightReservationSystem {
    
    Node root;
	
	 // This method adds details of patient to the queue.
        
	 // This method adds patient's detail at the end of the queue as per FIFO functionality.
        
	 // id stores id of patient.
        
	 // @param disease stores disease from which patient is suffering.
        
	void store(int id , String disease) {
            
		Node toAdd = new Node(id , disease);
		
		if(root == null) {
			root = toAdd;
			return;
		}
		
		Node temp = root;
		
		while(temp.next != null) {
			temp = temp.next;
		}
		
		temp.next = toAdd;
	}
	
	// This method deletes the entries of patient from queue.
        
	// It deletes first entry present in queue as per FIFO(First In First Out) functionality.
        
	// @throws Exception if queue is empty, it throws exception.
        
	void delete() throws Exception{
            
		if(root == null) {
			throw new Exception("Queue is already empty.");
		}
		
		root = root.next;
	}
	
       // This method display queue data.
        
	void print() {
            
		if(root == null) {
			System.out.println("Can't print an empty queue.");
			return;
		}
		
		Node temp = root;
		
		while(temp != null) {
			System.out.println("Seat number:  " + temp.seat + "\tBoarding card:  " + temp.card);
			temp = temp.next;
		}
	}
	
       // Node class to store different entries of patients.

	class Node{
            
		int seat;
		String card;
		
		// next pointer to connect each nodes
		Node next;
		
		Node(int seat , String card){
			this.seat = seat;
			this.card = card;
		}
	}

	// Main method
	public static void main(String[] args) throws Exception {
            
		FlightReservationSystem q = new FlightReservationSystem ();
		
		// a) Storing information.
                
                System.out.println("- - - - - - - - - - ");
                System.out.println(" Fight Reservation System");
                System.out.println("- - - - - - - - - - ");



               // Aircarft Seat number Boarding Pass
               
               
                System.out.println("- - - - - - - - - - ");
                System.out.println(" Seat Number || Boarding Pass");
                System.out.println("- - - - - - - - - - ");
        
		q.store(66, "AA5920");
                q.store(69, "AE6920");
                q.store(99, "AF4360");
                q.store(69, "BE3350");
                
               // c) Display Flight Record from queue - Here, we're displaying the data fro the Queue
		q.print();
                
               // b) Deleting One Record from Queue.
		q.delete();
		
                
                // Displaying the data after deleccting two node from the queue
		System.out.println("\nAfter deleting few entries from queue.\n");
		q.print();
                
                
	}

}
