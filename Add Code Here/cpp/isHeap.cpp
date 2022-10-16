// check if the given B-tree is heap or not...


#include "iostream"
using namespace std;

class Node {

    public:
        int value;
        Node* left;
        Node* right;

    Node(int val){
        this->value = val;
        this->left = nullptr;
        this->right = nullptr;
    }

};


int countNodes(Node* root){

    if(root == nullptr) return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);

}


bool isCBT(Node* root, int i, int n){

    if(root == nullptr) return true;

    // index is out of the array size bound..
    if(i >= n) return false;
    else {

        bool rightSubTree = isCBT(root->right, 2*i+2, n);
        bool leftSubTree = isCBT(root->left, 2*i+1, n);  

        return (rightSubTree && leftSubTree);
    }

}


bool isMaxOrder(Node* root){

    if(root->left == nullptr && root->right == nullptr) return true;

    if(root->right == nullptr){
        return (root->value > root->left->value);
    }
    else {
        bool leftTree = isMaxOrder(root->left);
        bool rightTree = isMaxOrder(root->right);

        return (root->value > root->left->value && root->value > root->right->value && leftTree && rightTree);

    }
    
}


bool isHeap(Node* root){

    if(root == nullptr) return true;

    int i = 0;
    int nodeCount = countNodes(root);

    if(isCBT(root, i, nodeCount) && isMaxOrder(root)){
        return true;
    
    } else {

        return false;
    }

}


int main(){

    Node* A = new Node(100);
    Node* B = new Node(50);
    Node* C = new Node(60);
    Node* D = new Node(10);
    Node* E = new Node(5);

    A->left = B;
    A->right = C;
    B->left = D;
    B->right = E;


    cout << isHeap(A) << "\n";


    return 0;
}