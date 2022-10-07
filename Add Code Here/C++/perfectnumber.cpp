#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    int i = 1, u = 1, sum = 0;
    while (i <= 500)
    {
        while (u <= 500)
        {
            if (u < i)
            {
                if (i % u == 0)
                {
                    sum = sum + u;
                }
            }
            u++;
        }
        if (sum == i)
        {
            cout << i << " is a perfect number" << endl;
        }
        i++;
        u = 1;
        sum = 0;
    }
    getch();
}