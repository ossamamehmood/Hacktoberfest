void getLength(){
int count=0;
Node*temp=head;

while(temp!=NULL){
count++;
temp=temp->next;
}
cout<<"The length is "<<count<<endl;