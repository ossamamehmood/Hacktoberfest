
#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int data;
    Node *left, *right;
};
 
Node* newNode(int item)
{
    Node* temp = new Node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
    void printCousins(Node* root, Node* node_to_find)
    {
        //code here
        vector<int> ans;
        queue<Node *> q;
        q.push(root);
        bool flag =false;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                Node* x = q.front();
                q.pop();
                if(x->left != node_to_find and x->right != node_to_find){
                    if(x->left){
                        q.push(x->left);
                    }
                    if(x->right){
                        q.push(x->right);
                    }
                }
                else{
                    flag=1;
                }
            }
            if(flag){
                  while(!q.empty()){
                   Node* a=q.front();
                   q.pop();
                   ans.push_back(a->data);
                }
               break;
            }
        }
            
       if(ans.size()==0){
            ans.push_back(-1);
            cout<<"No cousins there"<<endl;
            return;
    }
       for(int i=0;i<ans.size();i++){
           cout<<ans[i]<<" ";
       }
       cout<<endl;
       return;
   }
int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->right = newNode(15);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
 
    Node* x = newNode(43);
 
    printCousins(root, x);
    printCousins(root, root);
    printCousins(root, root->right);
    printCousins(root, root->left);
    printCousins(root, root->left->right);
 
    return 0;
}
