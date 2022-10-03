#include<iostream>
#include<string>
using namespace std;

void primesieve(int n){
    int arr[n] = {0};
    for(int i=2; i<=n; i++){
        if(arr[i]==0){
            for(int j=i*i; j<=n;j+=i){
                arr[j] = 1;

            }
        }
    }
    for(int i=2; i<=n; i++){
        if(arr[i]== 0 ){
            cout << i << endl;
        }
    }
}

// void primesieve(int n ){
//     int prime[n] = {0} ;
//     int i , j ;
//     for (i = 2; i <= n; i++)
//     {   if (prime[i] == 0)
//         {
//             for(j = i*i ; j<= n ; j+=i){
//                 prime[j] = 1;
//             }
//         }    
//     }

//     for ( i = 2; i <= n; i++)
//     {
//         if (prime[i] == 0)
//         {
//             cout<<i<<" " ;
//         }
        
//     }
    
// }
int main(){
    /////////////////////////////////            1 IS NOT A PRIME NUMBER           /////////////////////////////////
    int n ;
    cout<<"ENTER THE NUMBER : ";
    cin>>n;
    cout<<" ALL PRIME NUMBERS ARE : ";
    primesieve(n);
    return 0 ;
}