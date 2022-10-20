#include <iostream>
using namespace std;
   
int main(){
    int  count, i, num;
       
    cout << "Enter Number of Elements in Array\n";
    cin >> count;
     int *input=new int[count];
    cout << "Enter " << count << " numbers \n";
    for(i = 0; i < count; i++){
        cin >> input[i];
    }
      
    cout << "Enter a number to serach in Array\n";
    cin >> num;
      
    // search num in inputArray from index 0 to elementCount-1 
    for(i = 0; i < count; i++){
        if(input[i] == num){
            cout << "Element found at index " << i;
            break;
        }
    }
      
    if(i == count){
        cout  << "Element Not Present in Input Array\n";
    }
 	delete [] input;
 	input=0;
    return 0;
}