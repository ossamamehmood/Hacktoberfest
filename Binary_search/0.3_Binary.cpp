#include<iostream>
using namespace std;

void totalOccurance(int arr[], int n, int key){
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if(key == arr[i]){
            count++;
        }
    }
    cout << "The ans is " << count << endl;
    
}
int main(){
    int n;
    cout << "Enter the total inputs " << endl;
    cin >> n;

    int arr[20];
    cout << "Put array elements " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter key " << endl;
    int key;
    cin >> key;

    totalOccurance(arr, n, key);
    
}