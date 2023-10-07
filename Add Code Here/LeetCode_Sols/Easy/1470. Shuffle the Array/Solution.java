//  Using new array
class Solution {
    public int[] shuffle(int[] nums, int n) {
        int[] newNums = new int[nums.length];
        int i = 0, j, k;
        while (i < nums.length) {
            j = i/2;
            k = j + n;
            newNums[i++] = nums[j];
            newNums[i++] = nums[k];
        }
        return newNums;
    }
}

//  In-place
class Solution {
    public int[] shuffle(int[] nums, int n) {
        for(int i = 0; i < n; i++){
            nums[i] += nums[n + i] * 10000;
        }
        
        for(int i = n - 1; i >= 0; i--){
            nums[2 * i + 1] = nums[i] / 10000;
            nums[2 * i] = nums[i] % 10000;
        }
        
        return nums;
    }
}
