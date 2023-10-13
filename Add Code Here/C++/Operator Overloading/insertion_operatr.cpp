#include <iostream>
using namespace std;
class Rational
{
public:
    int p, q;
    Rational(int p = 0, int q = 0)
    {
        this->p = p;
        this->q = q;
    }
    void display()
    {
        cout << "The no. is " << p << " + " << q << "i" << endl;
    }
    Rational operator+(Rational r){
        Rational r3;
        r3.p = this->p * r.q + this->q * r.p;
        r3.q = r.q * this->q;
        return r3;
    }
    
    friend ostream & operator<<(ostream & out, Rational & c);
};
ostream & operator<<(ostream &out, Rational &c)
    {
        out  << c.p << "/" << c.q << " ";
        // return out;
    }
int main()
{
    Rational C1(1,2), C2(3,4), C3;
    C3 = C1 + C2;
cout<< "The sum of " << C1 << " and " << C2 << " is " << C3;

    return 0;
}