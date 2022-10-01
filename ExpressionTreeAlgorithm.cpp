#include <iostream>
using namespace std;

struct n//node declaration {
   char d;
   n *l;
   n *r;
};
char pf[50];
int top = -1;
n *a[50];
int r(char inputch)//check the symbol whether it is an operator or an operand. {
   if (inputch == '+' || inputch == '-' || inputch == '*' || inputch == '/')
      return (-1);
   else if (inputch >= 'A' || inputch <= 'Z')
      return (1);
   else if (inputch >= 'a' || inputch <= 'z')
      return (1);
   else
      return (-100);
}
void push(n *tree)//push elements in stack {
   top++;
   a[top] = tree;
}
n *pop() {
   top--;
   return (a[top + 1]);
}
void construct_expression_tree(char *suffix) {
   char s;
   n *newl, *p1, *p2;
   int flag;
   s = suffix[0];
   for (int i = 1; s!= 0; i++) {
      flag = r(s);
      if (flag == 1) {
         newl = new n;
         newl->d = s;
         newl->l = NULL;
         newl->r = NULL;
         push(newl);
      } else {
         p1 = pop();
         p2 = pop();
         newl = new n;
         newl->d = s;
         newl->l = p2;
         newl->r = p1;
         push(newl);
      }
      s = suffix[i];
   }
}

void inOrder(n *tree)//perform inorder traversal {
   if (tree != NULL) {
      inOrder(tree->l);
      cout << tree->d;
      inOrder(tree->r);
   }
}

int main(int argc, char **argv) {
   cout << "Enter Postfix Expression : ";
   cin >>pf;
   construct_expression_tree(pf);
   cout << "\nInfix Expression : ";
   inOrder(a[0]);
   return 0;
}
