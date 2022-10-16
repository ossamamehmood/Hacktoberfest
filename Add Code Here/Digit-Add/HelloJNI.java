import java.util.*;
public class HelloJNI {
   static {
      System.loadLibrary("hello"); 
   }
 
   private native void sayHello(int a,int b);
 
 
   public static void main(String[] args) {
	System.out.println("Adding corresponding digits of 2 numbers with parallel computing");
	Scanner sc=new Scanner(System.in);
	System.out.println("Enter numbers to add digits");
	int a=sc.nextInt();
	int b=sc.nextInt();
      new HelloJNI().sayHello(a,b);
   }
}