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

namespace CMS
{
    public partial class NoticeForm : Form
    {
        public NoticeForm()
        {
            InitializeComponent();
            TEACHERDL.readNoticeFromFile();
            noticeBox.Text = TEACHERDL.notice;
        }

        private void saveButton_Click(object sender, EventArgs e)
        {
            string Notice = noticeBox.Text;
            TEACHERDL.addNoticeIntoList(Notice);
            MessageBox.Show("Save Notice");
            noticeBox.Clear();

        }

        private void Backbutton_Click(object sender, EventArgs e)
        {
            TeacherMenu menu = new TeacherMenu();
            this.Close();
            menu.Show();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            noticeBox.Clear();
        }

        private void NoticeForm_Load(object sender, EventArgs e)
        {

        }
    }
}
