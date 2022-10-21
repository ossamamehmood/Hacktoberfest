#include <bits/stdc++.h>
using namespace std;

int main() {
    // number of test cases
	int t; cin >> t;
	
	while(t--){

	   // N cards, X face up cards
	    int n, x;
	    cin >> n >> x;

	   // face Down Cards = n - x
	    int fDown = n-x;
	    
	   // minimum operations for same facing cards
	    cout << min(x, check) << endl;
        
	}
	return 0;
}
