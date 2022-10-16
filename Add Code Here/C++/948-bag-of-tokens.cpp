class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int n=tokens.size();
        int l=0;
        int r=tokens.size();
        while(l<r)
        {
           if(power>=tokens[l])  // face up 
           {
               power=power-tokens[l];
               l++;
           }
            else if(l-(n-r) && r>l+1) // face down
            {
                                r--;

                power=power+tokens[r];
            }
            else
            {
                break;
}
}
        return l-(n-r);
    }
};
