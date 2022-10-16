#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"Enter String : ";
    string str;
    int key;
    getline(cin,str);
    cout<<"Enter Key : ";
    cin>>key;
    if(key==2)
      cout<<"This specific ciphering is called Caesar Cipher for key value equal to 2, just an info"<<endl;

    int len = str.length();
    vector<char> p,cy,y;

    // Removing spaces and converting the text to lower case. Also removing spaces.
    for(int i = 0;i<len;i++)
    {
        str[i] = tolower(str[i]);
        if(str[i]>='a' && str[i]<='z')
          p.push_back(str[i]);
    }
    
    //Printing the plain text
    cout<<"Plain text without any spaces : ";
    for(int i = 0;i<p.size();i++)
      cout<<p[i]<<"";
    cout<<endl;

    // Encryption
    cout<<"Encrypted Text : ";
    for(int i = 0;i<p.size();i++)
    {
        int a = (p[i]-97+key)%26;
        char res = a+97;
        cy.push_back(res);
    }

    // Printing the Cipher Text
    for(int i=0;i<cy.size();i++)
      cout<<cy[i];
    cout<<endl;

    // Decryption
    cout<<"Decrypted Original String : ";
    for(int i = 0;i<cy.size();i++)
    {
        int a = (cy[i]-key);
        if(a<97)
          a = (a+26);
        char res = a;
        y.push_back(res);
    }

    for(int i=0;i<y.size();i++)
      cout<<y[i];
    cout<<endl;

    return 0;
}