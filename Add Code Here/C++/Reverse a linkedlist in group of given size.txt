Reversing a linked list in group of given size:
The main aim of this program is that what number we enter it will divide the whole linked list to that number and it will reverse it
Example:
if we enter 3 it will divide whole linked list into three three parts and it will revers is like below

key = 3;
1 2 3 4 5  6 7 8 9 
3 2 1 6 5 4 9 8 7


Node* reverse(Node* head, int k){

Node* next;
Node* prev= Null;
int c=0;

Node*current = head;
while(current!=Null && c<k){

next=current->next;
current->next=prev;
prev=current;
current=next;
c++;
}

if(next!=Null){
head->next = reverse(next, k);

return prev;

}