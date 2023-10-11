#include <iostream>

using namespace std;

int main()
{      char c;
int n;
    cout<<"want to see a pyramid?(y/n)";
    cin>>c;
    if((c=='Y')||c=='y'){
        cout<<"give me a number";
        cin>>n;
    
    
     int i, j, k = n;
    for (i = 1; i <= n; i++) {
 
        // Inner loop for columns
        for (j = 1; j <= n; j++) {
 
            // Condition to print star pattern
            if (j >= k)
                cout << "* ";
            else
                cout << " ";
        }
        k--;
        cout << "\n";
    }
    }
    else{
        cout<<"sorry to disappoint you :(";
    }
    return 0;
}
