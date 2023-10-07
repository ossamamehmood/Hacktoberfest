//  Using HashMap
class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        for(int i = 0; i < nums.length; i++){
            int pair = target - nums[i];
            if(map.containsKey(pair))
                return new int[]{map.get(pair), i};
            map.put(nums[i], i);
        }
        return new int[]{};
    }
}
