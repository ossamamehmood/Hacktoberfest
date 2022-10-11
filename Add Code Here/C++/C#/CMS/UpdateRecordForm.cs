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
    public partial class UpdateRecordForm : Form
    {
        public UpdateRecordForm()
        {
            InitializeComponent();
        }

        private void dataGV_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            STUDENTBL user = (STUDENTBL)dataGV.CurrentRow.DataBoundItem;
            if (dataGV.Columns["Edit"].Index == e.ColumnIndex)
            {
                EditUserForm myform = new EditUserForm(user);
                myform.ShowDialog();
                STUDENTDL.addStudentDataIntoFile("Student.txt");
                dataBind();
            }
        }

        public void dataBind()
        {
            dataGV.DataSource = null;
            dataGV.DataSource = STUDENTDL.StudentList1;
            dataGV.Refresh();
        }

        private void UpdateRecordForm_Load(object sender, EventArgs e)
        {
            dataGV.DataSource = STUDENTDL.StudentList1; // introspection
        }

        private void button1_Click(object sender, EventArgs e)
        {
            TeacherMenu menu = new TeacherMenu();
            this.Hide();
            menu.Show();
        }
    }
}
