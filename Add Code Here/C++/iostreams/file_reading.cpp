#include <iostream>
#include <fstream> 
using namespace std;

int main(){
    ifstream infile("My.txt");
    if(infile){cout << "file is open"<< endl;}
    string name;
    int no;
     infile >> name >> no;
     infile.close();
      cout << name << " " << no;
    return 0;
}