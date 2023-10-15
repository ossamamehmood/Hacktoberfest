#include <iostream>
using namespace std;

int main(){
    int count =1, i, j;
    for ( i = 0; i < 4; i++)
    {
        for ( j = 0; j < 4; j++)
        {
            
            if (i+j < 4-1)
            {
                cout << " ";
            }
            else{
                cout << "*";
            }
        }
        for (int k = 0; k < i; k++)
        {
            {
                /* code */
                cout << "*";
            }
            
        }
        
        
            cout << endl;
    }
    
    return 0;
}