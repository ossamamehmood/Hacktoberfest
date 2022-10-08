public class Solution {

	public static void wavePrint(int mat[][]){
		//Your code goes here
        
        
        int row = mat.length;
        
        if(row<=0)
            return;
        
        int col = mat[0].length;
        
        for(int i=0;i<col;i++)
        {
            if(i%2 == 0)
            {
                for(int j=0;j<row;j++)
                    System.out.print(mat[j][i]+" ");
            }
            else
            {
                for(int j=row-1;j>=0;j--)
                    System.out.print(mat[j][i]+" ");
            }
        }
        
        
	}

}