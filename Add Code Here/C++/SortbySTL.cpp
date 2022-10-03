#include<iostream>
#include<algorithm> // STL function header for algos.

using namespace std;
//Inbuilt Sort Function (STL)

//Define Comparator function.
bool compare (int g, int h){
  return g<h;
}
int main(){
    int a[1000];
    int n;
    cin>>n;
    for( int i =0 ;i < n ; i++){
        cin>>a[i];
    }

   sort(a,a+n,compare);

      for( int i =0 ;i < n ; i++){
        cout<<a[i]<<" ,";
    }

    return 0;
}