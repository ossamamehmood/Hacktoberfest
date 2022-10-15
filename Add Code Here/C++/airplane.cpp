#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;


void main_menu();


class management{

    public:

        management(){

            main_menu();

        }


};


class details
{
    public:
        static string name, gender;
        int phone_no;
        int age;
        string city;                  //address
        static int cId;             //customer id 
        char arr[100];

        void information(){
            cout<<"\nEnter the customer id : ";
            cin>>cId;
            cout<<"\nEnter the name : ";
            cin>>name;
            cout<<"\nEnter the age : ";
            cin>>age;
            cout<<"\nEnter city : ";
            cin>>city;
            cout<<"\nEnter gender : ";
            cin>>gender;
            cout<<"Your Details Are Saved With Us\n"<<endl;
        }

};

int details::cId;
string details::name;
string details::gender;

class registration
{
    public:
        static int choice;
        int choice1;
        int back;
        static float charges;

        void flight(){
            string flightN[] = {"Dubai", "Canada", "UK", "USA", "Australa", "Europe"};

            for(int a=0;a<6;a++){
                cout<<(a+1)<<".flight to "<<flightN[a]<<endl;
            }
            cout<<"\nWelcome to the airlines"<<endl;
            cout<<"Press The Number Of The Country Of Which You Want To Book The Flight : ";
            cin>>choice;

            switch(choice)
            {
                case 1:
                    {
                        cout<<"_______________Welcome to Dubai Emirates___________________\n"<<endl;

                        cout<<"Your comfort is our proirity. Enjoy the journey"<<endl;

                        cout<<"Following are the flights \n"<<endl;

                        cout<<"1. DUB - 498"<<endl;
                        cout<<"\t09-10-2022  08:00 AM   11hrs   Rs. 14000"<<endl;
                        cout<<"2. DUB - 672"<<endl;
                        cout<<"\t10-10-2022  04:00 AM   16hrs   Rs. 12000"<<endl;
                        cout<<"3. DUB - 432"<<endl;
                        cout<<"\t09-10-2022  14:00 PM   22hrs   Rs. 10000"<<endl;


                        cout<<"\nSelect the flight you want to book : ";
                        cin>>choice1;

                        if(choice1==1){
                            charges = 14000;
                            cout<<"\n You have successfully booked the flight DUB - 498"<<endl;
                            cout<<"You can go back to menu and take the ticket"<<endl;
                        }

                        else if(choice1==2){
                            charges = 12000;
                            cout<<"\n You have successfully booked the flight DUB - 672"<<endl;
                            cout<<"You can go back to menu and take the ticket"<<endl;
                        }
                        else if(choice1==3)
                        {
                            charges = 10000;
                            cout<<"\n You have successfully booked the flight DUB - 432"<<endl;
                            cout<<"You can go back to menu and take the ticket"<<endl;
                        }
                        else{
                            cout<<"Invalid input, shifting to the previous menu"<<endl;
                            flight();
                        }

                        cout<<"Press any key to go back to the main menu "<<endl;
                        cin>>back;


                        if(back==1){
                            main_menu();
                        }
                        else{
                            main_menu();
                        }
                    }

                    case 2:
                    {
                        cout<<"_______________Welcome to Canadian Airlines___________________\n"<<endl;

                        cout<<"Your comfort is our proirity. Enjoy the journey"<<endl;

                        cout<<"Following are the flights \n"<<endl;

                        cout<<"1. CA - 456"<<endl;
                        cout<<"\t10-10-2022  08:00 AM   15hrs   Rs. 17000"<<endl;
                        cout<<"2. CA - 767"<<endl;
                        cout<<"\t11-10-2022  04:00 AM   13hrs   Rs. 15000"<<endl;
                        cout<<"3. CA - 989"<<endl;
                        cout<<"\t12-10-2022  14:00 PM   19hrs   Rs. 9000"<<endl;


                        cout<<"\nSelect the flight you want to book : ";
                        cin>>choice1;

                        if(choice1==1){
                            charges = 17000;
                            cout<<"\n You have successfully booked the flight CA - 456"<<endl;
                            cout<<"You can go back to menu and take the ticket"<<endl;
                        }

                        else if(choice1==2){
                            charges = 15000;
                            cout<<"\n You have successfully booked the flight CA - 767"<<endl;
                            cout<<"You can go back to menu and take the ticket"<<endl;
                        }
                        else if(choice1==3)
                        {
                            charges = 9000;
                            cout<<"\n You have successfully booked the flight CA - 989"<<endl;
                            cout<<"You can go back to menu and take the ticket"<<endl;
                        }
                        else{
                            cout<<"Invalid input, shifting to the previous menu"<<endl;
                            flight();
                        }

                        cout<<"Press any key to go back to the main menu "<<endl;
                        cin>>back;


                        if(back==1){
                            main_menu();
                        }
                        else{
                            main_menu();
                        }
                    }

                    case 3:
                    {
                         cout<<"_______________Welcome to UK Airways___________________\n"<<endl;

                        cout<<"Your comfort is our proirity. Enjoy the journey"<<endl;

                        cout<<"Following are the flights \n"<<endl;

                        cout<<"1. UK - 798"<<endl;
                        cout<<"\t10-10-2022  12:00 AM   8hrs   Rs. 30000"<<endl;


                        cout<<"\nSelect the flight you want to book : ";
                        cin>>choice1;

                        if(choice1==1){
                            charges = 30000;
                            cout<<"\n You have successfully booked the flight UK - 798"<<endl;
                            cout<<"You can go back to menu and take the ticket"<<endl;
                        }
                        else{
                            cout<<"Invalid input, shifting to the previous menu"<<endl;
                            flight();
                        }

                        cout<<"Press any key to go back to the main menu "<<endl;
                        cin>>back;


                        if(back==1){
                            main_menu();
                        }
                        else{
                            main_menu();
                        }
                    }
                    case 4:
                    {
                         cout<<"_______________Welcome to US Airways___________________\n"<<endl;

                        cout<<"Your comfort is our proirity. Enjoy the journey"<<endl;

                        cout<<"Following are the flights \n"<<endl;

                        cout<<"1. US - 569"<<endl;
                        cout<<"\t14-10-2022  11:00 AM   10hrs   Rs. 25000"<<endl;
                        cout<<"2. US - 324"<<endl;
                        cout<<"\t15-10-2022  02:00 AM   11hrs   Rs. 20000"<<endl;

                        cout<<"\nSelect the flight you want to book : ";
                        cin>>choice1;

                        if(choice1==1){
                            charges = 25000;
                            cout<<"\n You have successfully booked the flight US - 569"<<endl;
                            cout<<"You can go back to menu and take the ticket"<<endl;
                        }

                        else if(choice1==2){
                            charges = 20000;
                            cout<<"\n You have successfully booked the flight US - 324"<<endl;
                            cout<<"You can go back to 5menu and take the ticket"<<endl;
                        }
                        else{
                            cout<<"Invalid input, shifting to the previous menu"<<endl;
                            flight();
                        }

                        cout<<"Press any key to go back to the main menu "<<endl;
                        cin>>back;


                        if(back==1){
                            main_menu();
                        }
                        else{
                            main_menu();
                        }
                    }
                    case 5:
                    {
                         cout<<"_______________Welcome to Australian Airways___________________\n"<<endl;

                        cout<<"Your comfort is our proirity. Enjoy the journey"<<endl;

                        cout<<"Following are the flights \n"<<endl;

                        cout<<"1. AU - 255"<<endl;
                        cout<<"\t11-10-2022  17:00  PM   14hrs   Rs. 19000"<<endl;


                        cout<<"\nSelect the flight you want to book : ";
                        cin>>choice1;

                        if(choice1==1){
                            charges = 19000;
                            cout<<"\n You have successfully booked the flight AU - 255"<<endl;
                            cout<<"You can go back to menu and take the ticket"<<endl;
                        }
                        else{
                            cout<<"Invalid input, shifting to the previous menu"<<endl;
                            flight();
                        }

                        cout<<"Press any key to go back to the main menu "<<endl;
                        cin>>back;


                        if(back==1){
                            main_menu();
                        }
                        else{
                            main_menu();
                        }
                    }
                    case 6:
                    {
                         cout<<"_______________Welcome to Europe Airlines___________________\n"<<endl;

                        cout<<"Your comfort is our proirity. Enjoy the journey"<<endl;

                        cout<<"Following are the flights \n"<<endl;

                        cout<<"1. EU - 475"<<endl;
                        cout<<"\t13-10-2022  13:00 PM   15hrs   Rs. 21000"<<endl;
                        cout<<"2. EU - 682"<<endl;
                        cout<<"\t14-10-2022  20:00 PM   16hrs   Rs. 16000"<<endl;

                        cout<<"\nSelect the flight you want to book : ";
                        cin>>choice1;

                        if(choice1==1){
                            charges = 21000;
                            cout<<"\n You have successfully booked the flight EU - 475"<<endl;
                            cout<<"You can go back to menu and take the ticket"<<endl;
                        }

                        else if(choice1==2){
                            charges = 16000;
                            cout<<"\n You have successfully booked the flight EU - 682"<<endl;
                            cout<<"You can go back to menu and take the ticket"<<endl;
                        }
                        else{
                            cout<<"Invalid input, shifting to the previous menu"<<endl;
                            flight();
                        }

                        cout<<"Press any key to go back to the main menu "<<endl;
                        cin>>back;


                        if(back==1){
                            main_menu();
                        }
                        else{
                            main_menu();
                        }
                    }
                    default :
                    {
                        cout<<"Invalid input, shifting to main menu"<<endl;
                        main_menu();
                        break;
                    }
            }
        }
};

float registration::charges;
int registration::choice;


class ticket : public registration, details
{
    public:
        void bill(){
            string destination="";
            ofstream outf("records.txt");
            {
                outf<<"____________________onAIR AIRLINES________________________"<<endl;
                outf<<"____________________Ticket________________________"<<endl;
                outf<<"____________________________________________________"<<endl;

                outf<<"Customer ID : "<<details::cId<<endl;
                outf<<"Customer Name : "<<details::name<<endl;
                outf<<"Customer Gender : "<<details::gender<<endl;
                outf<<"\tDescription"<<endl<<endl;


                if(registration::choice==1){
                    destination="Dubai";
                }
                else if(registration::choice==2){
                    destination="Canada";
                }
                else if(registration::choice==3){
                    destination="UK";
                }
                else if(registration::choice==4){
                    destination="USA";
                }
                else if(registration::choice==5){
                    destination="Australia";
                }
                else if(registration::choice==6){
                    destination="Europe";
                }

                outf<<"Destination : \t\t"<<destination<<endl;
                outf<<"Flight cost : "<<registration::charges<<endl;
            }
            outf.close();

        }
        void dispbill(){
            ifstream ifs("records.txt");
            {
                if(!ifs){
                    cout<<"File Error"<<endl;
                }
                while(!ifs.eof()){
                    ifs.getline(arr,100);
                    cout<<arr<<endl;
                }
            }
            ifs.close();
        }
};

void main_menu(){

    int lchoice;        
    int schoice;
    int back;

    cout<<"\t               onAIR AIRLINES        \n"<<endl;
    cout<<"\t_________________MAin Menu__________________"<<endl;

    cout<<"\t____________________________________________"<<endl;
    cout<<"\t\t\t\t\t\t\t\t"<<endl;

    cout<<"\t|\t Press 1 to add the customer details         \t|"<<endl;
    cout<<"\t|\t Press 2 for flight registration             \t|"<<endl;
    cout<<"\t|\t Press 3 for tickets and charges             \t|"<<endl;
    cout<<"\t|\t Press 4 to exit                             \t|"<<endl;

    cout<<"\t__________________________________________________"<<endl;
    cout<<"\t\t\t\t\t\t\t\t"<<endl;

    cout<<"Enter the choice : ";
    cin>>lchoice;

    details d;
    registration r;
    ticket t;

    switch(lchoice){

        case 1:
            {
                cout<<"___________________Customers_________________________\n"<<endl;
                d.information();
                cout<<"Press any key to go to main menu ";
                cin>>back;

                if(back==1){
                    main_menu();
                }
                else{
                    main_menu();
                }
                break;
            }
        case 2:
            {
                cout<<"________________Book a flight using this system__________________\n"<<endl;
                r.flight();
                break;
            }
        case 3:
            {
                cout<<"________________GET YOUR TICKET_______________\n"<<endl; 
                t.bill();

                cout<<"Your ticket is printed , you can collect it \n"<<endl;
                cout<<"Press 1 to display your ticket ";

                cin>>back;

                    if(back==1){
                        t.dispbill();
                        cout<<"Press any key to go back to main menu ";
                        cin>>back;
                        if(back==1){
                            main_menu();
                        }
                        else{
                            main_menu();
                        }

                    }
                    else{
                        main_menu();
                    }
                    break;

            }
        case 4:
            {
                cout<<"\n\n\t______________THANK YOU________________"<<endl;
                break;
            }
        default:
            {
                cout<<"Invalid input, pleasde try again\n"<<endl;
                main_menu();
            }
    }
}


int main(){

    management m1;
    return 0;
}