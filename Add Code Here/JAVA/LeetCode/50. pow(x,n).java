class Solution {
    public double myPow(double x, int n) {
        double ans = 1.0;
        long nn=n;
        if(nn<0) nn=(-1)*nn;
        long nul=0;
        while(nn!=nul){

            if(nn%2!=nul){
                ans*=x;
                nn-=1;
            }
            else{
                x*=x;
                nn=nn/2;
            }
        }
        if(n<0) ans=(double)(1.0)/(double)(ans);
        return ans;
    }
}

// class Solution {
    
//     public double pow(double x, int n){
//         if (n >= Integer.MAX_VALUE) return x;
//         else if (n <= Integer.MIN_VALUE) return (x == 1 || x == -1) ? 1 : 0;
        
//         if(n==0) return 1;
//         double halfX = pow(x, n/2);
//         double fullX = halfX * halfX;
        
//         if(n%2==1) fullX*=x;
        
//         return fullX;
//     }
    
//     public double myPow(double x, int n) {
        
//         if(n>0){
//             return pow(x,n);
//         }
        
//         else{
//             double a = 1;
//             int n0 = (-1)*n;
//             return a/pow(x,n0);
//         } 
            
//     }
// }
