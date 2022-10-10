class MaxRec {
    public static int max(int[] arr){
        return max(arr, 0);
    }
  
     public static int max(int[] arr, int start){
         if (start == arr.length - 1) return arr[arr.length - 1];
         return Math.max(arr[start], max(arr, start + 1);
    }
}
