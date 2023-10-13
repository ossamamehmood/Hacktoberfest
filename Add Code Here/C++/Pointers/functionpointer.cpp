#include <iostream>
using namespace std;
int max(int a, int b){
    return a > b? a:b;

}

int min(int *a, int *b ){
    cout << *a;
    cout << *b;
    // return a < b? a:b;
}
int main(){
    int x = 10, y =20;
    int *q =  &x;
    int *r =  &y;

    int (*p)(int *,int *);
    // p = max;
    // cout << "Max is "<< p(5,10)<< endl;
    p = min;
    cout <<"Min is "<< p(q,r);
    return 0;
}