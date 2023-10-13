#include <iostream>
using namespace std;
class Student{
    int RollNo, PhyMarks, ChemMarks, MathMarks;
    string Name;
    public:
    Student(int RollNo, string Name, int PhyMarks, int MathMarks, int ChemMarks){
        this->RollNo = RollNo;
        this->Name = Name;
        this->PhyMarks = PhyMarks;
        this->MathMarks = MathMarks;
        this->ChemMarks = ChemMarks;
    }
    int TotalMarks(){
        return PhyMarks + ChemMarks + MathMarks;
    }
    char Grade();
};
char Student::Grade(){
    int Average = TotalMarks()/3;
    if(Average>=60){
        return 'A';
    }
    else if(Average >= 40 && Average < 60){
        return 'B';
    }
    else
    {
        return 'C';
    }
    
}
int main(){
    int RollNo, PhyMarks, ChemMarks, MathMarks;
    string Name;
    cout << "Enter the Roll NO.: ";
    cin>> RollNo;
    cout<< "Enter the Name of student: ";
    cin >> Name;
    cout<< "Enter marks in Physics: ";
    cin >> PhyMarks;
    cout<< "Enter marks in Maths: ";
    cin >> MathMarks;
    cout<< "Enter marks in Chemistry: ";
    cin >> ChemMarks;
    Student Swaraj(RollNo, Name, PhyMarks, MathMarks, ChemMarks);
    cout << "The total marks obtained by " << Name << " is " << Swaraj.TotalMarks()<< endl;
    cout << "The Greade obtained by " << Name << " is " << Swaraj.Grade()<< endl;
    return 0;
}