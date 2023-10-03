#include<bits/stdc++.h>
using namespace std;

int binary_search(vector<int> x,int f)
{
    int l = 0;
    int h = x.size()-1;
    int flag = false;

    while(l<h)
    {
        int mid = (l+h) / 2;
        if(x[mid] == f)
        {
            flag = true;
            break;
        }else
        { 
            if(x[mid] < f)
            {
                l = mid;
            }else if(x[mid] > f)
            {
                h = mid;
            }
            
        }
    }
    
    if(flag)
    {
        cout << f << " has been found!";
    }else
    {
        cout << f << " is not found!";
    }
}

int main()
{
    vector<int> arr(5);
    arr.push_back(2);
    arr.push_back(4);
    arr.push_back(6);
    arr.push_back(8);
    arr.push_back(9);
    binary_search(arr,8);
    return 0;
}
