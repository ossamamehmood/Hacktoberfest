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
    public partial class ViewAllStudent : Form
    {
        public ViewAllStudent()
        {
            InitializeComponent();
            STUDENTDL.StudentList1 = STUDENTDL.StudentList1.OrderByDescending(o => o.Matric_Marks1).ToList();
        }

        private void studentGV_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void ViewAllStudent_Load(object sender, EventArgs e)
        {
            studentGV.DataSource = STUDENTDL.StudentList1; // introspection
        }

        private void label2_Click(object sender, EventArgs e)
        {
            TeacherMenu Data = new TeacherMenu();
            this.Close();
            Data.Show();
        }

        private void label3_Click(object sender, EventArgs e)
        {
            Form1 menu = new Form1();
            this.Close();
            menu.Show();
        }
    }
}
