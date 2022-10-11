#include<bits/stdc++.h>
using namespace std;

int main() {
    // Set : Sorted and Unique
    // It is not a linear container, the internal structure is stored in tree like container
    // Most of the operations take O(log(n))
    set<int> st;
    for(auto &i: st) cout << i << ", "; cout << " | SIZE : " << st.size() << endl;
    
    st.insert(333);
    for(auto &i: st) cout << i << ", "; cout << " | SIZE : " << st.size() << endl;
    st.insert(3);
    for(auto &i: st) cout << i << ", "; cout << " | SIZE : " << st.size() << endl;
    st.insert(5);
    for(auto &i: st) cout << i << ", "; cout << " | SIZE : " << st.size() << endl;
    st.emplace(7);
    for(auto &i: st) cout << i << ", "; cout << " | SIZE : " << st.size() << endl;
    st.emplace(2);
    for(auto &i: st) cout << i << ", "; cout << " | SIZE : " << st.size() << endl;
    st.emplace(333);
    for(auto &i: st) cout << i << ", "; cout << " | SIZE : " << st.size() << endl;
    
    // Functionality of insert in vector can be used also, that only increases efficiency
    
    // begin(), end(), rbegin(), rend(), size()
    // empty(), and swap() are same as that of vector

    cout << "\n\nfind() in the Set container: \n";
    // Return Iterator
    auto it = st.find(333);
    cout << "*it :" << *it << endl;
    // Returns st.end() iterator if the element not founds 
    if(st.end() == st.find(555)) cout << "Element not Found!!";
    else cout << "Element Found!!";
    cout << endl;

    cout << "st.count(333) : " << st.count(333) << endl;    
    cout << "st.count(555) : " << st.count(555) << endl;    

    for(auto &i: st) cout << i << ", "; cout << " | SIZE : " << st.size() << endl;

    // Erase given value
    st.erase(5); // Takes logarithmic Time
    for(auto &i: st) cout << i << ", "; cout << " | SIZE : " << st.size() << endl;

    // Erase given iterator
    auto to_del = st.find(333);    
    st.erase(to_del); // Takes Constant Time
    for(auto &i: st) cout << i << ", "; cout << " | SIZE : " << st.size() << endl;

    // Erase (CLEAR) Everything
    st.clear();
    for(auto &i: st) cout << i << ", "; cout << " | SIZE : " << st.size() << endl;

    cout << "\n\n\n";

    for(auto &i:{1,2,3,4,5,6,7,8,9,10}) st.insert(i);
    for(auto &i: st) cout << i << ", "; cout << " | SIZE : " << st.size() << endl;

    // Erase Element In range of : [First, Last] : Via Iterators
    auto start = st.find(4); // start : inclusive
    auto end = st.find(9);   //   end : exclusive
    st.erase(start, end);
    for(auto &i: st) cout << i << ", "; cout << " | SIZE : " << st.size() << endl;

    // TODO : Study upper_bound() and lower_bound()

    auto it_lb = st.lower_bound(3);
    auto it_ub = st.upper_bound(9);
}
