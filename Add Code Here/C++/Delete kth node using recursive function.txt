Node*deletNode(Node* start, int k)
{
if(k<1)
return start;

if(start==NULL)
{
return NULL;
}

if(k==1)
{
Node*res=start->next;
delete(start);
return res;
}

start->next=deleteNode(start->next, k-1);
return start;