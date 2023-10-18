// Restaurant Project in C++.
#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int p_p=0,p_b=0,p_s=0,p_i=0,p_c=0;
    int s_p=0,s_b=0,s_s=0,s_i=0,s_c=0;
    int p=0,b=0,s=0,i=0,c=0, num1;
    int CHOICE, Q;

    cout<<"\t\t\t   WELCOME TO MEHWISH RESTURENT MANAGEMENT\n";
    cout<<"\n\t\t\t First of all, Enter Stock present at Resturent";
    cout<<"\n\t\t\t ::::> Number of Pizza: ";
    cin>>p_p;
    cout<<"\n\t\t\t ::::> Number of Burger: ";
    cin>>p_b;
    cout<<"\n\t\t\t ::::> Number of Sandwich: ";
    cin>>p_s;
    cout<<"\n\t\t\t ::::> Number of Ice-Cream: ";
    cin>>p_i;
    cout<<"\n\t\t\t ::::> Number of Cake: ";
    cin>>p_c;

    p:

    system ("cls");

    cout<<"\n\t\t\t Control Panel";
    cout<<"\n\n\t\t ::::> 1. Pizza ";
    cout<<"\n\t\t\t ::::> 2. Burger ";
    cout<<"\n\t\t\t ::::> 3. Sandwich ";
    cout<<"\n\t\t\t ::::> 4. Ice-Cream ";
    cout<<"\n\t\t\t ::::> 5. Cake";
    cout<<"\n\t\t\t ::::> 6. DETAILS ";
    cout<<"\n\t\t\t ::::> 7. EXIT ";
    cout<<"\n\t\t\t ::::> ENTER YOUR CHOICE: ";
    cin>>CHOICE;

    switch(CHOICE)
    {
    case 1:
        cout<<"\n\n Enter Pizza Quantity:";
        cin>>Q;
        if( p_p-s_p >=Q)
        {
            s_p +=Q;
            p += Q*800;
            cout<<"\n\n\n\t\t\t"<<Q<<"Pizza Sold Thank You !!!";
        }
            else
            cout<<"\n\n\n\t\t\t  SORRY "<<p_p-s_p<<"Pizza Remaining in Restaurant....";

        break;
        case 2:
        cout<<"\n\n Enter Burger Quantity:";
        cin>>Q;
        if( p_b-s_b >=Q)
        {
            s_b  +=Q;
            p += Q*200;
            cout<<"\n\n\n\t\t\t"<<Q<<"Burger Sold Thank You !!!";
        }
            else
            cout<<"\n\n\n\t\t\t  SORRY "<<p_b-s_b<<"Burger Remaining in Restaurant....";
        break;
    case 3:
        cout<<"\n\n Enter Sandwich Quantity:";
        cin>>Q;
        if( p_s-s_s >=Q)
        {
            s_s  +=Q;
            p += Q*50;
            cout<<"\n\n\n\t\t\t"<<Q<<"Sandwitch Sold Thank You !!!";
        }
            else
            cout<<"\n\n\n\t\t\t  SORRY "<<p_s-s_s<<"Sandwich Remaining in Restaurant....";
        break;
    case 4:
        cout<<"\n\n Enter Ice_Cream Quantity:";
        cin>>Q;
        if( p_i-s_i >=Q)
        {
            s_i  +=Q;
            p += Q*300;
            cout<<"\n\n\n\t\t\t"<<Q<<"Ice_Cream Sold Thank You !!!";
        }
            else
            cout<<"\n\n\n\t\t\t  SORRY "<<p_i-s_i<<"Ice_Cream Remaining in Restaurant....";
        break;
    case 5:
        cout<<"\n\n Enter Cake Quantity:";
        cin>>Q;
        if( p_c-s_c >=Q)
        {
            s_c  +=Q;
            p += Q*500;
            cout<<"\n\n\n\t\t\t"<<Q<<"Cake Sold Thank You !!!";
        }
            else
            cout<<"\n\n\n\t\t\t  SORRY "<<p_c-s_c<<"Cake Remaining in Restaurant....";
        break;
    case 6:
        system("cls");
        cout<<"\n\t\t DETAILS PANEL";
        cout<<"\n\n Purchased Pizza Quantity : "<<p_p;
        cout<<"\n Sold Pizza Quantity :  "<<s_p;
        cout<<"\n Remaining Pizza Quantity :  "<<p_p-s_p;
        cout<<"\n Total Pizza Price in a Day : "<<p;

        cout<<"\n\n Purchased Burger Quantity :  "<<s_b;
        cout<<"\n Sold Burger Quantity :  "<<p_b-s_b;
        cout<<"\n Remaining Burger Quantity : "<<b;
        cout<<"\n Total burger Quantity in a Day: "<<p_p;

        cout<<"\n\n Purchased Sandwich Quantity :  "<<s_s;
        cout<<"\n Sold Sandwich Quantity :  "<<p_s-s_s;
        cout<<"\n Remaining Sandwich Quantity : "<<p_s-s_s;
        cout<<"\n Total Sandwich Price in a Day : "<<s;

        cout<<"\n\n Purchased Ice-Cream Quantity : "<<p_i;
        cout<<"\n Sold Ice-Cream Quantity :  "<<s_i;
        cout<<"\n Remaining Ice-Cream Quantity :  "<<p_i-s_i;
        cout<<"\n Total Ice-Cream Price in a Day : "<<i;

        cout<<"\n\n Purchased Cake Quantity : "<<p_c;
        cout<<"\n Sold Cake Quantity :  "<<s_c;
        cout<<"\n Remaining Cake Quantity :  "<<p_c-s_c;
        cout<<"\n Total Cake Price in a Day : "<<c;
        cout<<"\n\n Total Day Price :"<<p+b+s+i+c;

        break;
    case 7:
        exit(0);

    default:
           cout<<"\n\n INVALID VALUE....PLEASE TRY AGAIN";
    }
    getch();
    goto p;
    return 0;




}
