public class CyclicSort{
    public static void main(String[] args) {
        //The cyclic sort sorts an array of [0, n-1] in O(n) time
        int[] arr = {3, 5, 2, 1, 4, 0};
        CyclicSort.sort(arr);
        for(int i = 0; i < arr.length; i++){
            System.out.print(arr[i] + " ");
        }
    }

    public static void sort(int[] arr){
        int i = 0;
        while(i < arr.length-1){
            int correct = arr[i];
            if(arr[i] != arr[correct]){
                int temp = arr[i];
                arr[i] = arr[correct];
                arr[correct] = temp;
            }else{
                i++;
            }
        }
    }
}