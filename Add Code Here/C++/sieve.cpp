#include<bits/stdc++.h>
using namespace std;

//for finding prime factor
void primeFactor(int n){
    int spf[100]={0};
    //smallest prime factor
    for(int i=2; i<=n; i++){
        spf[i]=i;
    }
    for(int i=2; i<=n; i++){
        if(spf[i]==i){
            for(int j=i*i; j<=n; j+=i){
                if(spf[j]=j){
                    spf[j]=i;
                }
            }
        }
    }
    while(n!=1){
        cout<<spf[n]<<" ";
        n = n/spf[n];
    }
}

//for finding prime no b/w a range
// void prime(int n){
//     int prime[100]={0};
//     for(int i=2; i<=n; i++){
//         if(prime[i]==0){
//             for(int j=i*i; j<=n; j+=i){
//                 prime[j]=1;
//             }
//         }
//     }
//     for(int i=2; i<=n; i++){
//         if(prime[i]==0){
//             cout<<i<<" ";
//         }
//     }
//     cout<<endl;
// }

int main(){
    
    int num;
    cin>>num;
    primeFactor(num);

    return 0;
}
