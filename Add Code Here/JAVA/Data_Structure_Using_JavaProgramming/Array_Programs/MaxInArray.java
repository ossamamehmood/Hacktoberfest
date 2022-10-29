public class MaxInArray {
    public static void main(String[] args) {
        int[] arr ={1,23,3,99,18};
        System.out.println(max(arr));
    }

    //assuming array is not empty
    static int max(int[] arr){
        int maxVal = arr[0];
        for(int i =1; i< arr.length ; i++){
            if(arr[i] >maxVal){
                maxVal = arr[i];
            }
        }
        return maxVal;
    }
}
