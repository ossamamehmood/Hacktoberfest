class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int result=0;
        map<char,int> mp1;
        for(const auto&it:chars) mp1[it]++;
        
        for(const auto&it:words){
            bool flag=1;
            map<char,int> mp2;
            for(const auto&itr:it) mp2[itr]++;

            if(mp2.size()>mp1.size()){
                continue;
                mp2.clear();
            }
            for(const auto&it:mp2){

                if(mp1[it.first] < it.second) {
                    flag=0;
                }
            }
            if(flag) result+=it.size();
            mp2.clear();
        }
        return result;
    }
};
