//Movie ticket booking program

#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <process.h>
#include <time.h>
using namespace std;

class ticket{
	public:
	char name[20];
	char cno[11];
} t;


class card :  public ticket{
public:
	char address[50];
	char emailid[20];
} v;


void pay(int);
void random();
void card();


int main(){
	system("CLS");

	int ent, a, b, N, x, cardid;
	char ans;
	do{
		cout<<"\n\t\t----------------------------------";
		cout<<"\n\t\t    Movie Ticket Booking System";
		cout<<"\n\t\t----------------------------------";
		cout<<"\n\t\t\tWelcome Customer!";
		cout<<"\n\n\t\t\t<1> Movie Timings";
		cout<<"\n\t\t\t<2> Recieving Ticket";
		cout<<"\n\t\t\t<3> Contact Us";
		cout<<"\n\t\t\t<4> DTCard Registration";
		cout<<"\n\t\t\t<5> Exit \n\n";
		cout<<"\t\t\tEnter Your Choice :"<<"\t";
		cin>>ent;
	switch(ent)
	{

		case 1:
		system("CLS");
		cout<<"\n\n\t\t\tThe Shows are :";
			cout<<"\n\n\t\t\t1. Avengers: Endgame";
			cout<<"\n\n\t\t\t2. Super Girl";
			cout<<"\n\n\t\t\t3. Deadpool 3";
			cout<<"\n\n\t\t\t4. Free Guy";
			cout<<"\n\n\t\t\t5. Ready or Not\n";
			cout<<"\n\t\t\tEnter Your Choice :"<<"\t";
			cin>>a;
			cout<<"\n\n\t\t\tThe Timings for the selected show are:";
			switch(a)
			{
				case 1:
					system("CLS");
				 cout<<"\n\n\t\t\tSelect the the timings: ";
					cout<<"\n\t\t\t1. 0800";
					cout<<"\n\t\t\t2. 1300";
					cout<<"\n\t\t\t3. 1450";
					cout<<"\n\t\t\t4. 1800";
					cout<<"\n\t\t\t5. 2100";
					cout<<"\n\t\t\t6. 0100 \n";
					cout<<"\n\n\t\tPlease select the timings: ";
					cin>>b;
					cout<<"\n\n\t\tEnter your name: ";
					cin>>t.name;
					cout<<"\n\n\t\tEnter your contact number: ";
					cin>>t.cno;
					cout<<"\n\n\t\tEnter the number of tickets you want to purchase: ";
					int x;
					cin>>x;
					pay(x);
					cout<<"\n\n\n\t\t\tYour ticket is here: ";
					cout<<"\n\t\t\tName 		:"<<t.name;
					cout<<"\n\t\t\tContact No	:"<<t.cno;
					cout<<"\n\t\t\tShow timings 	:";
					switch(b)
						{
							case 1:	cout<<"0800";
								break;
							case 2:	cout<<"1300";
								break;
							case 3:	cout<<"1450";
								break;
							case 4:	cout<<"1800";
								break;
							case 5:	cout<<"2100";
								break;
							case 6:	cout<<"0100";
								break;
						}
						cout<<"\n\n\t\t\tDo you want to choose another option(y/n)";
						cin>>ans;
						system("CLS");
						break;
				case 2:
				system("CLS");
				cout<<"\n\n\t\t\tSelect the the timings:";
					cout<<"\n\t\t\t1. 0900";
					cout<<"\n\t\t\t2. 1100";
					cout<<"\n\t\t\t3. 1250";
					cout<<"\n\t\t\t4. 1500";
					cout<<"\n\t\t\t5. 2000";
					cout<<"\n\t\t\t6. 2200";
					cout<<"\n\t\t\tPlease select the timings: ";
					cin>>b;
					cout<<"\n\n\t\t\tEnter your name: ";
					cin>>t.name;
					cout<<"\n\t\t\tEnter your contact number: ";
					cin>>t.cno;
					cout<<"\n\t\t\tEnter the number of tickets you want to purchase: ";
					cin>>x;
					pay(x);
					cout<<"\n\n\t\t\tYour ticket is here:";
					cout<<"\n\t\t\tName 		:"<<t.name;
					cout<<"\n\t\t\tContact No	:"<<t.cno;
					cout<<"\n\t\t\tShow timings 	:";
					switch(b)
					{
							case 1:	cout<<"0800";
								break;
							case 2:	cout<<"1300";
								break;
							case 3:	cout<<"1450";
								break;
							case 4:	cout<<"1800";
								break;
							case 5:	cout<<"2100";
								break;
							case 6:	cout<<"0100";
								break;
					}
					cout<<"\n\n\t\t\tDo you want to choose another option(y/n)";
					cin>>ans;
					system("CLS");
					break;
				case 3:
				system("CLS");
				cout<<"\n\n\t\t\tSelect the the timings:";
					cout<<"\n\t\t\t1. 0800";
					cout<<"\n\t\t\t2. 1300";
					cout<<"\n\t\t\t3. 1450";
					cout<<"\n\t\t\t4. 1800";
					cout<<"\n\t\t\t5. 2100";
					cout<<"\n\t\t\t6. 0100";
					cout<<"\n\t\t\tPlease select the timings";
					cin>>b;
					cout<<"\n\t\t\tEnter your name: ";
					cin>>t.name;
					cout<<"\n\t\t\tEnter your contact number: ";
					cin>>t.cno;
					cout<<"\n\t\t\tEnter the number of tickets you want to purchase: ";
					cin>>x;
					pay(x);
					cout<<"\n\n\t\t\tYour ticket is here: ";
					cout<<"\n\t\t\tName 		:"<<t.name;
					cout<<"\n\t\t\tContact No	:"<<t.cno;
					cout<<"\n\t\t\tShow timings 	:";
					switch(b)
					{
							case 1:	cout<<"0900";
								break;
							case 2:	cout<<"1300";
								break;
							case 3:	cout<<"1450";
								break;
							case 4:	cout<<"1800";
								break;
							case 5:	cout<<"2100";
								break;
							case 6:	cout<<"0100";
								break;
					}
					cout<<"\n\n\t\t\tDo you want to choose another option(y/n)";
					cin>>ans;
					system("CLS");
					break;
				case 4:
				system("CLS");
				cout<<"\n\n\t\t\tSelect the the timings: ";
					cout<<"\n\t\t\t1. 0800";
					cout<<"\n\t\t\t2. 1300";
					cout<<"\n\t\t\t3. 1450";
					cout<<"\n\t\t\t4. 1800";
					cout<<"\n\t\t\t5. 2100";
					cout<<"\n\t\t\t6. 0100";
					cout<<"\n\t\t\tPlease select the timings: ";
					cin>>b;
					cout<<"\n\t\t\tEnter your name: ";
					cin>>t.name;
					cout<<"\n\t\t\tEnter your contact number: ";
					cin>>t.cno;
					cout<<"\n\t\t\tEnter the number of tickets you want to purchase: ";
					cin>>x;
					pay(x);
					cout<<"\n\n\t\t\tYour ticket is here: ";
					cout<<"\n\t\t\tName 		:"<<t.name;
					cout<<"\n\t\t\tContact No	:"<<t.cno;
					cout<<"\n\t\t\tShow timings 	:";
					switch(b)
					{
							case 1:	cout<<"0800";
								break;
							case 2:	cout<<"1300";
								break;
							case 3:	cout<<"1450";
								break;
							case 4:	cout<<"1800";
								break;
							case 5:	cout<<"2100";
								break;
							case 6:	cout<<"0100";
								break;
					}
						cout<<"\n\n\t\t\tDo you want to choose another option(y/n)";
						cin>>ans;
						system("CLS");
						break;
				case 5:
				system("CLS");
				cout<<"\n\n\t\t\tSelect the the timings:";
					cout<<"\n\t\t\t1. 0800";
					cout<<"\n\t\t\t2. 1300";
					cout<<"\n\t\t\t3. 1450";
					cout<<"\n\t\t\t4. 1800";
					cout<<"\n\t\t\t5. 2100";
					cout<<"\n\t\t\t6. 0100";
					cout<<"\n\t\t\tPlease select the timings: ";
					cin>>b;
					cout<<"\n\t\t\tEnter your name: ";
					cin>>t.name;
					cout<<"\n\t\t\tEnter your contact number: ";
					cin>>t.cno;
					cout<<"\n\t\t\tEnter the number of tickets you want to purchase: ";
					cin>>x;
					pay(x);
					cout<<"\n \n\t\t\tYour ticket is here: ";
					cout<<"\n\t\t\tName 		:"<<t.name;
					cout<<"\n\t\t\tContact No	:"<<t.cno;
					cout<<"\n\t\t\tShow timings 	:";
					switch(b)
					{
							case 1:	cout<<"0800";
								break;
							case 2:	cout<<"1300";
								break;
							case 3:	cout<<"1450";
								break;
							case 4:	cout<<"1800";
								break;
							case 5:	cout<<"2100";
								break;
							case 6:	cout<<"0100";
								break;
					}
					cout<<"\n\n\t\t\tDo you want to choose another option(y/n)";
					cin>>ans;
					system("CLS");
					break;
			}break;
		case 2:	system("CLS");
				cout<<"\n\nThank you for booking the tickets online \nTo print out the tickets please enter your Name in the portal.";
				struct pre
				{
				char name[10];
				} p;
				cout <<"\nEnter your name:";
				cin>>p.name;
				cout<<"\nWe're sorry to say, but you will need to get the print out of the booking in front of our cinema.\nThe system did't have a printable function yet.";
				cout<<"\n Do you want to choose another option(y/n)";
				cin>>ans;
				system("CLS");
				break;
		case 3: system("CLS");
				cout<<"\n Do you want to choose another option(y/n)";
				cin>>ans;
				system("CLS");
				break;
		case 4: system("CLS");
				cout<<"Good Morning/Evening Mam/Sir\n Welcome to our cinemas \n";
				card();
				cout<<"It will take us a week for completing your registration for the card. \n Please see the benefits of the card on the next page. -->";
				char f;
				cout<<"\n For selecting the page to go to benefits say (y/n)\n";
				cin>>f;
				if(f=='y')
				{
					cout<<"Thank you for registeration once again \n The priveleges provided with this card are as follows:";
					cout<<"\n 1. For every purchase of a movie ticket you get 25 points(1point = 1$.) so after 16 movies you get a free movie ticket.";
					cout<<"\n 2. You are provided with regular updates regarding the movie and the showtimings.";
					cout<<"\n 3. Anytime prebook tickets for the upcoming movie and preffered seats will be provided.";
				}
				cout<<"\n Do you want to choose another option(y/n)";
				cin>>ans;
				if(ans=='y')
				{
					system("CLS");
					break;
				}
				else
				{
					exit(0);
				}
				break;
		case 5:
		system("CLS");
		system("PAUSE");
		exit(0);
				break;
	}
	}while(ans=='y');
	}


void card()
{
	int cardid;
	cout<<"\nWelcome:\nYou can register a card for facility in our cinemas";
	cout<<" \nEnter your name: ";
	cin>>v.name;
	cout<<"Enter your mobile number: ";
	cin>>v.cno;
	system("CLS");
	int ID;
	srand (time(NULL));
	ID = rand() % 400000 + 4000000;
	if (ID<0)
	ID=(ID*-1);
	cout<<"Your new card number is - :" <<"\t"<<ID;
	fstream fout;
	fout.open("card.dat", ios::out|ios::app);
	fout<<"\n Name :"<<v.name<<"\n"<<"\n Mobile No. :"<<v.cno<<"\n"<<"\nCard Number:"<<ID;
	fout.close();
	cout<<"\nThank you for the registeration for the card. \n";
}


void pay(int a)
{
	int normal, gold, amt[2],id;
	time_t t = time(NULL);
	tm* timePtr = localtime(&t);
	fstream fin;
	fin.open("card.dat", ios::in|ios::app);
	fin>>id;
	cout<<"\t\tThank you for selecting the show. Now we request you to select your type of seating \n\n\t\t\t\t 1.Normal Class \n\t\t\t\t OR \n\t\t\t\t 2. Gold Class";
	int c;
	cin>>c;
	if(c==1)
	{
		cout<<"\n\n\t\t\tYou selected for a Normal show \n\n\t\t\t\t";
		system("PAUSE");
		system("CLS");
		amt[1] = a * 400;
		char final;
		cout<<"\n\n\t\t\tDo you have DTcard(y/n): ";
		cin>>final;
		if(final=='y')
		{
			int cid;
			fin.read((char*) &v, sizeof(v));

			cout<<"\n\t\t\tEnter the card number[10 digits]: ";

			if(cid==id)
			{
				amt[1]=amt[1] - (0.1*amt[1]);
			};
		}
		cout<<"\n\t\t\tWant to pay by Card(y/n): ";
		char rep;
		cin>>rep;
		cout<<"\n\t\t\t"<<"Paying :"<<amt[1]<<"\n";
		if (rep=='y'||rep=='Y')
		{
			cout<<"\t\t\tName of the card holder: ";
			char n[10];
			gets(n);
			cout<<"\n\t\t\tEnter the card number: ";
			char Card[16];
			gets(Card);
			cout<<"\t\t\t\tExpiry(MM/YYYY)";
			int expirymm,expiryyy;
			cin>>expirymm;
			cout<<"\t\t\t\t/";
			cin>>expiryyy;
			while(expirymm<(timePtr->tm_mon) || expiryyy<(timePtr->tm_year + 1900)){
				if(expirymm<=(timePtr->tm_mon))
					{
						cout<<"\t\t\t\tEnter the month again: ";
						cin>>expirymm;
					}
				if(expiryyy<(timePtr->tm_year + 1900))
				{
					cout<<"\t\t\t\tPlease enter a valid year: ";
					cin>>expiryyy;
				}
			};
			char password[3],vh;
			int h;
			puts("\t\t\t\tEnter the CVV/CVV2: ");
			while (1)
			{
				if (h<0)
					h=0;
				vh=getch();
				if (vh==13)
					break;
				if (vh==8)
				{
					putch(NULL);
					putch(NULL);
					putch(NULL);
					h--;
					continue;
				}
				password[h++]=vh;
				vh='*';
				putch(vh);
			};
			password[h]=='\0';
		}
	}
	else
	{
		cout<<"\n\n\t\t\tYou selected for the Gold Class \n\t\t\t\t";
			system("PAUSE");
		system("CLS");
		amt[2] = a * 700;
		char final;
		cout<<"\n\t\t\tDo you have DTcard(y/n): ";
		cin>>final;
		if(final=='y')
		{
			int cid;
			cout<<"\n\t\t\tEnter the card id number: ";
			cin>>cid;
			if(cid==id)
			{
				amt[1]=amt[1] - (0.1*amt[1]);
			};
		}
		cout<<"\n\t\t\tWant to pay by Card(y/n): ";
		char rep;
		cin>>rep;
		cout<<"\n\t\t\t"<<"Paying :"<<amt[2]<<"\n";
		if (rep=='y'||rep=='Y')
		{
			cout<<"\t\t\tName of the card holder: ";
			char n[10];
			gets(n);
			cout<<"\n\t\t\tEnter the card number: ";
			char Card[16];
			gets(Card);
			cout<<"\n\t\t\tExpiry(MM/YY): ";
			int expirymm, expiryyy;
			cin>>expirymm;
			cout<<"\n/";
			cin>>expiryyy;
			while(expirymm<(timePtr->tm_mon) || expiryyy<(timePtr->tm_year + 1900)){
				if(expirymm<=(timePtr->tm_mon))
					{
						cout<<"\n\t\t\tEnter the month again: ";
						cin>>expirymm;
					}
				if(expiryyy<(timePtr->tm_year + 1900))
				{
					cout<<"\n\t\t\tPlease enter a valid year: ";
					cin>>expiryyy;
				}
			};
			char password[3],vh;
			int h;
			puts("\n\t\t\tEnter the CVV/CVV2: ");
			while (1)
			{
				if (h<0)
					h=0;
				vh=getch();
				if (vh==13)
					break;
				if (vh==8)
				{
					putch(NULL);
					putch(NULL);
					putch(NULL);
					h--;
					continue;
				}
				password[h++]=vh;
				vh='*';
				putch(vh);
			};
			password[h]=='\0';
			}
	};
}
