#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int reverse(int x)
    {

        string s = to_string(x);

        string reversed;
        int start = s[0] == '-' ? 1 : 0;

        for (int i = s.length() - 1; i >= start; i--)
        {
            reversed += s[i];
        }

        try
        {
            return x >= 0 ? stoi(reversed) : -stoi(reversed);
        }
        catch (exception e)
        {
            return 0;
        }
    }
};

int main()
{
    // call the fn here

    return 0;
}