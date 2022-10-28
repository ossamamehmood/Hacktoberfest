import java.util.*;
import java.lang.*;
import java.io.*;
class Maxscore
{
  public static int maxScore(String s) {
        int one = 0, zero = 0;
        for(int i=0;i<s.length();i++)
            if(s.charAt(i) == '0')
                zero++;
            else
                one++;
        int curZero = (s.charAt(0) == '0' ? 1 : 0), curOne = (s.charAt(0) == '1' ? 1 : 0);
        int ans = curZero + one - curOne;
        for(int i=1;i<s.length()-1;i++){
            if(s.charAt(i) == '0')curZero++;
            else curOne++;
            ans = Math.max(ans, curZero + one-curOne);
        }
        return ans;
    }
    
  public static void main (String[] args) throws java.lang.Exception
  {
    System.out.print(maxScore("00111"));
  }
}
