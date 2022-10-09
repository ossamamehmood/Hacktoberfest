#include<stdio.h>
#include<conio.h>
main(){
  float number1;
  float number2;
  char op;
  float result;
  printf("Enter the first number : ");
  scanf("%f" ,&number1);
  
  printf("Enter the operation : ");
  scanf("%f" ,&number2);
  
  switch(op)
  {
    case '+' :
      result = number1+number2;
      
      printf("%f" ,result);
      break;
      
       case '-' :
      result = number1-number2;
      
      printf("%f" ,result);
      break;
      
      
      case '*' :
      result = number1*number2;
      
      printf("%f" ,result);
      break;
      
      
       case '/' :
      result = number1/number2;
      
      printf("%f" ,result);
      break;
      
