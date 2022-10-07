#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long int

struct node{
    int data;
    node* left;
    node* right;
    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class tree{
    public:
    int indx;
    tree(){
        this->indx = -1;
    }
    // int indx=-1;
    node* built_tree(int arr[]){
        indx++;   
        if(arr[indx] == -1){
            return NULL;
        }
        node* newnode =new node(arr[indx]);
        newnode->left = built_tree(arr );
        newnode->right = built_tree(arr );
        return newnode;
    }
};

int solve(node* root, int &res){
    if(root == NULL){
        return 0;
    }

    int l = solve(root->left,res);
    int r = solve(root->right,res);

    int temp = max(l,r) + 1;
    int ans = max(temp, l+r+1);
    
    res = max(res,ans);

    return temp;
}

void print_tree(node* root){
    if(root == NULL){
        return ;
    }
    
    print_tree(root->left);
    cout<<root->data<<" ";
    print_tree(root->right);
}

void print_level_order(node* root){
    if(root == NULL){
        return;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        if( q.front() == NULL){
            cout<<endl;
            q.pop();
            if(!q.empty())
                q.push(NULL);
            else
                break;
        }
        node* curr = q.front();
        q.pop();
        cout<<curr->data<<" ";
        if(curr->left!= NULL)
            q.push(curr->left);
        if(curr->right !=NULL)
            q.push(curr->right);
    }
    cout<<endl;
}

int count_of_nodes(node * root){
    if(root == NULL){
        return 0;
    }
    int l = count_of_nodes(root->left);
    int r = count_of_nodes(root->right);

    return l+r+1;
}

int total_count(node* root){
    if(root ==NULL){
        return 0;
    }

    int l = total_count(root->left);
    int r = total_count(root->right);

    return l+r+root->data;
}

int height(node* root){
    if(root == NULL){
        return 0;
    }
    int l = height(root->left);
    int r = height(root->right);

    return max(l,r)+1;
}

struct treeInfo{
    int height;
    int diameter;
    treeInfo(int height, int diameter){
        this->height = height;
        this->diameter = diameter;
    }
};
treeInfo* diameter2(node* root){
    if(root == NULL){
        treeInfo* new_tree = new treeInfo(0,0);
        return new_tree;
    }

    treeInfo* l = diameter2(root->left);
    treeInfo* r = diameter2(root->right);

    int myheight = max(l->height , r->height) + 1;

    int dia1 = l->diameter; 
    int dia2 = r->diameter;
    int dia3 = l->height + r->height + 1;

    int mydia = max(dia1 , max(dia2 , dia3));

    treeInfo* newtree = new treeInfo(myheight, mydia);

    return newtree;
}
bool isIdentical(node* root, node* sub_root){
    if(root == NULL && sub_root == NULL){
        return true;
    }
    if(root == NULL || sub_root == NULL){
        return false;
    }
    if(root->data == sub_root->data){
        return isIdentical(root->left , sub_root->left) && isIdentical(root->right , sub_root->right);
    }

    return false;
}
bool subtree(node* root, node* sub_root){
    if(sub_root == NULL){
        return true;
    }
    if(root == NULL){
        return false;
    }
    if(root->data == sub_root->data){
        if(isIdentical(root, sub_root)){
            return true;
        }
    }

    return (subtree(root->left, sub_root) || subtree(root->right, sub_root));

}

node* binary_tree(node* root,int val){
    if(val==-1){
        return NULL;
    }
    if(root == NULL){
        root = new node(val);
        return root;
    }

    if(val>root->data){
        root->right = binary_tree(root->right,val);
    }
    else{
        root->left = binary_tree(root->left, val);
    }

    return root;
}

bool find(node * root, int val){
    if(root == NULL){
        return false;
    }
    if(root->data == val){
        return true;
    }
    if(root->data<val){
        return find(root->right,val);
    }else{
        return find(root->left,val);
    }
}
node* inorderSuccessor(node* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}
node* del(node* root,int val){

    if(val>root->data){
        root->right = del(root->right, val);
    }
    else if(val<root->data){
        root->left = del(root->left, val);
    }
    else{
        if(root->left == NULL && root->right == NULL){
            return NULL;
        }
        else if(root->left == NULL){
            return root->right;
        }
        else if(root->right == NULL){
            return root-> left;
        }else{
            node *IS = inorderSuccessor(root->right);
            root->data = IS->data;
            root->right = del(root->right, IS->data);
        }
    }
    return root;
}

void print_In_Range(node* root, int x,int y){
    if(root == NULL){
        return;
    }
    if(x<=root->data && root->data<=y){
        print_In_Range(root->left, x,y);
        cout<<root->data<<" ";
        print_In_Range(root->right, x, y);
    }
    else if(root->data >=y){
        print_In_Range(root->left,x,y);
    }
    else if(root->data<=x){
        print_In_Range(root->right,x,y);
    }
}
void root_to_leaf(node *root,vector<int> &v,vector<vector<int>> &all_v){
    
    if(root == NULL){
        return ;
    }
    v.push_back(root->data);
    if(root->left == NULL && root->right ==NULL){
        all_v.push_back(v);
    }
    else{
         root_to_leaf(root->left,v,all_v);
         root_to_leaf(root->right,v,all_v);
    }
    v.pop_back();
    
}
int main(){
    int arr[] = {1,2,3,-1,-1,4,-1,-1,5,6,7,-1,-1,8,-1,-1,9,-1,-1};
    int arr1[] = {6,7,-1,-1,9,-1,-1};
    int arr3[] = {5,1,3,4,2,7};
    tree t1,t2;
    node* root = t1.built_tree(arr);
    // node* sub_root = t2.built_tree(arr1);
    // cout<<root->data<<endl;

    // print_tree(root);
    // cout<<endl;

    // print_level_order(root);

    // int res = INT_MIN;
    // solve(root,res);
    // cout<<res<<endl;

    // cout<<count_of_nodes(root)<<endl;

    // cout<<total_count(root)<<endl;

    // cout<<height(root)<<endl;

    // treeInfo* dia = diameter2(root);
    // cout<<dia->diameter<<endl;

    // print_level_order(sub_root);

    // cout<<subtree(root, sub_root);
    // node* root = new node(arr3[0]);
    // cout<<root->data<<endl;
    // for(int i=1;i<6;i++){
    //     binary_tree(root,arr3[i]);
    // }
    // print_level_order(root);
    // // cout<<find(root,9);
    // node* new_root = del(root, 1);
    // print_level_order(new_root);
    // cout<<endl;
    // print_tree(root);
    // cout<<endl;
    // // print_In_Range(root,3,7);
    // print_level_order(root);
    // vector<int> v;
    // vector<vector<int>> all_v;
    // root_to_leaf(root,v,all_v);
    // for(auto vec: all_v){
    //     for(auto val:vec){
    //         cout<<val<<" ";
    //     }
    //     cout<<endl;
    // }
    print_level_order(root);

}