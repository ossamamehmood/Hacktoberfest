#include <iostream>
using namespace std;
  
int main()
{
    int N = 4, i, j, min;
    cout << "Value of N: " << N << endl;
  
    for (i = 1; i <= N; i++) {
        for (j = 1; j <= N; j++) {
            min = i < j ? i : j;
            cout << N - min + 1;
        }
        cout << endl;
    }
    return 0;
}
