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
    public partial class LoginFormForUser : Form
    {
        public LoginFormForUser()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string name = NameBox.Text;
            string password = PasswordBox.Text;
            bool Checker = TEACHERDL.isTeacher(name, password);
            if(Checker == true)
            {
                TeacherMenu menu = new TeacherMenu();
                this.Close();
                menu.Show();
            }
        }
    }
}
