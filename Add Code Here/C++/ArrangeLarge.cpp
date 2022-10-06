#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool compare(int x,int y){
    int xy=x,yx=y;
    int xdigit=0,ydigit=0;
    while(x!=0){
        xdigit++;
        x=x/10;
    }
    while(y!=0){
        ydigit++;
        y=y/10;
    }
    x=xy;y=yx;
    while(ydigit!=0){
        xy=xy*10;
        ydigit--;
    }
    while(xdigit!=0){
        yx=yx*10;
        xdigit--;
    }
    xy=xy+y;
    yx=yx+x;
    return xy>yx;
}

int main(){

    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr,arr+n,compare);
    for(int i=0;i<n;i++){
        cout << arr[i] <<" ";
    }


return 0;
}