//Single pointer Approach
// i and (len - i)
// len = str.length() - 1;
#include<bits/stdc++.h>
using namespace std;

void reverseString(string& str, int i, int len){
    cout<<"String  = "<<str<<endl;

    if(i>(len-i)) return ;

    swap(str[i], str[len]);
    i++;
    len -= i;

    reverseString(str,i,len);
}

int main(){

    string str = "abcdef";
    int len = str.length() - 1;
    

    cout<<"Original String  = "<<str<<endl<<endl;
    reverseString(str, 0, len);
    cout<<endl<<"Reversed String  = "<<str<<endl;

    return 0;
}