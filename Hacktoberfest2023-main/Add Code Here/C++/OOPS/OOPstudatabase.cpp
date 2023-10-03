//STUDENT DATABASE MANAGEMENT
//Name : SARVESH PRAMOD BIWALKAR




#include<iostream>
#include<string>
using namespace std; 

class Student{
	private:
		int *roll_no, div, marks,mob;
		string name, dob, blood_grp, addr, lic;
	public:
		friend class teacher;
		Student(){		//default constructor
		 roll_no=new int;
		 name, dob, blood_grp, addr, lic= " ";
		 div, marks, mob= 0;
		}
		
	Student( Student &obj){
		this->roll_no=obj.roll_no; //copy constructor
		this->name=obj.name;
		this->div=obj.div;
		this->addr=obj.addr;
		this->marks=obj.marks;
		this->dob=obj.dob;
		this->blood_grp=obj.blood_grp;
		this->lic=obj.lic;
		this->mob=obj.mob;
	}
	
	~Student(){ //destructor
		delete roll_no;
	}
	
	inline static void header_info(){
	cout<<"\n.....Student information.....";
	cout<<"\n Roll No. \t Name \t\t Div \t Address \t Marks \t DOB \t Blood Group \t License No \t Mobile No";	
	}
	
	void getdata(){
		cout<<"\n Enter the roll number:";
		cin>>*roll_no;
		cout<<"\n Enter the name:";
		cin.ignore();
		getline(cin,name);
		cout<<"\n Enter the division:";
		cin>>div;
		cout<<"\n Enter the address:";
		cin>>addr;
		cout<<"\n Enter the marks:";
		cin>>marks;
		cout<<"\n Enter the date of birth:";
		cin>>dob;
		cout<<"\n Enter the blood group:";
		cin>>blood_grp;
		cout<<"\n Enter the license number:";
		cin>>lic;
		cout<<"\n Enter the Mobile number:";
		cin>>mob;
	}
	
	void display(){
	cout<<"\n"<<*roll_no<<"\t"<<name<<"\t\t"<<div<<"\t"<<addr<<"\t"<<marks<<"\t"<<dob<<"\t"<<blood_grp<<"\t"<<lic<<"\t"<<mob;	
	}
};

class teacher{
	int id;
	public:
		teacher(){
			id=0;
		}
		void display_t(Student &obj1, int t_d){
			try{
				if (obj1.div==t_d)
				obj1.display();
				else
				throw(obj1.div);
			}
			catch (int x){
				cout<<"\n Teacher and student division cannot match.";
			}
		}
};

int main(){
	Student s[5];
	teacher t;
	int ch,count=0;
	do{
		cout<<"\n Student Information";
		cout<<"\n Menu";
		cout<<"\n 1. Add Student Information";
		cout<<"\n 2. Display Student information";
		cout<<"\n 3. Copy constructor";
		cout<<"\n 4. Division wise information";
		cout<<"\n 5. Exit";
		cout<<"\n Enter your choice:";
		cin>>ch;
	switch(ch){
		case 1 :
			s[count].getdata();
			count++;
			break;
		case 2 :
			Student::header_info();
			for(int i=0;i<count;i++){
				s[i].display();
			}
			break;
		case 3:{
			cout<<"\n This is copy constructor";
			Student obj;
			obj.getdata();
			Student s2(obj);
			s2.display();
			}
			break;
		case 4:
			int t_div;
			cout<<"\n Enter the division :";
			cin>>t_div;
			for (int i=0;i<count;i++){
				t.display_t(s[i],t_div);
			}
			break;
		case 5:
			exit(0);
		}
	}
	while (ch!=5);
	return 0;
}
