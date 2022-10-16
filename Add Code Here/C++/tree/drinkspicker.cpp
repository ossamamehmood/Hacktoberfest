#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

int main()
{
    int x;
    char acord;
    string selectie,slot1,slot2,slot3,slot4,slot5;
    float slot1price,slot2price,slot3price,slot4price,slot5price;
    slot1="Pepsi";
    slot2="Coca-Cola";
    slot3="Sprite";
    slot4="7Up";
    slot5="Mirinda";
    slot1price=2.85;
    slot2price=3.10;
    slot3price=3.00;
    slot4price=2.85;
    slot5price=1.00;
    cout<<"Drinks:\n1. "<<slot1<<"\n2. "<<slot2<<"\n3. "<<slot3<<"\n4. "<<slot4<<"\n5. "<<slot5<<"\n";
    std::this_thread::sleep_for(4s);
    inceput:
    cout<<"Drink name:";
    cin>>x;
    switch(x) {
    case 1:
    cout<<"The price of the drink "<<slot1<<" is "<<slot1price<<" ";
            if(slot1price!=1.00)
                cout<<"LEI";
            else
                cout<<"LEU";
            selectie=slot1;
            break;
     case 2: cout<<"The price of the drink "<<slot2<<" is "<<slot2price<<" ";
            if(slot2price!=1.00)
                cout<<"LEI";
            else
                cout<<"LEU";
            selectie=slot2;
            break;
    case 3: cout<<"The price of the drink "<<slot3<<" is "<<slot3price<<" ";
            if(slot3price!=1.00)
                cout<<"LEI";
            else
                cout<<"LEU";
                selectie=slot3;
            break;
    case 4: cout<<"The price of the drink "<<slot4<<" is "<<slot4price<<" ";
            if(slot4price!=1.00)
                cout<<"LEI";
            else
                cout<<"LEU";
                selectie=slot4;
            break;
    case 5: cout<<"The price of the drink "<<slot5<<" is "<<slot5price<<" ";
            if(slot5price!=1.00)
                cout<<"LEI";
            else
                cout<<"LEU";
                selectie=slot5;
            break;
    default: cout<<"Invalid input number";
            break;
    }
    cout<<"\n"<<"Confirm your order "<<selectie<<"? \n Press y to confirm or n to try again.";
    cin>>acord;
    if(acord=='y')
        cout<<"Pick up your "<<selectie<<" from below. \n";
    else
        goto inceput;
    std::this_thread::sleep_for(5s);
    cout<<"Pick it up!";
    return 0;
}
