import java.util.Scanner;

public class TicTacToe {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[][] board = new char[3][3];
        for(int row = 0; row < board.length; row++) {
            for(int col = 0; col < board[row].length; col++) {
                board[row][col] = '-';
            }
        }

        char player = 'X';
        boolean gameOver = false;
        int move = 1;

        while(!gameOver && move <= 9) {
            printBoard(board);
            if(move == 10) {
                System.out.println("Draw TADA!!!");
                break;
            }
            move++;
            System.out.print("Enter the row to place " + player + ": ");
            int row = sc.nextInt();
            System.out.print("Enter the column to place " + player + ": ");
            int col = sc.nextInt();

            if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == '-') {
                board[row][col] = player;
                gameOver = haveWon(board, player);
                if(gameOver) {
                    System.out.println("Player " + player + " has won!");
                }
                else {
                    player = (player == 'X') ? 'O' : 'X';
                }
            }
            else {
                System.out.println("Invalid Move, Try Again!");
                move--;
            }
        }

        sc.close();

    }

    public static void printBoard(char[][] board) {
        for(int row = 0; row < board.length; row++) {
            for(int col = 0; col < board[row].length; col++) {
                System.out.print(board[row][col] + " ");
            }
            System.out.println();
        }
    }

    public static boolean haveWon(char[][] board, char player) {
        //check the rows
        for(int row = 0; row < board.length; row++) {
            if(board[row][0] == player && board[row][1] == player && board[row][2] == player) {
                return true;
            }
        }
        for(int col = 0; col < board[0].length; col++) {
            if(board[0][col] == player && board[1][col] == player && board[2][col] == player) {
                return true;
            }
        }
        if(board[0][0] == player && board[1][1] == player && board[2][2] == player) {
            return true;
        }
        if(board[0][2] == player && board[1][1] == player && board[2][0] == player) {
            return true;
        }
        return false;
    }
}
