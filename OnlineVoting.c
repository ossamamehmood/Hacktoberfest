#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define CANDIDATE_COUNT

#define CANDIDATE1 "Manish Tiwari"
#define CANDIDATE2 "Shubam Tiwari"
#define CANDIDATE3 "Nazia Nafis"
#define CANDIDATE4 "Chandranath Adak"
#define option "NOTA"
void getLeadingCandidate();
void castVote();
void votesCount();
char a[1000][1000];
char p[1000][1000];
int q,r,k,x =0;
int z,s,l,y = 0;
void Login() 
{ 
   
  char voterid[20]; 
  char password[20];
  int i; 
   
  printf("\nEnter your voterid : "); 
  scanf("%s",&voterid); 
  printf("Enter your password : "); 
  scanf("%s",&password);
  
 if(!strcmp(voterid,"LCS2021045") && !strcmp(password,"sindhu")) 
    {
        if(q != 0)
        {
        for(int i = 0;i<q;i++)
        {
            if(strcmp(a[q],voterid) && strcmp(password,p[q]))
            {
                z = 1;
            }
        }
        if(z==0)
        {
            printf("\n\nLogged In Successful"); 
        
        strcpy(a[q],"LCS2021045");
        strcpy(p[q],"sindhu");
        q++;
        z=0;
        castVote();
        votesCount();
        }
        else if(z==1)
        {
            z=0;
            printf("\n Warning!!!! Your have already voted.\n");
            Login();
        }
        }
        else if(q==0)
        {
            printf("\n\nLogged In Successful"); 
        strcpy(a[q],"LCS2021045");
        strcpy(p[q],"sindhu");
        q++;
        castVote();
        votesCount();
        }
    }
    else if(!strcmp(voterid,"LCS2021046") && !strcmp(password,"madhava"))
    {
        if(r!=0)
        {
        for(int i = 0;i<r;i++)
        {
        if(strcmp(a[r],voterid) && strcmp(password,p[r]))
        {
           s=1;
        }
        }
        if(s==0)
        {
            printf("\n\nLogged In Successful");
            strcpy(a[r],"LCS2021046");
        strcpy(p[r],"madhava");
        r++;
        s=0; 
         castVote();
        votesCount();
        
        }
        else if(s==1)
        {
            s=0;
            printf("\n Warning!!!! Your have already voted.\n");
            
            Login();
        }
        }
        else if(r==0)
        {
            printf("\n\nLogged In Successful");
            strcpy(a[r],"LCS2021046");
            strcpy(p[r],"madhava");
            r++; 
        castVote();
        votesCount();
        
        }
    }
    else if(!strcmp(voterid,"LCS2021030") && !strcmp(password,"avani"))
    {
        if(k!=0)
        {
        for(int i = 0;i<k;i++)
        {
        if(strcmp(a[k],voterid) && strcmp(password,p[k]))
        {
            l=1;
        }
        }
        if(l==0)
        {
        printf("\n\nLogged in Sucessful");
        
        strcpy(a[k],"LCS2021030");
        strcpy(p[k],"avani");
        k++;
        l=0;
        castVote();
        votesCount();
        }
        else if(l==1)
        {
            printf("\n Warning!!!! Your have already voted.\n");
            l=0;
            Login();
        }
        }
        else if(k==0)
        {
            printf("\n\nLogged In Successful"); 
        
        strcpy(a[l],"LCS2021030");
        strcpy(p[l],"avani");
        k++;
        castVote();
        votesCount();
        }
    }
    else if(!strcmp(voterid,"LCS2021057") && !strcmp(password,"divya"))
    {
        if(x!=0)
        {
        for(int i = 0;i<x;i++)
        {
            if(strcmp(a[x],voterid) && strcmp(password,p[x]))
        {
            y=1;
        }
        }
        if(y==0)
        {
            printf("\n\nLogged in Sucessful");
        
        strcpy(a[x],"LCS2021057");
        strcpy(p[x],"divya");
        x++;
        y=0;
        castVote();
        votesCount();
        }
        else if(y==1)
        {
            printf("\n Warning!!!! Your have already voted.\n");
            y=0;
            Login();
        }
        }
        else if(x==0)
        {
            printf("\n\nLogged In Successful"); 
        
        strcpy(a[x],"LCS2021057");
        strcpy(p[x],"divya");
        x++;
        castVote();
        votesCount();
        }
    }
    else if(!strcmp(voterid,"0") && !strcmp(password,"0"))
    {
        printf("\n\nThank you.\n If you are facing issues please contact the developer team at 9381069270.\n ");
        getLeadingCandidate();
    }
    else 
    { 
        printf("\n\nIncorrect username or password.\n TO EXIT and to have a look at Winner.\nPlease Enter 0 for both password and id.\n");
        Login();
    }
} 

int votesCount1=0, votesCount2=0, votesCount3=0, votesCount4=0, votesCount5=0;

void castVote(){
int choice;    
printf("\n\n ### Please choose your Candidate ####\n\n");
printf("\n 1. %s", CANDIDATE1);
printf("\n 2. %s", CANDIDATE2);
printf("\n 3. %s", CANDIDATE3);
printf("\n 4. %s", CANDIDATE4);
printf("\n 5. %s", "NOTA");

printf("\n\n Input your choice (1 - 4) : ");
scanf("%d",&choice);

switch(choice){
    case 1: votesCount1++; break;
    case 2: votesCount2++; break;
    case 3: votesCount3++; break;
    case 4: votesCount4++; break;
    case 5: votesCount5++; break;
    default: printf("\n Error: Wrong Choice !! Please retry");
             //hold the screen
             getchar();
}
printf("\n thanks for vote !!");
}

void votesCount(){
printf("\n\n ##### Voting Statics ####");
printf("\n %s - %d ", CANDIDATE1, votesCount1);
printf("\n %s - %d ", CANDIDATE2, votesCount2);
printf("\n %s - %d ", CANDIDATE3, votesCount3);
printf("\n %s - %d ", CANDIDATE4, votesCount4);
printf("\n %s - %d ", option, votesCount5); 
int a = 0;
printf("\n \n Let me know whether you are the last voter or not by pressing \n 1-If you are Not last candidate\n 2-If you are the last candidate:\n");
scanf("%d",&a);
if(a == 1)
{
    Login();
}
else if ( a == 2)
{
    getLeadingCandidate();
}
}

void getLeadingCandidate(){
    printf("\n\n  #### Leading Candiate ####\n\n");
    if(votesCount1>votesCount2 && votesCount1>votesCount3 && votesCount1 >votesCount4)
    printf("[%s]",CANDIDATE1);
    else if (votesCount2>votesCount3 && votesCount2>votesCount4 && votesCount2 >votesCount1)
    printf("[%s]",CANDIDATE2);
    else if(votesCount3>votesCount4 && votesCount3>votesCount2 && votesCount3 >votesCount1)
    printf("[%s]",CANDIDATE3);
    else if(votesCount4>votesCount1 && votesCount4>votesCount2 && votesCount4 >votesCount3)
    printf("[%s]",CANDIDATE4);
    else
    printf("----- Warning !!! No-win situation----");    

exit(0);   
}

int main()
{
int i;
int choice;

// do{
printf("\n\n ###### Welcome to Election/Voting 2022 #####");
printf("\n\n 1.Login");
printf("\n 2. Cast the Vote");
printf("\n 3. Find Vote Count");
printf("\n 4. Find leading Candidate");
// printf("\n 0. Exit");

Login();

 getLeadingCandidate();
return 0;
}


