// Problem Statement: Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

// Link: https://leetcode.com/problems/trapping-rain-water/

#include <bits/stdc++.h>

using namespace std;

int trap(vector<int> &height)
{
    int n = height.size();
    vector<int> maxFromLeft(n), maxFromRight(n);
    maxFromLeft[0] = height[0];
    maxFromRight[n - 1] = height[n - 1];
    for (int i = 1; i < n; ++i)
        maxFromLeft[i] = max(maxFromLeft[i - 1], height[i]);
    for (int i = n - 2; i >= 0; --i)
        maxFromRight[i] = max(maxFromRight[i + 1], height[i]);

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ans += min(maxFromLeft[i] - height[i], maxFromRight[i] - height[i]);
    }

    return ans;
}

int main(){
    int n;  cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)  cin>>v[i];
    int result = trap(v);
    cout<<result<<endl;
    return 0;
}