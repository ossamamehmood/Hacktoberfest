#include <iostream>
using namespace std;

char words[][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
void convert(int n)
{
    if(n==0)
    return;
    else
    {
        convert(n/10);
        int digit=n%10;
        cout<<words[digit]<<" ";
    }
}

int main() {
   int n;
   cin>>n;

   convert(n);
}
