#include<bits/stdc++.h>
using namespace std;

int main() {
    // Key Value Pair
    // Where the keys are unique and values can be anything
    // Maps stores unique keys in sorted order

    // Most Operations works in  O(log(n))

    // Syntax be like :
    // map <key_datatype, value_datatype> name_of_the_container;
    map <int, int> mp;
    // Also can be defined as :
    // map <int, pair<int, int>> mp;
    // Or
    // map <pair<int, int>, int> mp;
    for(auto it: mp) cout << "{ " << it.first << ", " << it.second << "}, "; cout << " | SIZE : " << mp.size() << endl;

    // Inserting elements in the map
    mp[3] = 333;
    for(auto it: mp) cout << "{ " << it.first << ", " << it.second << "}, "; cout << " | SIZE : " << mp.size() << endl;
    mp[0] = 0;
    for(auto it: mp) cout << "{ " << it.first << ", " << it.second << "}, "; cout << " | SIZE : " << mp.size() << endl;
    mp.insert({9,999});
    for(auto it: mp) cout << "{ " << it.first << ", " << it.second << "}, "; cout << " | SIZE : " << mp.size() << endl;
    mp.insert({7,777});
    for(auto it: mp) cout << "{ " << it.first << ", " << it.second << "}, "; cout << " | SIZE : " << mp.size() << endl;
    mp.emplace(2,222);
    for(auto it: mp) cout << "{ " << it.first << ", " << it.second << "}, "; cout << " | SIZE : " << mp.size() << endl;
    mp.emplace(5,555);
    for(auto it: mp) cout << "{ " << it.first << ", " << it.second << "}, "; cout << " | SIZE : " << mp.size() << endl;

    // Accessing values using key
    cout << "mp[3] : " << mp[3] << endl;
    cout << "mp[4] : " << mp[4] << endl; // Doesn't Exist

    // Finding element by key
    // Returns Iterator
    auto find_it1 = mp.find(3);
    cout << "Element Found at : " << "{ " << (*find_it1).first << ", " << (*find_it1).second << " }" << endl;

    auto find_it2 = mp.find(69); // Doesn't Exist
    if(find_it2 == mp.end()) 
        cout << "Element not in the map..." << endl;
    else  
        cout << "Element Found at : " << "{ " << (*find_it2).first << ", " << (*find_it2).second << " }" << endl;

    
    // Other is same as that of vector and some properties of set
    // begin(), end(), rbegin(), rend()
    // clear(), empty(), swap(), erase()

    // Upper and Lower Bound functions are supported as well
    auto ubit = mp.upper_bound(2);
    auto lbit = mp.lower_bound(9);
}
