// Insertion sort Implementation using Javascript

//array to be sorted
var arr = [25, 13, 55, 63, 2, 61, 35, 47];

function insertionSort(arr) {
	let i, key, j;
	for (i = 1; i < arr.length; i++) {
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}

	console.log(arr);
}

// array is split into a sorted and an unsorted part and then arranged accordingly
// it is appropriate for data sets which are already partially sorted.
insertionSort(arr);
