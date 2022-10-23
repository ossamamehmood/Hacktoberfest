//:):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):)
//:):):):):)::):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):
//:):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):)
//:):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):)
//:):) -----------------------------------------------------------:):):):)
//:):)|   --------               -------     -------    --------   |:):):)
//:):)|   |         |       |   |       |   |       |   |          |:):):)
//:):)|   |         |       |   |       |   |       |   |          |:):):)
//:):)|   --------  |       |   |-------    |-------|   --------   |:):):)
//:):)|          |  |       |   | \         |       |           |  |:):):)
//:):)|          |  |       |   |   \       |       |           |  |:):):) 
//:):)|   --------   -------    |     \      -------    --------   |:):):)
//:):) ----------------------------------------------------------- :):):):
//:):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):)
//:):):):):)::):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):
//:):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):)
//:):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):)
 
 
 
#include <bits/stdc++.h>
using namespace std;

#define int long long
 
#define forf(i, k, n)  for (int i = k; i < n; i++)

int vis[1001][1001] ;
int p[]= {0,0,1,-1} ;
int q[]= {1,-1,0,0} ;
 
void dfs(int i, int j, int &n, int &m ){
	vis[i][j]=1 ;
	for(int k=0;k<4;k++){
		int x= i+p[k] ;
		int y= j+q[k] ;
		if(x>=0 && x<n && y>=0 && y<m){
			if(vis[x][y]==0){
				dfs(x,y,n,m) ;
			}
		}
	}
}
 
void solve() {
 
	int n , m ;
	cin >> n >> m ;
 
	char arr[n][m] ;
 
	forf(i,0,n){
		forf(j,0,m){
			cin >> arr[i][j] ;
			if(arr[i][j]=='#') vis[i][j]=1 ;
			else vis[i][j]=0 ;
		}
	}
	int ans=0 ;
	for(int i=0;i<n;i++){
		forf(j,0,m){
			if(vis[i][j]==0){
				ans++ ;
				dfs(i,j,n,m) ;
			}
		}
	}
	cout<<ans<<endl ;
	
 
}
 
 
int32_t main()
{
  
    
    int t=1;
    // cin >> t;
    
   
    for(int i=1;i<=t;i++){
    	solve();
    
    }
    
    
    return 0;
}



#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
};
 
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 
void printInorder(struct Node* node)
{
    if (node == NULL)
        return;

    printInorder(node->left);
 
    cout << node->data << " ";

    printInorder(node->right);
}
 
int main()
{
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
 
    cout << "\nInorder traversal of binary tree is \n";
    printInorder(root);
 
    return 0;
}