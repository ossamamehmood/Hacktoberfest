using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CMS.BL
{
    public class STUDENTBL
    {
        private string Name;
        private string Father_Name;
        private float Matric_Marks;
        private string Course;
        private string RollNumber;
        private string Cnic;
        private string Section;
        private string Password;
        private string Bankid;
        public STUDENTBL(string Name,string Father_Name,float Matric_Marks,string Course,string RollNumber,string Cnic,string Section,string Password,string Bankid)
        {
            this.Name1 = Name;
            this.Father_Name1 = Father_Name;
            this.Course1 = Course;
            this.Cnic1 = Cnic;
            this.Bankid1 = Bankid;
            this.Matric_Marks1 = Matric_Marks;
            this.RollNumber1 = RollNumber;
            this.Section1 = Section;
            this.Password1 = Password;
        }

        public string Name1 { get => Name; set => Name = value; }
        public string Father_Name1 { get => Father_Name; set => Father_Name = value; }
        public float Matric_Marks1 { get => Matric_Marks; set => Matric_Marks = value; }
        public string Course1 { get => Course; set => Course = value; }
        public string RollNumber1 { get => RollNumber; set => RollNumber = value; }
        public string Cnic1 { get => Cnic; set => Cnic = value; }
        public string Section1 { get => Section; set => Section = value; }
        public string Password1 { get => Password; set => Password = value; }
        public string Bankid1 { get => Bankid; set => Bankid = value; }
    }
}
