#include <iostream>

using namespace std;

int main() {
    int a[5] = {4, 3, 6, 8, 5};
    int i;
    int max = a[0];
    int min = a[0];

    for (i = 1; i < 5; i++) {
        if (a[i] > max) {
            max = a[i];
        } else if (a[i] < min) {
            min = a[i];
        }
    }
    
    cout << "Maximum element: " << max << endl;
    cout << "Minimum element: " << min << endl;

    return 0;
}

