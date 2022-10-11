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
    public partial class ShowResultForm : Form
    {
        public ShowResultForm()
        {
            InitializeComponent();
            ResultDL.Result = ResultDL.Result.OrderByDescending(o => o.Total).ToList();
        }

        private void resultGV_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void ShowResultForm_Load(object sender, EventArgs e)
        {
            resultGV.DataSource = ResultDL.Result;
        }

        private void label2_Click(object sender, EventArgs e)
        {
            AdminMenu menu = new AdminMenu();
            menu.Show();
            this.Close();
        }
    }
}
