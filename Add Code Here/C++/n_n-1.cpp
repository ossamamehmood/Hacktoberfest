// This program is basically used to calculate the number of set bits(i.e. 1) in given decimal number

#include<iostream>
using namespace std;

int main()
{
    int num, original, count = 0; 
    cout<<"Enter the number: ";        // Decimal number is entered
    cin>>num;
    original = num;                    // Here num is copied to original to retrieve the original number after calculation
    while(num>0)
    {
        num = num & (num - 1);          // Main logic here
        count++;                       // After each iteration count is incremented by 1
    }
    cout<<"Number of set bits in "<<original<<" is: " << count;
}

// Explaination
// Let us suppose we have entered 5
// Now we get into the loop
// num = 5 (0101)
// num - 1 = 4 (0100)
// After first iteration we assign num & (num - 1) value back to num
// which basically is    0101
//                     & 0100
//                     -------
//                       0100   --> 4
// we then increase the count value to 1
// In second iteration, 
// num = 4
// num - 1 = 3
// Therefore, num = 4 & 3
// i.e.                0100
//                   & 0011
//                   -------
//                     0000
// At this point num gets 0
// We increment the count value to 2

// Now, when we again check the while loop condition it will turn out to be false and we get out of the lexicographical_compare

// Thank You!
                    
