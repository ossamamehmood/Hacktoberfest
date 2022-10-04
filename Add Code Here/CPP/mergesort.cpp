#include <iostream>
using namespace std;

void merge(int *Arr, int st, int mid, int en){
    int B[(en-st+1)];
    int length = en-st+1;
    int cst=st, mst=mid+1, count=0;
    while(count<length){
        if(cst<=mid){
            if(mst<=en){
                if(Arr[cst]<Arr[mst]){
                    B[count++] = Arr[cst++];
                }else{
                    B[count++] = Arr[mst++];
                }
            }else{
                B[count++] = Arr[cst++];
            }
        }else{
            if(mst<=en){
                B[count++]= Arr[mst++];
            }
        }
    }
    for(int i=0;i<length;i++){
        Arr[i+st] = B[i];
    }
}

void mergesort(int* Arr, int st, int en){
    if(en>st){
        int mid = (st+en)/2;
        mergesort(Arr, st, mid);
        mergesort(Arr, mid+1, en);
        merge(Arr, st, mid, en);
    }
}

void sort(int* Arr, int length){
    mergesort(Arr, 0, length-1);
}

int main(){
    int n;
    cout<<"Enter the length of array\n";
    cin>>n;
    int Arr[n];
    for(int i = 0;i<n;i++){
        cout<<"Enter an array element\n";
        cin>>Arr[i];
    }
    //sort
    sort(Arr, n);

    //Print after sorting
    cout<<"Sorted array\n";
    for(int j=0;j<n;j++){
        cout<<Arr[j]<<endl;
    }
    return(0);
}
