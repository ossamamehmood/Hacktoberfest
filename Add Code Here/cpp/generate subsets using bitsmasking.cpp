//finding subsequences/subsets of a given string
//input="abc"
//output=" ",a,ab,abc,ac,b,bc,c
#include<iostream>
#include<cstring>
using namespace std;
void filter_characters(int n,char a[]){
	int j=0;
	while(n>0){
		int lastbit=(n&1);
		if(lastbit){            //if lastbit is 1 
			cout<<a[j];
		}
		j++;
		n=n>>1;
	}
	cout<<endl;
}
void print_subsets(char a[]){
	int n=strlen(a);
	for(int i=0;i<(1<<n);i++){
		filter_characters(i,a);
		
	}
	return;
}
int main(){
	char a[100];
	cin>>a;
	print_subsets(a);
	return 0;
}

