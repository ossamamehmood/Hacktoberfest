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
    public partial class RemoveStudentForm : Form
    {
        public RemoveStudentForm()
        {
            InitializeComponent();
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            try
            {
                STUDENTBL user = (STUDENTBL)studentGV.CurrentRow.DataBoundItem;
                if (studentGV.Columns["Remove"].Index == e.ColumnIndex)
                {
                    STUDENTDL.deleteStudentFromList(user);
                    STUDENTDL.addStudentDataIntoFile("Student.txt");
                    dataBind();
                    MessageBox.Show("Data Deleted Successfully");
                }
            }
            catch(Exception)
            {
                MessageBox.Show("Please Try again");
            }
        }

        public void dataBind()
        {
            studentGV.DataSource = null;
            studentGV.DataSource = STUDENTDL.StudentList1;
            studentGV.Refresh();
        }

        private void tableLayoutPanel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void RemoveStudentForm_Load(object sender, EventArgs e)
        {
            studentGV.DataSource = STUDENTDL.StudentList1; // introspection
        }

        private void label2_Click(object sender, EventArgs e)
        {
            AdminMenu Menu = new AdminMenu();
            this.Close();
            Menu.Show();

        }

        private void tableLayoutPanel2_Paint(object sender, PaintEventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void tableLayoutPanel3_Paint(object sender, PaintEventArgs e)
        {

        }

        private void tableLayoutPanel4_Paint(object sender, PaintEventArgs e)
        {

        }

        private void tableLayoutPanel5_Paint(object sender, PaintEventArgs e)
        {

        }

        private void tableLayoutPanel6_Paint(object sender, PaintEventArgs e)
        {

        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void pictureBox2_Click(object sender, EventArgs e)
        {

        }
    }
}
