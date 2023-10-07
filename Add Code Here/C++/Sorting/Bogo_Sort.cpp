#include<iostream>
#include<vector>
using namespace std;

void print_array(vector<int> &arr){
    cout<<"Array: "<<endl;
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

// Bogo Sort
// Time Complexity:  O(infinity)
// Space Complexity: O(1)
bool isSorted(vector<int> &arr){
    for(int i=1;i<arr.size();i++){
        if (arr[i] < arr[i - 1])
            return false;
        }    
    return true;
}

void shuffle(vector<int> &arr){
    for (int i = 0; i < arr.size(); i++){
        swap(arr[i], arr[rand() % arr.size()]);
    }
}
 
void Bogosort(vector<int> &arr){
    while (!isSorted(arr))
        shuffle(arr);
}

int main(){
    // User Driven Function
    // int n;
    // cin>>n;
    
    // vector<int> arr(n);
    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    // }

    // Using Saved Array
    vector<int> arr={4,2,5,1,6,7,3,7,23,62,3,1};

    cout<<"Original ";
    print_array(arr);

    Bogosort(arr);

    cout<<"Sorted ";
    print_array(arr);
 
    return 0;
}