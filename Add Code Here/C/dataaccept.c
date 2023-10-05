#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a student record
struct Student {
    int roll_number;
    char name[50];
    float marks;
};

// Function to add a new student record
void addStudent(struct Student students[], int *num_students) {
    struct Student new_student;

    printf("Enter Roll Number: ");
    scanf("%d", &new_student.roll_number);
    printf("Enter Name: ");
    scanf("%s", new_student.name);
    printf("Enter Marks: ");
    scanf("%f", &new_student.marks);

    students[*num_students] = new_student;
    (*num_students)++;

    printf("Student added successfully.\n");
}

// Function to display all student records
void displayStudents(struct Student students[], int num_students) {
    printf("\nStudent Records:\n");
    for (int i = 0; i < num_students; i++) {
        printf("Roll Number: %d\n", students[i].roll_number);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("----------------------------\n");
    }
}

int main() {
    struct Student students[100];
    int num_students = 0;
    int choice;

    while (1) {
        printf("\nStudent Record Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &num_students);
                break;
            case 2:
                displayStudents(students, num_students);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
