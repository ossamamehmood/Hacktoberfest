#include <iostream>
#include <vector>
#include <string>

using namespace std;

class SubstringSearch {
public:
    bool hasSubstring(const vector<char>& text, const vector<char>& pattern) {
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < text.size() && j < pattern.size()) {
            if (text[i] == pattern[j]) {
                i++;
                j++;
            } else {
                j = 0;
                k++;
                i = k;
            }
        }
        return j == pattern.size();
    }

    vector<int> computeTemporaryArray(const vector<char>& pattern) {
        vector<int> lps(pattern.size(), 0);
        int index = 0;
        for (int i = 1; i < pattern.size();) {
            if (pattern[i] == pattern[index]) {
                lps[i] = index + 1;
                index++;
                i++;
            } else {
                if (index != 0) {
                    index = lps[index - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    bool KMP(const vector<char>& text, const vector<char>& pattern) {
        vector<int> lps = computeTemporaryArray(pattern);
        int i = 0;
        int j = 0;
        while (i < text.size() && j < pattern.size()) {
            if (text[i] == pattern[j]) {
                i++;
                j++;
            } else {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return j == pattern.size();
    }
};

int main() {
    string str = "abcxabcdabcdabcy";
    string subString = "abcdabcy";
    
    SubstringSearch ss;
    bool result = ss.hasSubstring(vector<char>(str.begin(), str.end()), vector<char>(subString.begin(), subString.end()));

    cout << boolalpha << result << endl;

    return 0;
}
