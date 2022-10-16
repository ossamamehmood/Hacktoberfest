using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CMS.BL
{
    class TEACHERBL
    {
        private string Name;
        private string Post;
        private string Subject;
        private string CNIC;
        private string Phone_Number;
        private float Salary;
        private string Id;
        private string Password;
        public TEACHERBL(string Name,string Post,string Subject,string CNIC,string Phone_Number,float Salary,string Id,string Password)
        {
            this.Name1 = Name;
            this.Password1 = Password;
            this.Phone_Number1 = Phone_Number;
            this.Post1 = Post;
            this.Salary1 = Salary;
            this.Subject1 = Subject;
            this.CNIC1 = CNIC;
            this.Id1 = Id;
        }

        public string Name1 { get => Name; set => Name = value; }
        public string Post1 { get => Post; set => Post = value; }
        public string Subject1 { get => Subject; set => Subject = value; }
        public string CNIC1 { get => CNIC; set => CNIC = value; }
        public string Phone_Number1 { get => Phone_Number; set => Phone_Number = value; }
        public float Salary1 { get => Salary; set => Salary = value; }
        public string Id1 { get => Id; set => Id = value; }
        public string Password1 { get => Password; set => Password = value; }
    }
}
