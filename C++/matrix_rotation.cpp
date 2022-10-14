/*
  Platform: HackerRank
  Question URL: https://www.hackerrank.com/challenges/matrix-rotation-algo
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Main algorithm: in order to rotate the whole matrix, we'll just rotate one ring at a time
// We can do this in-place to achieve O(1) additional space complexity
int main() {
	int M, N, R;
	cin>>M>>N>>R;
	int **matrix = new int*[M];
	for(int i = 0; i < M; i++) {
		matrix[i] = new int[N];
		for(int j = 0; j < N; j++) {
			cin>>matrix[i][j];
		}
	}

	int numRings = min(M,N)/2;
	for(int i = 0; i < numRings; i++) {
		// Subtract the number of 360 degree rotations from R
		// A 360 degree rotation = rotating the same number of times as the perimeter of the current ring
		int numRotations = R%(2*(M + N - 4*i) - 4);
		for(int rotation = 0; rotation < numRotations; rotation++) {
			// Rotate the ring (see the clockwise algorithm for an in-depth example of how this is done)
			// Rotate top row
			for(int j = i; j < N-i-1; j++) {
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[i][j+1];
				matrix[i][j+1] = tmp;
			}
			// Rotate right column
			for(int j = i; j < M-i-1; j++) {
				int tmp = matrix[j][N-i-1];
				matrix[j][N-i-1] = matrix[j+1][N-i-1];
				matrix[j+1][N-i-1] = tmp;
			}
			// Rotate bottom row
			for(int j = N-i-1; j > i; j--) {
				int tmp = matrix[M-i-1][j];
				matrix[M-i-1][j] = matrix[M-i-1][j-1];
				matrix[M-i-1][j-1] = tmp;
			}
			// Rotate left column
			for(int j = M-i-1; j > i+1; j--) {
				int tmp = matrix[j][i];
				matrix[j][i] = matrix[j-1][i];
				matrix[j-1][i] = tmp;
			}
		}
	}
	// Output final matrix
	for(int i = 0; i < M; i++) {
		for(int j = 0; j < N; j++) {
			cout<<matrix[i][j]<<" ";
		}
		cout<<"\n";
	}
    return 0;
}
