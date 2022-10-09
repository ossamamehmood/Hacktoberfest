import java.util.Scanner;
class CaseStudy3{
	public static void main(String[] args){
		Scanner sc =  new Scanner(System.in);
		System.out.println("Enter a sequence of Characters");
		String sequence = sc.nextLine();
		sequence = sequence.trim();
		//String[] seq = sequence.split(" ");
		String[] vowels = {"a", "e", "i", "o", "u"};
		String[] digits = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
		String[] symbols = {"!", "@", "#", "?", "&", "$", "'", "\"", ",", ".", ";", ":", "(", ")", "/"};
		int no_of_char = sequence.length();
		int vow = 0, dig = 0, sym = 0, con = 0, wor = 0;
		for (int i = 0; i < no_of_char; ++i){
			if (isinarray(Character.toString(sequence.charAt(i)), vowels))
				vow++;
			else if(isinarray(Character.toString(sequence.charAt(i)), digits))
				dig++;
			else if(isinarray(Character.toString(sequence.charAt(i)), symbols))
				sym++;
			else if(Character.toString(sequence.charAt(i)).equals(" ") == false && Character.toString(sequence.charAt(i)).equals("\t") == false && Character.toString(sequence.charAt(i)).equals("\n") == false)
				con++;
			else
				wor++;
		}
		if (wor!=0)
			wor++;
		System.out.print("Number of Characters: "+no_of_char+"\nNumber of Vowels: "+vow+"\nNumber of Consonants: "+con+"\nNumber of Digits: "+dig+"\nNumber of Symbols: "+sym+"\nNumber of words: "+wor); 		
	}
	public static boolean isinarray(String i, String[] array){
		boolean b = false;
		for (String j:array){
			if (j.equalsIgnoreCase(i)){
				b = true;
				break;
			}
		} 
		return b;
	}
}
