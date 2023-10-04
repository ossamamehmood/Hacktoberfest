public class RatInMaze {

    private static final int OPEN = 1;
    private static final int PATH = 2;
    private int[][] maze;
    private int[][] solution;

    public RatInMaze(int[][] maze) {
        this.maze = maze;
        this.solution = new int[maze.length][maze[0].length];
    }

    public boolean solve() {
        if (findPath(0, 0)) {
            printSolution();
            return true;
        } else {
            System.out.println("No solution exists.");
            return false;
        }
    }

    private boolean findPath(int x, int y) {
        // Check if we reached the destination
        if (x == maze.length - 1 && y == maze[0].length - 1) {
            solution[x][y] = PATH;
            return true;
        }

        if (isSafe(x, y)) {
            solution[x][y] = PATH;

            // Move forward in X direction
            if (findPath(x + 1, y)) {
                return true;
            }

            // Move down in Y direction
            if (findPath(x, y + 1)) {
                return true;
            }

            // Backtrack if no direction leads to a solution
            solution[x][y] = 0;
        }

        return false;
    }

    private boolean isSafe(int x, int y) {
        return x >= 0 && x < maze.length && y >= 0 && y < maze[0].length && maze[x][y] == OPEN;
    }

    private void printSolution() {
        for (int i = 0; i < solution.length; i++) {
            for (int j = 0; j < solution[i].length; j++) {
                System.out.print(solution[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int[][] maze = {
            {1, 0, 0, 0},
            {1, 1, 0, 1},
            {0, 1, 0, 0},
            {1, 1, 1, 1}
        };
        RatInMaze rat = new RatInMaze(maze);
        rat.solve();
    }
}
