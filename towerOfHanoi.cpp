#include <iostream>
using namespace std;
  
void towerOfHanoi(int n, char from_rod, char to_rod,
                  char aux_rod)
{
    if (n == 0) {
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    cout << "Move disk " << n << " from rod " << from_rod
         << " to rod " << to_rod << endl;
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}
  
// Driver code
int main()
{
    // N : number of disks
    int N = 5;
  
    // A, B and C are names of rods
    towerOfHanoi(N, 'A', 'C', 'B');
    return 0;
}
