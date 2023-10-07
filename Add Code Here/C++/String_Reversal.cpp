// here we done with the refernce variable so, original string has been changed 
// Using two pointer's (i and j)
#include<bits/stdc++.h>
using namespace std;

void reverseString(string& str, int i, int j){
    cout<<"String  = "<<str<<endl;

    if(i>j) return ;

    swap(str[i], str[j]);
    i++;
    j--;

    reverseString(str,i,j);
}

int main(){

    string str = "abcdef";
    int len = str.length() - 1;
    

    cout<<"Original String  = "<<str<<endl<<endl;
    reverseString(str, 0, len);
    cout<<endl<<"Reversed String  = "<<str<<endl;

    return 0;
}