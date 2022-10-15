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
    public partial class TeacherMenu : Form
    {
        public TeacherMenu()
        {
            InitializeComponent();
        }

        private void label3_Click(object sender, EventArgs e)
        {
            UpdateRecordForm temp = new UpdateRecordForm();
            this.Close();
            temp.Show();
        }

        private void label4_Click(object sender, EventArgs e)
        {
            ViewAllStudent temp = new ViewAllStudent();
            this.Close();
            temp.Show();
        }

        private void label5_Click(object sender, EventArgs e)
        {
            NoticeForm notice = new NoticeForm();
            this.Close();
            notice.Show(); 
        }

        private void label6_Click(object sender, EventArgs e)
        {
            UsersForm user = new UsersForm();
            this.Close();
            user.Show();
        }
    }
}
