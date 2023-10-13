//The atoi() function in C takes a string (which represents an integer) as an argument and returns its value of type int. So basically the function is used to convert a string argument to an integer.

#include <bits/stdc++.h> 
using namespace std; 

int main() 
{ 
	int val; 
	char strn1[] = "12546"; 

	val = atoi(strn1); 
	cout <<"String value = " << strn1 << endl; 
	cout <<"Integer value = " << val << endl; 

	char strn2[] = "GeeksforGeeks"; 
	val = atoi(strn2); 
	cout <<"String value = " << strn2 << endl; 
	cout <<"Integer value = " << val <<endl; 

	return (0); 
} 

