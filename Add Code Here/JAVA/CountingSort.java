import java.util.*;

public class CountingSort {

    public static void main(String[] args) {
        int arr[]={1,3,4,6,8,5,9,3,5,7,8};
        CountSort(arr);
        System.out.println(Arrays.toString(arr));

    }
    public static void CountSort(int arr[]){
        int max=Integer.MIN_VALUE;
        for(var x: arr){
            max=Integer.max(max,x);
        }
        int count[]=new int[max+1];
        for(var x:arr){
            count[x]++;
        }
        int p=0;
        for(int i=0;i<count.length;i++){
            for(int j=0;j<count[i];j++)
            {
                arr[p]=i;
                p++;
            }
        }

    }
}
