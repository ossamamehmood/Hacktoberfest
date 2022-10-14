// Iterative Traversals
#include<iostream>
#include<stack>
using namespace std;

// Node class
class Node{
	
	public:
		int data;
		Node* left;
		Node* right;
	
		// Making Constructor
		Node(int d){
			data = d;
			left = NULL;
			right = NULL;
		}
};

// We're going to build our tree recursively first
Node* buildTree(Node* root){
	int n;
	cout<<"\nEnter Node's data -> ";
	cin>>n;
	
	if(n == -1){
		return NULL;
	}
	
	// Made the root Node only if the data entered by the user is not '-1'.	
	root = new Node(n);
	
	// Build the left side of our tree first.
	cout<<"Enter the data for inserting in the left of "<<n<<"-> ";
	root->left = buildTree(root->left);
	
	// Build the right side of our tree now.
	cout<<"Enter the data for inserting in the right of "<<n<<"-> ";
	root->right = buildTree(root->right);
	
	// Finally we return the tree built.
	return root;
}

void iterativeTraversals(Node* root){
	// Initialised three empty strings
	string pre("");
	string in("");
	string post("");
	
	// Making a stack to simulate the Recursion
	stack< pair<Node*, int> > s;
	
    // First insert the root Node into the Stack and set the state of the root Node to 1 (default state).
    // Root Node is the Node From which all the Other Nodes Originate.
	s.push({root, 1});
	
	while(!s.empty()){
		
		// Finding the current Node in hand first
		Node* node = s.top().first;
		int state = s.top().second;
		
		switch(state){
			
			case 1 : {
					pre.append(to_string(node->data));
					s.top().second++;
					
					// if the left child for the current Node existed, we push it into the stack since that's the next node we need to move onto
					if(node->left){
						s.push({node->left, 1});
					}
				}
				break;
			
			case 2:  {
					in.append(to_string(node->data));
					s.top().second++;
					
					// if the right child for the current node existed, we need to push it into the stack since that's the next element we need to move onto
					if(node->right){
						s.push({node->right, 1});
					}
			    }
			    break;
			   
			case 3:  {
					post.append(to_string(node->data));
					s.pop();
			    }
			    break;	   	
		}
	}
	
	cout<<endl<<"Pre-> "<<pre;
	cout<<"\nIn-> "<<in;
	cout<<"\nPost-> "<<post;
}



int main(){
	Node *root = NULL;
	root = buildTree(root);

	
	iterativeTraversals(root);
	
}