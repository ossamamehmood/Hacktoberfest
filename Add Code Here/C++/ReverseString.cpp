/*
Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.

*/
#include<iostream>
using namespace std;
void reverseString(vector<char>& s) {
        int n = s.size();
        for(int i = 0; i < n/2 ; i++)
        {
            swap(s[i],s[n-i-1]);
        }
        
    }
int main(){
}