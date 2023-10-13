#include <iostream>
using namespace std;
class Student
{
public:
    int RollNo;
    string name;
    static int AdmissionNo;
    Student(string n)
    {
        AdmissionNo++;
        RollNo = AdmissionNo;
        name = n;
    }
    static int display()
    {
        return AdmissionNo;
    }
    void output(){
        cout << "Name is  " << name << " and RollNo is " << RollNo << endl;
    }
};
int Student::AdmissionNo = 0;
int main()
{
    Student s1("Swaraj"), s2("Mhatre");
   s1.output();
   s2.output();
    return 0;
}