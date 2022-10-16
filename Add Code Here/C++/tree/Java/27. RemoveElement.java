class Solution {
    
    void delElement(int[] arr, int key, int len){
        for(int i=key;i<len-1;i++){
            arr[i]=arr[i+1];
        }
    }
    
    
    public int removeElement(int[] nums, int val) {
        int len=nums.length;
        
        for(int i=0 ; i < len ; i++){
            if(nums[i]==val){
                delElement(nums, i, len);
                len--;
                i--;
            }
        }
        return len;
    }
}
