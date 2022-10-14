using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using CMS.BL;
using CMS.DL;

namespace CMS
{
    public partial class AddStudentForm : Form
    {
        public string path = "Student.txt";
        public AddStudentForm()
        {
            InitializeComponent();
        }

        private void SubmitButton_Click(object sender, EventArgs e)
        {
            string Name = NameBox.Text;
            string fatherName = FatherBox.Text;
            string cnic = CnicBox.Text;
            string Password = PasswordBox.Text;
            string section = SectionBox.Text;
            float marks = 0;
            try
            {
                marks = float.Parse(MarksBox.Text);

            }
            catch(Exception)
            {
                MessageBox.Show("Please Input Numeric Number ");
            }
            string bankId = BankIdBox.Text;
            string course = CourseBox.Text;
            string rollNumber = RollNumberBox.Text;
            if (STUDENTDL.containsPassword(Password))
            {
                while (true)
                {
                    MessageBox.Show("Please Enter Correct Password");
                    Password = PasswordBox.Text;
                    if (STUDENTDL.containsPassword(Password) == false)
                    {
                        MessageBox.Show("Thanks For unique password");
                        break;
                    }
                }
            }
            if (STUDENTDL.containscnic(cnic))
            {
                while (true)
                {
                    MessageBox.Show("Please Enter Correct CNIC Unique");
                    cnic = CnicBox.Text;
                    if (STUDENTDL.containscnic(cnic) == false)
                    {
                        MessageBox.Show("Thanks For unique cnic");
                        break;
                    }
                }
            }
            if (STUDENTDL.containsbankid(bankId))
            {
                while (true)
                {
                    MessageBox.Show("Please Enter Correct bankid");
                    bankId = BankIdBox.Text;
                    if (STUDENTDL.containsbankid(bankId) == false)
                    {
                        MessageBox.Show("Thanks For unique bankid");
                        break;
                    }
                }
            }
            if (STUDENTDL.containsrollNumber(rollNumber))
            {
                while (true)
                {
                    MessageBox.Show("Please Enter Correct roll number");
                    bankId = BankIdBox.Text;
                    if (STUDENTDL.containsrollNumber(rollNumber) == false)
                    {
                        MessageBox.Show("Thanks For unique roll number");
                        break;
                    }
                }
            }

            STUDENTBL Student = new STUDENTBL(Name, fatherName, marks, course, rollNumber, cnic, section, Password, bankId);
            STUDENTDL.addStudentIntoList(Student);
            STUDENTDL.storeUserIntoFile(Student, path);
            MessageBox.Show("Data Save Successfully ");
            this.Close();
            AddStudentForm student = new AddStudentForm();
            student.Show();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            AdminMenu Menu = new AdminMenu();
            Menu.Show();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Form1 home = new Form1();
            this.Close();
            home.Show();
        }

        private void AddStudentForm_Load(object sender, EventArgs e)
        {

        }
    }
}
