#include <iostream>
using namespace std;

// Complement of Base 10 Integer

class Solution
{
public:
    int Complement(int num)
    {
        int temp = num;
        int mask = 0;

        //exceptional case
        if (temp == 0)
        {
            return 1;
        }

        while (temp != 0)
        {
            mask = (mask << 1) | 1;
            temp = temp >> 1;
        }

        int answer = (~num) & mask;
        return answer;
    }
};

int main()
{
    int num;
    cout << "enter number: ";
    cin >> num;

    Solution answer;
    cout << "Complement of " << num << " is: " << answer.Complement(num);
}