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
    public partial class StudentMenu : Form
    {
        private static STUDENTBL updated;
        public StudentMenu(STUDENTBL student)
        {
            InitializeComponent();
            updated = student;
        }
        public StudentMenu()
        {

        }

        private void tableLayoutPanel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {
            ChangePasswordForm password = new ChangePasswordForm(updated);
            this.Close();
            password.Show();
        }

        private void label5_Click(object sender, EventArgs e)
        {
            StudentNotice notice = new StudentNotice();
            this.Close();
            notice.Show();
        }

        private void label4_Click(object sender, EventArgs e)
        {
            this.Close();
            ResultForm result = new ResultForm(updated);
            result.Show();
        }

        private void label6_Click(object sender, EventArgs e)
        {

        }

        private void StudentMenu_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Close();
            Form1 mainpage = new Form1();
            mainpage.Show();
        }
    }
}
