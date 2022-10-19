#include<iostream>
using namespace std;
int main()
{
    intnum, temp, noOfDigit=0, res=0, rem, pow, i;
    cout<<"Enter the Number: ";
    cin>>num;
    temp = num;
    while(num>0)
    {
        num = num/10;
        noOfDigit++;
    }
    num = temp;
    while(num>0)
    {
        rem = num%10;
        pow = 1;
        i = 0;
        while(i<noOfDigit)
        {
            pow = pow*rem;
            i++;
        }
        res = res + pow;
        num = num/10;
    }
    if(res==temp)
        cout<<"\nIt is an Armstrong Number";
    else
        cout<<"\nIt is not an Armstrong Number";
    cout<<endl;
    return 0;
}
