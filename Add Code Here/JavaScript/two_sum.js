/**
 * Two Sum Algorithm Implementation
 * Author: Shekhar
 * Description: Find two numbers in array that add up to target sum
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

/**
 * Find two numbers in array that add up to target sum
 * @param {number[]} nums - Array of integers
 * @param {number} target - Target sum
 * @returns {number[]} - Indices of the two numbers
 */
function twoSum(nums, target) {
    const numMap = new Map();
    
    for (let i = 0; i < nums.length; i++) {
        const complement = target - nums[i];
        
        if (numMap.has(complement)) {
            return [numMap.get(complement), i];
        }
        
        numMap.set(nums[i], i);
    }
    
    return []; // No solution found
}

/**
 * Alternative implementation using object instead of Map
 * @param {number[]} nums - Array of integers
 * @param {number} target - Target sum
 * @returns {number[]} - Indices of the two numbers
 */
function twoSumObject(nums, target) {
    const numObj = {};
    
    for (let i = 0; i < nums.length; i++) {
        const complement = target - nums[i];
        
        if (complement in numObj) {
            return [numObj[complement], i];
        }
        
        numObj[nums[i]] = i;
    }
    
    return []; // No solution found
}

/**
 * Brute force approach (for comparison)
 * @param {number[]} nums - Array of integers
 * @param {number} target - Target sum
 * @returns {number[]} - Indices of the two numbers
 */
function twoSumBruteForce(nums, target) {
    for (let i = 0; i < nums.length; i++) {
        for (let j = i + 1; j < nums.length; j++) {
            if (nums[i] + nums[j] === target) {
                return [i, j];
            }
        }
    }
    return []; // No solution found
}

/**
 * Test function to demonstrate the algorithms
 */
function testTwoSum() {
    const testCases = [
        { nums: [2, 7, 11, 15], target: 9, expected: [0, 1] },
        { nums: [3, 2, 4], target: 6, expected: [1, 2] },
        { nums: [3, 3], target: 6, expected: [0, 1] },
        { nums: [1, 2, 3, 4, 5], target: 8, expected: [2, 4] },
        { nums: [1, 2, 3, 4, 5], target: 10, expected: [] }
    ];
    
    console.log("Two Sum Algorithm Test");
    console.log("=".repeat(40));
    
    testCases.forEach((testCase, index) => {
        console.log(`\nTest Case ${index + 1}:`);
        console.log(`Array: [${testCase.nums.join(', ')}]`);
        console.log(`Target: ${testCase.target}`);
        
        const result1 = twoSum(testCase.nums, testCase.target);
        const result2 = twoSumObject(testCase.nums, testCase.target);
        const result3 = twoSumBruteForce(testCase.nums, testCase.target);
        
        console.log(`Map approach: [${result1.join(', ')}]`);
        console.log(`Object approach: [${result2.join(', ')}]`);
        console.log(`Brute force: [${result3.join(', ')}]`);
        
        if (result1.length > 0) {
            const sum = testCase.nums[result1[0]] + testCase.nums[result1[1]];
            console.log(`Verification: ${testCase.nums[result1[0]]} + ${testCase.nums[result1[1]]} = ${sum}`);
        }
        
        console.log(result1.length > 0 ? "✅ Solution found!" : "❌ No solution");
    });
}

// Export functions for use in other modules
if (typeof module !== 'undefined' && module.exports) {
    module.exports = {
        twoSum,
        twoSumObject,
        twoSumBruteForce,
        testTwoSum
    };
}

// Run tests if this file is executed directly
if (typeof window === 'undefined' && require.main === module) {
    testTwoSum();
}
