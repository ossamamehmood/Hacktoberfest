/* 
                                           *******************************CRUD OPERATIONS ON TRIE*******************************
   A Trie, short for "reTRIEval tree," is a specialized tree-like data structure used primarily for the efficient storage and retrieval of strings or keys. 
   It is often referred to as a "prefix tree" because it excels at storing a set of strings that share common prefixes. 
   The Trie consists of nodes, with each node representing a single character. These nodes are interconnected through branches, where each branch corresponds to a possible character, typically from a fixed alphabet (e.g., 26 branches for uppercase English letters). 
   When inserting a string into a Trie, you start at the root and navigate through the branches according to the characters in the string. 
   If a branch is missing, a new node is created, ensuring that the path from the root to any node spells out a sequence of characters. 
   Searching in a Trie is similarly efficient, starting from the root and following branches based on the target string's characters. 
   If you reach a node marked as "terminal" at the end of the string, you've found it; otherwise, it's not present. 
   Tries are highly efficient for operations like autocompletion, searching for common prefixes, and have a time complexity of O(L) for insertions and searches, where L is the length of the string.
   While they can have higher space complexity, Tries are invaluable in applications such as spell checkers, autocomplete systems, IP routing (for longest prefix matching), and dictionary implementations, where fast string retrieval is essential.
*/

#include <bits/stdc++.h> // Include the C++ Standard Library headers.

using namespace std; // Declare the use of the 'std' namespace.

class TrieNode // Declare a class for TrieNode.
{
public:
    char data; // Store a character in the TrieNode.
    TrieNode *children[26]; // Create an array of TrieNode pointers for child nodes.
    bool isTerminal; // Boolean flag to indicate whether this node represents the end of a word.

    TrieNode(char ch) // Constructor for TrieNode, initializing data and children.
    {
        data = ch;
        for (int i = 0; i < 26; i++) // Initialize all children to NULL.
            children[i] = NULL;
        isTerminal = false; // Initialize isTerminal to false.
    }
};

class Trie // Declare a class for the Trie data structure.
{
public:
    TrieNode *root; // Create a root node for the Trie.

    Trie() // Constructor for Trie, initializing the root.
    {
        root = new TrieNode('\0'); // Create a root node with null character data.
    }

    bool searchWord(string word) // Define a function to search for a word in the Trie.
    {
        int n = word.size(); // Get the length of the input word.
        TrieNode *node = root; // Initialize a TrieNode pointer to start from the root.
        for (int i = 0; i < n; i++) // Traverse the Trie for each character in the word.
        {
            if (node->children[word[i] - 'A'] == NULL) // Check if the child node exists.
                return false; // If not found, return false.
            node = node->children[word[i] - 'A']; // Move to the next node.
        }
        if (node->isTerminal == true) // Check if the last node is a word-ending node.
            return true; // If yes, the word is present in the Trie.
        return false; // Otherwise, the word is not present.
    }

    void insertWord(string word) // Define a function to insert a word into the Trie.
    {
        int n = word.size(); // Get the length of the input word.
        TrieNode *node = root; // Initialize a TrieNode pointer to start from the root.
        for (int i = 0; i < n; i++) // Traverse the Trie for each character in the word.
        {
            if (node->children[word[i] - 'A'] == NULL) // Check if the child node exists.
            {
                node->children[word[i] - 'A'] = new TrieNode(word[i]); // Create a new node if not found.
            }
            node = node->children[word[i] - 'A']; // Move to the next node.
        }
        node->isTerminal = true; // Mark the last node as a word-ending node.
    }

    void deleteWord(string word) // Define a function to delete a word from the Trie.
    {
        int n = word.size(); // Get the length of the input word.
        int i;
        TrieNode *node = root; // Initialize a TrieNode pointer to start from the root.
        for (i = 0; i < n; i++) // Traverse the Trie for each character in the word.
        {
            if (!node->children[word[i] - 'A']) // Check if the child node exists.
                return; // If not found, return without deletion.
            node = node->children[word[i] - 'A']; // Move to the next node.
        }
        node->isTerminal = false; // Mark the last node as not representing a word.
    }
};

int main() // The main function where the Trie is used.
{
    Trie *t = new Trie(); // Create an instance of the Trie.

    t->insertWord("ARM"); // Insert words into the Trie.
    t->insertWord("ARMADILLO");
    t->insertWord("ARMWRESTLING");
    t->insertWord("DO");
    t->insertWord("DONE");
    t->insertWord("DOING");

    if (t->searchWord("DONE")) // Check if a word exists in the Trie.
        cout << "'DONE' is present" << endl;
    else
        cout << "'DONE' is absent" << endl;

    t->deleteWord("DONE"); // Delete a word from the Trie.

    if (t->searchWord("DONE")) // Check if the deleted word still exists.
        cout << "'DONE' is present" << endl;
    else
        cout << "'DONE' is absent" << endl;

    return 0; // Return 0 to indicate successful program execution.
}