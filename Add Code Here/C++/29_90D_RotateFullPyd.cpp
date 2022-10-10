// * 
// * *
// * * *
// * * 
// * 
#include<iostream>
using namespace std;
int main()
{
    int n,a, flag=1;
    cout << "\nEnter number of columns: ";
    cin >> n;
    for(int r=1; r<=2*n-1; r++)
    {
        for(int c=1; c<=n; c++)
        {
            if(c<=r && c<=n && flag==1)    {
                cout << "* ";
                if(c==n)    {
                    a = n;
                    flag=0;
                }
            }
            else if(r>n && c<=a)    {
                cout << "* ";
            }
            else
            cout << "  ";
        }
        a--;
        cout << endl;
    }
}