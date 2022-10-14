// STAIR CASE PROBLEM ON CODE-STUDIO (Recursion)
// we have to reach nth stair starting from 0.
// we can either climb 1 or 2 stairs at a time
// find number of process or ways to reach nth stair

#include<iostream>
using namespace std;

int number_of_ways(int n){
    if (n==0)
        return 1;
    if (n<0)
        return 0;
    return number_of_ways(n-1) + number_of_ways(n-2);
}

int main()
{
    int n;
    cin>>n;
    cout<<number_of_ways(n);
return 0;
}