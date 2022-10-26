import java.util.*;
public class nQueens {
    public static void main(String[] args) {
        int n = 4;
        char board [][] = new char [n][n];
        for (int i=0; i<board.length; i++) {
            for (int j=0; j<board.length; j++) {
                board[i][j] = 'X';
            }
        }
        nQueen(board, 0); 
    }
    public static boolean isSafe(char board[][], int row, int col) {
        //vertical 
        for (int i=row-1; i>=0; i--) {
            if (board[i][col] == 'Q') return false;
        }
        //diagonal upright
        for (int i=row-1, j=col-1; i>=0 && j>=0; i--,j--) {
            if (board[i][j] == 'Q') return false;
        }
        //diagonal upleft
        for (int i=row-1, j=col+1; i>=0 && j<board.length; i--,j++) {
            if (board[i][j] == 'Q') return false;
        }
        return true;
    }
    public static void nQueen(char board[][], int row) {
        if (row == board.length) {
            System.out.println("---------Chess Board---------");
            printBoard(board);
            return;
        }
        for (int j=0; j<board.length; j++) {
            if (isSafe(board, row, j)) {
                board[row][j] = 'Q';    //to place Queens
                nQueen(board, row+1);   //Recursive function
                board[row][j] = 'X';    //backtracking step
            }
        }
    }
    public static void printBoard(char board[][]) {     //To print board
        for(int i=0; i<board.length; i++) {
            for (int j=0; j<board.length; j++) {
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }
    }
}


// TO COUNT NO. OF WAYS TO SOLVE NQUEENS.  

// static int count = 0; (out of any funciton);
// nQueen (Base Case) => count++;
// main (after nQueen call) => sout("No. of ways to solve this problem are = " + count);



// TO PRINT SOLUTION IS POSSIBLE OR NOT AND IF POSSIBLE PRINT ONE.

// nQueen => boolean; (base case) -> return true; (recursive function) -> return true;
// main => if (nQueen) -> sout("Solution is possible") -> printBoard(board); 
//                     -> sout("Solution is not possible")