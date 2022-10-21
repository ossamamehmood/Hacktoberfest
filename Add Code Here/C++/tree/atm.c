#include <stdio.h>
#include <stdlib.h>
int main()
{
	main:
    float x,y;
    char ch;
    char choice;
    printf("                       =======================================================");
    printf("\n                      |                      ATM MACHINE                     |");
    printf("\n                      ========================================================");
    printf("\nEnter initial amount: ");
    scanf("%f",&x);
    printf("\n**********************ATM SERVICES*************************");
    printf("\nEnter c for credit.\nEnter d for debit.\nEnter b for balance.\n ");
    scanf("\n%c", &ch);
    printf("\n************************************************************");
    switch(ch)
    {
    	case 'c':
    		printf("\n                    Enter credit amount:");
    		scanf("%f",&y);
    		x=x+y;
    		printf("\n                       New Amount = %f",x);
    		printf("\n                      PRESS b TO GO BACK:");
    		scanf("\n%c",&choice);
    		system("cls");
    		if(choice=='b')
    		{
    			goto main;
			}
			else
			{
			  break;
		    }
    	case 'd':
    		printf("\n                     Enter debit amount:");
    		scanf("%f",&y);
    		if(x>=y)
    		{
			   x=x-y;
			   printf("\n                    New amount = %f",x);
    	    }
    	    else
    	    {
    	    	printf("\n          Insufficient amount in your account");
			}
    		printf("\n                      PRESS b TO GO BACK:");
    		scanf("\n%c",&choice);
    		system("cls");
    		if(choice=='b')
    		{
    			goto main;
			}
			else
			{
			  break;
		    }
    	case 'b':
    		printf("\n                Amount in your account is = %f",x);
    	    printf("\n                       PRESS b TO GO BACK:");
    		scanf("\n%c",&choice);
    		system("cls");
    		if(choice=='b')
    		{
    			goto main;
			}
			else
			{
			  break;
		    }
    	default:
    		printf("\n                    Invalid choice.");
    		printf("\n                  PRESS b TO GO BACK:");
    		scanf("\n%c",&choice);
    		system("cls");
    		if(choice=='b')
    		{
    			goto main;
			}
			else
			{
			  break;
		    }

	}

    return 0;
}
