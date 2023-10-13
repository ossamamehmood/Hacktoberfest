// Create a tree
tree *create_tree() {
  tree *t = new tree();
  return t;
}

// Add a node to a tree
void add_node(tree *t, int data) {
  node *n = new node();
  n->data = data;
  n->left = NULL;
  n->right = NULL;
  t->root = n;
}

// Find a node in a tree
node *find_node(tree *t, int data) {
  node *current = t->root;
  while (current != NULL) {
    if (current->data == data) {
      return current;
    } else if (current->data < data) {
      current = current->right;
    } else {
      current = current->left;
    }
  }
  return NULL;
}

// Delete a node from a tree
void delete_node(tree *t, int data) {
  node *current = t->root;
  node *parent = NULL;
  while (current != NULL) {
    if (current->data == data) {
      if (current->left == NULL && current->right == NULL) {
        if (parent == NULL) {
          t->root = NULL;
        } else if (parent->left == current) {
          parent->left = NULL;
        } else {
          parent->right = NULL;
        }
      } else if (current->left == NULL) {
        if (parent == NULL) {
          t->root = current->right;
        } else if (parent->left == current) {
          parent->left = current->right;
        } else {
          parent->right = current->right;
        }
      } else if (current->right == NULL) {
        if (parent == NULL) {
          t->root = current->left;
        } else if (parent->left == current) {
          parent->left = current->left;
        } else {
          parent->right = current->left;
        }
      } else {
        node *successor = current->right;
        while (successor->left != NULL) {
          successor = successor->left;
        }
        current->data = successor->data;
        delete_node(t, successor->data);
      }
      break;
    } else if (current->data < data) {
      parent = current;
      current = current->right;
    } else {
      parent = current;
      current = current->left;
    }
  }
}

// Print a tree in inorder
void print_inorder(tree *t) {
  node *current = t->root;
  while (current != NULL) {
    print_inorder(current->left);
    printf("%d ", current->data);
    print_inorder(current->right);
  }
}

// Print a tree in preorder
void print_preorder(tree *t) {
  node *current = t->root;
  while (current != NULL) {
    printf("%d ", current->data);
    print_preorder(current->left);
    print_preorder(current->right);
  }
}

// Print a tree in postorder
void print_postorder(tree *t) {
  node *current = t->root;
  while (current != NULL) {
    print_postorder(current->left);
    print_postorder(current->right);
    printf("%d ", current->data);
  }
}

// Free a tree
void free_tree(tree *t) {
  node *current = t->root;
  while (current != NULL) {
    free_tree(current->left);
    free_tree(current->right);
    delete current;
  }
}
