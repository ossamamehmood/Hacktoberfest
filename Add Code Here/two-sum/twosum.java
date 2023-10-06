class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        int[]ans=new int[2];
        int val=0;
        for(int i=0; i<nums.length; i++){
           val = target - nums[i];
           if(mp.containsKey(val)==false) mp.put(nums[i],i);
           else{
               ans[0] = mp.get(val);
               ans[1] = i;
               return ans;

           }
        }
        return ans;
    }
}
