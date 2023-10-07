//Palindrome Number :- If the reversed integer is equal to the integer entered by user then, 
//that number is a palindrome if not that number is not a palindrome.

// Enter a positive number: 12321
// The reverse of the number is: 12321
// The number is a palindrome.

// Enter a positive number: 12331
// The reverse of the number is: 13321
// The number is not a palindrome.



#include <iostream>
using namespace std;

int main()
{
     int n, num, digit, rev = 0;

     cout << "Enter a positive number: ";
     cin >> num;

     n = num;

     do
     {
         digit = num % 10;
         rev = (rev * 10) + digit;
         num = num / 10;
     } while (num != 0);

     cout << " The reverse of the number is: " << rev << endl;

     if (n == rev)
         cout << " The number is a palindrome.";
     else
         cout << " The number is not a palindrome.";

    return 0;
}
