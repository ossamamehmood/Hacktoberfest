#include<stdio.h>
int bubblesort(int n,int a[n]){
int i, j, temp;
int count =0;
for(i=0; i<n-1; i++)//instead of i<n we can write i<n-1 bcoz in swapping it is swapped from 
//next greater element which is includes n in a[j+1]. 
{
 for(j=0; j<n-i-1; j++)
 {
 if( a[j] > a[j+1])
 {
 temp = a[j]; 
 a[j] = a[j+1];
  a[j+1] = temp;
  count++;
 }}} 
 printf("\n%d is the no of swappings.",count);
}
int main(){
int b[5]={8,9,10,11,12};
bubblesort(5,b);
int c[5]={12,11,10,9,8};
bubblesort(5,c);
int d[5]={11,10,8,9,12};
bubblesort(5,d);
}
