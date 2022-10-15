using CMS.BL;
using System;
using System.Windows.Forms;

namespace CMS
{
    public partial class LoginForm : Form
    {
        public LoginForm()
        {
            InitializeComponent();
        }

        private void NameBox_TextChanged(object sender, EventArgs e)
        {
            

        }

        private void LoginButton_Click(object sender, EventArgs e)
        {
            string name = NameBox.Text;
            string password = PasswordBox.Text;
            ADMINBL Admin = new ADMINBL(name, password);
            if (Admin.isAdmin())
            {
                AdminMenu Menu = new AdminMenu();
                this.Close();
                Menu.Show();
            }
        }

        private void tableLayoutPanel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void LoginForm_Load(object sender, EventArgs e)
        {

        }
    }
}
