import java.util.*;
public class Solution 
{
public static boolean isSafe(int x, int y, int[][] visited, int[][] arr, int n)
    {
        return ((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && arr[x][y] == 1);
    }
    
    public static void solve(int i,int j, int n,int[][]visited,int[][] arr,ArrayList<String> output,String ans){
        if(i==n-1 && j==n-1){
            output.add(ans);
            return;
        }
        
                visited[i][j]=1; // we have to move first step to enter the matrix ie 0,0 so first visited[i][j] =1 visited[0][0]
                    //down
                    if(isSafe(i+1,j,visited,arr,n))
                    solve(i+1,j,n,visited,arr,output,ans+'D');
        
                    //left
                    if(isSafe(i,j-1,visited,arr,n))                    
                    solve(i,j-1,n,visited,arr,output,ans+'L');

                    //right
                   if(isSafe(i,j+1,visited,arr,n))
                    solve(i,j+1,n,visited,arr,output,ans+'R');

                    //up
                    if(isSafe(i-1,j,visited,arr,n))
                    solve(i-1,j,n,visited,arr,output,ans+'U');

        visited[i][j] = 0;

    }
    
    public static ArrayList < String > findSum(int[][] arr, int n) {
        ArrayList<String> output = new ArrayList<String>();
        int[][]visited = new int[n][n];
        //empty array ie if first ele is 0
         if(arr[0][0] == 0)
            return output;
        solve(0,0,n,visited,arr,output,"");
        return output;
    }
}

// explaination
// first make a visited array that help us to not got to infinite loop ie from r to l then l to r again n again
// mark the position of visited array as 1 when going for a position -> visited[i][j] = 1;
// initialized it with 0
// then make a ifSafe funct to check multiple things before moving forward
// 1. i and j is in boundary 0 <= i < n
//2. the position is not visited ie visited[i][j] == 0 not 1 
//3. arr[i][j] == 1 ie check available position to move

// isSafe function conditions check every time u make a move

// the return func according for U, D, L and R

// for multiple ans when the recursive functions backtrack you have to unmark the visited array ie visited[i][j] = 0;

// (ie one of the function call get return and swith to next function call)
