#include <iostream>
#include <vector>
#include <queue>

struct Node {
    int data;
    Node* left;
    Node* right;
};

std::vector<std::vector<int>> levelOrder(Node* root) {
    std::vector<std::vector<int>> result;
    
    if (root == nullptr) {
        return result;
    }

    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        std::vector<int> level;

        for (int i = 0; i < size; i++) {
            Node* current = q.front();
            q.pop();

            level.push_back(current->data);

            if (current->left != nullptr) {
                q.push(current->left);
            }

            if (current->right != nullptr) {
                q.push(current->right);
            }
        }

        result.push_back(level);
    }

    return result;
}

int main() {
  
    Node* root = new Node{1, new Node{2, nullptr, nullptr}, new Node{3, nullptr, nullptr}};

 
    std::vector<std::vector<int>> traversalResult = levelOrder(root);

 
    for (const auto& level : traversalResult) {
        for (int nodeData : level) {
            std::cout << nodeData << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}
