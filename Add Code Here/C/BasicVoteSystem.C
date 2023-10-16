#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
//Admin Password: 2004 (It can be change in admin function)
//Special Password : 1234
typedef struct voter_information
{
    char aadhar[20];
    char name[50];
    char birth_date[15];
    struct voter_information *next;
} node;

node *head;
node *space,*start=NULL;
node *search(char x[],char y[],char z[],node *,int *);
node *voter_insert(node *);
node *main_logs(node *);
 void admin();
 void winner();
	void exi();
	void voting();
	void not_again();
	void stop();
	void show();


int count=0,R=3,vote=0;
int vote1=0,vote2=0,vote3=0,vote4=0,vote5=0;
int main()
{
	int BB;
	while(1){

    system("cls");
    printf("\n\n\n");
    printf("\t          ****** WELCOME TO THE ONLINE VOTING PORTAL ******        \n\n");

    printf("\t       ***************************************************        \n\n\n\n\n");
    printf("      \t\ *****Please Enter One(1) for logging vote main Logs*****    \n\n\n");


    scanf("%d",&BB);
    if(BB==1)
    {
      start=  main_logs(start);
    }

}
    return 0;
}

node *main_logs(node *start)
{
    int T;
    system("cls");
    printf("\n\n\n");
    printf("        \t\t\t1. FOR VOTE ENTRY     \n");
    sleep(1);
    printf("        \t\t\t2. FOR ADMIN PANEL    \n");
    sleep(1);
    printf("        \t\t\t3. FOR WINNER         \n");
    printf("	 \t\t\t4.Exit             \n");
    printf("    \t IF YOUR CREDENTIALS MATCHES WITH THOSE IN THE VOTER LIST THEN ONLY YOU CAN GIVE YOUR VOTE OTHERWISE YOU CAN NOT    \n\n\n");
    sleep(1);
    printf("    \t ********So Plz Enter********\n\n\n");

    scanf("%d",&T);
    if(T==1)
    {
       start= voter_insert(start);
    }
    if(T==2)
    {
      admin();
    }
    if(T==3)
    {
      winner();
    }
    if(T==4)
    {
     exi();
    }
    if(T!=1||T!=2||T!=3||T!=4)
    {
	main_logs(start);
	}


    return start;
}

//The Voter list is pre defined and can be changed in code itself
node *voter_insert(node *start)
{
node *temp;
     char name[50],birth_date[15],aadhar[20];
	int UNIVERSAL=0;
int *z;
 z = &UNIVERSAL;

     system("cls");
     printf("\n\n\n\n");
     printf("\t IF AADHAR ID, YOUR NAME AND YOUR DATE OF BIRTH MATCHES THEN YOU CAN GIVE YOUR VOTE OTHERWISE NOT\n\n");
     sleep(1);
     printf("\tID YOU DO WRONG %d TIMES, THE PORTAL WILL BE CLOSED AUTOMATICALLY\n\n\n",R);
     sleep(1);
     printf("\t\tPlease \n");
     sleep(1);
     printf("\t\t\tEnter your AADHAR ID number  ");
     gets(aadhar);
     printf("\t\t\tEnter Your NAME   ");
     gets(name);
     printf("\t\t\tEnter Your BIRTH DATE  in dd-mm-yyyy format");
     gets(birth_date);
     temp=(node *)malloc(sizeof(node));
     strcpy(temp->aadhar,aadhar);
     strcpy(temp->name,name);
     strcpy(temp->birth_date,birth_date);
     temp->next=NULL;
     head=temp;
     while(temp!=NULL)
     {
	 if((strcmp(temp->aadhar,"10001")==0&& strcmp(temp->name,"Sam Jhonson")==0 &&strcmp(temp->birth_date,"30-11-2002")==0) ||
	 (strcmp(temp->aadhar,"10002")==0&& strcmp(temp->name,"Goutam Kumar Bhadani")==0 &&strcmp(temp->birth_date,"01-01-1999")==0)||
	 (strcmp(temp->aadhar,"10003")==0&& strcmp(temp->name,"Gautam Kumar")==0 &&strcmp(temp->birth_date,"12-10-1999")==0)||
	 (strcmp(temp->aadhar,"10004")==0&& strcmp(temp->name,"Kundan Kumar")==0 &&strcmp(temp->birth_date,"08-12-1999")==0)||
	 (strcmp(temp->aadhar,"10005")==0&& strcmp(temp->name,"Aniket Arora")==0 &&strcmp(temp->birth_date,"28-08-1999")==0)||
	 (strcmp(temp->aadhar,"10006")==0&& strcmp(temp->name,"Dipika Singh")==0 &&strcmp(temp->birth_date,"20-10-2000")==0)||
	 (strcmp(temp->aadhar,"10007")==0&& strcmp(temp->name,"Avinash Kumar")==0 &&strcmp(temp->birth_date,"02-03-1999")==0)||
	 (strcmp(temp->aadhar,"10008")==0&& strcmp(temp->name,"Ravi Raj")==0 &&strcmp(temp->birth_date,"26-12-1999")==0)||
	 (strcmp(temp->aadhar,"10009")==0&& strcmp(temp->name,"Shubham Kumar")==0 &&strcmp(temp->birth_date,"02-01-1999")==0)||
	 (strcmp(temp->aadhar,"10010")==0&& strcmp(temp->name,"Subham Kumar")==0 &&strcmp(temp->birth_date,"03-01-1999")==0))

	 {
		R=3;
		start=search(temp->aadhar,temp->name,temp->birth_date,start,&UNIVERSAL);

		if(UNIVERSAL==0)
	    {
		 voting();
			}
	    else
	     {
		not_again();
			 }
	   }
	 else
	    {
	      R--;
	 if(R==0)
	 {
	     stop();
	     break;
	 }
	 printf("\n\n\n\n");
	 printf("\tYour AADHAR ID or NAME or DATE OF BIRTH is wrong\n\n");
	 sleep(1);
	 printf("\t\tPlz Re-Enter\n\n");
	 sleep(1);
	 system("pause");
	start= main_logs(start);
	    }
	    temp=temp->next;
     }
     return start;
}


void voting()
{
	int B,j;
     system("cls");
    printf("\n\n\n\n");
    printf("\t\t     * * * * * LIST OF CANDIDATES * * * * * \n\n\n");
    sleep(1);
    printf("\t\t\t NAME     & THEIR RESPECTIVE      PARTY\n\n");
    sleep(1);
    printf("\t\t\t 1.Mamata Banerjee                1.TMC\n");
    sleep(1);
    printf("\t\t\t 2.Deepa Dasmunsi                 2.BJP\n");
    sleep(1);
    printf("\t\t\t 3.Protima Rajak                  3.Congress\n");
    sleep(1);
    printf("\t\t\t 4.Joydeb Halder                  4.AAP\n");
    sleep(1);
    printf("\t\t\t 5.Kartik Chandra Ghosh           5.Shivsena\n\n\n");




       printf("\t\t\t Plzz, \n");
       printf("\t\t\t Enter Your Choice \n");
       for(j=1;j<=1;j++)
       {
	   scanf("%d",&B);

	   if(B==1)
	   {
	       vote1++;
	       printf("\n\n\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO MAMTA BANERJEE\n");
	       break;

	   }
	   if(B==2)
	   {
	       vote2++;
		printf("\n\n\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO DEEPA DASMUNSI\n");
	       break;

	   }
	   if(B==3)
	   {
	       vote3++;
		printf("\n\n\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO PROTIMA RAJAK\n");
	       break;

	   }
	   if(B==4)
	   {
	       vote4++;
		printf("\n\n\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO JOYDEB HALDER\n");
	       break;
	   }
	   if(B==5)
	   {
	       vote5++;
		printf("\n\n\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO KARTIK CHANDRA GHOSH\n");
	       break;
	   }
	    if(B!=1||B!=2||B!=3||B!=4||B!=5)
	   {
		printf("\n\t\t************* INVALID CHOICE ENTERED**************\t\t\n");
		printf("\n\t\t\tENTER AGAIN\t\t\t\n");
		   }




       }
	   printf("\n\n**************************THANK YOU***************************\n\n");
	   printf("press any key");
	   getch();
}

 void admin()
 {
     int B;
     printf("\n\n\n\n");
     printf("\t\t\tEnter Your Password To Unlock The Admin Panel\n\n");
     scanf("%d",&B);
     if(B==2004)
     {
	 show();

     }
     else
     {
	 printf("Wrong Password\n");
     }
 }

  void show()
  {
	int G;
      system("cls");

      printf("\n\n\n\n");
      printf("\t\t\tPresent Vote Count :\n\n");
      sleep(1);
      printf("\t\t\t  Mamata Banerjee is on     %d Votes\n",vote1);
      sleep(1);
      printf("\t\t\t  Deepa Dasmunsi is on      %d Votes\n",vote2);
      sleep(1);
      printf("\t\t\t  Protima Rajak is on       %d Votes\n",vote3);
      sleep(1);
      printf("\t\t\t  Joydeb Halder  is on      %d Votes\n",vote4);
      sleep(1);
      printf("\t\t\t  Kartik Chandra Ghosh  is on     %d Votes\n\n\n\n",vote5);
      sleep(1);


      printf("\t\t\t\tEnter Any Key For Main Logs\n\n\t\t\t\t\t\t\tOR\n\n\t\t\t\tENTER THE SPECIAL PASSWORD TO CLOSING VOTING PORTAL\n ");
    scanf("%d",&G);
    if(G==1234)
    exi();
    else
    main_logs(start);

  }

   void winner()
   {
       system("cls");
       printf("\n\n\n\n");
       if(vote2<vote1 && vote3< vote1 && vote4<vote1 && vote5<vote1)
	printf("\t\t\tThe present Winner is Mamata Banerjee and she has got %d votes\n\n\n\n",vote1);

       if(vote1<vote2 && vote3< vote2 && vote4<vote2 && vote5<vote2)
	printf("\t\t\tThe present Winner is Deepa Dasmunsi and she has got %d votes\n\n\n\n",vote2);

	if(vote1<vote3 && vote2< vote3 && vote4<vote3 && vote5<vote3)
	printf("\t\t\tThe present Winner is Protima Rajak and she has got %d votes\n\n\n\n",vote3);

	if(vote1<vote4 && vote2< vote4 && vote3<vote4 && vote5<vote4)
	printf("\t\t\tThe present Winner is Joydeb Halder and he has got %d votes\n\n\n\n",vote4);

	if(vote1<vote5 && vote2< vote5 && vote3<vote5 && vote4<vote5)
	printf("\t\t\tThe present Winner is Kartik Chandra Ghosh and he has got %d votes\n\n\n\n",vote5);

	printf("\t\t\t\tEnter Any Key for Main Log\n\n");
	getch();
	main_logs(start);

   }

   void stop()
   {
       system("cls");

       printf("\n\n\n\n");
       printf("\t\t\t (:-SORRY YOU ENTERED WRONG CREDENTIALS FOR THREE(3) TIMES IN A ROW -:) \n\n\n");
       sleep(1);
       printf("\t\t\t Plz try again After A few Moment\n\n\n");
       sleep(1);
       printf("\t\t\t * * *Thank You* * *  \n\n\n");
       sleep(1);
       printf("press any key");
       getch();

   }

   void not_again()
   {
	int A;
		system("cls");
	printf("\n\n\n\n");
	printf("\t\t\t        ***YOU HAVE GIVEN YOUR VOTE SUCCESSFULLY***       \n\n\n");
	sleep(1);
	printf("\t\t\t        ***YOU CANNOT GIVE YOUR VOTE MORE THAN ONCE***     \n\n\n");
	sleep(1);
	printf("\t\t\t If You want to see present winner Enter One(1) or Enter Any Other Key for Main  Logs\n\n");
	sleep(1);

	scanf("%d",&A);
	if(A==1)
	{
	    winner();
	}
	else
	{
	    main_logs(start);
	}

   }

   void exi()
   {
       system("cls");

       printf("\n\n\n\n\n");
       sleep(1);
       printf("\t\t\t        ***YOU ARE NOW EXITING THE PORTAL***       \n\n\n");
       sleep(1);
       printf("\t\t\t * * *Thank You For Using This ONLINE PLATFORM For VOTING* * *  \n\n\n");
       sleep(1);
       exit(0);
   }
node *search(char x[],char y[],char z[],node *start,int *Y)
{
  node *t,*space;
	*Y=0;
  if(start==NULL)
  {
      space=(node*)malloc(sizeof(node));
     strcpy(space->aadhar,x);
     strcpy(space->name,y);
     strcpy(space->birth_date,z);

      start=space;
      space->next=NULL;

  }
  else
  {
      t=start;
      while(t!=NULL)
       {
	  if((strcmp(t->aadhar,x)==0&& strcmp(t->name,y)==0 &&strcmp(t->birth_date,z)==0))
	  {
		*Y=1;

		break;
	  }
	      t=t->next;
	}

	  if(*Y==0)
	  {

		space=(node*)malloc(sizeof(node));

		strcpy(space->aadhar,x);

		strcpy(space->name,y);

		strcpy(space->birth_date,z);
		t=space;
	    space->next=NULL;

	}
  }
  return start;
 }

