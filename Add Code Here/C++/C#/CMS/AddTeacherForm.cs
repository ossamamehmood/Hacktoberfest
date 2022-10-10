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
    public partial class AddTeacherForm : Form
    {
        public string path = "Teacher.txt";
        public AddTeacherForm()
        {
            InitializeComponent();
        }

        private void SaveButton_Click(object sender, EventArgs e)
        {
            string name = NameBox.Text;
            string passWord = PasswordBox.Text;
            string phoneNumber = NumberBox.Text;
            string cnic = CnicBox.Text;
            string id = IdBox.Text;
            float salary = 0;
            try
            {
                salary = float.Parse(SalaryBox.Text);
            }
            catch(Exception)
            {
                MessageBox.Show("Please Enter Correct Value in Salary Box");
            }
            string subject = SubjectBox.Text;
            string post = PostBox.Text;
            TEACHERBL Teacher = new TEACHERBL(name, post, subject, cnic, phoneNumber, salary, id, passWord);
            TEACHERDL.addTeacherIntoList(Teacher);
            TEACHERDL.addTeacherIntoFile(path);
            MessageBox.Show("Data Saved");
            this.Close();
            AddTeacherForm Temp = new AddTeacherForm();
            Temp.Show();
        }

        private void BackButton_Click(object sender, EventArgs e)
        {
            this.Close();
            AdminMenu Menu = new AdminMenu();
            Menu.Show();
        }

        private void HomeButton_Click(object sender, EventArgs e)
        {
            AdminMenu Menu = new AdminMenu();
            this.Close();
            Menu.Show();
        }

        private void NameBox_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
