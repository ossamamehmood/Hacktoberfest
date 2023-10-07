//C++ program that demonstrates object-oriented programming (OOP) concepts such as classes, objects, constructors, and member functions
#include <iostream>
#include <string>

// Class definition
class Student {
private:
    std::string name;
    int age;
    double gpa;

public:
    // Constructor
    Student(std::string n, int a, double g) {
        name = n;
        age = a;
        gpa = g;
    }

    // Member function to display student information
    void displayInfo() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "GPA: " << gpa << std::endl;
    }

    // Getter for GPA
    double getGPA() {
        return gpa;
    }

    // Setter for GPA
    void setGPA(double newGPA) {
        if (newGPA >= 0.0 && newGPA <= 4.0) {
            gpa = newGPA;
        } else {
            std::cout << "Invalid GPA. GPA should be between 0.0 and 4.0." << std::endl;
        }
    }
};

int main() {
    // Create objects of the Student class
    Student student1("Alice", 20, 3.8);
    Student student2("Bob", 22, 3.5);

    // Display student information
    std::cout << "Student 1 Information:" << std::endl;
    student1.displayInfo();
    std::cout << std::endl;

    std::cout << "Student 2 Information:" << std::endl;
    student2.displayInfo();
    std::cout << std::endl;

    // Update student2's GPA
    std::cout << "Updating Student 2's GPA..." << std::endl;
    student2.setGPA(3.9);

    // Display updated student2 information
    std::cout << "Updated Student 2 Information:" << std::endl;
    student2.displayInfo();

    return 0;
}
