class Solution {
public:
    int nthUglyNumber(int n) {
        vector <int> prime(1,1) ;
        int i=0,j=0,k=0;
        while(prime.size()<n){
            prime.push_back(min(prime[i]*2,min(prime[j]*3,prime[k]*5)));
            if(prime.back()%2==0){
                i++;
            }
            if(prime.back()%3==0){
                j++;
            }
            if(prime.back()%5==0){
                k++;
            }
        }
        return prime[n-1];
    }
};