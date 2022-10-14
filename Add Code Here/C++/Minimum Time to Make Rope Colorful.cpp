class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        char ch='*';
        int totalcost=0;
        int currcost=0;
        for(int i=0;i<colors.length();i++){
            // if our current char is same as previous
            if(colors[i]==ch){
                // checking which one is minimum and updating the value
                if(neededTime[i]>=currcost){
                    totalcost+=currcost;
                    ch=colors[i];
                    currcost=neededTime[i];
                }else{
                    totalcost+=neededTime[i];
                    ch=colors[i];
                }
            }else{
                // updating the values if both the character are not same 
                ch=colors[i];
                currcost=neededTime[i];
            }
        }
        return totalcost;
    }
};
