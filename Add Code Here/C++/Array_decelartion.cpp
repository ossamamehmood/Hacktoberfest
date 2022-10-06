#include<iostream>
using namespace std;
int main()
{ 
      cout<<"Declare an array " ;
    //   int A[12] = {7,8,6,0,6,2,8,2,8,3};  // print last digit 
    //   cout<<A[9];



      // if you want to print whole array you can use for loop or count function
    //   for(int i=0;i<=9;i++)
    //   cout<<A[i];


   //  or 1 more method 
//    int A[] = {7,8,6,0,6,2,8,2,8,3};
//       for(int x:A)  // declaring varible x for elements of A 
//       cout<<x;


      // you can use float and char in and array example
    //   float b[10] ={1.1,1.3,23.3,34.53};
    //   for(int i=0;i<=3;i++)  // 3 is because we have 3 array in list whe can give more but it will dispay 0
    //   cout<<b[i];
         
         float G[] = {2.3f,4.6f,5,6,4,2};
         for(float x :G)    // you can use ' auto ' in place of float its very good dont think of variable type
         cout<<x<<endl;
         


    return 0;
}
