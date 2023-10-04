import java.util.ArrayList;

public class StudentManagementSystem {
    private ArrayList<Student> students;

    public StudentManagementSystem(){
        this.students = new ArrayList<>();
    }
    // we need to define a add student method

    /**
     * function name - Add Student
     * @param student
     *  -- add the student in the list---
     */
    public void addStudent(Student student){
         students.add(student);
    }

    /**
     * function name - remove student
     * @param rollNumber
     * --remove the student in the list ---
     *  if the roll number is in the list it was successfully removed
     *
     */
    public void removeStudent(int rollNumber){
        for(int i=0;  i<students.size(); i++){
            if(students.get(i).getRollNumber() == rollNumber){
                students.remove(i);
                System.out.println("student Roll Number " + rollNumber + " was successfully removed.");
            }
        }
        System.out.println("Student Roll number " +  rollNumber + " was not found in the list ");
    }
    /**
     * function name searchStudent 
     * @param rollNumber
     * @return student
     * if the roll number matches it will return the student name
     */

    public Student searchStudent(int rollNumber){
        for(Student student : students){
            if(student.getRollNumber() == rollNumber){
                return student;
            }
        }
        return null;
    }
    /**
     * function name student
     * @param student
     * it will return the individual student
     */
    
    public void displayStudents(Student student){
        System.out.println("Roll Number: " + student.getRollNumber());
        System.out.println("Name: " + student.getName());
        System.out.println("Age: " + student.getAge());
        System.out.println("Grade: " + student.getGrade());      
    }
    /**
     * function name displayAllStudents 
     * helps to display all the students 
     */
    public void displayAllStudents(){
        for(Student student :  students){
            System.out.println(student);
        }
    }
}
