public class Solution {

	public static void totalSum(int[][] mat) {
		//Your code goes here
         if (mat.length == 0)
        {
            System.out.print("0");
        }
        else
        {
            int sum=mat[0][0];
            
            for (int i=1;i<mat.length;i++)
        	{
               
            	sum=sum+mat[i][0];
            	sum=sum+mat[0][i];
            	sum=sum+mat[i][i];
        	}
        
        	for (int i=1;i<mat[0].length-1;i++)
        	{
            	sum=sum+mat[mat[0].length-1][i];
            	sum=sum+mat[i][mat[0].length-1];
                
                for (int j=1;j<mat.length-1;j++)
                {
                    if (i+j == (mat.length-1) && i != j)
                    {
                        sum=sum+mat[i][j];
                    }
                }
            
        	}
            System.out.print(sum);
        }
	}

}