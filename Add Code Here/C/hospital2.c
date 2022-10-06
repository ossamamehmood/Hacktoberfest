#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void clrscr(void)
{
    system("cls()");
}
 
struct ad 
{
    char name[30];
    char disease[30];
    int cabin,phone,age;
} x[100];
int n,i,j=0,a=0,sum=0,g,flag,num; 
void read ();
void write(); 
void add();
void view();
void search();
void edit();
void del();
void show();
int main()
{
    read();
    int c,i,q;
    printf("\n\nWelcome to Manipal Hospital Management System\n\n");
    int m,n;
//making out the pattern
    
    for(m=1; m<=4; m++)
    {
        for(n=1; n<=5; n++)
            printf(" ");
        for(n=1; n<=m-1; n++)
        {
            printf(" ");
        }
        for(n=1; n<=4-m+1; n++)
        {
            if(n==4-m+1 || m==1 || m==4)
                printf("*");
            else
                printf(" ");
        }
        for(n=1; n<=4-m+1; n++)
        {
            if(n==1 ||m==1 || m==4)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    while(c!=6)
    {

        printf("*Enter your choice*\n\n1. Add Information\n2. View Information\n3. Search\n4. Edit Information\n5. Delete Information\n6. Exit\n\nOption =");
        scanf("%d",&c);//choice for option
        fflush(stdin);//making it clear
        if(c==1)//add
        {
            system("cls");
            add();
        }
        else if(c==2)//view
        {
            system("cls");
            view();
        }
        else if(c==3)//search
        {
            system("cls");
            search();
        }
        else if(c==4)//edit
        {
            system("cls");
            edit();
        }
        else if(c==5)//delete
        {
            system("cls");
            del();
        }
        else if(c==6)
        {
            write();
            return 0;
        }
        else
        {
            system("cls");
            printf("\n\nInvalid input , try again by using valid inputs");
        }
        printf("\n\n");
    }
    return 0;
}
void add()
{
    printf("\n\n");
    printf("Data already exists in the database = %d\n\n",num);//how many inputs
    printf("How many entry do you want to add =\n");
    scanf("%d",&n);
    sum=n+num;

    for(i=num,j=0; i<sum; i++)
    {
        printf("\n");
        fflush(stdin);
        printf("Enter patient's Name = ");
        gets(x[i].name);
        fflush(stdin);
        printf("Enter disease = ");
        gets(x[i].disease);
        fflush(stdin);
        printf("Enter the age = ");
        scanf("%d",&x[i].age);
        fflush(stdin);
        printf("Enter cabin no = ");
        scanf("%d",&x[i].cabin);
        fflush(stdin);
        printf("Enter phone number = ");
        scanf("%d",&x[i].phone);
        fflush(stdin);
        printf("\n");
        j++;
        a++;
        num++;
    }
}

void view()
{
    for(i=0; i<num; i++)
    {
        printf("\n");
        printf("Serial Number = %d\n",i);
        printf("Name = ");
        puts(x[i].name);
        printf("Disease = ");
        puts(x[i].disease);
        printf("Cabin no = %d\nPhone number = 0%d\nAge = %d",x[i].cabin,x[i].phone,x[i].age);
        printf("\n\n");
    }
}
void edit()
{
    int q,p;
    fflush(stdin);
    printf("What do you want to edit ?\n");
    printf("Enter your option\n");
    printf("1.Name\n2.Disease\n3.Age\n4.Cabin\n5.Phone no.\n");
    printf("Option =");
    scanf("%d",&q);//option
    if(q<=5)
    {
        printf("Enter the serial no of that patient = (0 - %d) =",num-1);
        scanf("%d",&p);//serial number
        if(p<num)
        {
            if(q==1)
            {
                fflush(stdin);
                printf("Enter the new name =");
                gets(x[p].name);

            }
            else if(q==2)
            {
                fflush(stdin);
                printf("Enter the new Disease =");
                gets(x[p].disease);
            }
            else if(q==3)
            {
                fflush(stdin);
                printf("Enter the new Age =");
                scanf("%d",&x[p].age);
            }

            else if(q==4)
            {
                fflush(stdin);
                printf("Enter the new Cabin no =");
                scanf("%d",&x[p].cabin);
            }

            else if(q==5)
            {
                fflush(stdin);
                printf("Enter the new Phone no =");
                scanf("%d",&x[p].phone);
            }
        }
        else
        {
            printf("\n\nInvalid Serial \nTry Again !!\n\n");
        }
    }
    else
    {
        printf("\n\nInvalid option\nTry Again!!\n\n");
    }
}
void search()
{
    int s,h,f;
    char u[100];
    printf("By what do you want to search ?\n");
    printf("1.Serial no.\n2.Name\n3.Disease\n4.Cabin no.\n5.Phone no.\n6.Age\n\nOption = ");
    scanf("%d",&h);
    if(h==1)
    {
        printf("Enter Serial number of the patient =");
        scanf("%d",&s);
        if(s<num)
        {
            printf("\n");
            printf("Serial Number = %d\n",s);
            printf("Name = ");
            puts(x[s].name);
            printf("Disease = ");
            puts(x[s].disease);
            printf("Cabin no = %d\nPhone number = 0%d\nAge = %d",x[s].cabin,x[s].phone,x[s].age);
            printf("\n\n");
        }
        else
            printf("\n\nNot Found\n\n");
    }
    else if(h==2)//problem is here.........
    {
        int f=1;
        fflush(stdin);
        printf("Enter your name =");
        gets(u);
        fflush(stdin);
        for(g=0; g<num; g++)
        {
            if(strcmp(u,x[g].name)==0)
            {
                printf("\n");
                printf("Serial Number = %d\n",g);
                printf("Name = ");
                puts(x[g].name);
                printf("Disease = ");
                puts(x[g].disease);
                printf("Cabin no = %d\nPhone number = 0%d\nAge = %d",x[g].cabin,x[g].phone,x[g].age);
                printf("\n\n");
                f=0;

            }
        }
        if(f==1)
            printf("\nNot Found\n");



    }
    else if(h==3)
    {
        int f=1;
        fflush(stdin);
        printf("Enter Disease = ");
        gets(u);
        fflush(stdin);
        for(g=0; g<num; g++)
        {
            if(strcmp(u,x[g].disease)==0)
            {
                printf("\n");
                printf("Serial Number = %d\n",g);
                printf("Name = ");
                puts(x[g].name);
                printf("Disease = ");
                puts(x[g].disease);
                printf("Cabin no = %d\nPhone number = 0%d\nAge = %d",x[g].cabin,x[g].phone,x[g].age);
                printf("\n\n");
                f=0;
            }


        }
        if(f==1)
            printf("\nNot Found\n");


    }
    else if(h==4)
    {
        int f=1;
        printf("Enter Cabin number = ");
        scanf("%d",&f);
        for(g=0; g<num; g++)
        {
            if(f==x[g].cabin)
            {
                printf("\n");
                printf("Serial Number = %d\n",g);
                printf("Name = ");
                puts(x[g].name);
                printf("Disease = ");
                puts(x[g].disease);
                printf("Cabin no = %d\nPhone number = 0%d\nAge = %d",x[g].cabin,x[g].phone,x[g].age);
                printf("\n\n");
                f=0;
            }

        }
        if(f==1)
            printf("Not Found\n\n");

    }
    else if(h==5)
    {
        int f=1;
        printf("Enter Phone number = ");
        scanf("%d",&f);
        for(g=0; g<num; g++)
        {
            if(f==x[g].phone)
            {
                printf("\n");
                printf("Serial Number = %d\n",g);
                printf("Name = ");
                puts(x[g].name);
                printf("Disease = ");
                puts(x[g].disease);
                printf("Cabin no = %d\nPhone number = 0%d\nAge = %d",x[g].cabin,x[g].phone,x[g].age);
                printf("\n\n");
                f=0;
            }

        }
        if(f==1)
            printf("Not Found");
    }
    else if(h==6)
    {
        int f=1;
        printf("Enter Age = ");
        scanf("%d",&f);
        for(g=0; g<num; g++)
        {
            if(f==x[g].age)
            {
                printf("\n");
                printf("Serial Number = %d\n",g);
                printf("Name = ");
                puts(x[g].name);
                printf("Disease = ");
                puts(x[g].disease);
                printf("Cabin no = %d\nPhone number = 0%d\nAge = %d",x[g].cabin,x[g].phone,x[g].age);
                printf("\n\n");
                f=0;
            }

        }
        if(f==1)
            printf("Not Found\n\n");

    }
    else
        printf("\n\nInvalid input\n\n");




}
void del()
{
    int f,h;
    printf("Enter the serial number of the patient that you want to delete =");
    scanf("%d",&f);
    if(f<num)
    {
        printf("What do you want ?\n");
        printf("1.Remove the whole record\n2.Remove Name\n3.Remove Disease\n4.Remove age\n5.Remove Cabin\n6.Remove phone number\nOption = ");
        scanf("%d",&h);
        if(h==1)
        {
            while(f<num)
            {
                strcpy(x[f].name,x[f+1].name);
                strcpy(x[f].disease,x[f+1].disease);
                x[f].age=x[f+1].age;
                x[f].cabin=x[f+1].cabin;
                x[f].phone=x[f+1].phone;
                f++;
            }
            num--;
        }
        else if(h==2)
        {
            strcpy(x[f].name,"Cleared");

        }
        else if(h==3)
        {
            strcpy(x[f].disease,"Cleared");
        }
        else if(h==4)
        {
            x[f].age=0;
        }
        else if(h==5)
        {
            x[f].cabin=0;
        }
        else if(h==6)
        {
            x[f].phone=0;
        }

    }
    else
        printf("\n\nInvalid Serial number\n");

}
void read()
{
    FILE *fp = fopen("patient.txt","r");
    if(fp == NULL)
    {
        //create empty file, so that we can open it
        //in the next execution of this program
        fp = fopen("patient.txt","w");
        fclose(fp);
        printf("File does not exist, I JUST CREATED IT, exiting...\n\n\n");
    }

    num = fread(x, sizeof(struct ad),100, fp);
    fclose(fp);
    
    
}
void write()
{
    FILE *fp = fopen("patient.txt","w");
    if(fp == NULL)
    {
        printf("Error");
        exit(1);
    }
    fwrite(x, sizeof(struct ad),num, fp);

    fclose(fp);
}