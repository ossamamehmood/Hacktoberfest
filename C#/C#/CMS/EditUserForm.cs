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
    public partial class EditUserForm : Form
    {
        private STUDENTBL previous;
        public EditUserForm(STUDENTBL Temp)
        {
            InitializeComponent();
            this.previous = Temp;

        }

        private void EditUserForm_Load(object sender, EventArgs e)
        {
            nameBox.Text = previous.Name1;
            passwordBox.Text = previous.Password1;
            CNICBox.Text = previous.Cnic1;
            fNameBox.Text = previous.Father_Name1;
            sectionBox.Text = previous.Section1; ;
            marksBox.Text = ""+previous.Matric_Marks1;
            bankBox.Text = previous.Bankid1;
            courseBox.Text = previous.Course1;
            rollNumberBox.Text = previous.RollNumber1;
        }

        private void tableLayoutPanel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void label9_Click(object sender, EventArgs e)
        {
            float Marks = float.Parse(marksBox.Text);
            STUDENTBL updated = new STUDENTBL(nameBox.Text, fNameBox.Text, Marks,courseBox.Text,rollNumberBox.Text,CNICBox.Text,sectionBox.Text,passwordBox.Text,bankBox.Text);
            STUDENTDL.EditUserFromList(previous, updated);
            this.Close();
        }
    }
}
