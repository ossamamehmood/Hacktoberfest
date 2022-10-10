#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
   int ch;
   char choice;

   do
   {
      printf("\t\t\t 1. Pascal's Triangle\n");
      printf("\t\t\t 2. Floyd's Triangle\n");

      printf("Select the choice of pattern: ");
      scanf("%d", &ch);
	
	  //Pascal Triangle
      if (ch == 1)
      {
         int rows, coef = 1, space, i, j;
         printf("Enter the number of rows: ");
         scanf("%d", &rows);
         printf("\n-------PASCAL'S' TRIANGLE--------\n\n");
         for (i = 0; i < rows; i++)
         {
            for (space = 1; space <= rows - i; space++)
               printf("  ");
            for (j = 0; j <= i; j++)
            {
               if (j == 0 || i == 0)
                  coef = 1;
               else
                  coef = coef * (i - j + 1) / j;
               printf("%4d", coef);
            }
            printf("\n");
         }
      }
      
      
      //Floyd's Triangle
      else if (ch == 2)
	  {
   			int rows, i, j, number = 1;
  		 	printf("Enter the number of rows: ");
   			scanf("%d", &rows);
   			printf("\n-------FLOYD'S TRIANGLE--------\n\n");
   			for (i = 1; i <= rows; i++)
   			{
      			for (j = 1; j <= i; ++j)
      			{
        			 printf("%d ", number);
         			++number;
      			}
      		printf("\n");
   			}
	  }
	  
	  else{
	  	printf("Invalid Choice!!");
	  }
	  
	 printf("\n\nDo you want to continue(y/Y): ");
	 cin>>choice;

   } while(choice == 'y' || choice == 'Y');

   return 0;
}


/*OUTPUT:

                         1. Pascal's Triangle
                         2. Floyd's Triangle
Select the choice of pattern: 1
Enter the number of rows: 6

-------PASCAL'S' TRIANGLE--------

               1
             1   1
           1   2   1
         1   3   3   1
       1   4   6   4   1
     1   5  10  10   5   1


Do you want to continue(y/Y): y
                         1. Pascal's Triangle
                         2. Floyd's Triangle
Select the choice of pattern: 2
Enter the number of rows: 5

-------FLOYD'S TRIANGLE--------

1
2 3
4 5 6
7 8 9 10
11 12 13 14 15


Do you want to continue(y/Y): n

--------------------------------
Process exited after 15.85 seconds with return value 0
Press any key to continue . . .*/

