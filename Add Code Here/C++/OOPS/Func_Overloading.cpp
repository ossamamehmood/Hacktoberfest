#include<iostream>
using namespace std;

// same function name but parameter names and types are different         
float add(int x, int y) {
	return x+y;
}

int add(int x, int y, int z) {
	return x+y+z;
}

float add(float x, float y) {
	return x+y;
}

float add(int x, float y) {
	return x+y;
}

int main() {
	int a=10, b=20, c=30;
	float p=10.57, q=20.58;
	cout<< add(a,b) <<endl;
	cout<< add(a,b,c) <<endl;
	cout<< add(p,q) <<endl;
	cout<< add(a,q) <<endl;

    return 0;
}
