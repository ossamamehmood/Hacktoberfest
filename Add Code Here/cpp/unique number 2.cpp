/*We are given an array containg n numbers. All the numbers are present twice except for two numbers which are present only once. Find the unique numbers in linear time without using any extra space. ( Hint - Use Bitwise )

Input Format
First line contains the number n. Second line contains n space separated number.

Constraints
n < 10^5

Output Format
Output a single line containing the unique numbers separated by space

Sample Input
4
3 1 2 1
Sample Output
2 3
Explanation
Smaller number comes before larger number*/
#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[100000];
	int no;
	int xori=0;          //store xor off all numbers;
	for(int i=0;i<n;i++){
		cin>>no;
		a[i]=no;
		xori=xori^no;
	}
	//xor=a^b and our task is to find a and b
	int temp=xori;
	//now we havr to find position of first set bit from right in temp
	int pos=0;
	while((temp&1)!=1){
		pos++;
		temp=temp>>1;
	}
	//the first set bit in xor is at position 'pos'
	int mask=(1<<pos);
	//now iterate over the array of numbers and find the number which have set bit at pos
	int x=0;
	int y=0;          //let x and y are unique numbers
	for(int i=0;i<n;i++){
		if((a[i]&mask)>0){
			x=x^a[i];
		}
	}
	//here we get the first number x
	y=xori^x;
	cout<<min(x,y)<<" "<<max(x,y)<<endl;
	return 0;
	
}
