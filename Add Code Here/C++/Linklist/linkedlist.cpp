#include<bits/stdc++.h>
using namespace std;
class node{
	public:
	int x;
	node* next;
};
class linkedlist{
	private:
	 node *first;
	 public :
	 	linkedlist(){ first =NULL;}
	 	linkedlist(int a[],int n);
	 	~linkedlist();
	 	void insert(int n,int p);
	 	void Delete(int n);
	 	void display();
};
linkedlist::linkedlist(int a[],int n){
	node *last,*t;
	first =new node;
	first->x=a[0];
	first->next=NULL;
	last=first;
	for(int i=1;i<=n;i++){
		t=new node;
t->x=a[i];
t->next=NULL;
last->next=t;
last=t;
	}
}
linkedlist::~linkedlist(){
	node *p=first;
	while(first){
		first=first->next;
		delete(p);
		p=first;
	}
}
void linkedlist::insert(int n,int l){
	node *p=first,*t;
	t=new node;
	t->x=n;
	if(l==0){
		t->next=first;
		first=t;
	}
	else {
	for(int i=1;i<=l-1;i++){
		p=p->next;
	}
	t->next=p->next;
	p->next=t;}
}
void linkedlist::Delete(int n){
	node *p=first,*q;
	if(first->x==n){
		p=first;
		first=first->next;
		delete(p);
	}
	else {
	while(p->x!=n){
		q=p;
	p=p->next;
	}
	if(p->next==first->next){
		q=p->next;
	}
	q->next=p->next;
	delete(p);}
}
void linkedlist::display(){
	node *p;
	p=first;
	while(p->next!=NULL){
		cout<<p->x<<" ";
		p=p->next;
	}
}
int main(){
	int a[]={1,2,3,4,5};
	linkedlist l(a,5);
	l.insert(4,3);
	l.insert(-1,0);
	l.display();
	cout<<endl;
	l.Delete(-1);
	l.Delete(4);
	l.display();


}
