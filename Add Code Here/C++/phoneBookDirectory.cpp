#include <iostream>
#include <string> //Text file handle
#include <fstream> //File handler
#include <stdio.h>

using namespace std;

//Declaring Global Variables
string searchName;
string newName;
string n;
int choice;

//Declaring a function to read and compare searches
bool IsFound(){

    ifstream read (searchName + ".txt");
        getline(read, n);

        if (searchName == n)
        {
            return true;
        }
        else
        {
            return false;
        }
}

//Declaring a class
class PhoneBook{
private:
    string name;
    string email;
    long long int num;
    long long int telNo;
public:
    //Declaring function to modifying contact List
    void modify()
    {


        cout << "\n.......MODIFY PHONE RECORD........." << endl;

        cout << "Search if record exist...\n" << endl;
        cout << "Enter name: "; cin >> searchName;

        bool found = IsFound();

        if (!found)
        {
            cout << "No record found!" << endl;
        }
        else
        {
            ifstream myData;
            myData.open(searchName+".txt");
            myData >> name;
            myData >> num;

            cout << endl;
            cout << "Record found!" << endl;
            cout << "\5 NAME: " << name << endl << "\5 PHONE: " << num;

            cout << endl;
            cout << "Enter name: ";
            cin.ignore();
            getline(cin, newName);
            cout << "Enter number: "; cin >> telNo;

            ofstream contact;
            contact.open(newName + ".txt");
            contact << newName << endl << "234" << telNo;
            contact.close();

            cout << endl;
            cout << "Modification recorded! Search for your name to see change." << endl;
            }

            cout << endl;

            ofstream toList;
            toList.open("PhoneBook.txt", ios_base::app);
            toList << newName << " " << "234" << telNo << "\n";
            toList.close();
    }


    //Declaring function to add a new contact
    void addNum(){
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter number: "; cin >> telNo;

    ofstream contact;
    contact.open(name + ".txt");
    contact << name << endl << "234" << telNo;
    contact.close();

    cout << endl;
    cout << "Contact saved!" << endl;

    ofstream toList;
    toList.open("PhoneBook.txt", ios_base::app);
    toList << name << " " << "234" << telNo << endl;
    toList.close();
    }

    //Declaring function to view contact records
    void viewList()
    {
    cout << endl;
    ifstream myContact;
    myContact.open("PhoneBook.txt", ios_base::app);

    cout << "-----------------------------------------------------" << endl;
    cout << "\tNAME\t\tPHONE NUMBER" << endl;
    cout << "-----------------------------------------------------";

    while(myContact >> name >> telNo)
    {
        cout << "\n\t" << name << "\t\t" << telNo;
    }

    myContact.close();

    }


    //Declaring function to search for saved record
    void nameSearch()
    {
        cout << "Enter name: "; cin >> searchName;

        bool found = IsFound();

        if (!found)
        {
            cout << "No record found!" << endl;
        }
        else
        {
            ifstream myData;
            myData.open(searchName+".txt");
            myData >> name;
            myData >> num;

            cout << endl;
            cout << "-----------------------------------------------------" << endl;
            cout << "\tNAME\t\tPHONE NUMBER" << endl;
            cout << "-----------------------------------------------------" << endl;
            cout << "\t" << name << "\t\t" << num;
            }

            cout << endl;
        }


    void delRecord()
    {
        cout << endl;

        int reRecord;
        char fileName[40];

        cout << "Enter name: "; cin >> fileName;
          reRecord  = remove(fileName);

          if(reRecord==0){
                cout << "Record successfully " << endl;
            } else {
                cout << "Error Occurred! Try again.\nConfirm if record exist!" << endl;
            }
    }
    //Display Menu and required information from user
    int menu(){
        cout << "-----------------------------------------------------" << endl;
        cout << "\tWelcome! What would you like to do?"<< endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "1. Add contact" << endl;
        cout << "2. View contacts" << endl;
        cout << "3. Search Contact" << endl;
        cout << "4. Modify contact" << endl;
        cout << "5. Delete Record " << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << " Your choice: ";
        cin >> choice;

        return choice;
    }

}x;

int main() //Main funciton
{

    system("cls"); //Clear console each time main() is called

    int g = x.menu();
    //Condition case to perform user's required function
    switch(g){
        case 1:
            system("cls"); //Clear console each time main() is called
            cout << "-----------------------------------------------------" << endl;
            cout << "\t\tCREATE NEW PHONE RECORD\t" << endl;
            cout << "-----------------------------------------------------" << endl;
            x.addNum();
            break;
        case 2:
            system("cls"); //Clear console each time main() is called
            cout << "-----------------------------------------------------" << endl;
            cout << "\t\tPHONE BOOK RECORDS\t";
            x.viewList();
            cout << endl;
            break;
        case 3:
            system("cls"); //Clear console each time main() is called
            cout << "-----------------------------------------------------" << endl;
            cout << "\t\tPHONE BOOK SEARCH\t" << endl;
            cout << "-----------------------------------------------------" << endl;
            x.nameSearch();
            break;
        case 4:
            system("cls"); //Clear console each time main() is called
            cout << "-----------------------------------------------------" << endl;
            cout << "\t\tPHONE BOOK SEARCH\t" << endl;
            cout << "-----------------------------------------------------" << endl;
            x.modify();
            break;
        case 5:
            system("cls"); //Clear console each time main() is called
            cout << "-----------------------------------------------------" << endl;
            cout << "\t\tDELETE PHONE RECORD\t" << endl;
            cout << "Enter name with the (.txt) extension...." << endl;
            cout << "-----------------------------------------------------" << endl;
            x.delRecord();
            break;
        }

    cout << endl;

    system("PAUSE");
    main();

}
