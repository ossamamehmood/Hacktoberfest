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
    public partial class StudentNotice : Form
    {
        public StudentNotice()
        {
            InitializeComponent();
            noticeBox.Text= TEACHERDL.readNoticeFromFile();
        }

        private void label3_Click(object sender, EventArgs e)
        {
            this.Close();
            StudentMenu menu = new StudentMenu();
            menu.Show();
        }

        private void noticeBox_TextChanged(object sender, EventArgs e)
        {

        }

        private void StudentNotice_Load(object sender, EventArgs e)
        {
            
        }
    }
}
