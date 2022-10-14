/*
https://leetcode.com/problems/reverse-integer/ 
*/

class Solution {
public:
    int reverse(int X) {
        string x = to_string(X);
        bool negative = x[0] == '-';
        int index = negative?1:0;
        string ans = negative?"-":"";
        for(int i=x.length()-1; i>=index;--i)
            ans.push_back(x[i]);
        try{
            return stoi(ans);
        }
        catch(exception &e){
            return 0;
        }
        
    }
};

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};