import java.util.Scanner;

class Node{
	int info;
	Node link;
}

class Stack{
	Node top;
	
	public void push(int item) {
		Node tmp = new Node();
		tmp.info = item;
		tmp.link = top;
		top = tmp;
	}
	
	public int pop() {
		Node tmp;
		if(top == null) {
			System.out.print("Stack is empty\n");
			return -1;
		}else {
			tmp = top;
			top = top.link;
			return tmp.info;
		}
	}
	
	public void display() {
		Node ptr = top;
		if(top == null)
			System.out.println("Stack is empty\n");
		else {
			while(ptr!=null) {
				System.out.print(ptr.info+" ");
				ptr = ptr.link;
			}
		}
	}
		
}
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Stack st = new Stack();
		while(true) {
			System.out.println("1. Push");
			System.out.println("2. Pop");
			System.out.println("3. Display");
			System.out.println("4. Quit");
			switch (sc.nextInt()){
				case 1:
					System.out.println("Enter item to push");
					st.push(sc.nextInt());
					break;
				case 2:
					System.out.println("Element Poped: "+st.pop());
					break;
				case 3:
					st.display();
					break;
				case 4:
					return;
			}
		}
	}
}
Footer
© 2022 GitHub, Inc.
