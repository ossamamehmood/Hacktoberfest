// Quick sort Implementation using Javascript

//array to be sorted
var arr = [25, 13, 55, 63, 2, 61, 35, 47];

/* Utility Functions */

//swapping function
function swap(arr, i, j) {
	let temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

//piovting function
function partition(arr, low, high) {
	let pivot = arr[high];
	let i = low - 1;

	for (let j = low; j <= high - 1; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(arr, i, j);
		}
	}
	swap(arr, i + 1, high);
	return i + 1;
}

//main function
function quickSort(arr, low, high) {
	if (low < high) {
		let pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
	console.log(arr);
}

//just like merge sort, this is also a recursive algorithm
quickSort(arr, 0, arr.length - 1);
