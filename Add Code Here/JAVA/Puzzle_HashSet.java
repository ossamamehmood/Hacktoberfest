import java.util.HashSet;
import java.util.Random;
import java.util.Set;


public class Puzzle_HashSet {
    private static final int SIZE = 3;
    private static final int TARGET = 123456789; 
    private int[][] grid;
    private Set<Integer> visitedConfigurations;

    public Puzzle_HashSet() {
        grid = new int[SIZE][SIZE];
        visitedConfigurations = new HashSet<>();
        initializeGrid();
    }

    private void initializeGrid() {
        int[] numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        shuffleArray(numbers);

        int index = 0;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                grid[i][j] = numbers[index++];
            }
        }
    }

    private void shuffleArray(int[] array) {
        Random random = new Random();
        for (int i = array.length - 1; i > 0; i--) {
            int j = random.nextInt(i + 1);
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    private int calculateConfiguration() {
        int configuration = 0;
        int multiplier = 1;
        for (int i = SIZE - 1; i >= 0; i--) {
            for (int j = SIZE - 1; j >= 0; j--) {
                configuration += grid[i][j] * multiplier;
                multiplier *= 10;
            }
        }
        return configuration;
    }

    public boolean isSolved() {
        return calculateConfiguration() == TARGET;
    }

    public void printGrid() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                System.out.print(grid[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
    	Puzzle_HashSet game = new Puzzle_HashSet();
        System.out.println("Initial Configuration:");
        game.printGrid();

        if (game.isSolved()) {
            System.out.println("Congratulations! You've solved the puzzle.");
        } else {
            System.out.println("Keep playing...");
        }
    }
}
