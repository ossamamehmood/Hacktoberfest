#include <iostream>
using namespace std;
class ac
{
    char name[15];
    int acc_no;
    float bal;

public:
    void read()
    {
        cout << "\nenter the account name: ";
        cin >> name;
        cout << "\nenter the account number: ";
        cin >> acc_no;
        cout << "\nenter the balance: ";
        cin >> bal;
    }
    friend void show(ac);
};
void show(ac c)
{
    cout << "\nAccount name: " << c.name << "\nAccount number= " << c.acc_no << "\nBalance= " << c.bal;
}
int main()
{
    ac k;
    k.read();
    show(k);
    return 0;
}