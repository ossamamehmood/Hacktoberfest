#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        
        while(n/10 >0){
            int sum=0;
            while(n>0){
                int digit=n%10;
                sum=digit*digit+sum;
                n/=10;
            }
            n=sum;
        }
        
        if(n==1 || n==7)//handling corner cases, as from 1 to 10 only 7 is a happy number
            return true;
        else 
            return false;
        
        
    }
};