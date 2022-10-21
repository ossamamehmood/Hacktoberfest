/*We are given two coins of value x and y. We have to find the maximum of value of a XOR b where x <= a <= b <= y.

Input Format
We are given two integers x and y

Constraints
l <= r <= 1000

Output Format
Print the maximum value of a XOR b

Sample Input
5
6
Sample Output
3
Explanation
If a and b are taken to be 5. Then a xor b = 0
If a and b are taken to be 6. Then a xor b = 0
If a is 5 and b is 6. Then a xor b is 3.*/
#include<iostream>
#include<climits>
using namespace std;
int XOR(int x,int y){
	int maxi=INT_MIN;
	int ans;
	for(int a=x;a<=y;a++){
		for(int b=y;b>=a;b--){
			int ans=a^b;
		}
		maxi=max(maxi,ans);

	}
	return maxi;
}
int main () {
	int x,y;
	cin>>x>>y;
	cout<<XOR(x,y);
	return 0;
}
