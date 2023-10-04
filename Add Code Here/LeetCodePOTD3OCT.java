class Solution {
    public int numIdenticalPairs(int[] nums) {
        Arrays.sort(nums);
        int sum =0;
        int flag = 1;
        for(int i=0;i<nums.length-1;i++)
        {   
            if(nums[i]==nums[i+1])
            {
                flag++;
            }
            else{
            System.out.println(flag);
            sum = sum + (flag*(flag-1)/2);
            flag = 1;
            }
        }
        System.out.println(flag);
        sum = sum + (flag*(flag-1)/2);
        System.out.println(Arrays.toString(nums));
        return sum;
    }
}
