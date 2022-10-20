#include <bits/stdc++.h>
using namespace std;
int count_set_bit_1(int n){
    int count=0;
    while(n>0)
    {
        if((1&n)==1)
             count++;
        n=n>>1;
    }
    return count;
}
int count_set_bit_2(int n){
    int count=0;
    while(n>0)
    {
        n=n&(n-1);
        count++;
    }
    return count;
}
int main() {
	int n;
    cout<<"Eneter a value :";
	cin>>n;
	cout<<"By Method-1 complexity- O(LogN): "<<count_set_bit_1(n)<<endl;
	cout<<"By Method-2 complexity- O(No. Of Set-bits): "<<count_set_bit_2(n)<<endl;

	return 0;
}