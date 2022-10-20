#include <iostream>
using namespace std;
int main()
{
    int rows = 96+14;
    int temp_no = 1;
    char alphabet;
    cout<<endl<<endl;
    cout<<endl<<endl;

    for (int i = 96; i < rows; i++)
    {
        for (int k = 0; k < 20; k++)
        {
            cout<<" ";
        }
        for (int k = i; k < rows; k++)
        {
            cout<<" ";
        }
        
        int count = 1;
        alphabet = i + 1;
        for (int j = 0; j < temp_no; j++)
        {
            if(count ==(temp_no / 2) + 2)
            {
                alphabet--;
            }
            if (count > (temp_no / 2) + 1)
            {
                alphabet--;
                cout<<alphabet;
            }
            else
            {
                cout << alphabet;
                alphabet++;
            }

            count++;
        }
        temp_no = temp_no + 2;
        cout << endl;
    }
    cout<<endl<<endl;
    cout<<endl<<endl;
    return 0;
}