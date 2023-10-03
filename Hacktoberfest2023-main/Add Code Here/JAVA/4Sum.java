class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        int n = nums.length;
        Arrays.sort(nums);
        Set<List<Integer>>set = new HashSet();
        for(int i=0;i<n;i++){
            
            for(int j=i+1;j<n;j++){
                
                int k = j+1;
                int l = n-1;
                while(k<l){
                    long sum = nums[i]+nums[j];
                    sum += nums[k];
                    sum += nums[l];
                if(sum==target){
                    List<Integer>arr = new ArrayList();
                    arr.add(nums[i]);
                    arr.add(nums[j]);
                    arr.add(nums[k]);
                    arr.add(nums[l]);
                    set.add(arr);
                    k++;
                    l--;
                    while(k<l && nums[k] == nums[k-1])k++;
                    while(k<l && nums[l] == nums[l+1])l--;
                }
                else if(sum<target)k++;
                else l--;
                }
                
            }
        }
        return new ArrayList(set);
    }
}