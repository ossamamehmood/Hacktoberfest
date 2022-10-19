#include <iostream>
using namespace std;

class student
{
private:
    int roll;
    char batch;
    int age;

public:
    void getroll(int x) // getters
    {
        this->roll = x;
    }
    void getbatch(char x)
    {
        this->batch = x;
    }
    void getage(int x)
    {
        this->age = x;
    }
    int putroll() // setters
    {
        return roll;
    }
    char putbatch()
    {
        return batch;
    }
    int putage()
    {
        return age;
    }
};

int main()
{
    student ram;
    ram.getroll(3);
    ram.getbatch('a');
    ram.getage(17);

    cout << ram.putroll() << endl;
    cout << ram.putage() << endl;
    cout << ram.putbatch() << endl;
    return 0;
}