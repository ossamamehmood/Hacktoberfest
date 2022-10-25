#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* leftChild, *rightChild;
};
struct Node* newNode(int data){
   struct Node* newNode = new Node;
   newNode->data = data;
   newNode->leftChild = newNode->rightChild = NULL;
   return (newNode);
}
int height(Node* root, int& ans){
   if (root == NULL)
      return 0;
   int left_height = height(root->left, ans);
   int right_height = height(root->right, ans);
   ans = max(ans, 1 + left_height + right_height);
   return 1 + max(left_height, right_height);
}
int diameter(Node* root){
   if (root == NULL)
      return 0;
   int ans = INT_MIN;
   int height_of_tree = height(root, ans);
   return ans;
}
int main(){
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    printf("Diameter is %d
", diameter(root));
    return 0;
}
