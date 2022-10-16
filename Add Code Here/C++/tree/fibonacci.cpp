#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int n,n1=0,n2=1,n3,i;
    cin >> n;
    
    for(i=0;i<n;i++){
        cout<<n1<<endl;
        n3=n1+n2;
        n1=n2;
        n2=n3;
    }
    return 0;
    
    
}