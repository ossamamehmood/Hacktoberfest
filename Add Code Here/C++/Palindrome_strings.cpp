#include<bits/stdc++.h>
using namespace std;

bool palindromeString(string str, int i, int j){

    if(i>j) return true;

    if(str[i] == str[j]){
        i++;
        j--;
        return palindromeString(str,i,j);
    }
    else{
        return false;
    }
}

int main(){

    string str = "babbalbab";
    int len = str.length() - 1;
    

    cout<<"Original String  = "<<str<<endl<<endl;
    int ans = palindromeString(str, 0, len);

    if(ans)
         cout<<"Given string is palindrome"<<endl;
    else  
        cout<<"Given string is not palindrome"<<endl;


    return 0;
}