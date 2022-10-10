#include<iostream>
#include<queue>
using namespace std;
class node {
	public:
		int value;
		node* left;
		node* right;
};
class tree{
	node *root;
	public:
		tree(){root=NULL;}
		void createtree();
		void preorder(){preorder(root);}
		void preorder(node *p);
		void inorder(){inorder(root);}
		void inorder(node *p);
		void postorder(){postorder(root);}
		void postorder(node *p);
		
	
};
void tree:: preorder(node *p){
	if(p){
	
		cout<<p->value<<" ";
		preorder(p->left);
		preorder(p->right);
	}
}
void tree:: inorder(node *p){

	if(p){
		inorder(p->left);
		cout<<p->value<<" ";
		inorder(p->right);
	}
}
void tree:: postorder(node *p){
	if(p){
	
		postorder(p->left);
		postorder(p->right);
		cout<<p->value<<" ";
	}
}
void tree:: createtree(){
	int x;
	cout<<"Enter the root value : ";
	cin>>x;
	node *p,*t;
	queue<node*> q;
	root= new node;
	root->value=x;
	root->left=NULL;
	root->right=NULL;
	q.push(root);
	while(!q.empty()){
		p=q.front();
		q.pop();
		cout<<"Enter left child of "<<p->value<<" \n";
		cin>>x;
		if(x!=-1){
			t= new node;
			t->value=x;
			t->left=NULL;
			t->right=NULL;
			p->left=t;
			q.push(t);}
		cout<<"Enter right child"<<p->value<<" \n";
		cin>>x;
		if(x!=-1){
			t= new node;
			t->value=x;
			t->left=NULL;
			t->right=NULL;
			p->right=t;
			q.push(t);}
	}
}
int main(){
	tree t;
	t.createtree();
	cout<<"The preorder is : ";
	t.preorder();
	//cout<<t->root<<"root";
	cout<<"\nThe inorder is : ";
	t.inorder();
	cout<<"\nThe postorder is : ";
	t.postorder();
		
}