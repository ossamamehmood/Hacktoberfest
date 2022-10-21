#include<iostream>
using namespace std;

int main(){
    int arr[7] = {1, 5, 10, 50, 100, 500, 1000};
    string s = "CM";
    int n = s.length();
    int sum = 0;
    for(int i = 0; n>i; i++){
        if(s[i]=='I' and s[i+1]=='V'){
            sum = sum + 4;
            i++;
        }
        else if(s[i]=='I' and s[i+1]=='X'){
            sum = sum + 9;
            i++;
        }
        else if(s[i]=='X' and s[i+1]=='L'){
            sum = sum + 40;
            i++;
        }
        else if(s[i]=='X' and s[i+1]=='C'){
            sum = sum + 90;
            i++;
        }
        else if(s[i]=='C' and s[i+1]=='D'){
            sum = sum + 400;
            i++;
        }
        else if(s[i]=='C' and s[i+1]=='M'){
            sum = sum + 900;
            i++;
        }
        else if(s[i]=='I'){
            sum = sum + arr[0];
        }
        else if(s[i]=='V'){
            sum = sum + arr[1];
        }
        else if(s[i]=='X'){
            sum = sum + arr[2];
        }
        else if(s[i]=='L'){
            sum = sum + arr[3];
        }
        else if(s[i]=='C'){
            sum = sum + arr[4];
        }
        else if(s[i]=='D'){
            sum = sum + arr[5];
        }
        else if(s[i]=='M'){
            sum = sum + arr[6];
        }
    }

    cout<<sum;

    return 0;
}