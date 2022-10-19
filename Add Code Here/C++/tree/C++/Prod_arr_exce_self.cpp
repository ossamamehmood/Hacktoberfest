#include <bits/stdc++.h>
using namespace std;
void prodArray(int a[], int n){
    int p[n], prod=1;
    
    //Find product of all elements of a[]
    for(int i=0; i<n; i++){
        prod = prod * a[i];
    }
    
    //Create array p[] to store
    //product except self
    for(int i=0; i<n; i++){
        p[i] = prod / a[i];
    }
    
    for(int i=0; i<n; i++){
        cout<<p[i]<<" ";
    }
}
int main() {
  int a[] = {4, 6, 1, 2};
  int n = sizeof(a)/sizeof(a[0]);
  prodArray(a,n);
  return 0;
}
