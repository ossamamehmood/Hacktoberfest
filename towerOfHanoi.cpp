#include<iostream>
using namespace std;
void towerOfHanoi(int n,char src,char des,char help){
	if(n==0)
		return;
	if(n==1){
		cout<<"Move disk 1 from rod "<<src<<" to rod "<<des<<endl;
		return;
	}
	towerOfHanoi(n-1,src,help,des);
	cout<<"Move disk "<<n<<" from rod "<<src<<" to rod "<<des<<endl;
	towerOfHanoi(n-1,help,des,src);
}

int main(){
	int n;
	cout<<"Enter the no. of disk"<<endl;
	cin>>n;
	towerOfHanoi(n,'A','B','C');
	return 0;
}
