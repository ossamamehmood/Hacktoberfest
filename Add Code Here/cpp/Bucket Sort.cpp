#include<iostream>
#include<vector>
using namespace std;
class student{
public:
	int marks;
	string name;
};
//bucket sort to sort an array of students
void bucket_sort(student s[],int n){
	//assuming marks in range 0-100
	vector<student> v[101];
	for(int i=0;i<n;i++){             //o(n)time
		int m= s[i].marks;
		v[m].push_back(s[i]);
	}
	//iterate over the vector and print the students
	
	for(int i=100;i>=0;i--){
		for(vector<student>::iterator it=v[i].begin();it!=v[i].end();it++)//iterate over the vector
		  
		  cout<<(*it).marks<<" "<<(*it).name<<endl;
		
		
		
		
		
		
	}
}
int main(){
	student s[100000];
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i].marks>>s[i].name;     //s.marks to access the marks and s.name is to access the name of the student s
	}
	bucket_sort(s,n);

return 0;
}
