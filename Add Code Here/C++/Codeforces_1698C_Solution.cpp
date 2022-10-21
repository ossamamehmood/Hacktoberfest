#include<iostream>
#include<math.h>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include <cstring>
#include <limits.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int j=0;j<n;j++){
            cin>>arr[j];
        }
        int neg=0;   
        int pos=0;
        int count0=0;
        ll sum=0;
        for(int j=0;j<n;j++){
            sum+=arr[j];
            if(arr[j]>0){
                pos++;     //count of positive numbers in the array
            }
            else if(arr[j]<0){
                neg++;     //count of negative numbers in the array
            }
            else{
                count0++;  //count of zeroes in the array
            }
        }
        //If we have more than 3 positive or negative numbers, the final sum would be greater
        //than maximum of the three numbers, which will not be a part of the array.
        //For eg : 1,2,3,4 -- if we choose 2+3+4, (i.e the largest positive/negative number along with two others)
        // the value will be larger than the largest number itself, which is not part of array. So, not 3Sum closed.

        if(neg>=3 || pos>=3 ||(pos==2 && count0>0) ||(neg==2 && count0>0)){
            cout<<"NO"<<endl;
        }
        //If there are all zeroes OR 1 negative number and others zero OR 1 positive number and others zero
        //Answer is a YES. 
        else if(count0==n || (count0==n-1 && neg==1) ||(count0==n-1 && pos==1)){
            cout<<"YES"<<endl;
        }
        else{
            //else, if we have one neg and one pos, we will have to check if the pos+neg==0 or not.

            if(count0==n-2 && neg==1 && pos==1){
                for(int j=0;j<n;j++){
               if(arr[j]>0){
                pos=arr[j];
            }
               else if(arr[j]<0){
                neg=arr[j];
            }
               
        }
        if(neg==-pos){
            cout<<"YES"<<endl;
        }

        else{
            cout<<"NO"<<endl;
        }


            }
            //else,in the absence of zero, we will have to check separately for all numbers given.
            else if(count0==0){
                int flag=-1;
                map<int,int> m;
                for(int j=0;j<n;j++){
                    m[arr[j]]++;
                }
                for(int j=0;j<n;j++){
                    for(int q=j+1;q<n;q++){
                        for(int k=q+1;k<n;k++){
                            if(m[arr[j]+arr[q]+arr[k]]==0){
                                flag=0;
                                break;
                            }
                        }
                    }
                }
                if(flag==0){
                    cout<<"NO"<<endl;
                }
                else{
                    cout<<"YES"<<endl;
                }

                
                
            }
            else{
                cout<<"NO"<<endl;
            }
            
        }

    }
}
        
 



    
