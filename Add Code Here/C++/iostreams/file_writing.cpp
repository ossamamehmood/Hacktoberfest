// #include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream outfile("My.txt");
    outfile<< "Swaraj"<< endl;
    outfile<< "Mhatre"<< endl;
    outfile.clear();
    outfile.close();
    return 0;
}