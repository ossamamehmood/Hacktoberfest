class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
      Arrays.sort(nums);
      List<List<Integer>> result = new ArrayList<>();
      for (int i = 0; i < nums.length && nums[i] <= 0; i++) {
          
        if (i == 0 || nums[i - 1] != nums[i]) {
            
          Set<Integer> set = new HashSet<>();
          for (int j = i + 1; j < nums.length; j++) {
              
            int target = -1 * (nums[i] + nums[j]);
            if (set.contains(target)) {
                
              result.add(Arrays.asList(nums[i], nums[j], target));
              while (j + 1 < nums.length && nums[j] == nums[j + 1]) {
                j++;
              }
            }
            set.add(nums[j]);
          }
        }
      }
      return result;
    }
  }