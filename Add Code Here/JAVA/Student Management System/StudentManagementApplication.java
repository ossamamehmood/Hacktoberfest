import java.util.Scanner;

public class StudentManagementApplication {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        StudentManagementSystem student = new StudentManagementSystem();

        while(true){
            System.out.println(" Student Management System");
            System.out.println("1. Add a Student");
            System.out.println("2 Remove a Student");
            System.out.println("3 Serach a Student");
            System.out.println("4 Display a Student");
            System.out.println("5 Exit the Student");

            System.out.print("Enter the choice: ");
            int choice = sc.nextInt();

            switch(choice){
                case 1:
                  System.out.print("Enter the student roll Number: ");
                  int rollNumber = sc.nextInt();

                  System.out.print("Enter the student name: ");
                  String studentName = sc.next();

                  System.out.print("Enter the student age: ");
                  int studentAge = sc.nextInt();

                  System.out.print("Enter the grade: ");
                  double grade = sc.nextDouble();

                  Student newStudent = new Student(studentName, rollNumber, studentAge, grade);
                  student.addStudent(newStudent);
                  break;

                case 2:
                   System.out.print("Enter the roll number to remove: ");
                   int rollNumberToDelete = sc.nextInt();
                   student.removeStudent(rollNumberToDelete);
                   break;
                case 3:
                   System.out.print("Enter the roll number to search the student: ");
                   int rollNumberToSearch = sc.nextInt();
                   
                   Student searchStudent = student.searchStudent(rollNumberToSearch);

                   if(searchStudent!=null){
                      System.out.println("Student Found " + searchStudent);
                   }
                   else{
                     System.out.println("Student not in list ");
                   }
                   break;
                case 4:
                      student.displayAllStudents();
                      break;
                case 5:
                    System.out.println("Exit");
                    System.out.println("Thank you");
                    sc.close();
                    System.exit(0);
                    break;           
                default:
                   System.out.println("Invalid choice");    
            }
                

                
        }
    }
    
}
