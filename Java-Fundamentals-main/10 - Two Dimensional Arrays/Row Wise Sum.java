public class Solution {

	public static void rowWiseSum(int[][] mat) {
		//Your code goes here
        
        
        int row = mat.length;
        
        if(row <= 0)
            return;
        
        
        int col = mat[0].length;
        
        
        for(int i=0;i<row;i++)
        {
            int sum = 0;
            for(int j=0;j<col;j++)
                sum += mat[i][j];
            System.out.print(sum+" ");
        }
        
        
	}

}