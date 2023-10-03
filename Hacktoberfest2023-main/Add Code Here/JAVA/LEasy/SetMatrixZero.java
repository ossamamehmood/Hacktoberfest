package LEasy;

import java.util.Arrays;

public class SetMatrixZero {
    public static void main(String[] args) {

        int[][] arr={
                {1,1,1,1},
                {1,0,1,1},
                {1,1,0,1},
                {1,1,1,1}
        };
        int n=arr.length;
        int m=arr[0].length;

//        bruteforce(arr,n,m);

        better(arr,n,m);
        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                System.out.print(arr[i][j]+" ");

            }
            System.out.println();

        }






    }

    private static void better(int[][] arr, int n, int m) {

        int[] col=new int[m];
        int[] row=new int[n];
        Arrays.fill(col,0);
        Arrays.fill(row,0);

        for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {

                    if(arr[i][j]==0){
                        row[i]=1;
                        col[j]=1;
                    }
                }
        }



        for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {

                    if(row[i]==1 ||  col[j]==1){
                        arr[i][j]=0;

                    }
                }
        }











    }

    private static void bruteforce(int[][] arr, int n, int m) {

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if(arr[i][j]==0){
                    markrow(arr,m,i);
                    markcol(arr,n,j);
                }

            }

        }


        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                System.out.print(arr[i][j]+" ");

            }
            System.out.println();

        }

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if(arr[i][j]==-1){
                    arr[i][j]=0;
                }

            }
            System.out.println();

        }
    }

    private static void markcol(int[][] arr, int n, int j) {

        for (int i = 0; i < n; i++) {

            if(arr[i][j]!=0){
                arr[i][j]=-1;
            }

        }

    }

    private static void markrow(int arr[][],int m, int i) {
        for (int j = 0; j < m ; j++) {
            if(arr[i][j]!=0){
                arr[i][j]=-1;
            }
        }
    }
}
