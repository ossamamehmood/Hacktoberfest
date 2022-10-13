#include<iostream>
#include<unordered_set>
using namespace std;

int main(){
    unordered_set <int> s;
    s.insert(5);
    s.insert(8);
    s.insert(7);
    if(s.find(8) == s.end()){
        cout<<"Not Found";
    }
    else{
        cout<<"Found";
    }
    cout<<endl;
    for(auto i=s.begin();i!=s.end();i++){
        cout<<*i;
    }
}