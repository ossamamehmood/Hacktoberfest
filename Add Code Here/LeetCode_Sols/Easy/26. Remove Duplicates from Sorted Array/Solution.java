//  Solution 1
class Solution {
    public int removeDuplicates(int[] nums) {
        Set<Integer> set = new HashSet<Integer>();
        int i = 0;
        for(int n: nums){
            if(!set.contains(n)){
                set.add(n);
                nums[i++] = n;
            }
        }
        return i;
    }
}

//  Solution 2
class Solution {
    public int removeDuplicates(int[] nums) {
        int last = Integer.MIN_VALUE;
        int i = 0;
        for(int n: nums){
            if(last != n){
                last = n;
                nums[i++] = n;
            }
        }
        return i;
    }
}

//Solution 3

class Solution {
    public int removeDuplicates(int[] nums) {
        int i = 0;
        for (int j = 1; j < nums.length; j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
}