import java.util.Scanner;

public class SineWave {
    public static int[][] input() {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c[][] = new int[a][b];

        for (int x = 0; x < a; x++) {
            for (int y = 0; y < b; y++) {
                c[x][y] = sc.nextInt();
            }
        }
        return c;
    }

    public static void printWave(int a[][]) {
        int k = 0;
        for (int x = 0; x < a[0].length; x++) {
            for (int y = 0; y < a.length; y++) {
                System.out.print(a[k][x] + " ");
                if (x % 2 == 0)
                    k++;
                else
                    k--;
            }
            if (x % 2 == 0)
                k--;
            else
                k++;
        }

    }

    public static void printWave2(int a[][]) {
        boolean even = true;
        for (int x = 0; x < a[0].length; x++) {
            if (even) {
                for (int y = 0; y < a.length; y++) {
                    System.out.print(a[y][x] + " ");

                }
                even = false;
            }

            else {
                for (int y = a.length - 1; y >= 0; y--) {
                    System.out.print(a[y][x] + " ");

                }
                even = true;
            }
        }

    }

    public static void printWave3(int a[][]) {

        for (int x = 0; x < a[0].length; x++) {
            if (x % 2 == 0) {
                for (int y = 0; y < a.length; y++) {
                    System.out.print(a[y][x] + " ");

                }

            }

            else {
                for (int y = a.length - 1; y >= 0; y--) {
                    System.out.print(a[y][x] + " ");

                }

            }
        }

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int x = 1; x <= t; x++) {
            int a[][] = input();
            printWave3(a);
        }
    }
}
