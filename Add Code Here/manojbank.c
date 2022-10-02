#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void login();  // maximum 3 attempts
void menu();
void checkbalance();
void withdraw();
void deposit();
void proceed();
float read();
void write(float n);

float total = 6000;

void main()
{
    login();
}

void write(float n)
{
    FILE *fp;
    fp = fopen("balance.txt","a");
    fprintf(fp,"\n%f",n);
    fclose(fp);
}


float read()
{
    FILE *fp;
    float n;
    fp = fopen("balance.txt","r");
    if(fp == NULL)
    {
        printf("Internal Error!");
        exit(0);
    }
    while(fscanf(fp,"%f",&n) == 1);
    fclose(fp);
    return n;
}

void proceed()
{
    char ch;
    printf("\nPress Y to continue... ");
    scanf(" %c",&ch);
    system("cls");
    if(ch == 'Y' || ch == 'y')
    {
        menu();
    }
    else
    {
        exit(0);
    }
}

void deposit()
{
    float da;
    float n = read();
    printf("Enter Amount to Deposit : ");
    scanf("%f",&da);
    if(da<=10000)
    {
        total = total + da;
        n += da;
        printf("\nDeposited Amount = $%.2f\n",da);
        printf("\nTotal Balance = $%.2f\n",n);
        write(n);
    }
    else
    {
        printf("\nAmount must not be greater than 10k!\n");
    }
}

void withdraw()
{
    float wa;
    float n = read();
    printf("Enter Amount to Withdraw : ");
    scanf("%f",&wa);
    if(wa <= n)
    {
        if(wa <= 5000)
        {
            if((int)wa%500 == 0)
            {
                total = total - wa;
                n -= wa;
                printf("\nWithdraw Amount = $%.2f\n",wa);
                printf("\nTotal Available Balance  = $%.2f\n",n);
                write(n);
            }
            else
            {
                printf("\nAmount must be Multiple of 500!\n");
            }
        }
        else
        {
            printf("\nAmount Exceeds Per Transaction Limit!\n");
        }
    }
    else
    {
        printf("\nInsufficient Balance!\n");
    }
}

void checkbalance()
{
    printf("Your Total Balance is $%.2f",read());
}

void menu()
{
    int n;
    printf("************* Welcome to Manoj International Bank ***************\n");
    printf("Options:\n1. Check Balance\n2. Withdraw\n3. Deposit\n4. Exit\n   Select : ");
    scanf("%d",&n);
    system("cls");
    switch(n)
    {
    case 1:

        checkbalance();
        break;
    case 2:

        withdraw();
        break;
    case 3:

        deposit();
        break;
    case 4:

        printf("Exit");
        break;
    default:
        printf("\nInvalid Option!\n");
    }
    proceed();
}


void login()
{
    char susr[20] = "manoj";
    char spwd[20] = "manoj@123";
    char usr[20],pwd[20];
    int i,flag=0;
    for(i=1;i<=3;i++)
    {
        printf("Attempt Remaining %d\n",(4-i));
        printf("Enter your user Name : ");
        gets(usr);
        printf("Enter your user Password : ");
        gets(pwd);

        if((strcmp(susr,usr)==0)&&(strcmp(spwd,pwd)==0))
        {
            flag = 1;
            printf("\nWelcome %s!\n\n\n",usr);
            menu();
        }
        else
        {
            flag = 0;
            printf("\nLogin Failed!\n");
        }
    }

    if(flag == 1)
    {
        printf("\nWelcome %s\n",usr);
    }
    else
    {

                printf("\nYour Account is Locked!\n");
    }
}
