// This is overloading function where compiler automatically catch your input and give result 
#include<iostream>
#include<math.h>
using namespace std;
//Volume of cylinder
int vol(double r , int h)
{
    return 3.14*r*r*h;
}
//Volume of cube
int vol(int a)
{
    return a*a*a;
}
// Volume of cuboid
int vol(int l,int b,int h)
{
    return l*b*h;
}

int main(int argc, char const *argv[])
{
    cout<<"The volume of Cuboid is: "<<vol(3,5,75)<<endl;
    cout<<"The volume of Cylinder is: "<<vol(36,22)<<endl;
    cout<<"The volume of Cube is: "<<vol(658)<<endl;
    return 0;
}
