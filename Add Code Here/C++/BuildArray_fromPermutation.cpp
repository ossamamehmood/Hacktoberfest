#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> buildArray(vector<int>& nums);
int main()
{
    vector <int> nums = {0,2,1,5,3,4};
    buildArray(nums);
    for(int i=0; i<nums.size(); i++)
    {
        cout<<nums[i]<<" ";
    }
    return 0;
}
    vector<int> buildArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=nums[i]+(n*(nums[nums[i]]%n));
        }
        for(int i=0;i<n;i++){
            nums[i]/=n;
        }
        return nums;
    }