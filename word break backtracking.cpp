//USING RECURSION AND BACKTRACKING BUT OPTIMAL SOLUTION IS DYNAMIC PROGRAMMING
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to segment a given string into a space-separated
// sequence of one or more dictionary words
void wordBreak(vector<string> const &dict, string word, string out)
{
    // if the end of the string is reached,
    // print the output string

    if (word.size() == 0)
    {
        cout << out << endl;
        return;
    }

    for (int i = 1; i <= word.size(); i++)
    {
        // consider all prefixes of the current string
        string prefix = word.substr(0, i);

        // if the prefix is present in the dictionary, add it to the
        // output string and recur for the remaining string

        if (find(dict.begin(), dict.end(), prefix) != dict.end())
        {
            wordBreak(dict, word.substr(i), out + " " + prefix);
        }
    }
}

// Word Break Problem Implementation in C++
int main()
{
    // vector of strings to represent a dictionary
    // we can also use a Trie or a set to store a dictionary

    /*vector<string> dict = {"this", "th", "is", "famous", "Word", "break","b", "r", "e", "a", "k", "br", "bre", "brea", "ak", "problem"}; */

    // input string
    string word = "Wordbreakproblem";

   // wordBreak(dict, word, "");

    return 0;
}
