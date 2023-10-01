package LEasy;

public class SpiralMatrix {
    public static void main(String[] args) {
        int[][] arr={
                {1,2,3,4,5,6},
                {20,21,22,23,24,7},
                {19,32,33,34,25,8},
                {18,31,36,35,26,9},
                {17,30,29,28,27,10},
                {16,15,14,13,12,11},
        };

        int n=arr.length;//rows
        int m=arr[0].length;//cols



        int left=0,right=m-1, top=0,bottom=n-1;

        while (top<=bottom && left<=right){


        for (int i = left; i <=right ; i++) {
            System.out.print(arr[top][i]+" ");
        }
        top++;

        for (int i = top; i <=bottom ; i++) {
            System.out.print(arr[i][right]+" ");
        }

        right--;


        for (int i = right; i >=left ; i--) {
            System.out.print(arr[bottom][i]+" ");
        }
        bottom--;


        for (int i = bottom; i >=top ; i--) {
            System.out.print(arr[i][left]+" ");
        }
        left++;

        }



















    }
}
