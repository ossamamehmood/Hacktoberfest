// Ques: Given a, b and c such that (a | X) & (b | X) = c; find minimum value of X which satisfies this condition. If no value of X is possible return -1;



import java.util.*;

public class Solution {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int b = sc.nextInt();
    int c = sc.nextInt();

    int a_and_b = a & b;  // (a | X) & (b | X) = c ==> (a & b) | X = c
    int not_ab = ~(a_and_b);
    int X = not_ab & c; // X = ~(a & b) & c
    
    if ((X | a_and_b) == c) {
      System.out.println(X);
    }
    else {
      System.out.println(-1);
    }   
  }
}
