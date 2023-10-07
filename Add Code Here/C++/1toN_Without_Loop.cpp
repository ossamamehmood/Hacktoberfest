//you are given a number 'n'. return series 1 to n without using loops
// we will do this by using recursion


void recursiveFunction(int x, vector<int>& ans, int n) {
    // Insert element in the array
    

    if(x == n+1) {
        return;
    }
    ans.push_back(x);
    // Call recursive function
    return recursiveFunction(x + 1, ans, n);
    
}

vector<int> printNos(int x) {
    // Declaring empty integer array
    vector<int> ans;
    
    // Calling recursive function
    recursiveFunction(1, ans , x);
    
    return ans;
}
