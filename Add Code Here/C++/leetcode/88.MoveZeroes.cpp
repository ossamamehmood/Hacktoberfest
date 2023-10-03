#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {
    for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
        if (nums[cur] != 0) {
            swap(nums[lastNonZeroFoundAt++], nums[cur]);
        }
    }
}

int main(){
    vector<int> v = {1,0};
    moveZeroes(v);
    for(int i:v) cout<<i<<" "; 


    return 0;
}