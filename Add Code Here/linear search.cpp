#include<stdio.h>
using namespace std;

int main(){
  int n , x;
  cin >> n >> x;
  
  int a[n];
  bool found = 0;
  
  for(int i = 0 ; i < n ; i++){
    cin >> a[i];

    if(a[i] == x) found = 1;
  }

  cout << (found?"we have found\n":"we didn't find\n");
  return 0;
}
