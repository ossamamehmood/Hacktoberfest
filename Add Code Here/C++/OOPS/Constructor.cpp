#include <iostream>
using namespace std;
class hero
{
    int roll;
public:
char batch;
    string name;
    hero()
    {
        cout << "constructor called" << endl;
    }
    hero(hero &x)             //copy constructor
    {
        roll=x.roll;
        batch=x.batch;
    }
    void getdata(int x,int y)    //parAmetric constroctor
    {
        this->roll=x;
        this->batch=y;
    }
    ~hero()
    {
        
    }
    void showdata()
    {
        cout<<this->roll <<endl;
        cout<<this->batch<<endl;
    }
};
int main()
{
    hero h1;
    hero h2;
    h2.getdata(23,'b');
    hero h3(h2);
    h3.showdata();
    h2.batch='a';
    h2.showdata();
    return 0;
}