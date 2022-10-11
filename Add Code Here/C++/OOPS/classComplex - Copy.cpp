// #include<iostream>
// using namespace std;
// class employee
// {
//     int id;
//     public:
//     void setdata()
//     {
//         cout<<"Enter the id of employee"<<endl;
//         cin>>id;
//     }
//     void getdata()
//     {
//         cout<<"The id of employee is "<<id<<endl;
//     }
// };
// int main()
// {
//     employee f[3];
//     for(int i=0 ; i<3; i++)
//     {
//         f[i].setdata();
//         f[i].getdata();
//     }

//     return 0;
// }
#include <iostream>
using namespace std;

class complex
{
    int a, b;

public:
    void setdata(int v1, int v2)
    {
        a = v1;
        b = v2;
    }
    void setbysum(complex o1, complex o2)
    {
        a = o1.a + o2.a;
        b = o1.b + o2.b;
    }
    void display()
    {
        cout << "Your complex number is " << a << " + " << b << "i" << endl;
    }
};
int main()
{
    complex c1, c2, c3;
    c1.setdata(5, 3);
    c1.display();

    c2.setdata(2, 3);
    c2.display();

    c3.setbysum(c1, c2); // passsing objects as function arguments
    c3.display();

    return 0;
}