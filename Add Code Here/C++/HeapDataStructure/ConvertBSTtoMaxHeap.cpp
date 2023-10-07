//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

/* Helper function that allocates a new node
with the given data and NULL left and right
pointers. */
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}
void postorderTraversal(Node* root)
{
    if (!root)
        return;

    // recur on left subtree
    postorderTraversal(root->left);

    // then recur on right subtree
    postorderTraversal(root->right);

    // print the root's data
    cout << root->data << " ";
}



// } Driver Code Ends
//User function Template for C++

/*struct Node {
    int data;
    Node *left, *right;
};*/

class Solution{
  public:
    
    void inorder(Node *root,vector<int> &inorderData) {
        if(!root)
        return;
        
        inorder(root->left,inorderData);
        inorderData.push_back(root->data);
        inorder(root->right,inorderData);
    }
  
    void fillPostorder(Node *root,vector<int> &inorderdata,int &index) {
        if(!root)
        return;
        
        fillPostorder(root->left,inorderdata,index);
        fillPostorder(root->right,inorderdata,index);
        root->data = inorderdata[index++];
    }
  
    void convertToMaxHeapUtil(Node* root)
    {
        // Your code goes here
        vector<int> inorderData;
        inorder(root,inorderData);
        int index = 0;
        fillPostorder(root,inorderData,index);
    }    
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    getchar();
    while (t--)
    {
        string inp, ch;
        getline(cin, inp);
        struct Node* root = buildTree(inp);
        Solution ob;
        ob.convertToMaxHeapUtil(root);
        postorderTraversal(root);
        cout << "\n";
    }
    return 0;
}


// } Driver Code Ends