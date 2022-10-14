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
    public partial class RemoveTeacherForm : Form
    {
        public RemoveTeacherForm()
        {
            InitializeComponent();
        }

        public void dataBind()
        {
            teacherGV.DataSource = null;
            teacherGV.DataSource = TEACHERDL.TeacherList1;
            teacherGV.Refresh();
        }

        private void label2_Click(object sender, EventArgs e)
        {
            AdminMenu menu = new AdminMenu();
            this.Close();
            menu.Show();
        }

        private void teacherGV_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            TEACHERBL user = (TEACHERBL)teacherGV.CurrentRow.DataBoundItem;
            if (teacherGV.Columns["Remove"].Index == e.ColumnIndex)
            {
                TEACHERDL.deleteTeacherFromList(user);
                TEACHERDL.addTeacherIntoFile("Teacher.txt");
                dataBind();
                MessageBox.Show("Data Deleted Successfully");
            }

        }

        private void RemoveTeacherForm_Load(object sender, EventArgs e)
        {
            teacherGV.DataSource = TEACHERDL.TeacherList1;
        }
    }
}
