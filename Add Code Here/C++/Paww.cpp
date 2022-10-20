#include <iostream>
#include <string.h>
using namespace std;

void print(char *num, int n) {
    for (int i = 0; i < n; i++)
        cout << num[i] << " ";
    cout << "\n";
}
int main() {

    char str[25], temp;
    cout << "Enter the string: ";
    gets(str);
    cout << "All the strings under this combinations are:\n ";
    for (int i = 0; i < strlen(str); i++) {
        for (int j = 0; j < strlen(str)-1; j++) {
            temp = str[j];
            str[j] = str[j+1];
            str[j+1] = temp;
            print(str, strlen(str));
        }
    }
    return 0;
}
