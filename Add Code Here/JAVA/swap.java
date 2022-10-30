import java.util.*;
class swap{
  public static void main(String a[]){
    int a, b;
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter 2 numbers to swap");
    a = sc.nextInt();
    b = sc.nextInt();
    int temp = 0;
    temp = a;
    a = b;
    b = temp;
    System.out.println("Numbers are swaped a="+a+" and b="+b);
  }
}
