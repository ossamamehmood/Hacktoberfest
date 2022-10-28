//Find the "Kth" max and min element of an array 
#include <iostream>
using namespace std;
void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int reverseBubbleSortKth(int A[], int N){
    int k;
    cout<<"Enter the value of k: "<<endl;
    cin>>k;
    for (int i=0; i<=k-1; i++){
        int flag=0;
        for (int j=0; j<N; j++){
            if (A[j]<A[j+1]){
                swap(&A[j], &A[j+1]);
                flag=1;
            }
        }
        if (flag==0){
            break;
        }
    }
    cout<<"The kth smallest element is given by: "<<endl;
    return A[N-k];
    // for (int i=0; i<N-1; i++){
    //     int flag=0;
    //     for (int j=0; j<N-1-i; j++){
    //         if (A[j]>A[j+1]){
    //             swap(&A[j], &A[j+1]);
    //             flag=1;
    //         }
    //     }
    //     if (flag==0){
    //         break;
    //     }
    // }
    // cout<<"The kth smallest element is given by: "<<endl;
    // return A[k-1];
}
int main()
{
    int N;
    cout << "Enter the size of the array: " << endl;
    cin >> N;
    int A[50];
    cout << "Enter the array elements: " << endl;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    cout<<reverseBubbleSortKth(A, 5);
}