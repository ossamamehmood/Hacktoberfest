// WAP to calculate simple earned interest by using objects, classes and access operator (i.e. outside class definition)
#include <iostream>
using namespace std;

class SI
{
    private:
        int p, n, r, si;
    public:
        void getDetails();
        void calculate();
};

void SI::getDetails()
{
    cout << "Enter principal: ";
    cin >> p;
    cout << "Enter number of years: ";
    cin >> n;
    cout << "Enter rate of interest: ";
    cin >> r;
}

void SI::calculate()
{
    si = p*(1+(r/100)*n);
    cout << si;
}

int main()
{
    SI s;
    s.getDetails();
    printf("\nSimple Interest: ");
    s.calculate();
}