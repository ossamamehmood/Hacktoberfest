#include <iostream>
using namespace std;
class Node
{
public:
int data;
int power;
Node *next;
Node()
{ this->data = data;
next = NULL; }
int getdata()
{ return data; }
void setdata(int num)
{
data = num;
}
Node* getnext()
{
return next;
}
void setnext(Node* nextnum)
{
next = nextnum; }
int getpow()
{
return power;
}
void setpow(int pow)
{
power = pow;
}
};
class list
{
public:
Node *head;
Node *tail;

Node *prenode;
Node *current;
int maxpow, recent, count;
list()
{
sethead(NULL);
settail(NULL);
setcurrent(NULL);
this->recent = recent;
this->maxpow = maxpow;
count = 0;
}
Node* getcurrent()
{
return current;
}
void setcurrent(Node* ptr)
{
current = ptr;
}
void sethead(Node* hd)
{
head = hd;
}
void settail(Node* tt)
{
tail = tt;
}
int getmaxpower()
{
return maxpow;
}
int getlength()
{
return count;
}
void movenextcurrent(){
current = current->next;
}
void add(int num, int pow)
{
Node *temp = new Node;
temp->data = num;
temp->power = pow;
temp->next = NULL;
if (head == NULL)
{
sethead(temp);

settail(temp);
setcurrent(temp);
maxpow = pow;
}
else if(maxpow>pow && recent>pow)
{
tail->next = temp;
settail(temp);
setcurrent(temp);
}
else if(maxpow>pow && recent<pow)
{
setcurrent(head);
while (current != NULL)
{
if (current->data = recent)
{
break;
}
prenode = current;
movenextcurrent();
}
temp->next = current;
prenode->next = temp;
setcurrent(temp);
}
else
{
temp->next = head;
sethead(temp);
setcurrent(temp);
maxpow = pow;
}
recent=pow;
++count;
}
void display()
{
setcurrent(head);
cout << "--- ";
while (current->next != NULL)
{
cout<<current->data;
cout<<"x^";
cout<<current->power;
cout<<" + ";
movenextcurrent();
}

cout<<current->data;
cout<<"x^";
cout<<current->power;
cout << " = 0 --- ";
}
};
int main()
{
list l1;
char input;
while (true)
{
cout << "Enter A to insert new Polynomial" << endl;
cout << "Enter D to View complete Equation" << endl;
cout << "Enter F to get length of Equation" << endl;
cout << "Enter E to Exit : ";
cin >> input;
if (input == 'A' || input == 'a')
{
int coff, expo;
cout << "Enter coefficient : ";
cin >> coff;
cout << "Enter exponent : ";
cin >> expo;
l1.add(coff, expo);
}
else if (input == 'D' || input == 'd')
{
l1.display();
cout << endl;
}
else if (input == 'F' || input == 'f')
{
cout << endl
<< "Length : " << l1.getlength()<<endl;
}
else if (input == 'E' || input == 'e')
{
break;
}
else{
cout << "INVALID INPUT" << endl;
}
}
return 0;
}
