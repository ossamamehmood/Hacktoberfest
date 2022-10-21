#include<iostream>
using namespace std;
int main ()
{
   int i, j,temp,pass=0;
   int n; cin>>n;
   int a[n];
    for(i = 0; i<n; i++) {
      cin>>a[i];
   }
   cout <<"Input list ...\n";
   for(i = 0; i<n; i++) {
      cout <<a[i]<<"\t";
   }
cout<<endl;
for(i = 0; i<n; i++) {
   for(j = i+1; j<n; j++)
   {
      if(a[j] < a[i]) {
         temp = a[i];
         a[i] = a[j];
         a[j] = temp;
      }
   }
pass++;
}
cout <<"Sorted Element List ...\n";
for(i = 0; i<n; i++) {
   cout <<a[i]<<"\t";
}
cout<<"\nNumber of passes taken to sort the list:"<<pass<<endl;
return 0;
}