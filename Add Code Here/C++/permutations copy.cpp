#include <iostream>
#include <fstream>

using namespace std;

int n,p,s[101];
ifstream f("permutari.in");
ofstream g("permutari.out");

void initializare(int k)
{
    s[k]=0;
}

int succesor(int k)
{
    s[k]++;
    if(s[k]<=n)
        return 1;
    else
        return 0;
}

int valid(int k)
{
    int i;
    for(i=1;i<k;i++)
        if(s[i]==s[k])
            return 0;
    return 1;
}

int solutie(int k)
{
    if(k==n)
        return 1;
    else
        return 0;
}

void tiparire(int k)
{
    int i;
    for(i=1;i<=k;i++)
        g<<s[i]<<" ";
    g<<endl;
}

void back(int k)
{
    int ok1,ok2;
    initializare(k);
    while(k>0)
    {
        do
        {
            ok1=succesor(k);
            ok2=valid(k);
        }while(ok1 && !ok2);

        if(ok1)
        {
            if(solutie(k))
                tiparire(k);
            else
            {
                k++;
                initializare(k);
            }
        }
        else
            k--;
        }

}

int main()
{
    f>>n;
    back(1);
    return 0;
}
