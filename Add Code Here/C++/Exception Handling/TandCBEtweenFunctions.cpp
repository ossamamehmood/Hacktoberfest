#include <iostream>
using namespace std;
int Divide(int a, int b){
    if(b == 0){
        throw 404; 
    }
    else{
        return a/b;
    }
}
int main(){
    try{
        cout <<Divide(4,2);
    }
    catch(int a){
        cout << "Can't divide by 0 error "<< a;
    }
    return 0;
}