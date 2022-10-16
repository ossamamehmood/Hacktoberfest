#include<iostream>
#include<cmath>
using namespace std;
class student29
{
    public:
    long int key;
    int partsize;
    void folding();
    void truncation();
    int hashSize;
    void moduloArithmetic();
};
void student29 :: folding()
{
    int a,b=0,i,sum=0,p;
    cout<<"Enter key: ";
    cin>>key;
    cout<<"Enter partition size of the key: ";
    cin>>partsize;
    a=key;
    while(a>0)
    {
       a=a/10;
       b++;
    }
    
    if(b%partsize!=0)
    cout<<"Hashing is not possible as the size given does not divide the key into equal parts ";
    else
    { 
    for(i=0;i<b/partsize;i++)
    {
       p=(int)pow(10,partsize);
       sum += key%p;
       key = key/p;
    }
    cout<<"The hash value is "<<sum%100;
    }
}
void student29 :: truncation()
{
    int position1, position2,count=0,n,i,a,rev=0;
    cout<<"Enter key: ";
    cin>>key;
    cout<<"Enter two positions: ";
    cin>>position1>>position2;
    n=key;
    while(n>0)
    {
        a=n%10;
        rev= rev*10 + a;
        n=n/10;
        count++;
    }
    if(position1>count||position2>count)
    cout<<"The position taken is more than the number of digits in the key";
    else
    {  
    n=rev;
    n=rev/(int)pow(10,position1-1);
    n=n%10;
    rev=rev/(int)pow(10,position2-1);
    rev=rev%10;
    cout<<"Hash value is "<<n*10+rev;
    }
}
void student29 :: moduloArithmetic()
{
    cout<<"Enter key: ";
    cin>>key;
    cout<<"Enter size of Hash Table: ";
    cin>>hashSize;
    cout<<"Key is stored in location "<<key%hashSize<<" of Hash Table";
}
int main()
{
    int choice;
    student29 a;
    cout<<"Choose\n1.Folding\n2.Truncation\n3.Modulo Arithmetic\n";
    cin>>choice;
    switch(choice)
    {
        case 1 : a.folding();
                  break;
        case 2: a.truncation();
                 break;
        case 3: a.moduloArithmetic();
                  break;
        default: cout<<"Enter correct choice";
    }
}