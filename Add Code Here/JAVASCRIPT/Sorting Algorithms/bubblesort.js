// Bubble sort Implementation using Javascript

//array to be sorted
var arr = [25, 13, 55, 63, 2, 61, 35, 47];

function bubbleSort(arr) {
	for (var i = 0; i < arr.length; i++) {
		for (var j = 0; j < arr.length - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				var temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	console.log(arr);
}

//One of the simple easy algorithm to implement
//Bubble sort algorithm sorts the array
//by comparing two adjacent elements and swaps them if they are not in the intended order
bubbleSort(arr);
