package stacks;
import StackX;
import java.util.Scanner;

public class MainStack {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		StackX theStack = new StackX(5);
		
		//Intialize Variable
		String input;
		
		//Accept Input
		Scanner scan = new Scanner(System.in);
		System.out.println("Enter the String and 'exit' to exit the loop: ");
		System.out.flush();
		input = scan.nextLine();
		
		//While Loop to loop the user input
		while(!input.equals("exit")) {
			
			//Push the Input to Stack
			theStack.push(input.charAt(0));
			//Accept Input
			System.out.println("Enter the String and 'exit' to exit the loop: ");
			System.out.flush();			
			input = scan.nextLine();		
		}
		
		//Close the scanner class
		scan.close();
		
		//Loop to Empty the Stack
		while(!theStack.isEmpty())
		{		
			char val=theStack.pop();
			System.out.println(val);
			System.out.println(" ");
		}
	}
}
