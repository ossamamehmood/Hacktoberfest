//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
  
    int nodeCount(struct Node *tree) {
        if(!tree)
            return 0;
        else {
            int l = nodeCount(tree->left);
            int r = nodeCount(tree->right);
            return l + r + 1;
        }
    }
  
    bool isCBT(struct Node *root,int ind,int total) {
        if(!root)
        return true;
        
        if(ind >= total)
        return false;
        
        else {
            bool l = isCBT(root->left,2*ind+1,total);
            bool r = isCBT(root->right,2*ind+2,total);
            return (l and r);
        }
    }
    
    bool Maxorder(struct Node *root) {
        //leaf node
        if(!root->left and !root->right)
        return true;
        
        // left child
        if(!root->right)
        return (root->data > root->left->data);
        
        // both children
        else {
            bool left = Maxorder(root->left);
            bool right = Maxorder(root->right);
            
            return (left and right and 
            (root->data > root->left->data and root->data > root->right->data)); 

        }
    }
  
    int isHeap(struct Node* tree) {
        // code here
        int ind = 0;
        int totalCount = nodeCount(tree);
        if(isCBT(tree,ind,totalCount) and Maxorder(tree))
            return true;
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}
// } Driver Code Ends