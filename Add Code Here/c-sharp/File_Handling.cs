using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
struct student
{
    public string name;
    public int age;
    public string dept;
    public float sem_percent;
};
public class program
{
    static void write(string name,int age,string dept,float percent,int i)
    {
            FileStream fs = new FileStream("file.txt", FileMode.Append, FileAccess.Write);
            StreamWriter sw = new StreamWriter(fs);
            sw.WriteLine("name of the student-{0}:{1}", i + 1, name);
            sw.WriteLine("age of the student-{0}:{1}", i + 1, age);
            sw.WriteLine("dept of the student-{0}:{1}", i + 1, dept);
            sw.WriteLine("semester percentage of the student-{0}:{1}", i + 1, percent);
            sw.WriteLine();
            sw.Close();
            fs.Close();
    }
    public static void Main(string[] args)
    {
        FileStream fs = new FileStream("file.txt", FileMode.Create, FileAccess.Write);
        fs.Close();
        Console.Write("Enter num of students:");
        int n = Convert.ToInt32(Console.ReadLine());
        student[] s = new student[n];
        for (int i = 0; i < n; i++)
        {
            Console.Write("Enter the name of the student-{0}:", i + 1);
            s[i].name = Console.ReadLine();
            Console.Write("Enter the age of the student-{0}:", i + 1);
            s[i].age = Convert.ToInt32(Console.ReadLine());
            Console.Write("Enter the dept of the student-{0}:", i + 1);
            s[i].dept = Console.ReadLine();
            Console.Write("Enter the semester percentage of the student-{0}:", i + 1);
            s[i].sem_percent = float.Parse(Console.ReadLine());
            write(s[i].name, s[i].age, s[i].dept, s[i].sem_percent,i);
            Console.WriteLine();
        }
        Console.ReadKey();
    }
}