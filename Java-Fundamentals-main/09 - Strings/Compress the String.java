public class Solution {
	public static String getCompressedString(String str) {
		// Write your code here.
        
        
		int i,c = 1,j = 0;
  	 	String result = "";
        
   		for(i = 0;i < str.length() - 1;i++) 
        {
    
	   		if(str.charAt(i+1) == str.charAt(i))
            {
		   		c++;	   
	   		}
	  	 	else 
       		{
               if(c != 1)
               		result = result + str.charAt(i) + c;
               else
               		result = result + str.charAt(i);
               c = 1;
	   		}
   		}
        
   		if(c != 1)
   			result = result + str.charAt(i) + c;
   		else
   			result = result + str.charAt(i);  
        
   		return result;
        
	}

}