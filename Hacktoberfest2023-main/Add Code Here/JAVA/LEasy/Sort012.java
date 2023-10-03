package LEasy;


import java.util.Arrays;

public class Sort012 {

    static class Node{
        int data;
        Node next;

        Node(int data){
            this.data=data;
            this.next=null;
        }
    }


    public static void main(String[] args) {
        int[] arr={0,1,2,0,1,2,1,2,0,0,0,1};
//        int n=arr.length;

//        bruteforce(mergesort);

        optimal(arr);




    }

    private static void optimal(int[] arr) {
        int low=0;
        int mid=0;
        int high=arr.length-1;
        while (mid<=high){
            if(arr[mid]==0){
                int temp=arr[low];
                arr[low]=arr[mid];
                arr[mid]=temp;
                low++;
                mid++;
            }else if(arr[mid]==1){
                mid++;
            }else{
                int temp=arr[mid];
                arr[mid]=arr[high];
                arr[high]=temp;
                high--;
            }
        }


        System.out.println(Arrays.toString(arr));

    }




}
