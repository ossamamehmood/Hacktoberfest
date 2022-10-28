//Name: Mahrukh khan
//Username: Suga7772
//Favorite Language: Java

#include<iostream>
using namespace std;

int countDigits(int n)
{
    if ((-10 < n) && (n < 10))
        return 1;
    else
    {
        return 1 + countDigits(n / 10);
    }
}

int main()
{
    int n;
    do
    {
        cout << "1. Enter digit "<<endl;
        cout << "2. Quit "<<endl;
        cin >> n;

        switch (n)
        {
        case 1:
            int num;
            cout << "Enter a number to count digits: ";
            cin >> num;
            cout << "Number of digits in " << num << " is " << countDigits(num) << endl;;
            break;
        case 2:
            cout << "Program terminated" << endl;
            break;
        default:
            cout << "Invalid input" << endl;
        }
    } while (n != 2);
    return 0;
}