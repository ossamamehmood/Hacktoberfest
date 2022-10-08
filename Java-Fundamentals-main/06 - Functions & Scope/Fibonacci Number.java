
public class Solution {
	
	public static boolean checkMember(int n){
				
		/* Your class should be named Solution
		* Don't write main().
	 	* Don't read input, it is passed as function argument.
	 	* Return output and don't print it.
	 	* Taking input and printing output is handled automatically.
		*/
        
        int f = 0;
        int s = 1;
        int term = 1;
        
        if(n == 0 || n == 1)
            return true;
        
        boolean flag = false;
        
        while(term <= n)
        {
            term = s+f;
            
            if(term == n)
            {
                flag = true;
                break;
            }
            
            f = s;
            s = term;
            
        }
        return flag;

	}
	

}
