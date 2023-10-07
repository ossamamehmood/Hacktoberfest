/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    const map = new Map();
    const result = [];
    for (let i = 0; i < nums.length; i++){

        let complement = target - nums[i];
        if(map.has(complement)){
            return [map.get(complement), i];
        }
        else {
            map.set(nums[i], i);
        }

    }
    return result;
};
