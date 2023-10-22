// Returns location of key, or -1 if not found
int BinarySearch(int A[], int l, int r, int key){
	int m;
	while( l <= r ){
		m = l + (r-l)/2;

		if( A[m] == key ) // first comparison
			return m;

		if( A[m] < key ) // second comparison
			l = m + 1;
		else
			r = m - 1;
	}
	return -1;
}
// THIS CODE IS CONTRIBUTED BY YASH AGARWAL(YASHAGARWAL2852002)
