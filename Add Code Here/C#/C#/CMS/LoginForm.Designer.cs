
namespace CMS
{
    partial class LoginForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.tableLayoutPanel2 = new System.Windows.Forms.TableLayoutPanel();
            this.tableLayoutPanel3 = new System.Windows.Forms.TableLayoutPanel();
            this.label2 = new System.Windows.Forms.Label();
            this.NameBox = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.PasswordBox = new System.Windows.Forms.TextBox();
            this.LoginButton = new System.Windows.Forms.Button();
            this.tableLayoutPanel1.SuspendLayout();
            this.tableLayoutPanel2.SuspendLayout();
            this.tableLayoutPanel3.SuspendLayout();
            this.SuspendLayout();
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.BackgroundImage = global::CMS.Properties.Resources.stock_vector_signup_form_login_page_design_you_can_use_it_for_multipurpose_web_projects_login_form_menu_line_1700033632;
            this.tableLayoutPanel1.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.tableLayoutPanel1.ColumnCount = 1;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel1.Controls.Add(this.tableLayoutPanel2, 0, 0);
            this.tableLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel1.Location = new System.Drawing.Point(0, 0);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 1;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel1.Size = new System.Drawing.Size(1766, 697);
            this.tableLayoutPanel1.TabIndex = 0;
            this.tableLayoutPanel1.Paint += new System.Windows.Forms.PaintEventHandler(this.tableLayoutPanel1_Paint);
            // 
            // tableLayoutPanel2
            // 
            this.tableLayoutPanel2.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.tableLayoutPanel2.BackColor = System.Drawing.Color.Transparent;
            this.tableLayoutPanel2.ColumnCount = 2;
            this.tableLayoutPanel2.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel2.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel2.Controls.Add(this.tableLayoutPanel3, 1, 0);
            this.tableLayoutPanel2.Controls.Add(this.LoginButton, 1, 1);
            this.tableLayoutPanel2.Location = new System.Drawing.Point(302, 143);
            this.tableLayoutPanel2.Name = "tableLayoutPanel2";
            this.tableLayoutPanel2.RowCount = 2;
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 84.39024F));
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 15.60976F));
            this.tableLayoutPanel2.Size = new System.Drawing.Size(1161, 410);
            this.tableLayoutPanel2.TabIndex = 0;
            // 
            // tableLayoutPanel3
            // 
            this.tableLayoutPanel3.BackColor = System.Drawing.Color.White;
            this.tableLayoutPanel3.ColumnCount = 2;
            this.tableLayoutPanel3.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel3.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Absolute, 439F));
            this.tableLayoutPanel3.Controls.Add(this.label2, 0, 1);
            this.tableLayoutPanel3.Controls.Add(this.NameBox, 1, 0);
            this.tableLayoutPanel3.Controls.Add(this.label1, 0, 0);
            this.tableLayoutPanel3.Controls.Add(this.PasswordBox, 1, 1);
            this.tableLayoutPanel3.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel3.Location = new System.Drawing.Point(583, 3);
            this.tableLayoutPanel3.Name = "tableLayoutPanel3";
            this.tableLayoutPanel3.RowCount = 2;
            this.tableLayoutPanel3.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel3.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 152F));
            this.tableLayoutPanel3.Size = new System.Drawing.Size(575, 339);
            this.tableLayoutPanel3.TabIndex = 0;
            // 
            // label2
            // 
            this.label2.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Book Antiqua", 10F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(18, 251);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(99, 24);
            this.label2.TabIndex = 3;
            this.label2.Text = "Password";
            // 
            // NameBox
            // 
            this.NameBox.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.NameBox.Font = new System.Drawing.Font("Book Antiqua", 8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.NameBox.Location = new System.Drawing.Point(222, 80);
            this.NameBox.Name = "NameBox";
            this.NameBox.Size = new System.Drawing.Size(266, 27);
            this.NameBox.TabIndex = 0;
            this.NameBox.TextChanged += new System.EventHandler(this.NameBox_TextChanged);
            // 
            // label1
            // 
            this.label1.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Book Antiqua", 10F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(36, 81);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(63, 24);
            this.label1.TabIndex = 1;
            this.label1.Text = "Name";
            // 
            // PasswordBox
            // 
            this.PasswordBox.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.PasswordBox.Font = new System.Drawing.Font("Book Antiqua", 8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.PasswordBox.Location = new System.Drawing.Point(222, 249);
            this.PasswordBox.Name = "PasswordBox";
            this.PasswordBox.Size = new System.Drawing.Size(266, 27);
            this.PasswordBox.TabIndex = 2;
            // 
            // LoginButton
            // 
            this.LoginButton.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.LoginButton.BackColor = System.Drawing.Color.Green;
            this.LoginButton.Font = new System.Drawing.Font("Book Antiqua", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LoginButton.Location = new System.Drawing.Point(819, 350);
            this.LoginButton.Name = "LoginButton";
            this.LoginButton.Size = new System.Drawing.Size(103, 55);
            this.LoginButton.TabIndex = 1;
            this.LoginButton.Text = "Login";
            this.LoginButton.UseVisualStyleBackColor = false;
            this.LoginButton.Click += new System.EventHandler(this.LoginButton_Click);
            // 
            // LoginForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1766, 697);
            this.Controls.Add(this.tableLayoutPanel1);
            this.Name = "LoginForm";
            this.Text = "LoginForm";
            this.Load += new System.EventHandler(this.LoginForm_Load);
            this.tableLayoutPanel1.ResumeLayout(false);
            this.tableLayoutPanel2.ResumeLayout(false);
            this.tableLayoutPanel3.ResumeLayout(false);
            this.tableLayoutPanel3.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel2;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel3;
        private System.Windows.Forms.TextBox NameBox;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox PasswordBox;
        private System.Windows.Forms.Button LoginButton;
    }
}