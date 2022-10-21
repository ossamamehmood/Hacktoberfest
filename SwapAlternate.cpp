#include<bits/stdc++.h>
using namespace std;
void SwapAlternate(int arr[],int n){

    for (int i = 0; i < n; i+=2)
    {
        if(i+1<n){
            swap(arr[i],arr[i+1]);
        }
    }cout<<endl;
}

void printArray(int num[],int n){

    for (int i = 0; i < n; i++)
    {
        cout<<num[i]<<endl;
    }

}




int main(){

    int even[]={1,2,3,4,5,6};
    int odd[]={1,2,3,4,5};


    SwapAlternate(even,6);
    SwapAlternate(odd,5);
    printArray(odd,5);





}
