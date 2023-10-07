
package com.mycompany.dsa;


public class subset 
{
    
    static void getsubset(String s,String curr,int i)
    {
       if(i==s.length())
       {
           System.out.println(curr);
           return;
       }
       getsubset(s,curr,i+1);
       getsubset(s,curr+s.charAt(i),i+1);

    }
    
    public static void main(String args[])
    {
        
                  getsubset("abc","",0);

}
    
}
