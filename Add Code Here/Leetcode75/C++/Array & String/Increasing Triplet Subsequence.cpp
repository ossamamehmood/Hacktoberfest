class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        long long a=LLONG_MIN,b=LLONG_MIN,c=LLONG_MIN;
        for(auto i:nums)
        {
            if(a==LLONG_MIN or i<=a)
                a=i;
            else if(b==LLONG_MIN or i<=b)
                b=i;
            else
                return true;
        }
        return false;
    }
};