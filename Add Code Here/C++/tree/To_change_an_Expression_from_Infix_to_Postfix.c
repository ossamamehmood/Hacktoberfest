/*
Problem statement: To change a Expression from Infix to Postfix
                   using stack in C

Algorithm:
   1. At first we'll make simple push and pop function 
   2. If the leftmost character is an operand, set it as the current output to the Postfix string.
      If the scanned character is the operator and the Stack is empty push the operator into the Stack.
   3. If the scanned operator has higher priority than the existing priority operator in the Stack, 
      push it on the Stack.
   4. If the scanned operator has lower or equal priority than the existing operator in the Stack,
      pop all the Stack operators and after that push the scanned operator into the Stack.
   5. If the scanned character is open parenthesis '(', always push it into the Stack.
   6. If the scanned character is close parenthesis ')', pop the Stack and print all output string
      character until '(' is encountered and discard both the bracket.
   7. Repeat all steps from 2 to 8 until the infix expression is scanned.
   8. Print the Stack output.
   9. Pop and output all characters, including the operator, from the Stack until it is not empty.
  
*/

#include<stdio.h>
#include<ctype.h>   //for alnum
#define max 100

//global variables 
char stack [max];  
//top is use to navigate in the stack
int top = -1;


void push (char x)  //push function
{
	if(top == max-1)
	{
		printf("\nStack Overflow.");
	}
	else
	{
		//increasing the top to next location and pushing character
		stack[++top] = x ;
	}
}

char pop()    //pop function
{
	char item;
    if(top == -1)
	{ 
		printf("stack under flow: invalid infix expression");
	    /* underflow may occur because of invalid expression */
	    exit(1);
	}
	else
	{
		item = stack[top];
		top = top-1;
		return(item);
	}	
}

int priority(char x)  //priority function
//it defines a level of precedence of a inputed character
{
	if(x== '^')
	return 3;
	else if(x=='*' || x=='/')
	return 2;
    else if(x=='+' || x=='-')
	return 1;
	else
	return 0;
}

void main()
{
	char exp[20];
	char*e , x;
	printf("Enter an Infix expression: ");
	scanf("%s",&exp);
	e=exp;
	printf("Its Post fix expression is: ");
	while(*e!='\0')
	//this loop will iterate untill value in *e become NULL
	{
		if(isalnum(*e))
		{
			//isalnum checks whether a given element is alphabet or number
	    	printf("%c",*e);
		}
		  
		else if(*e == '(')
		{
			//checks if the value on *e is '('
		    push(*e);	
		}
		    
		else if(*e == ')')
		{   
		    //checks if the value on *e is ')'
			while((x = pop()) != '(')
			printf("%c",x);
		}
		else
		{
			/*it means an operator is encountered so we 
			check its precedence by calling priority function.*/
			
			while(priority(stack[top]) >= priority(*e)) 
			printf("%c ",pop()); 
			push(*e);
			
		}
		e++;  //incrementing to check next character
	} //end of while
	while(top != -1)
    {
      //printing all the remaining elements in the stack
      printf("%c ",pop());
    }
return 0;
    
}  //end of main

/*
INPUT 1:
Enter an Infix expression: a*(b+c)

OUTPUT 2:
Its Post fix expression is: abc+*

INPUT 2:
Enter an Infix expression: ((A+B)*C-D)*E

OUTPUT 2:
Its Post fix expression is: AB+C* D-E*

Time Complexity : O(n^2)
as expression is iterated two 
times simultaneously, firstly for scanning the infix expression
and secondly while poping out of stack.
 
Space Complexity : O(n)
For storing Infix expression of n literals the space complexity
is O(n) and for stack to hold atmost n literals the space complexity 
is O(n), hence
Total space complexity is O(n+n) = O(2n) i.e : O(n)
*/
