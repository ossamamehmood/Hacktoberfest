#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class pairSum {
public:
    int first;
    int sec;
    int sum;
};

int compare(const void* a, const void* b) {
    return ((*(pairSum*)a).sum - (*(pairSum*)b).sum);
}

bool noCommon(pairSum a, pairSum b) {
    if (a.first == b.first || a.first == b.sec
        || a.sec == b.first || a.sec == b.sec)
        return false;
    return true;
}

void findFourElements(vector<int>& arr, int X) {
    int n = arr.size();
    int i, j;
    int size = (n * (n - 1)) / 2;
    pairSum aux[size];
    int k = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            aux[k].sum = arr[i] + arr[j];
            aux[k].first = i;
            aux[k].sec = j;
            k++;
        }
    }
    qsort(aux, size, sizeof(aux[0]), compare);
    i = 0;
    j = size - 1;
    while (i < size && j >= 0) {
        if ((aux[i].sum + aux[j].sum == X)
            && noCommon(aux[i], aux[j])) {
            cout << arr[aux[i].first] << ", "
                << arr[aux[i].sec] << ", "
                << arr[aux[j].first] << ", "
                << arr[aux[j].sec] << endl;
            return;
        }
        else if (aux[i].sum + aux[j].sum < X)
            i++;
        else
            j--;
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    vector<int> arr(n);
    
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int X;
    cout << "Enter the target sum: ";
    cin >> X;
    
    findFourElements(arr, X);
    
    return 0;
}
