#include&lt;iostream&gt;
using namespace std;
 
struct bintree_node{
    bintree_node *left;
    bintree_node *right;
    int data;
} ;
class bst{
    bintree_node *root;
    public:
    bst(){
        root=NULL;
    }
    int isempty() {
        return(root==NULL);
    }
    void insert(int item);
    void displayBinTree();
    void printBinTree(bintree_node *);
     
};
void bst::insert(int item){
    bintree_node *p=new bintree_node;
    bintree_node *parent;
    p-&gt;data=item;
    p-&gt;left=NULL;
    p-&gt;right=NULL;
    parent=NULL;
    if(isempty())
        root=p;
    else{
        bintree_node *ptr;
        ptr=root;
        while(ptr!=NULL){
            parent=ptr;
            if(item&gt;ptr-&gt;data)        
                ptr=ptr-&gt;right;
            else
                ptr=ptr-&gt;left;
        }   
        if(item&lt;parent-&gt;data)
            parent-&gt;left=p;
        else
            parent-&gt;right=p;
    }
}
void bst::displayBinTree(){
    printBinTree(root);
}
void bst::printBinTree(bintree_node *ptr){
    if(ptr!=NULL){
        printBinTree(ptr-&gt;left);
        cout&lt;&lt;"  "&lt;&lt;ptr-&gt;data&lt;&lt;"     ";
        printBinTree(ptr-&gt;right);
    }
}
int main(){
    bst b;
    b.insert(20);
    b.insert(10);
    b.insert(5);
    b.insert(15);
    b.insert(40);
    b.insert(45);
    b.insert(30); 
     
    cout&lt;&lt;"Binary tree created: "&lt;&lt;endl;
    b.displayBinTree(); 
}
Output:

Binary tree created:

5       10       15       20       30       40       45
