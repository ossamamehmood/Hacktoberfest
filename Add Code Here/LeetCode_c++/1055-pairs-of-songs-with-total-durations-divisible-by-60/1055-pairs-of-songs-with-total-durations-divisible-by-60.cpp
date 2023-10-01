class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time)
    {
        long long ans =0,cnt[60]={0};
        for( int i=0;i<time.size();i++)
        cnt[time[i]%60]+=1;

        ans+= cnt[0]*(cnt[0]-1)/2;
        ans+= cnt[30]*(cnt[30]-1) /2;

        int temp=0;

        for(int i=1;i<30;i++)
        temp += (cnt[i]*cnt[60-i]);
        
        // cout<<temp;
         return ans+temp;
    }
};