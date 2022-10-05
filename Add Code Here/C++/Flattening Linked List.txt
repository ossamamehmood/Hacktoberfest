Node*Merge(Node*a, Node*b)
{
    if(a==NULL)return b;
    if(b==NULL)return a;
    
    Node* results;
    if(a->data<b->data)
    {
        results=a;
        results->bottom=a;
        results->next=Merge(a->bottom, b);
    }
    else{
        results=b;
        results->bottom=Merge(a, b->bottom);
    }
    results->next=NULL;
    return results;
}

Node*Flatten(Node *root)
{
    if(root==NULL || root->next==NULL)
    {
        return root;
        
    }
    else{
        return Merge(root, Flatten(root->next));
    }
}


  