// wap to perform push pop and peek in stack
#include<stdio.h>
#define max 14
int top=-1,st[max],val;
void push(int st[],int val);
void pop(int st[]);
void peek(int st[]);
void display(int st[]);
int main()
{
	int val,ch,i;
	for(i=0;i<4;i++)
	{
	  printf("\n1. PUSH");
	  printf("\n2. POP");
      printf("\n3. PEEK");
	  printf("\n4. DISPLAY");
	  printf("\n\nselect an option from list:");
	  scanf("%d",&ch);
	  switch(ch)
	 {
		case 1:
			printf("Enter number to be added in stack");
			scanf("%d",&val);
			push(st,val);
			break;
		case 2:
			pop(st);
			break;
		case 3:
			peek(st);
			break;
		case 4:
			display(st);
			break;
		default:
		    printf("!!!Wrong choice!!!");
	  }
	}
	/*if(ch<=3)
	   display(st);
	else
	    printf("no action performed in stack");*/
	return 0;
}
//for push
void push(int st[],int val)
{
	if(top == max-1)
	   printf("Stack Overflow");
	else 
	   top++;
	   st[top]=val;
}

//for pop
void pop(int st[])
{
	if(top == -1)
	   printf("Stack underflow");
	else
	    {
	    	val=st[top];
	        top--;
	        printf("%d is the value deleted from stack",val);
    	}
	   	   
}
//for peek
void peek(int st[])
{
	if(top == -1)
	   printf("Stack underflow");
	else
    	{
		  val=st[top];
	      printf("value at top is %d",val);
	    }
}
//for display
void display(int st[])
{
	int i;
	if(top == -1)
	   printf("Stack is empty");
	else
	{
		for(i=top;i>=0;i--)
	    	printf("%d",st[i]);
	}
}
