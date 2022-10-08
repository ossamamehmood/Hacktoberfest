/*
Author : Rounak Ghosh
GitHub : rounak-ghosh
Institution : GCETTB
Date : 08/10/2022
*/

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main()
{
    int x=0;
    priority_queue<int, vector<int>> pqmax;
    pqmax.push(2);
    pqmax.push(3);
    pqmax.push(1);
    x=pqmax.top();
    cout << x << endl;
    pqmax.pop();
    x=pqmax.top();
    cout << x << endl;

    priority_queue<int, vector<int>, greater<int>> pqmin;
    pqmin.push(2);
    pqmin.push(3);
    pqmin.push(1);
    x=pqmin.top();
    cout << x << endl;
    pqmin.pop();
    x=pqmin.top();
    cout << x << endl;

    return 0;
}