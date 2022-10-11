using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using CMS.DL;
using CMS.BL;

namespace CMS
{
    public partial class ChangePasswordForm : Form
    {
        private static STUDENTBL updated;
        public ChangePasswordForm(STUDENTBL student)
        {
            InitializeComponent();
            updated = student;
        }

        private void PasswordGV_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            
        }


        private void ChangePasswordForm_Load(object sender, EventArgs e)
        {
            nameBox.Text = updated.Name1;
            fatherBoxBox1.Text = updated.Father_Name1;
            passwordBox.Text = updated.Password1;
            rollnumberBox.Text = updated.RollNumber1;
            MarksBox.Text = "" + updated.Matric_Marks1;
            courseBox.Text = updated.Course1;
        }

        private void button2_Click(object sender, EventArgs e)
        {

        }


        private void button1_Click(object sender, EventArgs e)
        {
            Form1 homePage = new Form1();
            this.Close();
            homePage.Show();
        }

        private void savebutton_Click(object sender, EventArgs e)
        {

        }

        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void label9_Click(object sender, EventArgs e)
        {
            STUDENTBL newStudent = new STUDENTBL(updated.Name1, updated.Father_Name1, updated.Matric_Marks1, updated.Course1, updated.RollNumber1, updated.Cnic1, updated.Section1, passwordBox.Text, updated.Bankid1);
            STUDENTDL.EditUserFromList(updated, newStudent);
            MessageBox.Show("Password Has Been Updated ");
            this.Close();
            StudentMenu menu = new StudentMenu();
            menu.Show();

        }
    }
}
