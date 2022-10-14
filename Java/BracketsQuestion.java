package vectorAndstacks;
import java.util.Scanner;
import java.util.Stack;

public class BracketsQuestion {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the number of statements you want to test: ..");
		int t = sc.nextInt();
		sc.nextLine();
		while(t--!= 0) {
			System.out.println("Enter the parenthesis statement: ...");
		String s = sc.nextLine();	
			
		Stack<Character> stack = new Stack<>();
		
		boolean isBalanced = true;
		
		for(int i = 0; i<s.length();i++) {
			char ch = s.charAt(i);
			if(ch == '('|| ch =='['|| ch == '{') {
				stack.push(ch);
				continue;
			}
			if(stack.isEmpty()) {
				isBalanced = false;
				break;
			}
			if(ch ==')') {
				if(stack.peek() == '(') {
					stack.pop();
		     }else {
				isBalanced = false;
				break;
			}
	      }
		    if(ch ==']') {
		    	if(stack.peek() == '['){
				stack.pop();				
		   }else {
			    isBalanced = false;
			    break;
		    }
	      }  
	        if(ch =='}') {
	    	    if(stack.peek() == '{') {
	    		  stack.pop();				
	    	   }else {
	    		  isBalanced = false;
	    		  break;
	    	}
	      }
}//for loop
	       if(!stack.isEmpty()) {
	    	   isBalanced = false;
	       }
	       if(isBalanced) {
	    	   System.out.println("Balanced");
	       }else {
	    	   System.out.println("not balanced");
	       }
}//while loop

		sc.close();
}//main
	
}//class
   


