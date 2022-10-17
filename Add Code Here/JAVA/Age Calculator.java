//-------- AI Programming ----------
//   Gregorian Age Calculator
// Join our Underground Coding Movement
//@freecodecs (c) Oct, 2019.


package runstudent;
import java.util.Scanner;

class Date{
    int date;
    int month;
    int year;
}

class Student {
    String name;
    Date dob;

    public Student(String n, Date db)
    {
        name = n;
        dob = db;
    }

    public void calAge()
    {
        int calcDate, calcMonth, calcYear;
        int feb=28;
        
        Date curD=new Date();
        Scanner usIn = new Scanner(System.in);
        
        System.out.print("Enter Current : \nDate - ");
        curD.date = usIn.nextInt();
        System.out.print("Month - ");
        curD.month = usIn.nextInt();
        System.out.print("Year - ");
        curD.year = usIn.nextInt();
        
        if (curD.year%4 == 0) { feb = 29; }
        else if(curD.year %4 != 0) { feb = 28; }
        
        int []months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        months[1] = feb;
        
        if(dob.date > curD.date){
            curD.month = curD.month -1;
            curD.date = curD.date + months[curD.month];
        }
        if(dob.month > curD.month){
            curD.year = curD.year - 1;
            curD.month = curD.month +12;
        }
        
        calcDate = curD.date - dob.date;
        calcMonth = curD.month - dob.month;
        calcYear = curD.year - dob.year;
        System.out.println("------------");
        System.out.println(name+"'s Age is: "+ calcYear + " year, "+ calcMonth + " month, "+ calcDate + " day");    }
}

public class Main {
   
    public static void main(String[] args) {
        Date DOB = new Date();
        Scanner userIn = new Scanner(System.in);
        
        System.out.println("-- Gregorian Calendar Age Calculator --");
        System.out.print("Enter Name: ");
        String userN = userIn.nextLine();
        
        System.out.print("Enter Date of Birth: \nDate - ");
        DOB.date = userIn.nextInt();
        System.out.print("Month - ");
        DOB.month = userIn.nextInt();
        System.out.print("Year - ");
        DOB.year = userIn.nextInt();
        
        Student Std = new Student(userN, DOB);
        System.out.println("------------------------------");
        Std.calAge();
        System.out.println("------------------------------");
    }

}
