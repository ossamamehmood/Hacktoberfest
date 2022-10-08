#include <iostream>
#include <string.h>
using namespace std;
class binary
{
private:
    string s;

public:
    void read();
    void chk_binary();
    void one_complement();
    void display_binary();
};

void binary ::read(void)
{
    cout << "Enter any string to check binary " << endl;
    cin >> s;
}

void binary::chk_binary(void)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) != '0' && s.at(i) != '1')
        {
            cout << "Incorrect binary format";
            exit(0);
        }
    }
}

void binary::one_complement(void)
{
    chk_binary(); // nasting of member functions
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) == '0')
        {
            s.at(i) = '1';
        }
        else
        {
            s.at(i) = '0';
        }
    }
}

void binary::display_binary(void)
{
    cout << "" << s;
    cout << endl;
}

int main()
{
    binary yash;
    yash.read();
    //yash.chk_binary();
    yash.one_complement();
    cout << "After one's complement of binary number" << endl;
    yash.display_binary();
    return 0;
}