#include <iostream>
using namespace std;

int Validity_Checker(int a,int b,int c)
{
    if(((a+b)>c) && ((b+c)>a) && ((c+a)>b))
    {
        if((a == b)&&(b == c)&&(c == a))
            return 3;
        
        else if((a == b)||(b == c)||(c == a))
            return 2;
        
        else
            return 1;
    }

    else
        return 0;
}
int main()
{
    int a,b,c;
    cout<<"Enter the sides of the triangle here ";
    cin>>a>>b>>c;

    int check = Validity_Checker(a,b,c);

    switch(check)
    {
        case 3:
            cout<<"Hola!! It is an Equilateral Triangle"<<endl;
            break;
        
        case 2:
            cout<<"Hola!! It is an Isosceles Triangle"<<endl;
            break;
        
        case 1:
            cout<<"Hola!! It is an Scalene Triangle"<<endl;
            break;
        
        case 0:
            cout<<"It is an Invalid Triangle"<<endl;
            break;
    }

    return 0;

}