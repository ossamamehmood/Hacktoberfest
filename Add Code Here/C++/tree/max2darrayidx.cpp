#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Function to return the element index number of the vector with the largest length in a 2d array.
size_t max_size_index(vector<vector<int>> v) {
    decltype(v)::iterator m = max_element(v.begin(), v.end(), [](vector<int> a, vector<int> b) {
        return a.size() < b.size(); });
    size_t index = std::distance(v.begin(), m);
    return index;

}





int main() {
    vector<vector<int>> array2d = { {1,2,3}, {4,5,6}, {7,8,9,10} };

    auto i = max_size_index(array2d);
    //return 2
    cout << i << endl;
	return 0;
}