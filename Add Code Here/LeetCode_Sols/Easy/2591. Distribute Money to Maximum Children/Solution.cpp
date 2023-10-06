class Solution {
public:
    int distMoney(int money, int children) {
        if(money < children) return -1;
        
        money -= children; //Distributing one coin to each children
        int ans = money/7; // only 7 coins left to make it 8 hence divide to by 7 to get the number of children with 8 coins

        // If number of children with 8 coins i.e ans is more than the given children then we can simply give all the remaining coins to one child and rest will have 8 coins hence returning children - 1;
        if(ans > children) return children - 1;
        
        int remaning = money%7;
        children -= ans;
        if((remaning > 0 && children == 0) || 
            (remaning == 3 && children == 1)) return ans - 1;
        return ans;
    }
};
