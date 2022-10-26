// C++ implementation of the approach
#include <iostream>
using namespace std;
 
// Function that returns true if the queen
// can attack the opponent
bool canQueenAttack(int qR, int qC, int oR, int oC)
{
    // If queen and the opponent are in the same row
    if (qR == oR)
        return true;
 
    // If queen and the opponent are in the same column
    if (qC == oC)
        return true;
 
    // If queen can attack diagonally
    if (abs(qR - oR) == abs(qC - oC))
        return true;
 
    // Opponent is safe
    return false;
}
 
// Driver code
int main()
{
    int qR = 1, qC = 1;
    int oR = 3, oC = 2;
    if (canQueenAttack(qR, qC, oR, oC))
        cout << "Yes";
    else
        cout << "No";
 
    return 0;
}
