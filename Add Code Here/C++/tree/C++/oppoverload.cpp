#include<iostream>
using namespace std;

class test
{
int a;
public:
void get()
{
    cin>>a;
}

void compare(test t2)
{
    if (a==t2.a)
    cout<<"equal\n";

    else 
    cout<<"not equal\n";
}

};

int main()
{
  test t1,t2;
  cout<<"enter the a of t1\n";
  t1.get();
  cout<<"enter the a of t2\n";
  t2.get();

  t1.compare(t2);  
}

