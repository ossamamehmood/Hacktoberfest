#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
static const char alphanum[] = "0123456789""?><!@#$%^&*()_+|}{""QWERTYUIOPLKJHGFDSAZXCVBNM""mnbvcxzlkjhgfdsapoiuytrewq";
int size=sizeof(alphanum) - 1;

int main()
{
int length = 69;
srand(time(0));
cout << "Random password of length 69 characters is - ";
for(int i=0;i<length;i++)
{
cout << alphanum[rand() % ::size];
}
return 0;
}

