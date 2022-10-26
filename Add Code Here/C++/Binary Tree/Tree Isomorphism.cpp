#include<bits/stdc++.h>
using namespace std;
struct treenode {
   int data;
   treenode * left;
   treenode * right;
};
struct treenode * createNode(int d) {
   struct treenode * root = new treenode;
   root -> data = d;
   root -> left = NULL;
   root -> right = NULL;
   return root;
}
bool isIsomor(treenode * r1, treenode * r2) {
   if (r1 == NULL and r2 == NULL) {
      return true;
   }
   if (r1 == NULL or r2 == NULL) {
      return false;
   }
   return (r1 -> data == r2 -> data &amp;&amp; ((isIsomor(r1 -> left, r2 -> right) &amp;&amp;       isIsomor(r1 -> right, r2 -> left)) || (isIsomor(r1 -> left, r2 -> left) &amp;&amp; isIsomor(r1 -> right, r2 -> right))));
}
int main() {
   struct treenode * r1 = createNode(1);
   r1 -> left = createNode(2);
   r1 -> right = createNode(3);
   r1 -> left -> left = createNode(4);
   r1 -> left -> right = createNode(5);
   r1 -> right -> left = createNode(6);
   r1 -> left -> right -> left = createNode(7);
   r1 -> left -> right -> right = createNode(8);
   struct treenode * r2 = createNode(1);
   r2 -> left = createNode(3);
   r2 -> right = createNode(2);
   r2 -> right -> left = createNode(4);
   r2 -> right -> right = createNode(5);
   r2 -> left -> right = createNode(6);
   r2 -> right -> right -> left = createNode(8);
   r2 -> right -> right -> right = createNode(7);
   if (isIsomor(r1, r2)) {
      cout << "Isomorphic" << endl;
   } else {
      cout << "Not an Isomorphic" << endl;
   }
   return 0;
}
