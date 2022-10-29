#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter a number. \n";
    cin>>n;

    float sum=0,lastdigit;
    int orignaln=n;
    while(n>0){
        lastdigit= n%10;
        sum+= pow(lastdigit,3);
        n=n/10;
    }  
    
    if(sum==orignaln){
        cout<<"Armstrong number."<<endl;
    }
    else{
        cout<<"Not Armstrong."<<endl;
    }
    cout<<sum<<endl<<lastdigit;
    return 0;
}