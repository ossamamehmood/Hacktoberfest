class Solution {
public:
    string reverseWords(string s) {
        // Trim the input string to remove leading and trailing spaces
        int i = 0, j = s.size() - 1;
        while (i <= j && s[i] == ' ') i++;   // Find the first non-space character
        while (j >= i && s[j] == ' ') j--;   // Find the last non-space character
        s = s.substr(i, j - i + 1);          // Extract the trimmed substring

        // Split the trimmed string into words based on spaces
        vector<string> words;                // Create a vector to store words
        stringstream ss(s);                  // Create a stringstream with the trimmed string
        string word;
        while (ss >> word) {                 // Tokenize the string into words
            words.push_back(word);           // Store each word in the vector
        }

        // Initialize the output string
        string out = "";

        // Iterate through the words in reverse order
        for (int i = words.size() - 1; i > 0; i--) {
            // Append the current word and a space to the output
            out += words[i] + " ";
        }

        // Append the first word to the output (without trailing space)
        return out + words[0];               // Concatenate the reversed words
    }
};