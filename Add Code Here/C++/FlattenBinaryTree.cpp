// Given the root of a binary tree, flatten the tree into a "linked list":
// 	•	The "linked list" should use the same Node class where the right child pointer points to the next   node in the list and the left child pointer is always null.
// 	•	The "linked list" should be in the same order as a pre-order traversal of the binary tree.

void flatten(Node *root)
{

  // code here

  Node *current = root;

  while (current != NULL)
  {

    if (current->left != NULL)
    {

      Node *prev = current->left;

      // Node *t=prev;

      while (prev->right != NULL)
      {

        //   t=prev;

        prev = prev->right;
      }

      prev->right = current->right;

      current->right = current->left;

      current->left = NULL;
    }

    current = current->right;
  }
}
