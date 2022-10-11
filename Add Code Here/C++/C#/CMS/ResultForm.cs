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
    public partial class ResultForm : Form
    {
        private STUDENTBL previous;
        public ResultForm(STUDENTBL temp)
        {
            InitializeComponent();
            this.previous = temp;
            ResultDL.changePassword(previous);

        }

        private void ResultForm_Load(object sender, EventArgs e)
        {
            ResultBL temp = ResultDL.checkResult(previous);
            bool checker = ResultDL.isvalid(previous);
            if (checker)
            {
                nameBox.Text = temp.Name;
                urduBox.Text = "" + temp.Urdu;
                mathBox.Text = "" + temp.Math;
                physicsBox.Text = "" + temp.Physics;
                computerBox.Text = "" + temp.Computer;
                englishBox.Text = "" + temp.Computer;
            }
            else
            {
                MessageBox.Show("No record Found");
            }

        }

        private void label9_Click(object sender, EventArgs e)
        {
            this.Close();
            StudentMenu menu = new StudentMenu();
            menu.Show();
        }

        private void label10_Click(object sender, EventArgs e)
        {
            this.Close();
            Form1 mainPage = new Form1();
            mainPage.Show();
        }
    }
}
