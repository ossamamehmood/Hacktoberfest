#include <iostream>
using namespace std;

int ispali(int a){
        cout<<a;
        // std::cout << arr[1] << std::endl;
        // for (int i = 0; i < count; i++)
        // {
        //     if ()
        //     {
                
        //     }
        // }
        
    }
    
int PalinArray(int a[], int n)
    {
        int yORn = 0;
        
        
        
        
        
        for(int i= 0;i<n;i++){
            
            yORn = ispali(a[i]);
            if(yORn == 0) break;
            
        }
        
        
        
        
        
        
        
    	return yORn;
    }
int main() {
    
int arr[]={121,221,21};
    
   int x = PalinArray(arr,3);
    cout<<x;
    return 0;
}