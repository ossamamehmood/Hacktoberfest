using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CMS
{
    public partial class ViewDataForm : Form
    {
        public ViewDataForm()
        {
            InitializeComponent();
        }

        private void ViewDataForm_Load(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {
            ViewAllStudent student = new ViewAllStudent();
            this.Close();
            student.Show();
        }

        private void MenuLabel_Click(object sender, EventArgs e)
        {
            AdminMenu Menu = new AdminMenu();
            this.Close();
            Menu.Show();
        }

        private void label3_Click(object sender, EventArgs e)
        {
            ViewAllTeachers teacher = new ViewAllTeachers();
            this.Close();
            teacher.Show();
        }
    }
}
