// username :SyedMIrtazaHyder
// name: Syed Muhammad Irtaza Hyder
// Institute: NUSTCEME


package stuff;
import java.util.Scanner;

public class Student {
	//attributes
	private String name;
	private int rollNo;
	private float [] marks;
	private float percentage;
	private int subjects;
	private int total;  // signifying total marks
	private static int totalStudents;
	
	//constructors
	public Student() { //default constructor
		name = "";
		rollNo = 0;
		subjects = 6; //default amount of subjects are 6
		total = 100;
		this.marks = new float[subjects];
		for (int i = 0; i < subjects; i++) {
			marks[i] = 0;
		}
		totalStudents++;
	}
	
	public Student(String name, int rollNo, int subjects, int total) { //parametric constructor
		this.name = name;
		this.rollNo = rollNo;
		this.subjects = subjects;
		this.marks = new float[subjects];
		System.out.println("\n");
		for (int i = 0; i < subjects; i++)
		{
			System.out.print("Enter marks: ");
			Scanner input = new Scanner(System.in);
			this.marks[i] = input.nextFloat();
			if (this.marks[i] > total) {
				System.out.println("Invalid Input!!!");
				i--;
				continue;
			}
		}
		totalStudents++;
		this.total = total;
	}
	
	//setters
	public void setName(String name) {
		this.name = name;
	}
	
	public void setSubjects(int subjects) {
		this.subjects = subjects;
	}
	
	public void setRollNo(int rollNo) {
		this.rollNo = rollNo;
	}
	
	public void setTotalMarks(int total) {
		this.total = total;
	}

	
	public void setMarks(float [] marks) { //using function overloading to allow adding marks manually or input based
		this.marks = marks;
	}
	
	public void setPercentage(float percentage) {
		this.percentage = percentage;
	}
	
	public void setTotalStudetns(int students) {
		totalStudents = students;
	}
	
	//getters
		public String getName() {
			return name;
		}
		
		public int getRollNo() {
			return rollNo;
		}
		
		public int getTotalMarks() {
			return total;
		}
		
		public int getSubjects() {
			return subjects;
		}
		
		public float [] getMarks() {
			return marks; //atm just returning whole array
		}
		
		public float getPercentage() {
			return percentage;
		}
		
		public static int getTotalStudents() {
			return totalStudents;
		}
		
		//member functions
		public float calculatePercentage(float num) {
			return (num / total) * 100;
		}
		
		public String calculateGrade(float percentage) { //local percentage var used within function
			if (percentage < 0) {
				return "Faulty inputs";
			}
			if (percentage > 90) {
				return "A";
			} else if (percentage > 80) {
				return "B+";
			} else if (percentage > 70) {
				return "B";
			} else if (percentage > 60) {
				return "C+";
			} else if (percentage > 50) {
				return "C";
			} else if (percentage > 40) {
				return "D+";
			} else if (percentage > 30) {
				return "D";
			} else if (percentage > 20){
				return "F";
			}
			else {
				return "XF";
			}
		}
}

