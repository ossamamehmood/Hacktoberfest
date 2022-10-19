

var removeDuplicates = function (nums) {
    // Handling Edge Case
    if (nums.length === 0) return 0;
    let p1 = 0;
    for (let p2 = 1; p2 < nums.length; p2++) {
      if (nums[p1] !== nums[p2]) {
        console.log(nums);
        p1++;
        nums[p1] = nums[p2];
        //  console.log(nums)
      }
    }
    return p1 + 1;
  };
  console.log(removeDuplicates([1, 1, 2, 3,3, 4, 4]));
  