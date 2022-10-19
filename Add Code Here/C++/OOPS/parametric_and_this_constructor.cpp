#include <iostream>
using namespace std;
class hero
{
    int roll;
    int batch;

public:
   // string name;
    hero()
    {
        cout << "constructor called" << endl;
    }
    hero(int roll)
    {
        this->roll=roll;
    }
    hero(int roll,int batch)
    {
        this->roll=roll;
        this->batch=batch;
    }
    void putalldata() 
    {
        cout<<"roll number :"<<roll<<endl;
        cout << "batch:"<<batch<<endl ;
    }
};
int main()
{
    hero h1;

    hero h2(23);

    hero h3(12,1);

    h1.putalldata();    // print "constructor called"
    h2.putalldata();    // batch garbadge
    h3.putalldata();

    return 0;
}