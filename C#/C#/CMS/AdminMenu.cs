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
    public partial class AdminMenu : Form
    {
        public AdminMenu()
        {
            InitializeComponent();
        }

        

        private void tableLayoutPanel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void radioButton3_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {
            AddStudentForm StudentForm = new AddStudentForm();
            this.Hide();
            StudentForm.Show();
        }

        private void tableLayoutPanel5_Paint(object sender, PaintEventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {
            AddTeacherForm teacherForm = new AddTeacherForm();
            this.Hide();
            teacherForm.Show();
        }

        private void label4_Click(object sender, EventArgs e)
        {
            RemoveStudentForm Student = new RemoveStudentForm();
            this.Hide();
            Student.Show();
        }

        private void removeTeacher_Click(object sender, EventArgs e)
        {
            RemoveTeacherForm teacher = new RemoveTeacherForm();
            this.Close();
            teacher.Show();
        }


        private void label6_Click_1(object sender, EventArgs e)
        {
            ViewDataForm dataFrom = new ViewDataForm();
            this.Hide();
            dataFrom.Show();
        }

        private void label7_Click(object sender, EventArgs e)
        {
            AddResultForm Result = new AddResultForm();
            this.Hide();
            Result.Show();
        }

        private void label8_Click(object sender, EventArgs e)
        {
            ShowResultForm Result = new ShowResultForm();
            this.Hide();
            Result.Show();
        }

        private void label9_Click(object sender, EventArgs e)
        {
            AttendanceForm temp = new AttendanceForm();
            this.Hide();
            temp.Show();
        }

        private void label10_Click(object sender, EventArgs e)
        {
            Form1 menu = new Form1();
            this.Hide();
            menu.Show();
        }
    }
}
