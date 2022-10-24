class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new List<>();
        int order=nums.length;
        for(int i=0;i<order;i++){
            for(int j=0;j<order;j++){
                for(int k=0;k<order;k++){
                    if( i != j && i != k && j != k && nums[i] + nums[j] + nums[k] ==0){
                        List<Integer> sub=[i,j,k];
                        result.add(sub);
                    }
                }
            }
        }
        return result;
    }
}
