#include<bits/stdc++.h>
using namespace std;

const int sz = 2;
const int mod = 1e9+7;

struct Mat{
    int m[sz][sz];

    Mat(){
        memset(m,0,sizeof(m));
    }
    void Identity(){
        for (int i = 0; i < sz; i++)
        {
            m[i][i] = 1;
        }
        
    }

    Mat operator* (Mat a){
        Mat res;
        for (int i = 0; i < sz; i++)
        {
            for (int j = 0; j < sz; j++)
            {
                for (int k = 0; k < sz; k++)
                {
                    res.m[i][j]+= m[i][k]*a.m[k][j];
                    res.m[i][j] %= mod;
                }
            }
        }
        return res;
    }
};

int Fib(int n){

    Mat T;
    T.m[0][0] = T.m[0][1] = T.m[1][0] = 1;

    Mat res;
    res.Identity();

    int x = n-2;
    while (x>0)
    {
        if(x&1){
            res= res *T;
        }

        T = T*T;
        x>>=1;

    }

    // res is T^(n-2) therefore answer =  res*F[2] , i.e.
    return (res.m[0][0] + res.m[0][1])%mod;
}

int main(int argc, char const *argv[])
{

    int n = 6;

    cout<<Fib(n)<<endl;
    return 0;

}