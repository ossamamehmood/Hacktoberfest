class Solution {
    public int[] singleNumber(int[] nums) {
       int xXORy = 0, i=0;
        int[] res = new int[2];
       for(int x:nums){
           xXORy=xXORy^x;
       }

       int rsbm=xXORy & -xXORy;
       int x=0, y=0;
       while(i<nums.length){

           if((nums[i]&rsbm)!=0) x=x^nums[i];
           else y=y^nums[i];
           ++i;
       }
        res[0]=x;
        res[1]=y;
        return res;
    }
}