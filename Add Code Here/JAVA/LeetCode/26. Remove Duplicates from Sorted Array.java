class Solution {
    public int removeDuplicates(int[] nums) {
        
        ArrayList<Integer> intList = new ArrayList<Integer>(nums.length);
for (int i : nums)
{
    intList.add(i);
}
        Set<Integer> s = new LinkedHashSet<Integer>(intList);
        int n = s.size();
        int x = 0;
        for(Integer num: s){
            nums[x]=num;
            x++;
        }
        return n;
    }
}
