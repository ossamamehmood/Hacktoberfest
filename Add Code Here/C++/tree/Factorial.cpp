
#include <iostream>
using namespace std;
int main() {
   int n = 5, fact = 1, i;
   for(i=1; i<=n; i++)
   fact = fact * i;
   cout<<"Factorial of "<<n<<" is "<<fact;
   return 0;
}
