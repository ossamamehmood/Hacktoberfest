/*Nishant is a very naughty boy in Launchpad Batch. One day he was playing with strings, and randomly shuffled them all. Your task is to help Nishant Sort all
 the strings ( lexicographically ) but if a string is present completely as a prefix in another string,then string with longer length should come first.
  Eg bat, batman are 2 strings and the string bat is present as a prefix in Batman - then sorted order should have - Batman, bat.

Input Format
N(integer) followed by N strings.

Constraints
N<=1000

Output Format
N lines each containing one string.

Sample Input
3
bat
apple
batman
Sample Output
apple
batman
bat
Explanation
In mathematics, the lexicographic or lexicographical order (also known as lexical order, dictionary order, alphabetical order or lexicographic(al) product) is a
 generalization of the way words are alphabetically ordered based on the alphabetical order of their component letters.*/
 #include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
bool myCompare(string a, string b) {
    if (a.find(b)==0 || b.find(a)==0)
        return a.length() > b.length();
    return a < b;
}

int main() {
	int N;
	cin>>N;
	cin.get();
	string s[1000];
	for(int i=0;i<N;i++){
        getline(cin,s[i]);
	}
	sort(s,s+N,myCompare);
	for(int i=0;i<N;i++){
		cout<<s[i]<<endl;
	}
	return 0;
}
