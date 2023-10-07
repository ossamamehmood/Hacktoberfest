class Solution {
public:
    string convert(string s, int r) {
        int n=s.size();
        if(r==1)
            return s;

        int fh=(r-1)*2;
        int sh=0;
        int flg=1;
        string ans;
        int k=0;

        while(fh>=0)
        {
            int temp=k;
            while(temp<n)
            {
                if(flg && fh)
                {
                    ans.push_back(s[temp]);
                    temp+=fh;
                }
                else
                {
                    if(sh)
                        ans.push_back(s[temp]);
                    temp+=sh;
                }

                flg=1-flg;
            }
            flg=1;
            fh-=2;
            sh+=2;
            k++;
        }
        return ans;
    }
};
