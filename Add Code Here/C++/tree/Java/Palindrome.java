public class Palindrome {
    public static boolean isPalindrome(int n) {
      int temp = n;
      int rem;
      int ans = 0;
      while(n>0){
        rem = n%10;
        ans = ans*10+rem;
        n=n/10;
      }
      if(ans==temp){
        return true;
      }
      return false;
    }
    public static void main(String[] args){
        int N = 124321;
        boolean res = isPalindrome(N);
        System.out.print(res);
    }
}
