class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        int n=nums.size();
        vector<int>nge(2*n);
        for(int i=2*n-1;i>=0;i--)
        {
            if(st.empty())
                nge[i]=-1;
            else
            {
                while(st.empty()==false && st.top()<=nums[i%n])
                    st.pop();
                if(st.empty())
                    nge[i]=-1;
                else
                    nge[i]=st.top();
            }
            st.push(nums[i%n]);
        }
        vector<int>vec;
        for(int i=0;i<n;i++)
        {
            vec.push_back(nge[i]);
        }
        return vec;
    }
};