//######## Mini Project **Calculator Using C** ##########
// Developer - Dernyt-TPE

#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include <ctype.h> 

void optionTray();
void secondOptionTray();

void addition()
{printf("\nEnter nos. to add separated by space_ || press Enter ┘ for solution \n\n");
    int input=0; int ans=0; char c='\0';
    while(c!='\n'){
        scanf("%d", &input);
        ans+= input;
        c=getchar();
            
    }
    printf("\n = %d",ans);
    secondOptionTray();
}

void subtraction ()
{
  int first, second; int ans = 0;
  printf ("\nEnter the first number  : ");
  scanf ("%d", &first);
  printf ("Enter the second number : ");
  scanf ("%d", &second);
  ans=first - second;
  printf ("\n = %d", ans);
  secondOptionTray();
}


void multiplication ()
{
    printf("\nEnter nos. to multiply separated by space_ || press Enter ┘ for solution \n\n");
    int input=0; int ans=1; char c='\0';
    while(c!='\n'){
        scanf("%d", &input);
        ans*= input;
        c=getchar();
            
    }
    printf("\n = %d",ans);
    secondOptionTray();
}

void division ()
{
  int dend, isor=0;char c='\0';
  printf ("\nEnter the Dividend: ");
  scanf ("%d", &dend);
  printf ("Enter the Divisor: ");
  scanf ("%d", &isor);
  int ans = dend / isor;
  printf ("\nQuotient is = %d", ans);
  printf("\nRemainder is");
  printf(" = %d", (dend%isor));
  secondOptionTray();
}


void power ()
{
  double base, exponent, ans;
  printf ("\nEnter the Base: ");
  scanf ("%lf", &base);

  printf ("Enter the Exponent(Power): ");
  scanf ("%lf", &exponent);

  ans = pow (base, exponent);
  printf ("\n = %lf", ans);
  secondOptionTray();
}

void sqroot()
{
    
    double input;
    printf("\nEnter no. for Square Root: ");
        
        scanf("%lf", &input);
        printf("\n = %lf", sqrt(input));
        secondOptionTray();
    
}

void cbroot(){
        double input;
    printf("\nEnter no. for Cube Root: ");
    scanf("%lf", &input);
        printf("\n = %lf", cbrt(input));
        secondOptionTray();
}


void factorial ()
{
  int input, fact = 1;

  printf ("\nEnter a number to find factorial : ");
  scanf ("%d", &input);

  if (input < 0)
      printf ("\nPlease enter a positive number..");
  if (input == 0)
      printf("\n = 1");
  else{
      for (int x = 1; x <= input; x++){
          fact = fact * x;}
      
      printf ("\n = %d", fact);
      
    }secondOptionTray();
}





//**************************************

int main ()
{
  
  char choice='\0';

  printf ("\n\t\t\t\t*****Welcome to C calculator*****\n\n");
  optionTray();

  while (1>0)
    {
      
      

      choice= getchar();

      switch (choice)
	{
	    case '1':
	    case '+':
	    addition ();break;

	case '-':
	case '2':
	subtraction ();
	break;

	case '*':
	case '3':
	  multiplication ();
	  break;

	case '/':
	case '4':
	  division ();
	  break;

	case '^':
	case '5':
	    power();
	    break;

	case '|':
	case '6':
	  sqroot();
	  break;
	  
	case '~':
	case '7':
	  cbroot();
	  break;

	case '!':
	case '8':
	  factorial();
	  break;

	case 'M':
	case 'm':
	optionTray();break;
	
	case 's':
	case 'S':
	exit(0);break;

	}
	
    }
}

void secondOptionTray()
{
  
  printf ("\n\n## Press 's' to stop ##");
  
  printf("\n\n## Press 'm' for Full Option Menu ##  ");
  
    
}

void optionTray()
{

  
  secondOptionTray();

  printf ("\n\n\nEnter '+' or '1' for Addition");
  printf ("\t\t\t\tEnter '-' or '2; for Subtraction");
  printf ("\nEnter '*' or '3' for Multiplication");
  printf ("\t\t\tEnter '/' or '4' for Division");
  printf ("\nEnter '^' or '5' for Power");
  printf ("\t\t\t\tEnter '|' or '6' for Square Root");
  printf ("\nEnter '~' or '7' for Cube Root");
  printf ("\t\t\t\tEnter '!' or '8' for Factorial \n\n");
  
  
  printf ("\n\n\n\nEnter the option you wish to perform — ");
}

