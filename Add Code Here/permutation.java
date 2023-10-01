class Solution {
    public void solve(int [] nums, List<Integer> ds, List<List<Integer>>ans, boolean [] check){
        if(ds.size()==nums.length){
            if(!ans.contains(ds)){
                ans.add(new ArrayList<>(ds));
            }
        }
        for(int i=0; i<nums.length; i++){
            if(check[i]==false){
                ds.add(nums[i]);
                check[i]=true;
                solve(nums, ds, ans , check);
                check[i]=false;
                ds.remove(ds.size()-1);
            }
        }
    }
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<Integer> ds =new ArrayList<>();
        List<List<Integer>> ans = new ArrayList<>();
        boolean [] check = new boolean [nums.length];
        Arrays.fill(check, false);
        solve(nums, ds, ans, check);
        return ans;
    }
}
