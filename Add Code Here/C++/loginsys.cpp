#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
void login();
void registerr();
void forget();
int main()
{

   int choice;
   cout<<"\t\t\t  LOGIN PAGE \t\t\t"; 
   cout<<"\t\t\t ----------Menu------------"; 
   cout<<"\t\t\t                                    \t\t\t"<<endl;
   cout<<"\t | Click 1 to register |"<<endl;
   cout<<"\t | Click 2 to login |"<<endl;
   cout<<"\t | Click 3  for forgot password |"<<endl;
   cout<<"\t | Click 4  exit |"<<endl;
   cout<<"\t |                         |"<<endl;
   cout<<"\t | ----Pleasew enter your choice------ |"<<endl;
   cin>>choice;
   cout<<"          Thankyou for your response                  "<<endl;
            switch(choice)
         {
     case 1 :cout<<" ----going to register menu----";
      registerr();
      break;
     case 2 :cout<<" ----going to login menu----";
      login();
      break;
      case 3 :cout<<" ----going to forget password menu----";
       forget();
      break;
      case 4 : cout<<"----    Thank You    ----"<<endl;
      break;
     default:
     system("CLS");
     cout<<"  --Please select from the option given --";
     main();
      
       }
return 0;
};

void login(){
   int count;
   string id,password,userid,pass;
   system("cls");
   cout<<"   --please enter UIsername and Password--"<<endl;
   cout<<" ----USERNAME---- ";
   cin>>userid;
   cout<<" --PASSWORD--";
   cin>>password;
   ifstream input("records.txt");
   while(input>>id>>pass){
     if(id == userid && pass == password){
      count =1;
      system("cls");
     }
   }
input.close();
if(count ==1){
   cout<<" ----login Success----"<<endl;
   cout<<" your user id is "<<userid;
   cout<<"   -----Thanks for Logging ------";
   main();
}
else{
   cout<<" \t\t User Not regisster \t\t";
   cout<<" \t\t Check your username \t\t";
   main();
}
}
void registerr(){
   string ruserid,rid,rpassword,rpass;
   cout<<" Enter the user Name you want to put";
   cin>>ruserid;
   cout<<" Enter the password you want to put";
   cin>>rpassword;
   ofstream f1("records.txt", ios::app);
   f1<<ruserid<<"  "<<rpassword;
   system("cls");
   cout<<"\t\t\t --- registration succesful-=----\n";
   main();


}
void forget(){
   int option;
   system("cls");
   cout<<" \t\t\t  FORGOT PASSWORD MENU\n";
   cout<<" press 1 to search your id "<<endl;
   cout<<" press 2 to goto main"<<endl;
   cout<<" \t\t\t  Enter your choice"<<endl;
   cin>>option;
   switch(option){

      case 1: {
         int count = 0;
         string suserid,spassword,id,pass;
         cout<<" enter your username ";
         cin>>suserid;
         ifstream in("names.txt");
         in>>id>>pass;
         if(suserid==id&&spassword==pass){
            count =1;
      
         }
in.close();
if(count == 1){
    cout<<" your id is found ";
    cout<<" your password is "<<spassword;
    main();
}
else {
   cout<<" account not found going to main ";
   main();
}
      }

   case 2 : cout<<" going to main ";
   main();
   break;
   default : system("cls");
   cout<<" enter valid option";
   main();

   }
}