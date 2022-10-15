import java.util.Scanner;
public class CharCaseCheck {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		char ch = sc.next().trim().charAt(0);
		System.out.println(ch);
		
		if(ch >= 'a' && ch <= 'z') {
			System.out.println("lowecase");
		}else {
			System.out.println("uppercase");
		}
		
		
		//USE OF charAt(0)
//		String word = "heelo";
//		System.out.println(word.charAt(2));
		//OUTPUT: e
		
		
		//USE OF TRIM FUNCTION
//		System.out.println(sc.next().trim());
		//INPUT: hello guuyss hcbDHCbzdx  ||
		//OUTPUT:hello
        
		
	}

}
