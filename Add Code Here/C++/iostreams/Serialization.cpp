#include <iostream>
#include<fstream>
using namespace std;
class Student{
private: 
string Name;
int Roll;
string Branch;
public:
Student(){};
Student(string n, int r, string b){
    Name = n;
    Roll = r;
    Branch = b;
}
friend ofstream & operator<<(ofstream &ofs, Student s);
friend ifstream & operator>>(ifstream &ifs, Student &s);
friend ostream & operator<<(ostream &os, Student &s);
};
ofstream & operator<<(ofstream &ofs, Student s){
    ofs << s.Name<<endl;
    ofs << s.Roll<<endl;
    ofs << s.Branch<<endl;
return ofs;
}
ostream & operator<<(ostream &os, Student &s){
    os <<"Name " << s.Name<<endl;
    os <<"NO " << s.Roll<<endl;
    os <<"Branch" << s.Branch<<endl;
return os;
}
ifstream & operator>>(ifstream &ifs, Student &s){
    ifs>>s.Name;
    ifs>>s.Roll;
    ifs>>s.Branch;
    return ifs;
}
int main(){
    ofstream ofs("My.txt");
    Student Swaraj("Swaraj", 52, "CS");
    ofs<<Swaraj;
    ofs.close();
    Student s2;
    ifstream ifs("My.txt");
    ifs >> Swaraj;
    cout <<Swaraj;
    return 0;
}