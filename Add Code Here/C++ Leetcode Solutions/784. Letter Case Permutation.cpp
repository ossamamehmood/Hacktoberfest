class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = s.length();
        string letters = "";
        vector<string>alls;
        
        for(int i=0;i<n;i++) {
            if(isalpha(s[i])) {
                letters+=s[i];
            }    
        }

        n = letters.length();
        for(int i=0;i<pow(2,n);i++) {
            bitset<12> decimal(i);

            string temp;
            temp = decimal.to_string();

            string test = "";
            for(int i=12-n;i<12;i++) {
                test+=temp[i];
            }

            string permu = letters;
            for(int i=0;i<test.length();i++) {
                if(test[i]=='1') {
                    permu[i] = toupper(permu[i]);
                }
                else {
                    permu[i] = tolower(permu[i]);
                }
            }

            alls.push_back(permu);          
        }

        n = s.length();
        int t = pow(2,letters.length());
        vector<string>res;

        for(int i=0;i<t;i++) {
            string temp = "";
            int k = 0;
            for(int j=0;j<n;j++) {
                if(isalpha(s[j])) {
                    temp+=alls[i][k];
                    k++;
                } 
                else {
                    temp+=s[j];
                }
            }
            res.push_back(temp);
        }

        return res;
    }
};
