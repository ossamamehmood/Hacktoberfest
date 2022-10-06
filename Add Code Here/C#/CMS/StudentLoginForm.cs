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
    public partial class StudentLoginForm : Form
    {
        public StudentLoginForm()
        {
            InitializeComponent();
        }

        private void StudentLoginForm_Load(object sender, EventArgs e)
        {

        }

        private void loginbutton_Click(object sender, EventArgs e)
        {
            string name = NameBox.Text;
            string password = PasswordBox.Text;
            STUDENTBL student=STUDENTDL.isStudentValid(name, password);
            bool checker = STUDENTDL.isValid(name, password);
            if(checker == true)
            {
                StudentMenu menu = new StudentMenu(student);
                menu.Show();
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Close();
            Form1 mainpage = new Form1();
            mainpage.Show();
        }
    }
}
