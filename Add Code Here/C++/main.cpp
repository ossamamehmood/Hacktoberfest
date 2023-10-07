//Given a n x n matrix. The problem is to sort the given matrix in strict order. Here strict order means that the matrix is sorted in a way such that all elements in a row are sorted in increasing order and for row ‘i’, where 1 <= i <= n-1, the first element of row ‘i’ is greater than or equal to the last element of row ‘i-1’.
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	vector<vector<int>>v{{5, 4, 7},{1, 3, 8},{2, 9, 6}};
	int n=v.size();
	vector<int>x;
	for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
	x.push_back(v[i][j]);
	}
	}
	sort(x.begin(),x.end());
	int k=0;
	for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
	v[i][j]=x[k++];
	}
	}
cout<<"Sorted Matrix Will be:"<<endl;
	for(auto it:v){
	for(auto vt:it){
	cout<<vt<<" ";
	}cout<<endl;
	}
	return 0;
}
