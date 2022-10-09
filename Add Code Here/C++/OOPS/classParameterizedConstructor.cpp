#include <iostream>
using namespace std;
class complex
{
    int a, b;

public:
    complex(int x, int y)
    {
        a = x;
        b = y;
    }
    void displaynumber()
    {
        cout << "complex number is " << a << " + " << b << "i" << endl;
    }
};
int main()
{
    //implicit call
    complex z(5, 7);
    z.displaynumber();
    //explicit call
    complex m = complex(7, 8);
    m.displaynumber();
    return 0;
}
//           Example--> 1 - print a point with the help of consructor
// #include<iostream>
// using namespace std;
// class point
// {
//    int x, y;
//    public:
//    point(int m , int n)
//    {
//        x = m;
//        y = n;
//    }
//    void displaypoint()
//    {
//        cout<<"point is ("<<x<<" , "<<y<<")"<<endl;
//    }
// };
// int main()
// {
//     point p(4,6);
//     p.displaypoint();
//     point q(7,8);
//     q.displaypoint();
//     point r(1,2);
//     r.displaypoint();

//     return 0;
// }
//           Example--> 2 - print the distance between two cartesian points:
// #include<iostream>
// #include<math.h>
// using namespace std;
// class point
// {
//    int x, y;
//    friend class Distance;
//    public:
//    point(int m , int n)
//    {
//        x = m;
//        y = n;
//    }
//    void displaypoint()
//    {
//        cout<<"point is ("<<x<<" , "<<y<<")"<<endl;
//    }
// };
// class Distance
// {
//     float k;
//     public:
//      void cartesiandistance(point a, point b)
//      {
//         k = sqrt((b.y - a.y)*(b.y - a.y) + (b.x - a.x)*(b.x - a.x)) ;
//      }
//      void printdistance()
//      {
//          cout<<"distance is "<<k<<" units...";
//      }
// };
// int main()
// {
//    int x1,x2,y1,y2;
//    cout<<"Enter coordinates of first cartesian point "<<endl;
//    cin>>x1>>y1;
//    cout<<"Enter coordinates of second cartesian point "<<endl;
//    cin>>x2>>y2;
//     point p(x1,y1);
//     p.displaypoint();
//     point q(x2,y2);
//     q.displaypoint();
//     Distance z;
//     z.cartesiandistance(p,q);
//     z.printdistance();
//     return 0;
// }

//             Example -->2 Alternative
// #include<iostream>
// #include<math.h>
// using namespace std;
// class point
//{
// int x;
// int y;
// public :
//     friend void difference(point , point);
//     point(int a, int b){
//     x=a;
//     y=b;
//     }
//     void displaypoint(){
//     cout<<"The point is : ("<<x<<","<<y<<")"<<endl;
//     }
// };
// void difference(point o1, point o2)
//{
// int x_diff=o2.x-o1.x;
// int y_diff=o2.y-o1.y;
// double dist = sqrt((x_diff)*(x_diff) + (y_diff)*(y_diff));
// cout<<"Distance is :"<<dist<<" units";
// }
// int main()
// {
// point p1(1,2),p2(4,3);
// p1.displaypoint();
// p2.displaypoint();
// cout<<endl<<endl;
// difference(p1,p2);
// return 0;
// }