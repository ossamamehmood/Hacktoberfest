#include <iostream>
using namespace std;
class Employee{
    private:
    int id;
    string name;
    public:
    Employee(int id, string name){
        this->id = id;
        this->name = name;
    }
    int getid(){
        return id;
    }
    string getname(){
        return name;
    }
};
class Fulltime : public Employee{
    private:
    int salary;
    public:
    Fulltime(int salary, int id, string name): Employee(id, name){
        this->salary = salary;
    }
    void showsalary(){
        cout << "The salary of " << getname() << " with id "<< getid() << " is " << salary << endl;
    }
};
class Parttime : public Employee{
    private:
    int DailyWage;
    public:
    Parttime(int DailyWage, int id, string name): Employee(id, name){
        this->DailyWage = DailyWage;
    }
    void showwage(){
        cout << "The DailyWage of " << getname() << " with id "<< getid() << " is " << DailyWage<< endl;
    }
};
int main(){
    Fulltime f1(20000000, 1, "Swaraj");
    Parttime f2(200000000, 2, "Mhatre");
    f1.showsalary();
    f2.showwage();
    return 0;
}