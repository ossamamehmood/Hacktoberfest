#include<iostream>
using namespace std;
int factorial(int n)
{  
    if(n<0)
       return 0;
    else if (n==0)
        return 1;
    else 
      return n*factorial(n-1);
}

int main()
{  
    int n;
    int e;
    cout<<"enter number of rows = ";
    cin>>n;
    for(int r=1;r<=n;r++)
    {   
        for(int k=1;k<=(n-r);k++)
        cout<<" ";
            for(int c=1;c<=r;c++)
            {
                e = factorial(r-1) / (factorial(c-1)*factorial(r-c));
                cout<<e<<" ";
            }
            cout<<endl;
    } 
}