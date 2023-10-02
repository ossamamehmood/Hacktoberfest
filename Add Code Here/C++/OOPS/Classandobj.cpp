class and object

class : A class is a user-defined data type that we can use in our program, and it works as an object constructor, or a "blueprint" for creating objects.

object : An object is an instance of a class

#include <bits/stdc++.h>
using namespace std;
class Student
{
    // there are 3 types of access modifiers they are private , public and protected
    // data members are private by default
    // we should specify it as public to access directly
public:
    string name;
    int roll;
    int classno;
    void intro()
    {
        cout << name << " " << roll << " " << classno;
    }
};
int main()
{
    Student s1;
    s1.name = "sanu";
    s1.classno = 12;
    s1.roll = 28;
    s1.intro();

    //    cout<<s1.name;
    //    cout<<s1.roll;
    //    cout<<s1.classno;
    return 0;
}