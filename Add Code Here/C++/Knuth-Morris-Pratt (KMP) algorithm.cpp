#include <iostream>
#include <vector>

// Preprocess the pattern to compute the longest prefix that is also a suffix for each position in the pattern.
std::vector<int> computeLPS(const std::string& pattern) {
    int m = pattern.length();
    std::vector<int> lps(m, 0);
    int len = 0;  // Length of the previous longest prefix suffix

    for (int i = 1; i < m; ) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

// Search for the pattern in the text using the KMP algorithm
void KMPSearch(const std::string& text, const std::string& pattern) {
    int n = text.length();
    int m = pattern.length();
    std::vector<int> lps = computeLPS(pattern);
    int i = 0;  // Index for text[]
    int j = 0;  // Index for pattern[]

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            // Pattern found, print its starting position
            std::cout << "Pattern found at index " << i - j << std::endl;
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    std::string text, pattern;
    std::cout << "Enter text: ";
    std::cin >> text;
    std::cout << "Enter pattern to search for: ";
    std::cin >> pattern;

    KMPSearch(text, pattern);

    return 0;
}
