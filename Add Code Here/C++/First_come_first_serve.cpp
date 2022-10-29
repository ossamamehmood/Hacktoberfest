#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of addresses in the Request Sequence : ";
    cin >> n;
    int RequestSequence[n];
    cout << "Enter the Request Sequence" << endl;
    for(int i=0 ; i<n ; i++){
        cin >> RequestSequence[i];
    }
    int head;
    cout << "Enter the Initial head Position : ";
    cin >> head;
    int SeekSequence[n];
    int sum = 0;
    for(int i=0 ; i<n ; i++){
        sum += abs(RequestSequence[i] - head);
        head = RequestSequence[i];
        SeekSequence[i] = RequestSequence[i];
    }
    cout << "Total number of seek operations = " << sum << "\n";
    cout << "Seek Sequence is " << "\n";
    for(int i=0 ; i<n ; i++){
        cout << SeekSequence[i] << endl;
    }
return 0;
}
