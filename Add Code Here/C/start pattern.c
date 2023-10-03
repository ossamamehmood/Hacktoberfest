#include<stdio.h>

 int main(){
      int i;
// forming a rectangle 
//here i denoting i = rows / j = columns 
// this code will be basic template for all the patterns only few logic will be changed
// steps to be followed
//step 1 : draw lines horizontally and vertically (will help to understand easily)
//step 2 : if i = 3 then j = 1,2,3 and so we have to write i = 3 ===  j <=4
     for(int j=0; j<5; j++) {
      for(i=0; i<5; i++){
        if(i<=j) // step 2 i s this
        printf("*");
           else
             printf(" ");
        }
         printf("\n");
      }
 }


//Same just we did is j<=i 
//doing the reverse thing upper did
/*
for(int j=0; j<5; j++) {
      for(i=0; i<5; i++){
        if(j<=i) // step 2 is this
        printf("*");
           else
             printf(" ");
        }
         printf("\n");
      }


      //output :
      *****
       ****
        ***
         **
          *
*/
