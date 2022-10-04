import java.util.*;
public class Solution 
{
    public static int longcommonsequence(int index1,int index2,String a,String b,int[][]dp)
    {
        //Base Case
        if(index1<0 || index2<0)
        { 
            return 0;
        }
        if(dp[index1][index2]!=-1)
        {
            return dp[index1][index2];
        }
        //Match Condition
        if(a.charAt(index1)==b.charAt(index2))
        {
            return dp[index1][index2]=1+longcommonsequence(index1-1,index2-1,a,b,dp);
        }
        
        //Not Match Condition
        
        return dp[index1][index2]=0+Math.max(longcommonsequence(index1-1,index2,a,b,dp),longcommonsequence(index1,index2-1,a,b,dp));
    }
    public static int lcs(String s, String t) 
    {
        //Your code goes here
        //Dp Solution
        //Match and Dont Match Concept
        int[][]dp=new int[s.length()][t.length()];
        for (int i = 0; i < s.length(); i++) 
        {
            Arrays.fill(dp[i], -1);
        }
        return longcommonsequence(s.length()-1,t.length()-1,s,t,dp);
    }

}
