import java.util.Scanner;

class ticTacToe {
    public static void main(String[] args) {
        char board[][] = new char[3][3];
        
        //Initialising empty spaces
        for (int row = 0; row < board.length; row++) {
            for(int col = 0; col <board[row].length; col++) {
                board[row][col] = ' ';
            }
        }

        char player = 'X';
        boolean gameOver = false;
        Scanner scanner = new Scanner(System.in);

        while(!gameOver) {
            printBoard(board);

            System.out.println("Player " + player + "'s turn");
            System.out.print("Enter row and column:\t");
            int row = scanner.nextInt();
            int col = scanner.nextInt();

            if (board[row][col] == ' ') {
                board[row][col] = player; // Placing the element or charecter
                gameOver = hasWon(board, player); 

                if (gameOver) {
                    System.out.println("\nPlayer "+ player + " has won!");
                    System.out.println();
                }
                else {
                    player = (player == 'X') ? 'O' : 'X';
                }
            }
            else {
                System.out.println("Invalid move, Try Again!");
                System.out.println();
            }       
        }
        printBoard(board);
    }

    public static boolean hasWon(char[][] board, char player) {
        // Checking equal rows  
        for (int row = 0; row < board.length; row++) {
            if(board[row][0] == player && board[row][1] == player && board[row][2] == player) {
                return true;
            }
        }

        // Checking equal columns
        for (int col = 0; col < board.length; col++) {
            if(board[0][col] == player && board[1][col] == player && board[2][col] == player) {
                return true;
            }
        }

        //Checking equal diagonals
        if(board[0][0] == player && board[1][1] == player && board[2][2] == player) {
            return true;
        }
        if(board[0][2] == player && board[1][1] == player && board[2][0] == player) {
            return true;
        }

        return false;
    }

    public static void printBoard(char[][] board) {
        for (int row = 0; row < board.length; row++) {
            for(int col = 0; col <board[row].length; col++) {
                System.out.print(board[row][col] + "  |  ");
            }
        System.out.println();
        }
    }
}