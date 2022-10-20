#include <iostream>
using namespace std;
class complex
{
    double real;
    double img;

    public:
        void input(double x,double y)
        {
            real=x;
            img=y;
        }
        void show()
        {
            cout<<real<<"+"<<img<<"i"<<endl;
        }   
      friend complex sum(complex,complex);     
};

complex sum(complex x,complex y)
{
    complex c3;
    c3.real=x.real+y.real;
    c3.img=x.img+y.img;
    return c3;
}
int main()
{
    complex c1,c2,c3;
    c1.input(45,1);
    c2.input(11,6);
    c1.show();
    c2.show();
    c3=sum(c1,c2);
    c3.show();
    return 0;
}