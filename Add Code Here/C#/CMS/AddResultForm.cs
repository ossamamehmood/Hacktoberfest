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
    public partial class AddResultForm : Form
    {
        static int count = 0;
        public AddResultForm()
        {
            InitializeComponent();
        }

        private void AddResultForm_Load(object sender, EventArgs e)
        {
            if(ResultDL.Result.Count < STUDENTDL.StudentList1.Count)
            {
                NameBox.Text = STUDENTDL.StudentList1[count].Name1;
                RollNumberBox.Text = STUDENTDL.StudentList1[count].RollNumber1;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if(ResultDL.Result.Count + 1 > STUDENTDL.StudentList1.Count)
            {
                AdminMenu menu = new AdminMenu();
                this.Close();
                menu.Show();
            }
            else
            {
                MessageBox.Show("Please Add Total Student Result In Form");
            }
        }

        private void label9_Click(object sender, EventArgs e)
        {
            if(ResultDL.Result.Count < STUDENTDL.StudentList1.Count)
            {
                float urdu = float.Parse(urduBox.Text);
                float math = float.Parse(mathBox.Text);
                float computer = float.Parse(computerBox.Text);
                float physics = float.Parse(physicsBox.Text);
                float english = float.Parse(englishBox.Text);
                ResultBL Result = new ResultBL(STUDENTDL.StudentList1[count].Name1, urdu, math, computer, physics, english,STUDENTDL.StudentList1[count].Password1);
                ResultDL.addResultIntoList(Result);
                ResultDL.addResultIntoFile(Result, "Result.txt");
                count++;
                AddResultForm Temp = new AddResultForm();
                this.Close();
                Temp.Show();
            }
        }

        private void tableLayoutPanel6_Paint(object sender, PaintEventArgs e)
        {

        }
    }
}
