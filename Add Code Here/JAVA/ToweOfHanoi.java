package dsQstns;
import java.util.Scanner;
public class ToweOfHanoi {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		System.out.print("Enter number of plates: ");
		int n=sc.nextInt();
		tower(n,"source","helper","destination");
	}
	public static void tower(int n, String source, String helper, String destination) {
		if(n==1) {
			System.out.println("Disc "+n+" moves from "+source+" to "+destination);
			return;
		}
		tower(n-1,source,destination,helper);
		System.out.println("Disc "+n+" moves from "+source+" to "+destination);
		tower(n-1,helper,source,destination);
	}
}