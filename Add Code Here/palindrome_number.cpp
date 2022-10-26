bool isPalindrome(int x) {
        int n =0;
        int tx = x;
        if(x<0) return false;
        string ans = "";
        while(tx){
            ans += tx%10 - '0';
            tx = tx/10;
        }
        int i = 0, j=ans.size()-1;
        while(i<j){
            if(ans[i]!=ans[j]){
                return false;
            }
            i++;j--;
        }
        return true;
    }
