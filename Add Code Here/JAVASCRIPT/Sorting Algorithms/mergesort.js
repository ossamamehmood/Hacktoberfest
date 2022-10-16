// Merge sort Implementation using Javascript

//array to be sorted
var arr = [25, 13, 55, 63, 2, 61, 35, 47];

function merge(arr, l, m, r) {
	var n1 = m - l + 1;
	var n2 = r - m;

	var L = new Array(n1);
	var R = new Array(n2);

	for (var i = 0; i < n1; i++) L[i] = arr[l + i];
	for (var j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

	var i = 0;
	var j = 0;
	var k = l;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

// l is for left index and r is
function mergeSort(arr, l, r) {
	if (l >= r) {
		return;
	}
	var m = l + parseInt((r - l) / 2);
	mergeSort(arr, l, m);
	mergeSort(arr, m + 1, r);
	merge(arr, l, m, r);
	console.log(arr);
}

//this is a recursive algorithm
//splits the array recursively until the last element and merge them back in sorted manner
mergeSort(arr, 0, arr.length - 1);
