#include<iostream>
using namespace std;
 
//- Optimized bubble sort technique (elements gets bubbled up!)
void bubbleSort(int* a,int n)
{
    int flag;     //-flag to check whether the further array is already sorted or not (This is gonna reduce ur passes!)
    for(int i=0;i<n-1;i++){
        flag = 0;

        for(int j=0;j<n-1-i;j++)    //- n-1-i used to reduce the number of comparisons done inside the array
        {
            if(a[j]>a[j+1])    //-comparing adjacent elements and swapping them
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                flag = 1;
            }
        }
        if(flag == 0)   //-break out if further array is sorted (if array isn't sorted then flag was to be 1)
        {
            break;
        }
    }
    cout<<"The sorted array is: \n";
    for(int k=0;k<n;k++)
    {
        cout<<a[k]<<"  ";
    }
}

int main()
{
    int a[10] = {5,4,8,7,3,1,7,45,12,34};
    int n = sizeof(a);
    int totalElements = n/sizeof(int);
    // cout<<totalElements<<endl;

    bubbleSort(a,totalElements);
    return 0;
}
// Best case O(n)
// Worst Case O(n^2)
