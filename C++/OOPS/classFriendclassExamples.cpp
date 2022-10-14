//                Example 1 --> sum of private dataof classes

// #include<iostream>
// using namespace std;
// class Y;
// class X
// {
//     int data;
//     friend void add (X , Y);
//     public:
//     void setdata(int value)
//     {
//         data = value;
//     }
// };
// class Y
// {
//     int valv;
//     friend void add (X , Y);
//     public:
//     void setdata(int num)
//     {
//         valv = num;
//     }
// };

// void add(X a1 , Y b1)
// {
//     cout<<"Sum of private data of class X have value "<<a1.data<<" and class Y have value "<<b1.valv<<" is : "<<a1.data + b1.valv;
// }
// int main()
// {
//     X n1;
//     n1.setdata(56);
//     Y n2;
//     n2.setdata(78);
//     add(n1 , n2);

//     return 0;
// }
//              Example-2 -->   swapping of value of private data
#include <iostream>
using namespace std;
class c2;
class c1
{
    int value1;
    friend void exchange(c1 &, c2 &);

public:
    void indata(int n1)
    {
        value1 = n1;
    }
    void display()
    {
        cout << value1 << endl;
    }
};
class c2
{
    int value2;
    friend void exchange(c1 &, c2 &);

public:
    void indata(int n2)
    {
        value2 = n2;
    }
    void display()
    {
        cout << value2 << endl;
    }
};
void exchange(c1 &x, c2 &y)
{
    int swap;
    swap = x.value1;
    x.value1 = y.value2;
    y.value2 = swap;
}

int main()
{
    c1 m;
    c2 n;
    m.indata(25);
    m.display();
    n.indata(58);
    n.display();
    exchange(m, n);
    cout << "value of c1 after exchanging becomes is : ";
    m.display();
    cout << "value of c2 after exchanging becomes is : ";
    n.display();
    return 0;
}