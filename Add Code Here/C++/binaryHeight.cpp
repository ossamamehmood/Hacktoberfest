#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
template <typename T>
class BinaryTree
{
public:
    T data;
    BinaryTree<int> *left;
    BinaryTree<int> *right;
    BinaryTree(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTree()
    {
        delete left;
        delete right
    }
};
void printLW(BinaryTree<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<BinaryTree<int> *> pendingNode;
    pendingNode.push(root);
    while (pendingNode.size() != 0)
    {
        BinaryTree<int> *front = pendingNode.front();
        pendingNode.pop();
        cout << front->data;
        if (front->left)
        {
            pendingNode.push(front->left);
            cout << "L " << front->left->data;
        }
        if (front->right)
        {
            pendingNode.push(front->right);
            cout << "R " << front->right->data;
        }
    }
}
BinaryTree<int> *takeInLW()
{
    int data;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    BinaryTree<int> *root = new BinaryTree<int>(data);
    queue<BinaryTree<int> *> pendingNode;
    pendingNode.push(root);
    while (pendingNode.size() != 0)
    {
        BinaryTree<int> *front = pendingNode.front();
        pendingNode.pop();
        int childN;
        cout << "Enter Numeber of Children for " << front->data << ": ";
        cin >> childN;
    }
}
int main()
{

    return 0;
}