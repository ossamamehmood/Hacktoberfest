class Solution {
public:
    bool isUgly(int n) {
        if(n<1){
            return false;
        }
        vector<int>primes;
        primes.push_back(2);
        primes.push_back(3);
        primes.push_back(5);
        for(auto i:primes){
            while(n%i==0){
                n/=i;
            }    
        }
        if(n==1)
            return true;
        else
        return false;
    }
};