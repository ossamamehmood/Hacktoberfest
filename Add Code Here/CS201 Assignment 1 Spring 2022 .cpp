#include <iostream>
using namespace std;

int main()
{
	int numberOfCourses = 6;
	int studentId = 2;
	int add = 0;
	int i = 1;

	cout << "\nMy Name is Muhammad Saim Raza" << endl;
	cout << "MY VU id is BC210419616" << endl;
	cout << "\nCourse List in current semester" << endl;

	cout << "1. CS201 - Introduction to Programing" << endl;
	cout << "2. CS201P - Introduction to Programing (Practical)" << endl;
	cout << "3. ENG201 - Business and Technical English Writing" << endl;
	cout << "4. MGT301 - Principles of Marketing" << endl;
	cout << "5. MTH101 - Calculus And Analytical Geometry" << endl;
	cout << "6. PHY101 - Physics" << endl;

	cout << "\nTotal Number of Courses = " << numberOfCourses << endl;
	cout << "First digit of VU ID = " << studentId << endl;

	add = studentId + numberOfCourses;

	cout << "Sum of first digit of VUID and total courses  = " << add << endl;
	cout << "\n";

	while (i <= add)
	{
		cout << i << ": Welcome to CS201 Introduction to Programming " << endl;
		i++;
	}
}