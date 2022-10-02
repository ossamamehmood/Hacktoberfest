import java.util.Scanner;

/**
 * Tic Tac Toe is two player console based game 
 * It fetches the row and column values from both players to place their mark 
 * Player 1 moves are represented by letter 1 and Player 2 moves are represented by letter 2
 */
public class TicTacToe {

	public static int[][] grid = new int[3][3];
	public static final int PLAYER_ONE = 1;
	public static final int PLAYER_TWO = 2;
	public static final int TOTAL_MOVES = 9;

	public static void main(String[] args) {

		boolean matchWon = false;
		printBoard();
		int currentMoves = 0, currentPlayer = 0;
		while (currentMoves < TOTAL_MOVES) {
			if (currentMoves % 2 == 0)
				currentPlayer = PLAYER_ONE;
			else
				currentPlayer = PLAYER_TWO;

			playMove(currentPlayer);
			matchWon = checkFrame();
			if (matchWon) {
				System.out.println("Player " + currentPlayer + " Won!");
				printBoard();
				break;
			}
			printBoard();
			currentMoves++;
		}
		if (!matchWon)
			System.out.println("Game Draw!");
	}

	public static void printBoard() {
		System.out.println("-------------");
		for (int i = 0; i < 3; i++) {
			System.out.print("| ");
			for (int j = 0; j < 3; j++)
				System.out.print(grid[i][j] + " | ");
			System.out.println();
			System.out.println("-------------");
			System.out.println();
		}
	}

	public static int validateMove(String message) {
		int num = 0;
		Scanner in = new Scanner(System.in);
		while (true) {
			System.out.print(message);
			String input = in.nextLine();
			try {
				num = Integer.parseInt(input);
			} catch (Exception e) {
				System.out.println("Invalid integer!");
				continue;
			}
			if (num < 0 || num > 2) {
				System.out.println("Number should be with in matrix range i.e 0 - 2");
				continue;
			}
			return num;
		}
	}

	public static boolean checkRows() {
		for (int i = 0; i < grid[0].length; i++) {
			if ((grid[i][0] == grid[i][1]) && (grid[i][1] == grid[i][2]) && grid[i][0] != 0)
				return true;
		}
		return false;
	}

	public static boolean checkColumns() {
		for (int i = 0; i < grid[0].length; i++) {
			if ((grid[0][i] == grid[1][i]) && (grid[1][i] == grid[1][i]) && grid[2][i] != 0)
				return true;
		}
		return false;
	}

	public static boolean checkDiagonals() {
		return (((grid[0][0] == grid[1][1]) && (grid[1][1] == grid[2][2]) && grid[0][0] != 0)
				|| ((grid[0][2] == grid[1][1]) && (grid[1][1] == grid[2][0]) && grid[1][1] != 0));
	}

	public static boolean checkFrame() {
		return (checkRows() || checkColumns() || checkDiagonals());
	}

	public static void playMove(int playerNumber) {
		System.out.println("Player " + playerNumber + " turn");
		int row = 0, column = 0;
		while (true) {
			row = validateMove("Enter row number: ");
			column = validateMove("Enter column number: ");
			if (grid[row][column] == 0)
				break;
			System.out.println(row + ", " + column + " is marked\n");
		}
		grid[row][column] = playerNumber;
	}

}