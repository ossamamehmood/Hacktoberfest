#include<iostream>

using namespace std;

int main() {

	char ch;
	cout << "enter a character : ";
	cin >> ch;

	// if(ch >= 65 && ch <= 90) {
	// 	cout << ch << " is an upper-case letter" << endl;
	// } else if(ch >= 97 and ch <= 122) {
	// 	cout << ch << " is an lower-case letter" << endl;
	// } else if(ch >= 48 and ch <= 57) {
	// 	cout << ch << " is a digit" << endl;
	// } else {
	// 	cout << ch << " is a special symbol" << endl;
	// }

	if(ch >= 'A' and ch <= 'Z') {
		cout << ch << " is an upper-case letter" << endl;
	} else if(ch >= 'a' and ch <= 'z') {
		cout << ch << " is an lower-case letter" << endl;
	} else if(ch >= '0' and ch <= '9') {
		cout << ch << " is a digit" << endl;
	} else {
		cout << ch << " is a special symbol" << endl;
	}
	
	return 0;
}