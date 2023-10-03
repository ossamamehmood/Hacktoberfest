/* Given a boolean expression S of length N with following symbols. 
Symbols 
'T' ---> true 
'F' ---> false 
and following operators filled between symbols 
Operators & ---> boolean AND 
| ---> boolean OR 
^ ---> boolean XOR 
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true. 
Note: The answer can be large, so return it with modulo 1003 */






// User function Template for C++

class Solution{
public:
    unordered_map<string, int> map;
    
    int solve(string &s, int i, int j, bool isTrue){
        if(i>j)    return 0;
        if(i==j){
            if(isTrue==true)    return s[i]=='T';
            else    return s[i]=='F';
        }
        
        string temp = to_string(i)+' '+to_string(j)+' '+to_string(isTrue);
        if(map.find(temp)!=map.end())   return map[temp];
        
        int ans = 0;
        for(int k=i;k<=j-2;k+=2){
            int lt = solve(s, i, k, true);
            int lf = solve(s, i, k, false);
            int rt = solve(s, k+2, j, true);
            int rf = solve(s, k+2, j, false);
            
            if(s[k+1]=='&'){
                if(isTrue)    ans += lt * rt;
                else    ans += lt * rf + lf * rt + lf * rf;
            }
            else if(s[k+1]=='|'){
                if(isTrue)    ans += lt * rt + lf * rt + lt *rf;
                else    ans += lf * rf;
            }
            else if(s[k+1]=='^'){
                if(isTrue)    ans += lf * rt + lt *rf;
                else    ans += lf * rf + lt * rt;
            }
        }
        return map[temp] = ans%1003;
    }

    int countWays(int n, string &s){
        map.clear();
        return solve(s, 0, n-1, true);