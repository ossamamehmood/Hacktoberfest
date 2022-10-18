// Test implementation

const twoSum = (nums, target) => {
    const hash = {};
    for (let i = 0; i < nums.length; i++) {
        const num = nums[i];
        const complement = target - num;
        if (hash[complement] !== undefined) {
            return [hash[complement], i];
        }
        hash[num] = i;
    }
    return [-1, -1];
}