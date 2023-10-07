var twoSum = function (nums, target) {
	let map = new Map();

	// console.log(map);

	for (var i = 0; i < nums.length; i++) {
		let complement = target - nums[i];

		console.log("complement's" + complement);
		if (map.has(complement)) {
			return [map.get(complement), i];
		}
		map.set(nums[i], i);
	}

	console.log("after" + map);
};

console.log(twoSum([7, 4, 1, 3], 5));

var twoSum = function (nums, target) {
	let length = nums.length;
	let currentIndex = 0;
	for (let i = 1; i <= length && length != 1; i++) {
		if (i != length && nums[currentIndex] + nums[currentIndex + i] == target) {
			console.log(`[${currentIndex},${currentIndex + i}]`);
			return [currentIndex, currentIndex + i];
		} else if (i == length) {
			i = 0;
			length--;
			currentIndex++;
		}
	}
};
