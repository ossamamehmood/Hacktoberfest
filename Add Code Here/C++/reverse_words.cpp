// C++ program to reverse individual words in a given
// string using STL list
 
#include <bits/stdc++.h>
using namespace std;
 
// reverses individual words of a string
void reverseWords(string str)
{
    stack<char> st;
 
    // Traverse given string and push all characters
    // to stack until we see a space.
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] != ' ')
            st.push(str[i]);
 
        // When we see a space, we print contents
        // of stack.
        else {
            while (st.empty() == false) {
                cout << st.top();
                st.pop();
            }
            cout << " ";
        }
    }
 
    // Since there may not be space after
    // last word.
    while (st.empty() == false) {
        cout << st.top();
        st.pop();
    }
}
 
// Driver program to test function
int main()
{
    string str = "Geeks for Geeks";
    reverseWords(str);
    return 0;
}