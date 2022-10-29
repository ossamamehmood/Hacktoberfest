#include<bits/stdc++.h>
using namespace std;

int reverse(int a)
{
    int ans=0;
    while(a>0)
    {
        int ld=a%10;
        ans=ans*10+ld;
    }
}

int binaryToDecimal(int n)
{
    int ans=0;
    int x=1;
    while(n>0)
    {
        int y=n%10;
        ans += x*y;
        x*=2;
        n/= 10;
    }
    return ans;
}

int octalToDecimal(int n)
{
    int ans=0;
    int x=1;
    while(n>0)
    {
        int y=n%10;
        ans+=x*y;
        x*= 8;
        n /=10;
    }
    return ans;
}

int hexadecimalToDecimal(string n)
{
    int ans=0;
    int x=1;
    
    int s = n.size();
    for(int i=s-1; i>=0;i--)
    {
        if(n[i] >='0' && n[i] <='9')
        {
            ans+=x*(n[i]-'0');
        }
        else if(n[i] >= 'A' && n[i] <= 'F')
        {
            ans+=x*(n[i]-'A'+10); 
        }
        x*=16;
    }
    return ans;
}

int decimalToBinary(int n)
{
    int y=0;
    int x=1;
    while(n>0)
    {
        y+=(n%2)*x;
        n/=2;
        x*=10;
    }
    return y;
}

int decimalToOctal(int n)
{
    int y=0;
    int x=1;
    while(n>0)
    {
        y+=(n%8)*x;
        n/=8;
        x*=10;
    }
    return y;
}

string decimalToHexadecimal(int n)
{
    string ans="";
    int x=1;
    while(x<=n)
    {
        x *= 16;
    }
    x/=16;
    while(x>0)
    {
        int lastdigit=n/x;
        n -= lastdigit*x;
        x/=16;

        if(lastdigit <=9)
        {
            ans=ans+to_string(lastdigit);
        }
        else{
            char c='A' + lastdigit -10;
            ans.push_back(c);
        }
        return ans;
    }
}
int dtb(int n)
{
    int x=1;
    int ans=0; 
    while(x<=n)
    x*=2;
    x/=2;
    
    while(x>0)
    {
        int lastdigit = n/x;
        n-=lastdigit*x;
        x/=2;
        ans=ans*10+lastdigit;
    }
    return ans;
}
int dd(int a,int b)
{
    int c=0;
    int ans=0;
    while(a>0 && b>0)
    {
        if(a%2==0 && b%2==0)
        {
            ans=ans*10 + c;
            c=0;
        }else if((a%2==0 && b%2==1) || (a%2==1 && b%2==0))
        {
            if (c==0)
            {
                ans=ans*10+1;
                c=0;
            }
            else
            {
                ans=ans*10+0;
                c=1;
            }
            
        }
        else
        {
            if(c==0)
            {
                ans=ans*10+0;
                c=1;
            }
            else
            {
                ans=ans*10+1;
                c=1;
            }
            a/=10;
            b/=10;
        }
        while(a>0)
        {
            if (c==1){
                if(a%2==1){
                    ans=ans*10+0;
                    c=0;
                }else
                {
                    ans=ans*10+1;
                    c=0;
                }
            }
            else{
                ans=ans*10+(a%2);
                a/=10;
            }
        }
        while(b>0)
        {
            if (c==1){
                if(b%2==1){
                    ans=ans*10+0;
                    c=0;
                }else
                {
                    ans=ans*10+1;
                    c=0;
                }
            }
            else{
                ans=ans*10+(b%2);
                b/=10;
            }
        }
        if(c==1)
        ans = ans*10 +1;
        ans= reverse(ans);
    return ans;
    }

int32_t main()
{
    int a;
    int b;
    cin<<a<<b;
    cout<<dd(a,b)<<endl;

    return 0;
}