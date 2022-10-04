#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Node{
	int data;
	Node* left;
	Node* right;
};

class BST{
	private:
		Node* root;
	public:
		BST();
		void insert(int n);
		void print();
		void del(int n);
		void find(int n, Node* &p,Node* & parent);
		void find_rec(int n, Node* &p,Node* & parent);
	private:
	void insert_rec(int n, Node* &root);
	void print_tree(Node * root);
	void getLargestNode(Node * &r, Node * &pred_r);
	Node *del_OneChildNode(Node *p,Node *parent);
	Node *del_Leaf(Node *p,Node *parent);
	Node *del_TwoChildNode(Node *p,Node *parent);
	};
//////////////////////////////////////////////////
// constructor
////////////////////////////////////////
BST::BST()
{
	root=NULL;
}

///////////////////////////////////
// the public recurisive function that is used only so that root is not accessible outside the class
//////////////////////////////
void BST::insert(int n)
{
	insert_rec(n,root);
}
//////////////////////////////////////////////
// the recurisive function that does the actual insertion
//////////////////////////////////////
void BST::insert_rec(int n, Node* &root)
{
	if(root==NULL)
	{
	root=new Node;
	root->data=n;
	root->left=NULL;
	root->right=NULL;
	return;
	}
	else if (root->data==n)
	{
		cout<<"\n Data already in BST ..not inserting node with data "<<n;
		return;
	
	
	}
	else if(n<root->data)
	insert_rec(n,root->left);
	else
	insert_rec(n,root->right);
}


void BST::print()
{
	cout<<"\n Printing Tree \n";
	print_tree(root);
}
///////////////////////////////////

/////////////////////////////////////
void BST::print_tree(Node * root)
{
	if(root==NULL)
	return;
	else
	{
		print_tree(root->left);
		cout<<" "<<root->data;
		print_tree(root->right);
	}

}

//////////////////////////////////////////////////
//The below function searches for a node with data n a node and its parent.

/////////////////////////////////////////////////////

void BST::find(int n, Node * &p, Node* &parent)
{
	p=root;
	parent=NULL;
	find_rec( n, p, parent);
	
	if(p==NULL)
	cout<<"Node not found";
	else if(parent==NULL)
	cout<<"\n found node "<<p->data<<" at root";
	else
	cout<<"\n p->data "<<p->data<<" parent->data "<<parent->data;
}
/////////////////////////////////////////
// actual finding work is done here
// when the function returns to the calling function (main) 
// p should poiint to the node and parent to its parent 
// p will be NULL if the node does not exist
// parent is NULL if the required node is the root


///////////////////////////////////////////
void BST::find_rec(int n, Node * &p, Node* &parent)
{
	if(p==NULL)
	return;
	if(p->data==n)
	return;
	else if(n<p->data)
	{
		parent=p;
		p=p->left;
		find_rec(n,p,parent);
	}
	else{//required node on the right
		parent=p;
		p=p->right;
		find_rec(n,p,parent);
	}
}
///////////////////////////////////////
// function to delete a node
// input n

////////////////////////////////////////
void BST::del(int n)
{
	//search the pointer to the node and the parent
	Node *p;
	Node* parent;
	find(n,p,parent);
	
	if(p==NULL){//if the node doesnt exist
	cout<<"\n Node does not exist in the BST";
	
	return;
	}
	else if(p->left==NULL &&p->right==NULL){//p is a leaf
		cout<<"\n Leaf Node";
		
		p=del_Leaf(p,parent);
		
	}

	else if(p->left==NULL ||p->right==NULL){//p has one child . If both cases are true then the above if is executed
		cout<<"\n One child";
	
	p=del_OneChildNode(p, parent);	
	}
	else{//p has 2 children
		cout<<"\n two children";
		p=del_TwoChildNode(p,parent);
		
	}
delete p; // now the node is properly removed from the tree so we just free memory
}


////////////////////////////////////////////////

///////////////////////////////////////////
Node * BST::del_OneChildNode(Node *p,Node *parent)
{
	
		//identify the single child of p
		Node *temp;
		if(p->left!=NULL)
		temp=p->left;
		else
		temp=p->right;
		cout<<"\n temp->data "<<temp->data;
		
		if(parent==NULL)// p is the root
		{
			root=temp;
		}
		else if(parent->left==p)
			parent->left=temp;
		else
			parent->right=temp;	

return p;		
}

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////
Node * BST::del_TwoChildNode(Node *p,Node *parent)
{
	Node *r=p->left;// r is the address of the node we will replace p with
	Node* pred_r; // the predecessor or parent of r
	getLargestNode(r,pred_r);
	cout<<"\n the largest node in the left subtree is "<<r->data;

	
	// now we will replace the p with r
	//first see where to do the replacement
	if(parent==NULL)// we are deleting the root
	{
	root=r; //now replacement becomes the root
	}
	else if(parent->left==p)//p is on the left side of parent
	parent->left=r;
	else// its on right
	parent->right=r;
	
	
	//now do the  setting in pred_r ( parent of r)
	// Note that r is the right most node of the left subtree of p so
	// Either 1) it is a leaf
	// or 2) r has a left subtree but not a right subtree
	// also r is on the right side of pred_r
	
	pred_r->right=r->left;

	
	//now set the left right pointers of the replacement r
	r->left=p->left;
	r->right=p->right;

		
return p;
}
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////
Node * BST::del_Leaf(Node* p,Node* parent)
{
	if(parent==NULL)//p is the root
		root=NULL;
		if(parent->left==p)//if p is on left
		parent->left=NULL;
		else// p is on right
		p->right=NULL;
		
return p;
		
}

////////////////////////////////////////////
// this function returns the largest node for the tree/subtree rooted at r
// return NULL if tree/subtree rooted at r is empty. ( this should never happen in delete node with 2 children)
/////////////////////////////////////////////////////
void BST::getLargestNode(Node * &r, Node * &pred_r)
{
	pred_r=NULL;
	if(r==NULL)
	return ;
	
	
	while(r->right!=NULL){//iterate till you reach the right most node
		pred_r=r;
		r=r->right;
	}
}
int main() {
	BST tree;
	tree.insert(101);
	tree.insert(50);
	tree.insert(10);
	tree.insert(5);
	
	tree.insert(15);
	tree.insert(2);
	tree.insert(7);
	tree.insert(17);
	tree.insert(75);
	tree.insert(16);
	tree.insert(500);
	tree.print();
	/*Node* p;
	Node * parent;
	tree.find(10,p,parent);*/
	tree.del(50);
	tree.print();
	
	return 0; 
}
