using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CMS.DL
{
    public partial class TimeTableFrom : Form
    {
        public TimeTableFrom()
        {
            InitializeComponent();
        }

        private void tableLayoutPanel1_Paint(object sender, PaintEventArgs e)
        {
            string period1 = textBox1.Text;
            string period2 = textBox2.Text;
            string period3 = textBox3.Text;
            string period4 = textBox4.Text;
            string period5 = textBox5.Text;
            textBox6.Text = period2;
            textBox7.Text = period5;
            textBox8.Text = period1;
            textBox9.Text = period3;
            textBox10.Text = period4;
            textBox11.Text = period3;
            textBox12.Text = period2;
            textBox13.Text = period5;
            textBox14.Text = period4;
            textBox15.Text = period1;
            textBox16.Text = period5;
            textBox17.Text = period1;
            textBox18.Text = period4;
            textBox19.Text = period2;
            textBox20.Text = period3;
            textBox21.Text = period4;
            textBox22.Text = period1;
            textBox23.Text = period5;
            textBox24.Text = period3;
            textBox25.Text = period2;
        }
    }
}
