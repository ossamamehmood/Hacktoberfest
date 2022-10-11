#include <iostream>
using namespace std;
class employee
{
    int id;
    static int count;

public:
    void setdata(void)
    {
        cout << "Enter id " << endl;
        cin >> id;
        count++;
    }
    void getdata()
    {
        cout << "The id is " << id << endl
             << "employee number is " << count << endl;
    }

    static void getcount()
    {
        cout << "the employee number is " << count << endl;
    }
};

int employee::count;
//  int employee::count=100;

int main()
{
    employee yash, ram, rishi;
    yash.setdata();
    yash.getdata();
    employee::getcount();

    ram.setdata();
    ram.getdata();
    employee::getcount();

    rishi.setdata();
    rishi.getdata();
    employee::getcount();

    return 0;
}