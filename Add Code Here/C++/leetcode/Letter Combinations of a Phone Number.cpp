class Solution {
public:
    vector<string> answer;
    void solver(vector<string> numstr,string ans,string digit,int index){
       if(index==digit.size()){
           answer.push_back(ans);
           return;
       }
        // cout<<numstr[digit[index]]<<endl;
        int n=digit[index]-'0';
        for(int i=0;i<numstr[n].size();i++){
            solver(numstr,ans+numstr[n][i],digit,index+1);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return answer;
        vector<string> numstr={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string ans="";
        solver(numstr,ans,digits,0);
        return answer;
    }
};