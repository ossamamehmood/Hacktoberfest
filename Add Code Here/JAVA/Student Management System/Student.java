public class Student{
    
    private String name;
    private int rollNumber;
    private int age;
    private double grade;

    // constructors getters and setters

    public Student(String name, int rollNumber, int age, double grade){
        this.name = name;
        this.rollNumber = rollNumber;
        this.age = age;
        this.grade = grade;
    }
    // getters and setters

    public String getName() {
        return this.name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getRollNumber() {
        return this.rollNumber;
    }

    public void setRollNumber(int rollNumber) {
        this.rollNumber = rollNumber;
    }

    public int getAge() {
        return this.age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public double getGrade() {
        return this.grade;
    }

    public void setGrade(double grade) {
        this.grade = grade;
    }

    @Override
    public String toString() {
        return "{" +
            " name='" + getName() + "'" +
            ", rollNumber='" + getRollNumber() + "'" +
            ", age='" + getAge() + "'" +
            ", grade='" + getGrade() + "'" +
            "}";
    }


}