class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int count_flip = 0, count_one = 0;
        for (auto i : s){ 
            //keep track of all one (we will use count_one in else condition if we need)  
            //if we want flip one into 0
            if (i == '1') count_one++;
            else{
                count_flip++;
                count_flip = min(count_flip, count_one);
            }
        }
        return count_flip;
    }
};
