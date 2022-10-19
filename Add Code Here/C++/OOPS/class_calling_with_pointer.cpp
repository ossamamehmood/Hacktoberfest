#include<iostream>
using namespace std;
class hero
{
    int level;
public:
int health;
void gethealth(int x)
{
    health=x;
}
void getlevel(int x)
{
    level=x;
}
int putlevel()
{
    return level;
}
};
int main()
{
    hero *h1=new hero;
    int x;
    cin>>h1->health;
    cin>>x;
    h1->getlevel(x);
    cout<<h1->health;
    cout<<h1->putlevel() <<endl;
    return 0;
}