#include <iostream>
using namespace std;
class shop
{
    int itemid[100];
    int itemprice[100];
    int i = 0;

public:
    // void iinitiaizer(){i=0;}
    void setprice();
    void displayitem(void);
};
void shop::setprice()
{
    cout << "Enter item id at " << i + 1 << " index." << endl;
    cin >> itemid[i];
    cout << "Enter item price at " << i + 1 << " index." << endl;
    cin >> itemprice[i];
    i++;
}
void shop::displayitem()
{
    for (int j = 0; j < i; j++)
    {
        cout << "The price of item id " << itemid[j] << " is " << itemprice[j] << endl;
    }
}
int main()
{
    shop yash;
    //    yash.iinitiaizer();
    yash.setprice();
    yash.setprice();
    yash.displayitem();
    return 0;
}