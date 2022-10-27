class Solution {
public:
    int reverse(int x) {
        if(x>=2147483647||x<=-2147483648){
            return 0;
        }
        long int ans=0;
        if(x>0){
            while(x>0){
            ans=ans*10;
            if(ans>=2147483647||ans<=-2147483648){
                return 0;
            }
            ans+=x%10;
            x=x/10;
            }
        }
        else{
            x=-1*x;
            while(x>0){
            ans=ans*10;
            if(ans>=2147483647||ans<=-2147483648){
                return 0;
            }
            ans+=x%10;
            x=x/10;
            }
            ans=-1*ans;
            
        }
        return ans;
        
    }
};