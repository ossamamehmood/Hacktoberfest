#include <iostream>
#include <string.h>
 
#define MAX_SIZE 100 //Maximum size of the string
using namespace std;
 
    int main()
    {
        int i, j, lenght;
        char string[MAX_SIZE];
        char reverse[MAX_SIZE];
 
           cout<<"Enter a string: ";
           cin>>string;
 
        lenght = strlen(string);
        j = 0;
 
        for(i=lenght-1; i>=0; i--)
        {
            reverse[j] = string[i];
            j++;
        }
        reverse[j] = '\0';
 
        cout<<reverse;
 
    return 0;
 
}
