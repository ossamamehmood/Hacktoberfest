import java.util.Scanner;

public class Selection_Sort {
    //Program to do Selection_Sort
    public static void selection_sort(int arr[],int size){
        int i,j,min_index,t;

        for (i=0;i<size;i++){
            min_index = i;

            //Finding the minimum element in the array after the index i+1
            for (j=i+1;j<size;j++){
                if (arr[j]<arr[min_index])
                    min_index = j;
            }

            //Swapping arr[i] <-> arr[min_index]
            t = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = t;
        }

    }

    //Driver Program
    public static void main(String[] args) {
        int arr[]={9,23,343,12,421,213};
        int size = arr.length;
        selection_sort(arr,size);
        System.out.print("Array after sorting : ");
        for(int i=0;i<size;i++){
            System.out.print(arr[i]);
            System.out.print(' ');
        }
        System.out.println(' ');
    }
}
