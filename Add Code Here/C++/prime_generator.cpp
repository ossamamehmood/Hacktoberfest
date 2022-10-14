#include <iostream>
#include <bits/stdc++.h>
#include <sstream>

using namespace std;

void fastscan(int &number)
{
    //variable to indicate sign of input number
    register int c;

    number = 0;
    c = getchar();

    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int testcases;
    fastscan(testcases);

    register int initial , finall;
    if(initial == 1)
        initial = 2;
    register int counter = 1;
    while(counter <= testcases)
    {
        bool flag = 0;
        fastscan(initial);
        fastscan(finall);
        int half = initial/2;
        while(initial<=finall)
        {
            for(int i = 2;i<=half;i++)
            {
                if(initial%i == 0)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
            {

                cout << initial << endl;
            }
            flag = 0;
            initial++;
        }
        counter++;
//        cout << initial << " " << finall << endl;
    }

    return 0;
}
