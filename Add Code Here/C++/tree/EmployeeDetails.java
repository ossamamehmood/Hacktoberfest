import java.util.*;  
abstract class EmployeeData
{
    String EmpName,Empid;
    EmployeeData()
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter EmpName & Empid");
        EmpName=sc.nextLine();
        Empid=sc.nextLine();
    }
}
interface EmployeeMethods
{
    void getDetails();
    void calculateSal();
    void display();
}
class Employee extends EmployeeData implements EmployeeMethods
{  double DA,HRA,PF,LIC,Grosspay,Netpay,Basicpay;
   String designation;
   Employee()
   {   
       int choice;
       Scanner sc = new Scanner(System.in);
       System.out.println("Enter choice\n1 for Manager\n2 for Scientist\n3 for Labour :");
       choice=sc.nextInt();
       switch(choice) {
        case 1 :
            designation= "Manager";
            break;
        case 2 :
            designation= "Scientist";
            break;
        case 3 :
            designation= "Labour";
            break;
        default :
            System.out.println("Invalid Input");
            
       }

   }
   public void getDetails()
   { Scanner sc = new Scanner(System.in);
     System.out.println("Enter basic pay :");
     Basicpay=sc.nextDouble();
     System.out.println("Enter DA % :");
     DA=sc.nextDouble();
     System.out.println("Enter HRA % :");
     HRA=sc.nextDouble();
     System.out.println("Enter PF % :");
     PF=sc.nextDouble();
     System.out.println("Enter LIC % :");
     LIC=sc.nextDouble();
   }
   public void calculateSal()
   {
    DA/=100;
    HRA/=100;
    PF/=100;
    LIC/=100;
    Grosspay=Basicpay+(DA*Basicpay)+(HRA*Basicpay);
    Netpay=Grosspay-((PF*Basicpay)+(LIC*Basicpay));
   } 
   
   public void display()
   { 
     System.out.println("Employee Name\t:\t"+EmpName);
     System.out.println("Employee Id\t:\t"+Empid);
     System.out.println("Designation\t:\t"+designation);
     System.out.println("Grosspay\t:\t"+Grosspay);
     System.out.println("Net pay\t\t:\t"+Netpay);
   }
   
}
class EmployeeDetails
{
    public static void main(String[] args)
    {
       Employee obj=new Employee();
       obj.getDetails();
       obj.calculateSal();
       obj.display(); 
    }
}
