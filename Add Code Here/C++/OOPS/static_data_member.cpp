#include <iostream>
using namespace std;
class item
{
    int number;
    static int count;
public:
   static  void getdata(int i)
    {
        number = i;
        count++;
        number++;
    }
    void getcount()
    {
        cout << count;
    }
};
int item::count;
int main()
{
    item a, b, c;
    a.getcount();
    b.getcount();
    a.getdata(100);
    b.getdata(200);
    c.getdata(300);
    a.getcount();
    b.getcount();
    c.getcount();
    return 0;
}