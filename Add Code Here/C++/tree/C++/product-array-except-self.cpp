https://leetcode.com/problems/product-of-array-except-self/
time complexity: O(n)
Given an integer array nums, return an array answer 
such that answer[i] is equal to the product of all the elements of nums except nums[i].
example-
Given numbers [2, 3, 4, 5], regarding the third number 4, the product of array
except 4 is 2*3*5 which consists of two parts: left 2*3 and right 5.
The product is left*right. We can get lefts and rights:
.....
Numbers:     2    3    4     5
Lefts:            2  2*3 2*3*4
Rights:  3*4*5  4*5    5      
......
Let’s fill the empty with 1:
......
Numbers:     2    3    4     5
Lefts:       1    2  2*3 2*3*4
Rights:  3*4*5  4*5    5     1
......
We can calculate lefts and rights in 2 loops. The time complexity is O(n).
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> v(nums.size());
        v[0]=1;
        for(int i=1;i<nums.size();i++){
            v[i]=v[i-1]*nums[i-1];//left
        }
        int p=1;//variable for right 
        for(int i=nums.size()-2;i>=0;i--){
            p*=nums[i+1];
            v[i]*=p;
        }
        return v;
    }
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    vector<int>p=productExceptSelf(v);
    for(int i=0; i<n; i++)cout<<p[i]<<" ";
    return 0;
}
