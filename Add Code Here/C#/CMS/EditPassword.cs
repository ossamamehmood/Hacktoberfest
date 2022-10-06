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
    public partial class EditPassword : Form
    {
        private STUDENTBL previous;
        public EditPassword(STUDENTBL Temp)
        {
            InitializeComponent();
            this.previous = Temp;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            STUDENTBL updated = new STUDENTBL(previous.Name1, previous.Father_Name1, previous.Matric_Marks1, previous.Course1, previous.RollNumber1, previous.Cnic1, previous.Section1,PasswordBox.Text, previous.Bankid1);
            STUDENTDL.EditUserFromList(previous, updated);
            this.Close();
            StudentMenu menu = new StudentMenu();
            menu.Show();
        }
    }
}
