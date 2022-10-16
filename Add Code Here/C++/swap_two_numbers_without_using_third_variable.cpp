#include <iostream>
using namespace std; 
  
int main() 
{ 
  int x = 10, y = 50; 

  x = x + y; // x = 60
  y = x - y; // y = 10
  x = x - y; // x = 50
  cout << "After Swapping: x = " << x << ", y = " << y; 
} 
  
