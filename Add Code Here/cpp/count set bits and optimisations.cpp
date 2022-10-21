#include<iostream>
using namespace std;
//given a number n , find the number of set bits in its binary representation
//ex. N=13 , binary representation = 1101, no of set bits =3
//first method
int count_set_bits(int n){
	int ans=0;
	while(n>0){
		ans+=(n&1);
		n=n>>1;
	}
	return ans;
}
//second method
int count_bits_fast(int n){        //more efficient
    int ans=0;
    while(n>0){
    	n=n&(n-1);
    	ans++;
	}
	return ans;
}
int main(){
	int n;
	cin>>n;
	cout<<count_set_bits(n)<<endl;
	cout<<count_bits_fast(n)<<endl;
	cout<<__builtin_popcount(n)<<endl;
	return 0;
}
