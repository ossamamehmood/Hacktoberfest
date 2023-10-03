#include <cstdlib>
#include <iostream>
using namespace std;
int main() {
    int t; 
    cin>> t;
    for(int i =0 ; i<t ; i++){
        int w,d,h ; 
        cin>> w>> d>>h ; 
        int a,b ;  
        int f,g ; 
        cin>> a>> b >>f>>g ; 
        
        int max1 = 0 ; 
        if(a+f>(2*w-a-f)){
         max1 += (2*w-a-f)+abs(b-g)+h;} 
        else{
            max1 += a+f +abs(b-g)+h;
        }  
        int max2 = 0 ; 
        if(b+g>(2*d-b-g)){
         max2 += (2*d-b-g)+abs(a-f)+h;}  
         else{
             max2 += b+g+abs(a-f)+h;
         } 
         if(max1>max2){
             cout<<max2<<endl;
         }
         else{
             cout<<max1<<endl;
         }
    }
    return 0;
}