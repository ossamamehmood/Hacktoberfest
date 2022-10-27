#include<iostream>
using namespace std;
//replace bits in n by m
/* you are given two 32 bits numbers , N and M and two positions i and j. write a method
to set all bits between i and j in N equal to M.*/
int replace_bits(int n,int m,int i,int j){
	int ones=(~0);
	int a=ones<<j+1;
	int b=(1<<i)-1;
	int mask1=a|b;
	int no=n&mask1;
	int mask2=m<<i;
	int ans=no|mask2;
	return ans;
}
int main(){
	int n,m,i,j;
	cin>>n>>m>>i>>j;
	cout<<replace_bits(n,m,i,j);
	return 0;
}
