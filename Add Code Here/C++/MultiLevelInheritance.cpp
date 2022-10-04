#include <iostream>

using namespace std;

class Student{
	private:
	int roll;
	
	public:
		void getRoll(){
			cout<<"Enter Roll no"<<endl;
			cin>>roll;
		}
		
		void DisplayRoll(){
			cout<<"Roll is "<< roll<<endl;
		}
};

class Exam: public Student {
	protected:
		float sub1, sub2;
		
		public:
			void getMarks(){
				cout<<"Enter sub1 mark: "<<endl;
				cin>>sub1;
				cout<<"Enter sub2 mark: "<<endl;
				cin>>sub2;
				
			}
			
			void DisplayMarks(){
				cout<<"Sub1 mark: "<<sub1<<endl;
				cout<<"Sub2 mark: "<<sub2<<endl;
				
			}
};

class Result: public Exam{
	
private:
	float total;
	
	public:
	void CalculateTotal(){
		total = sub1 + sub2;
	}
	void DisplayResult(){
		cout<<"Total is: "<<total<<endl;
	}
	
};

int main(){
	
	Result r;
	r.getRoll();
	r.getMarks();
	r.CalculateTotal();
	
	cout<<"After Calculating result: "<<endl;;
	
	r.DisplayRoll();
	r.DisplayMarks();
	r.DisplayResult();
	
	return 0;
}