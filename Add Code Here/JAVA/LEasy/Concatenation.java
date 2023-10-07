class Solution {
    public int[] getConcatenation(int[] nums) {
        int size = nums.length*2;
        int[] arr = new int[size];
        for(int i = 0; i < nums.length; i++){
            arr[i] = nums[i];
        }
        int a=0;
        for(int i = nums.length; i < size; i++){
            arr[i] = nums[a];
            if(a<nums.length-1){
                a++;
            }
            
        }
        return arr;
    }
}
