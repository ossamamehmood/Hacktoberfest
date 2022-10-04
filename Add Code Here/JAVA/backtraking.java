import java.util.Scanner;

public class backtraking {
    
    static int[][] oArr;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter N:\t");
        int N = sc.nextInt();

        int[][] inArr = new int[N][N];
        oArr = new int[N][N];

        //Input arr '0' for block and '1' for pass
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                inArr[i][j] = sc.nextInt();
                oArr[i][j] = 0;
            }
        }

       
        //start the game
        ratInMaze(inArr, 0, 0, N);

        //print the path (final output)
        for(int i=0; i<N; i++)
            {
                for(int j=0; j<N; j++)
                {
                    System.out.print(oArr[i][j]+"\t");
                }
                System.out.print("\n");
            }

    }


    public static boolean ratInMaze(int[][] inArr, int x, int y, int n)
    {

        if(x==(n-1) && y==(n-1))
        {
            oArr[x][y]=1;
            return true;
        }


        if(isSafe(inArr, x, y, n))
        {
            oArr[x][y] = 1;
            if(ratInMaze(inArr, x+1, y, n))
            {
                return true;
            }
            if(ratInMaze(inArr, x, y+1, n))
            {
                return true;
            }

            //backtracking
            oArr[x][y]=0;
            return false;
        }
        
        return false;
    }

    //Check whether rat can pass thorugh given block or not
    public static boolean isSafe(int[][] inArr, int x, int y, int n)
    {
     
        if(x<n && y<n && inArr[x][y]==1)
        {
            return true;
        }

        return false;
    }
}
