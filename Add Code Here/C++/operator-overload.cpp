#include<iostream>
using namespace std;
class ComplexNumbers
{
    double realNumber ;
    double imaginaryNumber ;
    public:
    ComplexNumbers()
    {
        realNumber = imaginaryNumber = 0 ;
    }
    ComplexNumbers(double realNumber)
    {
        this->realNumber = realNumber ;
        imaginaryNumber = 0 ;
    }
    ComplexNumbers(double realNumber , double imaginaryNumber)
    {
        this->realNumber = realNumber ;
        this->imaginaryNumber = imaginaryNumber ;
    }
    ComplexNumbers(const ComplexNumbers & obj)
    {
        realNumber = obj.realNumber ;
        imaginaryNumber = obj.imaginaryNumber ;
    }
    void print()
    {
        if(this->imaginaryNumber > 0)
        {
            cout<<this->realNumber<<"+"<<this->imaginaryNumber<<"i"<<endl;
        }
        else
        {
            cout<<this->realNumber<<this->imaginaryNumber<<"i"<<endl;
        }
    }
    void setReal(double realNumber)
    {
        this->realNumber=realNumber;
    }
    void setImg(double imaginaryNumber)
    {
        this->imaginaryNumber=imaginaryNumber;
    }
    double getReal()
    {
        return this->realNumber;
    }
    double getImg()
    {
        return this->imaginaryNumber;
    }
    friend ComplexNumbers operator + (ComplexNumbers c1,ComplexNumbers c2);
    friend ComplexNumbers operator - (ComplexNumbers c1,ComplexNumbers c2);
    friend ComplexNumbers operator * (ComplexNumbers c1,ComplexNumbers c2);
    friend ComplexNumbers operator / (ComplexNumbers c1,ComplexNumbers c2);
};
ComplexNumbers operator + (ComplexNumbers c1,ComplexNumbers c2)
{
    ComplexNumbers C1;

    C1.realNumber=c1.realNumber+c2.realNumber;
    C1.imaginaryNumber=c1.imaginaryNumber+c2.imaginaryNumber;
    return C1;
}
ComplexNumbers operator - (ComplexNumbers c1,ComplexNumbers c2)
{
    ComplexNumbers C1;
    C1.realNumber=c1.realNumber-c2.realNumber;
    C1.imaginaryNumber=c1.imaginaryNumber-c2.imaginaryNumber;
    return C1;
}
ComplexNumbers operator / (ComplexNumbers c1,ComplexNumbers c2)
{
    ComplexNumbers C1;
    double temp1=c1.realNumber*c2.realNumber;               // real number one 
    double temp2=c1.imaginaryNumber*c2.imaginaryNumber;           // real number two by formula of divsion
    double temp3=c1.realNumber*c2.imaginaryNumber;           //imaginary number one
    double temp4=c1.imaginaryNumber*c2.realNumber;
    double real=temp1+temp2;
    double imag=(-1)*c2.imaginaryNumber;
    double temp5=c2.realNumber*c2.realNumber;
    double temp8=c2.imaginaryNumber*imag;
    double realNum=temp5-temp8;
    temp4=(-1)*temp4;
    double imaginary=temp3-temp4;
    C1.realNumber=(real)/realNum;
    C1.imaginaryNumber=(imaginary)/realNum;
    return C1;
}
ComplexNumbers operator * (ComplexNumbers c1, ComplexNumbers c2)
{
    ComplexNumbers C1;
    double temp=c1.realNumber*c2.realNumber;
    double temp2=c1.realNumber*c2.imaginaryNumber;
    double temp3=c1.imaginaryNumber*c2.realNumber;
    double temp4=c1.imaginaryNumber*c2.imaginaryNumber;
    temp4=(-1)*temp4;
    C1.imaginaryNumber=temp2+temp3;
    C1.realNumber=temp+temp4;
    return C1;
}
int main()
{
    ComplexNumbers complex1,complex2,complex3;
    
    double realNumber1,realNumber2,imaginaryNumber1,imaginaryNumber2;
    cout<<"Enter first real Numbers and complex number: ";
    cin>>realNumber1>>imaginaryNumber1;
    cout<<"Enter 2nd real Numbers: and complex number: ";
    cin>>realNumber2>>imaginaryNumber2;
    complex1=new ComplexNumbers(12.122);
    complex1.setReal(realNumber1);
    complex1.setImg(imaginaryNumber1);
    complex2.setReal(realNumber2);
    complex2.setImg(imaginaryNumber2);
    complex3=complex1+complex2;
    complex3.print();
    complex3=complex1-complex2;
    complex3.print();
    complex3=complex1*complex2;
    complex3.print();
    complex3=complex1/complex2;
    complex3.print();
}