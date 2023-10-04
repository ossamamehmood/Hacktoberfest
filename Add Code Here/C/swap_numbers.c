/* Date & Time      : Wed Oct  4 05:40:42 PM IST 2023
 * Author           : Mr.Derek
 * Tool core        : Swap 2 numbers with 2 methods
 * Command          : gcc swap_numeric_value.c; ./a.out
 * Description      : This program swaps two numbers using arithmetic operators and XOR (^) operator.
 * */
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
	//clear the mess
	printf("\033[H\033[2J");
	// Access the command-line arguments as strings	
  char *arg1 = argv[1]; 
	char *arg2= argv[2];
  if (argc < 2){
	  arg1 = "182";
	  arg2 = "32";
	  printf("Syntax: %s <YOUR_1st_NUMERIC_VALUE> <YOUR_2nd_NUMERIC_VALUE>\n\nFor example: %s", argv[0], argv[0]);
	  printf(" %s %s\n\nOutput:", arg1, arg2);
	  argc = 2;
  }
  // Convert the arguments to integers if needed 
     int argnum1 = atoi(arg1);
     int argnum2 = atoi(arg2);
     if (argc > 3) {
	     printf("Please provide only 2 Arguments.\n\n");
	     exit(0);
     } 
     // by using Arithmetic operators
     int a, b, c, d; a = b = c = d = 0;
     a = argnum1;
     b = argnum2;
     c = a;
     d = b;
     if (a >= b){
	     a = (a - b);
	     b = (a + b);
	     a = (b - a);
     } else if (b >= a){
	     b = (b - a);
	     a = (a + b);
	     b = (a - b);
     }
     printf("\nby Arithmetic operators\nOriginal Var value : a = \e[0;33m%d\e[0m and b = \e[0;33m%d\e[0m\n\nSwap var value : a = \e[0;32m%d\e[0m, b = \e[0;32m%d\e[0m\n", c, d, a, b);
	/*printf("\n\nARG 1ST = %d, ARG 2ND = %d", argnum1, argnum2);
	printf("\n\nOnly argv1 = s: %s d: %d", argv[1], argv[1]);
        printf("\nOnly argv2 = s: %s, d: %d", argv[2], argv[2]);
	*/
     
     // by using ^ (XOR) operator
     a = c; b = d;
     if (c >= d){
	     c = (c ^ d);
	     d = (c ^ d);
	     c = (d ^ c);
     } else if (d >= c){
	     d = (d ^ c);
	     c = (c ^ d);
	     d = (c ^ d);
     }
     printf("\nby XOR (^) operator\nOriginal Var value: a = \e[0;33m%d\e[0m and b = \e[0;33m%d\e[0m\n\nSwap var value : a = \e[0;32m%d\e[0m, b = \e[0;32m%d\e[0m\n", a, b, c, d);
     return 0;
}
