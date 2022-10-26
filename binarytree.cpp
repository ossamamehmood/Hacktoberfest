// hare krishna
// ritik dagar


#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class node{
	public:
		int data;
		node *left, *right;
		
		node(int n)
		{
			data=n;
			left=right=NULL;
		} 
};

node *root = NULL;

class tree{
	public:
	node *insert(node *t,int x)
	{
		if(t==NULL)
		t=new node(x);
		else{
			queue<node *> q;
			q.push(t);
			node *n= new node(x);
			while(!q.empty())
			{
				node *t= q.front();
				q.pop();
				if(!t->left)
				{
					t->left = n;
					break;
				}
				else
				q.push(t->left);
				
				if(!t->right)
				{
					t->right= n;
					break;
				}
				else
				q.push(t->right);
				
			}
		}
		return t;
	}
		void preorder(node *t)
		{
			if(t!=NULL)
			{
				cout<<t->data<<" ";
				preorder(t->left);
				preorder(t->right);
			}
		}
		void inorder(node *t)
		{
			if(t!=NULL)
			{
				inorder(t->left);
				cout<<t->data<<" ";
				inorder(t->right);
			}
		}
		void postorder(node *t)
		{
			if(t!=NULL)
			{
				postorder(t->left);
				postorder(t->right);
				cout<<t->data<<" ";
			}
		}
		void deletedeepest(node *t, node *d)
		{
			queue<node *>q;
			q.push(t);
			
			node *temp;
			while(!q.empty())
			{
				temp= q.front();
				q.pop();
				if(temp==d)
				{
					temp=NULL;
					delete(d);
					return ;
				}
				if(temp->right)
				{
					if(temp->right==d)
					{
						temp->right=NULL;
						delete(d);
						return ;
					}
					else
					q.push(temp->right);
				}
				if(temp->left)
				{
					if(temp->left==d)
					{
						temp->left=NULL;
						delete(d);
						return ;
					}
					else
					q.push(temp->left);
				}
				
			}
		
		
			
		}
		node *deletenode(node *t,int x)
		{
			if(t==NULL)
			return NULL;
			if(t->left==NULL && t->right==NULL)
			{
				if(t->data==x)
				return NULL;
				else
				return t;
			}
			
			queue<node*> q;
			q.push(t);
			
			node *temp,*key_node=NULL; //deepest node and deleted node
			
			while(!q.empty())
			{
				temp= q.front();
				q.pop();
				
				if(temp->data==x)
				key_node=temp;
				
				if(temp->left)
				q.push(t->left);
				
				if(t->right)
				q.push(t->right);
				

			}
			
			if(key_node!=NULL)
			{
				int d= temp->data;
				deletedeepest(t,temp);
				key_node->data=d;
			}
			return t;
		}
		void levelorder(node *root)
		{
			if(root)
			{
				queue<node *> q;
				q.push(root);
				while(!q.empty())
				{
					node *t= q.front();
					cout<<t->data<<" ";
					q.pop();
					if(t->left)
					{
						q.push(t->left);
					}
					if(t->right)
					{
						q.push(t->right);
					}
				}
			}
		}
		
		void reverselevelorder(node *root)
		{
			if(root)
			{
				queue<node *>q;
				stack<node *>st;
				q.push(root);
				while(!q.empty())
				{
					node *x= q.front();
					st.push(x);
					q.pop();
					if(x->right)
					q.push(x->right);
					if(x->left)
					q.push(x->left);
					
					
				}
				while(!st.empty())
				{
					node *x=st.top();
					cout<<x->data<<" ";
					st.pop();
				}
			}
		}
		
		bool search(node *root,int x)
		{
			if(root)
			{
				queue<node *>q;
				q.push(root);
				while(!q.empty())
				{
					node *t=q.front();
					q.pop();
					if(t->data==x)
					return true;
					
					if(t->left)
					q.push(t->left);
					
					if(t->right)
					q.push(t->right);
				}
				
			}
			return false;
		}
		
		int height(node *root)
		{
			if(root==NULL)
			return 0;
			else
			{
				int lh= height(root->left);
				int rh=height(root->right);
				if(lh>rh)
				return lh+1;
				else
				return rh+1;
			}
		}
		int max(int a,int b)
		{
			return a>b?a:b;
		}
		int heightd(node *root, int& ans)
		{
			if(root)
			{
				int lh= heightd(root->left, ans);
				int rh= heightd(root->right,ans);
				ans= max(ans, 1+lh+rh);
				
				return 1+max(lh,rh);
				}
		}
		int diameter(node *root)
		{
			int ans=INT_MIN;
			if(root)
			{
				int h= heightd(root,ans);
				
				return ans;
				
			}
		}
		
		void mirror(node *root)
		{
			if(root)
			{
				node *t;
				mirror(root->left);
				mirror(root->right);
				
				t= root->left;
				root->left= root->right;
				root->right=t;
			}
		}
		
		bool checkbalance(node *root)
		{
			if(root)
			{
				int lh= height(root->left);
				int rh= height(root->right);
				
				if(abs(lh-rh)<=1&&checkbalance(root->left)&&checkbalance(root->right))
				return 1;
				
				return 0;
				
			}
			return 1;
		}
		int maxv(node *root)
		{
			if(root)
			{
				int val= root->data;
				int lval= maxv(root->left);
				int rval= maxv(root->right);
				if(lval>val)
				val= lval;
				if(rval>val)
				val= rval;
				return val;
			}
			return 0;
		}
		
			int minv(node *root)
		{
			if(root)
			{
				int val= root->data;
				int lval= minv(root->left);
				int rval= minv(root->right);
				if(lval<val)
				val= lval;
				if(rval<val)
				val= rval;
				return val;
			}
			return INT_MAX;
		}
		
};

int main()
{
	tree t;
	int n,x;
	do{
		
	cout<<"1. insert element "<<endl;
	cout<<"2. preorder traversal "<<endl;
	cout<<"3. inorder traversal "<<endl;
	cout<<"4. postorder traversal "<<endl;
	cout<<"5. delete node "<<endl;
	cout<<"6. level order traversal "<<endl;
	cout<<"7. reverse level order traversal "<<endl;
	cout<<"8. search value "<<endl;
	cout<<"9. height of tree "<<endl;
	cout<<"10. diameter of tree "<<endl;
	cout<<"11. mirror of tree "<<endl;
	cout<<"12. check tree balance "<<endl;
	cout<<"13. find minimum value of tree "<<endl;
	cout<<"14. find maximum value of tree "<<endl;
	cout<<"15. exit"<<endl;
		cin>>n;
		cout<<endl;
		switch(n)
		{
			case 1:
				cout<<"element to be inserted in tree is "<<endl;
				cin>>x;
				root=t.insert(root,x);
				break;
				
			case 2:
				cout<<"preorder traversal of the tree is "<<endl;
				t.preorder(root);
				cout<<endl;
				break;
				
			case 3:
				cout<<"inorder traversal of the tree is "<<endl;
				t.inorder(root);
				cout<<endl;
				break;
				
			case 4:
				cout<<"postorder traversal of the tree is "<<endl;
				t.postorder(root);
				cout<<endl;
				break;
			
			case 5:
				cout<<"node to be deleted is "<<endl;
				cin>>x;
				root=t.deletenode(root,x);
				break;
				
			case 6:
				cout<<"level order traversal of the tree is "<<endl;
				t.levelorder(root);
				cout<<endl;
				break;
			
			case 7:
				cout<<"reverse  level order traversal of the tree is "<<endl;
				t.reverselevelorder(root);
				cout<<endl;
				break;
				
			case 8:
				cin>>x;
				if(t.search(root,x))
				cout<<"value found "<<endl;
				else
				cout<<"value not found "<<endl;
				
				break;
				
			case 9:
				cout<<"height of tree is "<<endl;
				cout<<t.height(root);
				cout<<endl;
				break;
				
			case 10:
				cout<<"diameter of tree is "<<endl;
				cout<<t.diameter(root)<<endl;
				break;
				
			case 11:
				cout<<"mirror of tree is "<<endl;
				t.mirror(root);
				break;
				
			case 12:
				if(t.checkbalance(root))
				cout<<"tree is balance "<<endl;
				else
				cout<<"tree not balanced "<<endl;
				break;
				
			case 13:
				cout<<"minimum value in tree is "<<endl;
				cout<<t.minv(root)<<endl;
				break;
				
			case 14:
				cout<<"maximum value of tree is "<<endl;
				cout<<t.maxv(root)<<endl;
				break;
				
	
			
		}
		cout<<endl;
	}while(n!=15);
	
	
	return 0;
}
