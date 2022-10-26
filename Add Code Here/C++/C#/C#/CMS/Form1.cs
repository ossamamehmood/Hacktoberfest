using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using CMS.Properties;
using CMS.BL;
using CMS.DL;

namespace CMS
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }        

        private void AdminButton_Click_1(object sender, EventArgs e)
        {
            /*this.Close();*/
            LoginForm Login = new LoginForm();
            Login.Show();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            STUDENTDL.readDataFromFile("Student.txt");
            ResultDL.readDataFromFile("Result.txt");
            TEACHERDL.readDataFromFile("Teacher.txt");
        }

        private void tableLayoutPanel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void UserButton_Click(object sender, EventArgs e)
        {
            LoginFormForUser Login = new LoginFormForUser();
            Login.Show();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            StudentLoginForm login = new StudentLoginForm();
            login.Show();
        }
    }
}
