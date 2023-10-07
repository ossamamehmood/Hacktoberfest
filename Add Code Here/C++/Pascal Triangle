#include <iostream>
using namespace std;

int main()
{
    int r, c = 1;

    cout << "Number of rows: ";
    cin >> r;

    for(int i = 0; i < r; i++)
    {
        for(int space = 1; space <= r-i; space++)
            cout <<"  ";

        for(int j = 0; j <= i; j++)
        {
            if (j == 0 || i == 0)
                c = 1;
            else
                c = c*(i-j+1)/j;

            cout << c << "   ";
        }
        cout << endl;
    }

    return 0;
}
