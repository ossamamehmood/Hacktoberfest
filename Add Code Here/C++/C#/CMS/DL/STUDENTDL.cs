using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using CMS.BL;

namespace CMS.DL
{
    class STUDENTDL
    {
        public static int count = 0;
        private static List<STUDENTBL> StudentList = new List<STUDENTBL>();

        public static List<STUDENTBL> StudentList1 { get => StudentList; set => StudentList = value; }

        public static void addStudentIntoList(STUDENTBL Temp)
        {
            StudentList1.Add(Temp);
        }

        public static bool containsPassword(string password)
        {
            foreach(STUDENTBL temp in StudentList1)
            {
                if(temp.Password1 == password)
                {
                    return true;
                }
            }
            return false;
        }
        public static bool containscnic(string cnic)
        {
            foreach (STUDENTBL temp in StudentList1)
            {
                if (temp.Cnic1 == cnic)
                {
                    return true;
                }
            }
            return false;
        }
        public static bool containsbankid(string bankid)
        {
            foreach (STUDENTBL temp in StudentList1)
            {
                if (temp.Bankid1 == bankid)
                {
                    return true;
                }
            }
            return false;
        }
        public static bool containsrollNumber(string rollnumber)
        {
            foreach (STUDENTBL temp in StudentList1)
            {
                if (temp.RollNumber1 == rollnumber)
                {
                    return true;
                }
            }
            return false;
        }

        public static void EditUserFromList(STUDENTBL previous,STUDENTBL updated)
        {
            foreach (STUDENTBL user in StudentList1)
            {
                if (user.Name1 == previous.Name1 && user.Password1 == previous.Password1)
                {
                    user.Name1 = updated.Name1;
                    user.Password1 = updated.Password1;
                    user.Matric_Marks1 = updated.Matric_Marks1;
                    user.RollNumber1 = updated.RollNumber1;
                    user.Section1 = updated.Section1;
                    user.Course1 = updated.Course1;
                    user.Cnic1 = updated.Cnic1;
                    user.Bankid1 = updated.Bankid1;
                    user.Father_Name1 = updated.Father_Name1;
                }
            }
        }

        public static void storeUserIntoFile(STUDENTBL User, string path)
        {
            StreamWriter file = new StreamWriter(path, true);
            file.WriteLine(User.Name1 + "," + User.Father_Name1 + "," + User.Course1 + "," + User.RollNumber1 + "," + User.Password1 + "," + User.Matric_Marks1 + "," + User.Cnic1 + "," + User.Bankid1 + "," + User.Section1);
            file.Flush();
            file.Close();
        }
            
        public static STUDENTBL isStudentValid(string name,string password)
        {
            foreach(STUDENTBL Student in StudentList1)
            {
                if(name == Student.Name1 && password == Student.Password1)
                {
                    return Student;
                }
            }
            return null;
        }

        public static bool isValid(string name,string password)
        {
            foreach (STUDENTBL Student in StudentList1)
            {
                if (name == Student.Name1 && password == Student.Password1)
                {
                    return true;
                }
            }

            return false;
        }

        public static void addStudentDataIntoFile(string Path)
        {
            StreamWriter file = new StreamWriter(Path);
            foreach (STUDENTBL storedUser in StudentList1)
            {

                file.WriteLine(storedUser.Name1 + "," + storedUser.Father_Name1 + "," + storedUser.Course1+","+storedUser.RollNumber1+","+storedUser.Password1+","+storedUser.Matric_Marks1+","+storedUser.Cnic1+","+storedUser.Bankid1+","+storedUser.Section1);
            }
            file.Flush();
            file.Close();
        }
        public static void readDataFromFile(string Path)
        {
            StreamReader SFile = new StreamReader(Path);
            string Record;
            if (File.Exists(Path))
            {
                while ((Record = SFile.ReadLine()) != null)
                {
                    string[] SplitRecord = Record.Split(',');
                    string Name = SplitRecord[0];
                    string Father_Name = SplitRecord[1];
                    string Course = SplitRecord[2];
                    string Roll_Number = SplitRecord[3];
                    string Password = SplitRecord[4];
                    float Marks = float.Parse(SplitRecord[5]);
                    string CNIC = SplitRecord[6];
                    string Bankid = SplitRecord[7];
                    string Section = SplitRecord[8];
                    STUDENTBL Student = new STUDENTBL(Name, Father_Name, Marks, Course, Roll_Number, CNIC, Section, Password, Bankid);
                    addStudentIntoList(Student);
                }
                SFile.Close();
            }
        }
        public static void deleteStudentFromList(STUDENTBL Temp)
        {
            for (int index = 0; index < StudentList1.Count; index++)
            {
                if (StudentList1[index].Name1 == Temp.Name1 && StudentList1[index].Password1 == Temp.Password1 && StudentList1[index].Cnic1 == Temp.Cnic1 && StudentList1[index].Course1==Temp.Course1 && StudentList1[index].Bankid1==Temp.Bankid1 && StudentList1[index].Father_Name1 == Temp.Father_Name1 && StudentList1[index].Matric_Marks1==Temp.Matric_Marks1&&StudentList1[index].Section1 == Temp.Section1)
                { 
                    StudentList1.RemoveAt(index);
                }
            }
        }
    }
}
