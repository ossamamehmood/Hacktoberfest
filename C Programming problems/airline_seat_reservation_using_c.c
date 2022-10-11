/*
QUESTION : 
Design a Simple Airline Seat Reservation System using C programming
The programme asks the user to choose the type of class they want to travell in , there are mainly 3 classes First class, Buisness class, Economy class
and then display the seats under the category and ask them to choose the seat number 
If the seat is not taken by anyone reserve the seat and print the details of the seat 
if the seat is already taken by a passenger then print seat already taken 
If a user enter invalid out of the bounds seat number then print Invalid seat Number!
Constrains :  Total number of seats available for each class are equal and the total number of seats is 30 , 10 for each class  
CODE:
*/
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int main(void)
{
	int c,p;
	int i,j, s;
	printf("Enter the total number of seats in the plane :  ");//Default given seats are 30 
	scanf("%d", &s);
	int seats[s];
	printf("\n\n");
	printf("    🙏  Welcome to KINGFISHER Airlines Seat Reservations System  🙏\n");
	printf("   -------------------------------------------------------------\n\n\n");
	int n;
	char name[50];
	char phone_number[50];
	char email[50];
	for (j=0; j<1; j++)
	{
	    printf("Enter name of the passenger : ");
	    scanf("%s", &name);
	    printf("Enter mobile number  of the passenger : ");
	    scanf("%s", &phone_number);
	    printf("Enter mail-id of the passenger : ");
	    scanf("%s", &email);
	    printf("\n\n");
		printf("Choose 1 for First Class \n       2 for Buisness class\n       3 for Economy class\n");
		printf("----> :  ");
		scanf("%d",&c);
		switch(c)
		{
		case 1:
			printf("\nFirst class\n");
			printf("--------------------------------------------------------------\n");
			printf("Seats available are : 1, 2, 3, 4, 5, 6, 7, 8, 9, 10\n");
			do
			{
                printf("Pick a seat: ");
                scanf("%i",&p);
                seats[j]=p;
			    for (i=0; i<j; i++)
			    {
                    if (seats[j]==seats[i])
                    {
                        printf("\n\nSeat taken.\n\n");
                        break;
                    }
			    }
            }
            while (i!=j);
                if(seats[j] <= 10)
                {
                    printf("\n");
                    printf(" ----------------------------------------------\n");
                    printf("|  Name : %s\n", name);
                    printf("|  Mobile Number : %s\n", phone_number);
                    printf("|  Mail-id : %s\n", email);
                    printf("|  Class: First class\n");
                    printf("|  Seat no : %i\n",seats[j]);
                    printf(" ----------------------------------------------\n");
                }
                else
                printf("\nInvalid Seat Number!\n\n");
            break;
		case 2:
			printf("\nBuisness Class\n");
			printf("-------------------------------------------------------------------\n");
			printf("Seats available are :  11, 12, 13, 14, 15, 16, 17, 18, 19, 20\n");
			do
			{
                printf("Pick a seat:\n\n");
                scanf("%i",&p);
                seats[j]=p;
			    for (i=0; i<j; i++)
			    {
                    if (seats[j]==seats[i])
                    {
                        printf("\n\nSeat taken.\n\n");
                        break;
                    }
			    }
            }
            while (i!=j);
                if(seats[j] >10 && seats[j]<=20 )
                {
                    printf("\n");
                    printf(" -----------------------------------------------------\n");
                    printf("|  Name : %s\n", name);
                    printf("|  Mobile Number : %s\n", phone_number);
                    printf("|  Mail-id : %s\n", email);
                    printf("|  Class: Buisness class\n");
                    printf("|  Seat no : %i\n",seats[j]);
                    printf(" -----------------------------------------------------\n\n");
                }
                else
                printf("\nInvalid Seat Number!\n\n");
            break;
		case 3:
			printf("\nEconomical class\n");
			printf("---------------------------------------------------------------------\n");
			printf("Seats available are :  21, 22, 23, 24, 25, 26, 27, 28, 29, 30\n");
			do
			{
                printf("Pick a seat:\n\n");
                scanf("%i",&p);
                seats[j]=p;
			    for (i=0; i<j; i++)
			    {
                    if (seats[j]==seats[i])
                    {
                        printf("\n\nSeat taken.\n\n");
                        break;
                    }
			    }
            }
            while (i!=j);
                if(seats[j] > 20 && seats[j] <=30)
                {
                    printf("\n");
                    printf(" ---------------------------------------------------\n");
                    printf("|  Name : %s\n", name);
                    printf("|  Mobile Number : %s\n", phone_number);
                    printf("|  Mail-id : %s\n", email);
                    printf("|  Class: Economy class");
                    printf("|  Seat no : %i\n",seats[j]);
                    printf(" ---------------------------------------------------\n\n");
                }
                else
                printf("\n Invalid Seat Number!\n\n");
            break;
        default:
                break;
        }
    }
	return 0;
}
                                                  
/*
----> SAMPLE OUTPUT <----
Enter the total number of seats in the plane :  30
    🙏  Welcome to KINGFISHER Airlines Seat Reservations System  🙏
   -------------------------------------------------------------
Enter name of the passenger : SHRISHAIL
Enter mobile number  of the passenger : 8658512576
Enter mail-id of the passenger : shrishail@gmail.com
Choose 1 for First Class 
       2 for Buisness class
       3 for Economy class
----> :  2
Buisness Class
-------------------------------------------------------------------
Seats available are :  11, 12, 13, 14, 15, 16, 17, 18, 19, 20
Pick a seat:
17
 -----------------------------------------------------
|  Name : SHRISHAIL
|  Mobile Number : 8658512576
|  Mail-id : shrishail@gmail.com
|  Class: Buisness class
|  Seat no : 17
 -----------------------------------------------------
...Program finished with exit code 0
Press ENTER to exit console.
*/
