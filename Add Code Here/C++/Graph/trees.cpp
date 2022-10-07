#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long int

struct node{
    int value;
    node* left;
    node* right;
    node(int value){
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

void print_tree(node* root){
    if(root == NULL){
        return;
    }
    cout<<root->value<<" ";
    print_tree(root->left);
    print_tree(root->right);
}
class tree{
    public:
    int indx = -1;
    node* built_tree(int arr[]){
        indx++;
        if(arr[indx] == -1){
            return NULL;
        }
        node * newnode = new node(arr[indx]);
        newnode->left =  built_tree(arr);
        newnode->right = built_tree(arr);

        return newnode;
    }
};

node* binary_tree(int val,node * root){
    if(root == NULL){
        node* newnode = new node(val);
        return newnode;
    }
    if(val>root->value){
        root->right = binary_tree(val,root->right);
    }else{
        root->left = binary_tree(val,root->left);
    }
    return root;
}
void print_level_order(node* root){
    if(root == NULL){
        return ;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* curr = q.front();
        q.pop();
        if(curr == NULL){
            cout<<endl;
            if(q.empty()){
                break;
            }else{
                q.push(NULL);
            }
        }
        else{
            cout<<curr->value<<" ";
            if(curr->left!= NULL)
                q.push(curr->left);
            if(curr->right != NULL)
                q.push(curr->right);
        }
    }
} 
int count_of_nodes(node* root){
    if(root == NULL){
        return 0;
    }
    int l = count_of_nodes(root->left);
    int r = count_of_nodes(root->right);

    return l+r+1;
}

int total_count(node* root){
    if(root == NULL){
        return 0;
    }
    int l = total_count(root->left);
    int r = total_count(root->right);

    return l+r+root->value;
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
    treeInfo(int height ,int diameter){
        this->height = height;
        this->diameter = diameter;
    }
};
treeInfo* diameter2(node* root){
    if(root == NULL){
        return new treeInfo(0,0);
    }

    treeInfo* l = diameter2(root->left);
    treeInfo* r = diameter2(root->right);

    int myheight = max(l->height, r->height) +1;

    int dia1 = l->diameter;
    int dia2 = r->diameter;
    int dia3 = l->height + r->height +1;

    int mydiameter = max(dia1 , max(dia2 , dia3));
    treeInfo* mytree = new treeInfo(myheight, mydiameter);
    return mytree;
}

int diameter(node* root, int &res){
    if(root == NULL){
        return 0;
    }

    int l = diameter(root->left, res);
    int r = diameter(root->right, res);
    int temp = max(l,r) + 1;
    int ans = max(temp , l+r+1);

    res = max(res,ans);
    return temp;
}
bool isIdentical(node* root, node* sub_root){
    if(sub_root == NULL && root==NULL){
        return true;
    }
    if(root == NULL){
        return false;
    }
    if(root->value == sub_root->value){
        return isIdentical(root->left,sub_root->left) &&
                isIdentical(root->right, sub_root->right);
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
    if(root->value == sub_root->value){
        if(isIdentical(root,sub_root)){
            return true;
        }
    }
    return subtree(root->left,sub_root) || subtree(root->right, sub_root);
}

bool find(node * root, int val){
    if(root == NULL){
        return false;
    }
    if(root->value == val){
        return true;
    }
    return find(root->left, val) || find(root->right,val);
}
node* inorderSuccessor(node* root){
    while(root->left!=NULL){
        root = root->left;
    }
    return root;
}
node* del(node *root,int val){
    if(root == NULL){
        return NULL;
    }

    if(root->value>val){
        root->left = del(root->left, val);
    }
    else if(root->value<val){
        root->right = del(root->right, val);
    }
    else{
        if(root->left == NULL && root->right == NULL){
            return NULL;
        }
        else if(root->left == NULL){
            return root->right;
        }
        else if(root->right == NULL){
            return root->left;
        }else{
            node* IS = inorderSuccessor(root->right);
            root->value = IS->value;
            root->right = del(root->right,IS->value);
        }
    }
    return root;
}

void print_In_Range(node*root, int x,int y){
    if(root ==NULL){
        return;
    }
    if(x<=root->value && root->value<=y){
        print_In_Range(root->left,x,y);
        cout<<root->value<<" ";
        print_In_Range(root->right,x,y);
    }
    else if(root->value<=x){
        print_In_Range(root->right,x,y);
    }else if(root->value>=y){
        print_In_Range(root->left,x,y);
    }
}

void root_to_leaf(node* root, vector<int> &v, vector<vector<int>> &all_v){
    if(root == NULL){
        return;
    }
    
    v.push_back(root->value);

    if(root->left == NULL && root->right == NULL){
        all_v.push_back(v);
    }else{
        root_to_leaf(root->left,v,all_v);
        root_to_leaf(root->right,v,all_v);
    }

    v.pop_back();

}
int main()
{
    // int arr[] = {1,2,3,4,-1,-1,5,-1,-1,6,-1,-1,7,-1,-1};
    int arr[] = {1,2,3,-1,-1,4,-1,-1,5,6,7,-1,-1,8,-1,-1,9,-1,-1};
    int arr3[] = {5,1,3,4,2,7};
    int arr2[] = {6,7,-1,-1,8,-1,-1};
    tree t1,t2;

    node* root = t1.built_tree(arr);
    // node* sub_root = t2.built_tree(arr2);
    // cout<<root->value<<endl;
    // print_tree(root);
    // cout<<endl;
    // print_level_order(root);
    // node* root = new node(arr3[0]);
   
    // for(int i=1;i<6;i++){
    //     binary_tree(arr3[i],root);
    // }
    // cout<<root->value<<endl;
    
    // print_level_order(root);
    // del(root,3);
    // print_level_order(root);
    // cout<<endl;
    // cout<<count_of_nodes(root)<<endl;
    // cout<<total_count(root)<<endl;
    // cout<<height(root)<<endl;
    // treeInfo* tr = diameter2(root);
    // cout<<tr->diameter<<endl;

    // int res = INT_MIN;
    // diameter(root, res);
    // cout<<res<<endl;
    
    // cout<<subtree(root,sub_root)<<endl;

    // cout<<find(root,11)<<endl;
    vector<int> v;
    vector<vector<int>> all_v;
    root_to_leaf(root,v,all_v);
    for(auto vec:all_v){
        for(auto val:vec){
            cout<<val<<" ";
        }
        cout<<endl;
    }

}