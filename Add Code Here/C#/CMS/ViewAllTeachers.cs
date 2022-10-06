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
    public partial class ViewAllTeachers : Form
    {
        public ViewAllTeachers()
        {
            InitializeComponent();
        }

        private void teacherGV_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void ViewAllTeachers_Load(object sender, EventArgs e)
        {
            teacherGV.DataSource = TEACHERDL.TeacherList1; // introspection
        }

        private void label2_Click(object sender, EventArgs e)
        {
            ViewDataForm data = new ViewDataForm();
            this.Close();
            data.Show();
        }

        private void label3_Click(object sender, EventArgs e)
        {
            AdminMenu menu = new AdminMenu();
            menu.Show();
            this.Close();
        }
    }
}
