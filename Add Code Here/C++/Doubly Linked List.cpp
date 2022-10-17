#include<iostream>
using namespace std;
struct Student
{
	int age;
	string name;
	string id;
	char sex;
	Student *next;
	Student *prev;
	Student(int a,string na,string i,char s, Student *n=NULL, Student *p=NULL)
	{name =na;  age=a; id=i; sex=s; next =n; prev = p;}
};

// Create new node with structure Student
void create(Student * &t, string na, string i, char s, int a){
	t= new Student(a, na, i, s);
}

// Register new Student
void insert(Student *&h, Student *&t)
{
	Student *cur =h;
	if(h == NULL)
		h=t;
	else {
		while(cur->next)
		{
			cur = cur->next;		
		}
		cur->next=t;
		t->prev = cur;
	}
}

// Register new student after a specific record
void insertAfter(Student *&h, Student *&t, string p)
{
	Student *cur =h;
	while(cur)
	{
		if(cur->id == p)
		{
			//t->prev=cur;
			t->next = cur->next;
			cur->next = t;
			t->prev = cur;
			//cout<<cur->next->name<<endl;
		}
		cur = cur->next;		
	}
}

//Display all students from last to end order
void reverse(Student *&h){
	Student *tail=h;
	
	while(tail->next !=NULL)
		tail = tail->next;
	
	cout<<"ID\tName\tAge\tSex\n";
	cout<<"----------------------------\n";
	
	do {
		cout<<tail->id<<"\t"<<tail->name<<"\t"<<tail->age<<"\t"<<tail->sex<<"\n";
		tail=tail->prev;
	}while(tail->prev != NULL);
		cout<<tail->id<<"\t"<<tail->name<<"\t"<<tail->age<<"\t"<<tail->sex<<"\n";
}

//Display all students record
void display(Student *&h){
	Student *cur=h;
	cout<<"ID\tName\tAge\tSex\n";
	cout<<"----------------------------\n";
	
	while(cur){
		cout<<cur->id<<"\t"<<cur->name<<"\t"<<cur->age<<"\t"<<cur->sex<<"\n";
		cur=cur->next;
	}
}

//Display a specific student record
void displaySingle(Student *&h, string i){
	Student *cur=h;
	
	while(cur){
		if(cur->id == i){
				cout<<"ID: "<<cur->id<<"\n";
				cout<<"Name: "<<cur->name<<"\n";
				cout<<"Age: "<<cur->age<<"\n";
				cout<<"Sex: "<<cur->sex<<"\n";
			}
		cur=cur->next;
	}
	
}

//Delete a specific student record
void remove(Student *&h, string i)
{
	Student  *cur = h;
	if(cur->id == i)
	{
		h = cur->next;
		h->prev = NULL;
		delete cur;	
	}
	else{
		while(cur){
			if(cur->id==i)
			{
				if(cur->next == NULL)
				{
					cur->prev->next = NULL;
				}
				else{
					cur->prev->next = cur->next;
					cur->next->prev = cur->prev;
				}
				
				delete cur;
			}
			cur=cur->next;
			
		}
	}
}

int main(){
	//int data;
	Student *temp, *head = NULL;
	
	//student data variable declaration	
	int choice, ins_age;
	string ins_id, ins_name, id_after;
	char ins_sex;
	
	cout<<"----- Menu -----\n";
	cout<<endl<<"1. Add a Student : ";
	cout<<endl<<"2. Add After a Specific Student : ";
	cout<<endl<<"3. Delete a Student : ";
	cout<<endl<<"4. Display All Students : ";
	cout<<endl<<"5. Display Single Student : ";
	cout<<endl<<"6. Display All Students Reverse : ";
	cout<<endl<<"7. Exit : ";
	cout<<"\n-----------------\n";
	
	do{
		cout<<"\nEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				{
				cout<<endl<<"Enter student name: ";
				getchar();
				getline(cin,ins_name);
				cout<<endl<<"Enter student id: ";
				cin>>ins_id;
				cout<<endl<<"Enter student sex: ";
				cin>>ins_sex;
				cout<<endl<<"Enter student age: ";
				cin>>ins_age;
				
				create(temp, ins_name, ins_id, ins_sex, ins_age);
				insert(head, temp);
				break;
				}
			case 2:
				{
				cout<<endl<<"After which student you want to add ? \n Enter Student ID : ";
				getchar();
				getline(cin, id_after);
				cout<<endl<<"Register your student";
				cout<<endl<<"Enter student name: ";
				cin>>ins_name;
				cout<<"\nEnter student id: ";
				cin>>ins_id;
				cout<<"\nEnter student sex: ";
				cin>>ins_sex;
				cout<<"\nEnter student age: ";
				cin>>ins_age;
				
				create(temp, ins_name, ins_id, ins_sex, ins_age);				
				insertAfter(head, temp, id_after);
				break;
				}
			case 3:
				{
				cout<<endl<<"Enter student id. to be deleted: ";
				cin>>ins_id;
				remove(head, ins_id);
				break;
				}
			case 4:
				display(head);
				break;
			case 5:
				{
				cout<<endl<<"Enter a student id: ";
				getchar();
				getline(cin, ins_id);
				displaySingle(head, ins_id);
				break;	
				}
			case 6:
				{
				reverse(head);
				break;
				}
			case 7:
				{
				exit(1);
				break;
				}
			default:
				cout<<"Wrong choice! ";
				break;
				
		}
	} while(choice != 7);
	
	return 0;
}
