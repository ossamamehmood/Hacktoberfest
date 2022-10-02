// Implementation of the code in C++
#include <bits/stdc++.h>
using namespace std;

int main()
{

// Hex String variable
string hex_s = "653cae8da8edb426052";

// Plain text variable
string plain = "";

// variable to store the XOR
// of previous digits
int x = 0;

int l = hex_s.length();

// Loop for loop from the end to
// the mid section of the string
for (int i = l - 1; i > (l / 2) - 1; i--) {
	string digit = "";
	digit += hex_s[i];

	// calculation of the plaintext digit
	unsigned int y = x ^ stoul(digit, nullptr, 16);

	// calculation of XOR chain
	x = x ^ y;
	stringstream sstream;
	sstream << hex << y;
	string z = sstream.str();
	plain = z[z.length() - 1] + plain;
}

cout << plain;
}

