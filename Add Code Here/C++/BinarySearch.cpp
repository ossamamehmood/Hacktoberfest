
#include <iostream>

using namespace std;


int binary_search(int arr[], int s, int e, int key)
{
    while(s <= e)
    {
        int mid = (s + e)/2;
        
        if(arr[mid] == key)
        {
            return mid;
        }
        else if(arr[mid] > key)
        {
            return binary_search(arr,s,mid-1,key);
        }
        else if(arr[mid] < key)
        {
            return binary_search(arr,mid+1,e,key);
        }
    }
    
    return -1;
}


int binary_search_using_shift(int arr[], int n, int key)
{
    int s = 0;
    int e = n-1;
    
    while(s <= e)
    {
        int mid = (s+e)/2;
        
        if(arr[mid] == key)
        {
            return mid;
        }
        
        else if(arr[mid] > key)
        {
            e = mid-1;
            
        }
        else
        {
            s = mid+1;
        }
        
    }
    
    return -1;
}


int main()
{
    int arr[100];
    int n;
    cin >>n;
    
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    int key;
    cin >> key;
    cout << "Index:  " << binary_search(arr,0,n-1,key) << endl;
    cout << "Index using shift:  " << binary_search_using_shift(arr,n,key) << endl;

    return 0;
}




