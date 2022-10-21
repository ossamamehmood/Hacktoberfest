#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

 typedef struct Customers
{
    char name[100];
    long long int debit;
    int password;
    long long int balance;

}customer;
customer user[10];

 int security(char username[], long long int debit , int password){
    // printf("%d",user[0].password);
    int check=0,state=0;
    for(int i=0;i<2;i++){
        state=i;
        if(strcmp(username,user[i].name)){
            check++;
        }if(user[i].password==password){
            check++;
        }if(user[i].debit==debit){
            check++;
        }
        
    };
    if(check==3){
        // printf("\nmathced");
        return state;
    }else{
        state=0;
        // printf("\n not matched");
        return state;
    }
}
int main(){
    char name_list[][20]={"",""};
    long long int debit[10]={123456789,987654321};
    int password[10]={123,456};
    
    for(int i=0;i<2;i++){
        strcpy(user[i].name,name_list[i]);
        user[i].debit=debit[i];
        user[i].password=password[i];
        user[i].balance=10000;


    }
    //for debugging
    //     for(int i=0;i<2;i++){
    //    printf("\n name= %s debit number =%lld passowrd = %d balance = %d",user[i].name,user[i].debit,user[i].password,user[i].balance);
       
    // }
    while(true){
        int outerchoice;
        printf("------------------------------\n");
        printf("|WELCOME TO THE BANK CLI !!|\n");
        printf("|LOGIN TO PROCEED!!          |\n");
        printf("|----------------------------|\n");
        printf("\n[1] Login");
        printf("\n[2] Exit");
        printf("\nEnter your choice:- ");
        scanf("%d",&outerchoice);
        if(outerchoice==1){
            char username[20];
            int password;
            long long int debit;
            int local_state;
            printf("Enter your username:- ");
            scanf("%s",&username);
            printf("Enter your debit number:- ");
            scanf("%lld",&debit);
            printf("Enter your password:- ");
            scanf("%d",&password);
            local_state=security(username,debit,password);
            // printf("\n%d",local_state);
            if(local_state!=0){
                printf("\nLOGGED IN AS %S",user[local_state].name);
                while(true){
                    int innerchoice;
                    printf("\n[1] Withdraw");
                    printf("\n[2] Deposit");
                    printf("\n[3] Check Balance");
                    printf("\n[4] Exit");
                    printf("\nEnter your choice:- ");
                    scanf("%d",&innerchoice);
                    if(innerchoice==1){
                        printf("\n|--------------------------|");
                        printf("\n| WELCOME TO WITHDRAW MENU |");
                        printf("\n|--------------------------|");
                        printf("\n\n");
                        int ammount;
                        printf("\n Enter the ammount to withdraw:- ");
                        scanf("%d",&ammount);
                        if(ammount>user[local_state].balance){
                            
                            printf("\nERROR 404 ENOUGH FUNDS NOT FOUND !!");
                            printf("\nAVAILABLE BALANCE:- %d",user[local_state].balance);
                            printf("\n\n");
                        }else{
                            printf("\n%d WAS SUCCESSFULLY WITHDRAWN!!",ammount);
                            user[local_state].balance-=ammount;
                            printf("\nREMAINING BALANCE:- %d",user[local_state].balance);
                            printf("\n\n");

                        }
                        break;
                    }if(innerchoice==2){
                        printf("\n|--------------------------|");
                        printf("\n| WELCOME TO DEPOSIT MENU  |");
                        printf("\n|--------------------------|"); 
                        printf("\n\n");
                        int ammount;
                        printf("\n Enter the ammount to deposit:- ");
                        scanf("%d",&ammount);
                        printf("\n%d WAS SUCCESSFULLY DEPOSITED !!",ammount);
                        user[local_state].balance+=ammount;
                        printf("\nAVAILABLE BALANCE:- %d",user[local_state].balance);
                        printf("\n\n");
                        break;                     

                    }if(innerchoice==3){
                        printf("\nAVAILABLE BALANCE IS :-%d ",user[local_state].balance);
                        printf("\n\n");
                    }
                    if(innerchoice==4){
                        break;
                    }
                }
            }else{
                printf("\nDaya Kuch To Gadbad Hai");
                printf("\n\n");
            }
        }
        else if(outerchoice==2){
            break;
        }else{
            printf("\nThank you");
            printf("\n\n\n\n\n");
        }
    }
    return 0;
}
