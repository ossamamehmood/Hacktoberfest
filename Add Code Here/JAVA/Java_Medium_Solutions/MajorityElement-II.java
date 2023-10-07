class Solution {
    public List<Integer> majorityElement(int[] nums) {
        List<Integer> ans=new ArrayList<>();
        HashMap<Integer,Integer> map=new HashMap<>();
        int n=nums.length;
        for(int ele: nums) {
            map.put(ele, map.getOrDefault(ele,0)+1);
            if(map.containsKey(ele)) {
                int count=map.get(ele);
                if(count>(n/3) && !ans.contains(ele)) {
                    ans.add(ele);
                    map.remove(ele);
                }
            }
        }
        return ans;
    }
}