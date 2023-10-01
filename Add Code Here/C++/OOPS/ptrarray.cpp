
#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int arr[31]={0,34,53,32,84,63,54,45,31,56,46,78,34,54,25,79,75,45,76,76,87,88,86,66,76,74,75,77,89,90,86};
    int* ptr=arr;
    cout<<*(ptr)<<endl;
    cout<<*(ptr+1)<<endl;
    cout<<*(ptr+2)<<endl;
    

    return 0;
}
