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

namespace CMS.DL
{
    public partial class AttendanceForm : Form
    {
        static int count=0;
        public AttendanceForm()
        {
            InitializeComponent();
        }

        private void AttendanceForm_Load(object sender, EventArgs e)
        {
            if (count < STUDENTDL.StudentList1.Count)
            {
                NameBox.Text = STUDENTDL.StudentList1[count].Name1;
                NumberBox.Text = STUDENTDL.StudentList1[count].RollNumber1;
            }
        }

        private void tableLayoutPanel5_Paint(object sender, PaintEventArgs e)
        {

        }

        private void monthBox_TextChanged(object sender, EventArgs e)
        {

        }

        private void label7_Click(object sender, EventArgs e)
        {
            if (count < STUDENTDL.StudentList1.Count)
            {
                int month = int.Parse(monthBox.Text);
                float days=0;
                try
                {
                   days = float.Parse(textBox1.Text);

                }
                catch(Exception)
                {
                    MessageBox.Show("Please Enter Correct Number");
                }
                string Name= STUDENTDL.StudentList1[count].Name1;
                float percentage = AttendanceClass.calculatePercentage(month, days);
                MessageBox.Show("Total Percentage is " + percentage);
                AttendanceClass Object = new AttendanceClass(Name, percentage);
                AttendanceDL.addAttendanceIntoList(Object);
                count++;
                AttendanceForm Form = new AttendanceForm();
                this.Close();
                Form.Show();
            }
            if(count >= STUDENTDL.StudentList1.Count)
            {
                this.Close();
                AdminMenu menu = new AdminMenu();
                menu.Show();
            }
        }

        private void label8_Click(object sender, EventArgs e)
        {
            if(AttendanceDL.AttendanceData1.Count+1 >= STUDENTDL.StudentList1.Count)
            {
                AllAttendanceForm attendance = new AllAttendanceForm();
                this.Close();
                attendance.Show();
            }
            else
            {
                AllAttendanceForm attendance = new AllAttendanceForm();
                this.Close();
                attendance.Show();
                MessageBox.Show("Please Add  Full Student Data");
            }
        }
    }
}
