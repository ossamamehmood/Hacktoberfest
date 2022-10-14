public class Solution {

	public static void findLargest(int mat[][]){
		//Your code goes here
        
        int rowmax = 0;
        int rowindex = 0;
        
        int colmax = 0;
        int colindex = 0;
        
        int row = mat.length;
        if(row <= 0)
        {
            System.out.println("row "+0+" "+Integer.MIN_VALUE);
            return;
        }
        
        int col = mat[0].length;
        
        for(int i=0;i<row;i++)
        {
            int sum = 0;
            for(int j=0;j<col;j++)
                sum += mat[i][j];
            if(sum > rowmax)
            {
                rowmax = sum;
                rowindex = i;
            }
        }
        
        
        for(int i=0;i<col;i++)
        {
            int sum = 0;
            for(int j=0;j<row;j++)
                sum += mat[j][i];
            if(sum > colmax)
            {
                colmax = sum;
                colindex = i;
            }
        }
        
        if(rowmax>=colmax)
        {
           System.out.println("row "+rowindex+" "+rowmax); 
        }
        else
        {
            System.out.println("column "+colindex+" "+colmax); 
        }
        
	}

}