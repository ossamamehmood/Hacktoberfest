class Solution {
    
    public int majorityElement(int[] arr) {  
        
        int count = 1;
        int ans =0;

        for (int i = 0; i < arr.length; i++) {
            if (arr[i]==arr[ans]){
                count++;
            }else {
                count--;
            }

            if (count==0){
                ans = i;
                count=1;
            }
        }
        return arr[ans];
   }
}
