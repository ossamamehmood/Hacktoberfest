public class Solution {

	public static void spiralPrint(int matrix[][]){
		//Your code goes here
        if (matrix.length == 0)
        {
            System.out.print("");
        }
        else
        {
            
        	int rstart=0,rend=matrix.length-1,cstart=0,cend=matrix[0].length-1;
        	int count=matrix.length*matrix[0].length;
            
            while (count>0)
            {

                for (int i=cstart;i<=cend;i++)
                {
                    System.out.print(matrix[rstart][i] + " ");
                    count--;
                }

                rstart++;

                for (int i=rstart;i<=rend;i++)
                {
                    System.out.print(matrix[i][cend] + " ");
                    count--;
                }

                cend--;

                for (int i=cend;i>=cstart;i--)
                {
                    System.out.print(matrix[rend][i] + " ");
                    count--;
                }

                rend--;

                for (int i=rend;i>=rstart;i--)
                {
                    System.out.print(matrix[i][cstart] + " ");
                    count--;
                }

                cstart++;       
            }
        }
	}
}