class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        stack<int> st;
        vector<int> ans,v;
        for(int i=0;i<n;i++)
        {
            if(asteroids[i]>=0) 
            st.push(asteroids[i]);
            else if(asteroids[i]<0)
            {
                int f=0;
                while(st.size()>0)
                {
                    if(st.top()<abs(asteroids[i]))
                    {
                        st.pop();
                    }
                    else if(st.top()==abs(asteroids[i]))
                    {
                      st.pop();
                      f=1;
                      break;
                    }
                    else 
                    break;
                }
                if(st.size()==0&&f==0) 
                ans.push_back(asteroids[i]);
            }
        }
        while(st.size())
        {
           v.push_back(st.top());
           st.pop();
        }
        reverse(v.begin(),v.end());
        for(auto it:v) 
        ans.push_back(it);
        return ans;
    }
};
