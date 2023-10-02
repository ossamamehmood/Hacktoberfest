#include<iostream>
using namespace std;
int binarySearch(int arr[], int n, int key){
    int start = 0;
    int last = n-1;

    while (start <= last)
    {
        //int mid = (start + last) / 2;
        int mid = start + (last - start) / 2;
        if (arr[mid] == key)
        {
            cout << "The index is " << endl;
            return mid;
        }

        else if (key < arr[mid])
        {
            last = mid - 1;
        }

        else{
            start = mid +1;
        }
        
    }
      cout << "Key not present " << endl;
      return -1;
}   
    

  /*  for (int i = 0; i < n; i++)
    {
        int mid = (start + last) / 2;
        if (arr[mid] == key)
        {
            return i;
        }

        else if (key < arr[mid])
        {
            last = mid - 1;
        }

        else{
            start = mid +1;
        }
        
        
    }
    cout << "Key not present " << endl;
    return -1;
    
}*/
int main(){
    int n;
    cout << "Enter the total value " << endl;
    cin >> n;

    int arr[20];
    cout << "Put the value in array " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter key value " << endl;
    int key;
    cin >> key;

    cout << binarySearch(arr, n, key) << endl;
    
}