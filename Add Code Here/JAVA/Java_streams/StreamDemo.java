import java.util.List;
import java.util.ArrayList;
import java.util.stream.Collector;
import java.util.stream.Collectors;

public class StreamDemo {
    
    public static void main(String[] args) {
        StreamDemo streamDemo = new StreamDemo();
        streamDemo.demo();    
    }

    private void demo(){
       List<Employee> list = employeeListPersisted();

       // All employees
       System.out.println("All employee: ");
       for (Employee employee : list) {
           System.out.println(employee.employeeName + " : " + employee.department);
       }

       //filter employees only in IT department, we can use streams
       List<Employee> employeeFilterItDepartment = list.stream()
               .filter(i -> i.department.equals("IT"))
               .collect(Collectors.toList());

       //filtered employees
       System.out.println("\n\nFiltered employee: ");
       for (Employee employee : employeeFilterItDepartment) {
           System.out.println(employee.employeeName + " : " + employee.department);
       }
   }

    private List<Employee> employeeListPersisted(){
        List<Employee> employeeList = new ArrayList<Employee>();

        employeeList.add(new Employee(1, "Kavindu", 300000, "IT"));
        employeeList.add(new Employee(2, "Niluka", 50000, "Finance"));
        employeeList.add(new Employee(3, "Kavindi", 100000, "HR"));
        employeeList.add(new Employee(4, "Eranda", 100000, "IT"));
        employeeList.add(new Employee(5, "Supun", 150000, "IT"));
        employeeList.add(new Employee(6, "Kalana", 200000, "HR"));

        return employeeList;

    }
}
