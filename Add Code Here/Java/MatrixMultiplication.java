 public class MatrixMultiplication {
    public static void main(String[] args) {
        // Define two matrices A and B
        int[][] A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        int[][] B = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

        // Check if the matrices can be multiplied
        if (A[0].length != B.length) {
            System.out.println("Matrix multiplication is not possible.");
        } else {
            // Initialize the resulting matrix C
            int[][] C = new int[A.length][B[0].length];

            // Perform matrix multiplication
            for (int i = 0; i < A.length; i++) {
                for (int j = 0; j < B[0].length; j++) {
                    for (int k = 0; k < B.length; k++) {
                        C[i][j] += A[i][k] * B[k][j];
                    }
                }
            }

            // Print the resulting matrix C
            System.out.println("Resultant Matrix C:");
            for (int i = 0; i < C.length; i++) {
                for (int j = 0; j < C[0].length; j++) {
                    System.out.print(C[i][j] + " ");
                }
                System.out.println();
            }
        }
    }
 }
