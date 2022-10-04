#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n= heights.size();
        priority_queue<int> pq;
        int jump=0;
        int i;
        for(i=0;i<n-1;i++){
            jump=heights[i+1]-heights[i];
            if(jump<=0) continue;
            pq.push(-jump);// -ve dign because we want to use bricks for very small height differences
            if(pq.size()>ladders){
                bricks+=pq.top();
                pq.pop();
            } 
            if(bricks<0) return i;
            
        }
        
        return i;
    }
};  