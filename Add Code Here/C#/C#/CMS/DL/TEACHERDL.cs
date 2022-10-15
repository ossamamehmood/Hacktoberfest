using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using CMS.BL;
namespace CMS.DL
{
    class TEACHERDL
    {
        private static List<TEACHERBL> TeacherList = new List<TEACHERBL>();
        public static string notice;

        internal static List<TEACHERBL> TeacherList1 { get => TeacherList; set => TeacherList = value; }

        public static void addTeacherIntoList(TEACHERBL Temp)
        {
            TeacherList1.Add(Temp);
        }
        public static void addNoticeIntoList(string Notice)
        {
            string Path = "Notice.txt";
            StreamWriter file = new StreamWriter(Path);
            file.WriteLine(Notice);
            file.Flush();
            file.Close();

        }
        public static string readNoticeFromFile()
        {
            string path = "Notice.txt";
            StreamReader TFile = new StreamReader(path);
            string Record;
            if (File.Exists(path))
            {
                while ((Record = TFile.ReadLine()) != null)
                {
                    notice = Record;
                }
                TFile.Close();
            }
            return notice;
        }

        public static bool isTeacher(string Name,string Password)
        {
            foreach(TEACHERBL Temp in TeacherList1)
            {
                if(Temp.Name1 == Name && Temp.Password1 == Password)
                {
                    return true;
                }
            }
            return false;
        }
        public static void addTeacherIntoFile(string Path)
        {
            StreamWriter file = new StreamWriter(Path);
            foreach (TEACHERBL Temp in TeacherList1)
            {

                file.WriteLine(Temp.Name1 + "," + Temp.Post1 + "," + Temp.Password1 + "," + Temp.Id1 + "," + Temp.Subject1 + "," + Temp.Phone_Number1 + "," + Temp.CNIC1 + "," + Temp.Salary1);
            }
            file.Flush();
            file.Close();
        }
        public static void deleteTeacherFromList(TEACHERBL Temp)
        {
            for (int index = 0; index < TeacherList1.Count; index++)
            {
                if (TeacherList1[index].Name1 == Temp.Name1 && TeacherList1[index].Password1 == Temp.Password1&& TeacherList1[index].Id1 == Temp.Id1)
                {
                    TeacherList1.RemoveAt(index);
                }
            }
        }
        public static void readDataFromFile(string Path)
        {
            StreamReader TFile = new StreamReader(Path);
            string Record;
            if (File.Exists(Path))
            {
                while ((Record = TFile.ReadLine()) != null)
                {
                    string[] SplitRecord = Record.Split(',');
                    string Name = SplitRecord[0];
                    string Post = SplitRecord[1];
                    string Password = SplitRecord[2];
                    string Id = SplitRecord[3];
                    string Subject = SplitRecord[4];
                    string Phone_Number = SplitRecord[5];
                    string CNIC = SplitRecord[6];
                    float Salary = float.Parse(SplitRecord[7]);
                    TEACHERBL Teacher = new TEACHERBL(Name, Post, Subject, CNIC, Phone_Number, Salary, Id, Password);
                    TEACHERDL.addTeacherIntoList(Teacher);
                }
                TFile.Close();
            }
        }
    }
}
