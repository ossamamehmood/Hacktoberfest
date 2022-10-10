using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using CMS.BL;

namespace CMS.DL
{
    class ResultDL
    {
        private static List<ResultBL> result = new List<ResultBL>();

        internal static List<ResultBL> Result { get => result; set => result = value; }

        public static ResultBL checkResult(STUDENTBL student)
        {
            foreach(ResultBL temp in Result)
            {
                if(temp.Name == student.Name1 && temp.Password == student.Password1)
                {
                    return temp;
                }
            }
            return null;
        }
        public static void changePassword(STUDENTBL updated)
        {
            foreach (ResultBL user in Result)
            {
                if (user.Name == updated.Name1 && user.Password == updated.Password1)
                {
                    user.Name = updated.Name1;
                    user.Password = updated.Password1;
                    user.Urdu = user.Urdu;
                    user.Math = user.Math;
                    user.English = user.English;
                    user.Computer = user.Computer;
                    user.Password = user.Password;
                }
            }

        }
        public static bool isvalid(STUDENTBL student)
        {
            foreach (ResultBL temp in Result)
            {
                if (temp.Name == student.Name1 && temp.Password == student.Password1)
                {
                    return true;
                }
            }
            return false;
        }
        public static void addResultIntoList(ResultBL Temp)
        {
            Result.Add(Temp);
        }
        public static void addResultIntoFile(ResultBL Temp,string path)
        {
            StreamWriter file = new StreamWriter(path, true);
            file.WriteLine(Temp.Name + "," + Temp.Urdu + "," + Temp.Math + "," + Temp.English + "," + Temp.Computer + "," + Temp.Physics+","+Temp.Password);
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
                    float urdu = float.Parse(SplitRecord[1]);
                    float math = float.Parse(SplitRecord[2]);
                    float english = float.Parse(SplitRecord[3]);
                    float computer = float.Parse(SplitRecord[4]);
                    float physics = float.Parse(SplitRecord[5]);
                    string password = SplitRecord[6];
                    ResultBL Temp = new ResultBL(Name, urdu, math, english, computer, physics,password);
                    addResultIntoList(Temp);
                }
                SFile.Close();
            }
        }
    }
}
