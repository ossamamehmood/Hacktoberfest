import java.util.Scanner;
import java.util.HashMap;
class Solution{
    public static void main(String []argh)
    {
        Scanner sc = new Scanner(System.in);
        HashMap<String,Integer> l = new HashMap<>();
		System.out.println("Enter value of n: ");
        int n = sc.nextInt();
		sc.nextLine(); //to tackle the skipped nextLine()
		String s;
		System.out.println("Enter values for Phone Book now");
        for(int i=0;i<n;i++)
        {
			System.out.println("Enter Name: ");
			s = sc.nextLine();
			System.out.println("Enter Number: ");
            l.put(s,sc.nextInt());
            sc.nextLine(); //to tackle the skipped nextLine() 
        }
        
        while(sc.hasNext())
        {
			//System.out.println("Enter Name to be searched: ");
            s = sc.nextLine();
            if(l.containsKey(s)){
                System.out.println(s+"="+l.get(s));
            }
            else{
                System.out.println("Not found");
            }
        }
    }
}