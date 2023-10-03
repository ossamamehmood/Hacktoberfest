// Problem Statement: Generate all possible permutations of the integers present in the array.

class Solution {
    List<List<Integer>> ans;
    public List<List<Integer>> permute(int[] nums) {
        ans = new ArrayList<>();
        solve(nums, nums.length, new ArrayList<Integer>(), new boolean[nums.length]);
        return ans;
    }
    private void solve(int[] nums, int n, List<Integer> perms, boolean[] picked) {
        if(perms.size() == n) {
            if(ans.contains(perms)) return ;
            ans.add(new ArrayList(perms));
        }
        
        for(int i= 0; i< n; i++) {
            if(picked[i]) continue;
            picked[i] = true;
            perms.add(nums[i]);
            solve(nums, n, perms, picked);
            picked[i] =false;
            perms.remove(perms.size() -1);
        }
        return;
    }
}
