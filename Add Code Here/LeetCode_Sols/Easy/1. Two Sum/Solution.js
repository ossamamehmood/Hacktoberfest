// Solution #1
const twoSum = function (nums, target) {
    //search of all Array
    for (let i = 0; i < nums.length; i++) {
        for (let j = i + 1; j < nums.length; j++) {
            // if (nums[j] === target - nums[i])
            if(nums[i] + nums[j] === target) {
                return [i, j];
            }
        }
    }
};

// Solution #2
const twoSum = function (nums, target) {
    //search of all Array
    //The time complexcity is O(n^2)
    for (let i = 0; i < nums.length; i++) {
        for (let j = i + 1; j < nums.length; j++) {
            // if (nums[j] === target - nums[i])
            if(nums[i] + nums[j] === target) {
                return [i, j];
            }
        }
    }

    // here is my solution with complexcity of O(n)
    //Solve problem using hashtable
    const hashTable = {}
    for(let i=0; i < nums.length; i++){
        const want = target - nums[i]
        if(want in hashTable){
            return [hashTable[want], i]
        }
        hashTable[nums[i]] = i
    }
};
