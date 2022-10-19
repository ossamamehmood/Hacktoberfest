#include<iostream>
using namespace std;
int cafeMenu();
int drinkables();
int shakes();
int softdrinks();
int hotbevrages();
int mineralwater();
int fastfood();
int snacks();
int friedfood();
void spaceForUi();
int calculateBill(int value);
int moneycalculate(int Total);
int Bill;
main()
{
    cout<<"\t\t\t\t\t\tWelcome to Cafe";
    cafeMenu();
}
int cafeMenu()
{
    int choosingFood;
    cout<<"\nplease select any one from following\n";
    cout<<"\n1.drinkables\t2.fastfood\t3.snacks\t4.friedfood";
    spaceForUi();
    cout<<"\nEnter a number :";
    cin>>choosingFood;
    cout<<"\n";
   switch(choosingFood)
    {
        case 1:
            {
                drinkables();
                break;
            }
        case 2:
            {
                fastfood();
                break;
            }
        case 3:
            {
                snacks();
                break;
            }
        case 4:
            {
                friedfood();
                break;
            }
        default:
            {
                cout<<"\nEnter correct value\n";
                cout<<"\n";
                cafeMenu();
            }
    }
}
int drinkables()
{
    int choosedrinkables;
    cout<<"1.shakes\n2.softdrinks\n3.hot bevrages\n4.mineral water\n5.Return to menu";
     spaceForUi();
    cout<<"\nEnter a number :";
    cin>>choosedrinkables;
    cout<<"\n";
    switch(choosedrinkables)
    {
        case 1:
            {
               shakes();
               break;
            }
        case 2:
            {
               softdrinks();
               break;
            }
        case 3:
            {
               hotbevrages();
               break;
            }
        case 4:
            {
                mineralwater();
               break;
            }
          case 5:
            {
                cafeMenu();
               break;
            }
        default:
            {
                cout<<"\nEnter correct value\n";
                 cout<<"\n";
                drinkables();
            }
    }
}
int shakes()
{
    int choosingshakes;
    cout<<"1.mango\t\tRs.80\n2.banana\tRs.100\n3.oreo\t\tRs.140\n4.Return to menu";
    spaceForUi();
      cout<<"\nEnter a number : ";
    cin>>choosingshakes;
cout<<"\n";
    switch(choosingshakes)
    {
        case 1:
            {
               calculateBill(80);
               break;
            }
        case 2:
            {
               calculateBill(100);
               break;
            }
        case 3:
            {
               calculateBill(140);
               break;
            }
          case 4:
            {
                cafeMenu();
               break;
            }
        default:
            {
                cout<<"\nEnter correct value\n";
                 cout<<"\n";
                shakes();
            }

    }
}
int softdrinks()
{
    int choosingsoftdrinks;
    cout<<"1.coke\t\tRs.80\n2.sprite\tRs.100\n3.fanta\t\tRs.140\n4.Return to menu";
    spaceForUi();
      cout<<"\nEnter a number : ";
    cin>>choosingsoftdrinks;
cout<<"\n";
    switch(choosingsoftdrinks)
    {
        case 1:
            {
               calculateBill(80);
               break;
            }
        case 2:
            {
               calculateBill(100);
               break;
            }
        case 3:
            {
               calculateBill(140);
               break;
            }
          case 4:
            {
                cafeMenu();
               break;
            }
        default:
            {
                cout<<"\nEnter correct value\n";
                 cout<<"\n";
                softdrinks();
            }

    }
}
int hotbevrages()
{
    int choosinghotbevrages;
    cout<<"1.coffee\tRs.80\n2.tea\t\tRs.30\n3.latte\t\tRs.140\n4.Return to menu";
    spaceForUi();
      cout<<"\nEnter a number : ";
    cin>>choosinghotbevrages;
cout<<"\n";
    switch(choosinghotbevrages)
    {
        case 1:
            {
               calculateBill(80);
               break;
            }
        case 2:
            {
               calculateBill(30);
               break;
            }
        case 3:
            {
               calculateBill(140);
               break;
            }
          case 4:
            {
                cafeMenu();
               break;
            }
        default:
            {
                cout<<"\nEnter correct value\n";
                 cout<<"\n";
                hotbevrages();
            }

    }
}
int mineralwater()
{
    int choosingmineralwater;
    cout<<"1.smallbottle\t\tRs.80\n2.largebottle\t\tRs.130\n3.Return to menu";
    spaceForUi();
      cout<<"\nEnter a number : ";
    cin>>choosingmineralwater;
cout<<"\n";
    switch(choosingmineralwater)
    {
        case 1:
            {
               calculateBill(80);
               break;
            }
        case 2:
            {
               calculateBill(130);
               break;
            }

          case 3:
            {
                cafeMenu();
               break;
            }
        default:
            {
                cout<<"\nEnter correct value\n";
                 cout<<"\n";
                mineralwater();
            }

    }
}

int fastfood()
{
    int choosingfastfood;
    cout<<"1.burger\tRs.150\n2.shawarma\tRs.100\n3.pizza\t\tRs.240\n4.Return to menu";
    spaceForUi();
      cout<<"\nEnter a number : ";
    cin>>choosingfastfood;
cout<<"\n";
    switch(choosingfastfood)
    {
        case 1:
            {
               calculateBill(150);
               break;
            }
        case 2:
            {
               calculateBill(100);
               break;
            }
        case 3:
            {
               calculateBill(240);
               break;
            }
          case 4:
            {
                cafeMenu();
               break;
            }
        default:
            {
                cout<<"\nEnter correct value\n";
                 cout<<"\n";
                fastfood();
            }

    }
}
int snacks()
{
    int choosingsnacks;
    cout<<"1.biscuits\tRs.10\n2.Chips\t\tRs.50\n3.nimko\t\tRs.100\n4.salad\t\tRs.80\n5.Return to menu";
    spaceForUi();
    cout<<"\nEnter a number : ";
    cin>>choosingsnacks;
cout<<"\n";
    switch(choosingsnacks)
    {
        case 1:
            {
               calculateBill(10);
               break;
            }
        case 2:
            {
               calculateBill(150);
               break;
            }
        case 3:
            {
               calculateBill(100);
               break;
            }
        case 4:
            {
                calculateBill(80);
               break;
            }
          case 5:
            {
                cafeMenu();
               break;
            }
        default:
            {
                cout<<"\nEnter correct value\n";
                 cout<<"\n";
                snacks();
            }
    }

}
int friedfood()
{
     int choosingfriedfood;
    cout<<"1.samosa\t\tRs.30\n2.friedchicken\t\tRs.150\n3.nuggets\t\tRs.100\n4.finger chips\t\tRs.40\n5.Return to menu";
    spaceForUi();
    cout<<"\nEnter a number : ";
    cin>>choosingfriedfood;
    cout<<"\n";
     switch(choosingfriedfood)
    {
        case 1:
            {
               calculateBill(30);
               break;
            }
        case 2:
            {
               calculateBill(150);
               break;
            }
        case 3:
            {
               calculateBill(100);
               break;
            }
        case 4:
            {
                calculateBill(40);
               break;
            }
          case 5:
            {
                cafeMenu();
               break;
            }
        default:
            {
                cout<<"\nEnter correct value\n";
                 cout<<"\n";
                friedfood();
            }
    }
}

int calculateBill(int value)
{


    char choice;
    int totalbill;
    totalbill=Bill+value;
    Bill = value;
    cout<<"Anything else you want to buy ";
    cout<<"press y for yes and n for no :";
    cin>>choice;
     cout<<"\n";
    if(choice=='Y'||choice=='y')
        {
            cafeMenu();
        }
    else
        {
        cout<<"your Total bill = "<<totalbill;
        moneycalculate(totalbill);
        }

}
void spaceForUi()
{
    cout<<"\n------------------------------------------------------------------------------------------------------------------\n";
}
int moneycalculate(int Total)
{
    int money,returnedmoney;
    cout<<"\nEnter amount of money :";
    cin>>money;
    if(money<Total)
        {
            cout<<"Give more money";
            moneycalculate(Total);
        }
    else
        {
            returnedmoney=money-Total;
        cout<<"your change : Rs"<<returnedmoney;
        cout<<"\nThanks for shopping here";
        cout<<"\nContact us @www.ourwebsite.com\tor\tCallUs:0300-1234567";
         cout<<"\n";
          cout<<"\n";
        return NULL;
        }

}
