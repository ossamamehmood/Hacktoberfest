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
    public partial class AllAttendanceForm : Form
    {
        public AllAttendanceForm()
        {
            InitializeComponent();
            AttendanceDL.AttendanceData1 = AttendanceDL.AttendanceData1.OrderByDescending(o => o.Percentage).ToList();
        }

        private void AllAttendanceForm_Load(object sender, EventArgs e)
        {
            attendanceGV.DataSource = AttendanceDL.AttendanceData1;
        }

        private void attendanceGV_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {
            AdminMenu menu = new AdminMenu();
            menu.Show();
            this.Close();
        }
    }
}
