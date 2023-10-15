class Solution {
public:
    int climbStairs(int n) {
        if(n<=2){
            return n;
        }
        else{
            int a=1,b=2,next;
            for(int i=3;i<=n;i++){
                next=a+b;
                a=b;
                b=next;
            }
            return next;
        }

    }
};