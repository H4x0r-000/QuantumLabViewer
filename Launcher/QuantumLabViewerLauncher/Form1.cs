using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Diagnostics;

namespace QuantumLabViewerLauncher
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Process p = new Process();
            p.StartInfo.FileName = ".\\viewer.exe";
            p.StartInfo.Arguments = "";
            p.Start();

            if (checkBox1.Checked)
            {
                Application.Exit();
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Process p = new Process();
            p.StartInfo.FileName = ".\\viewer.exe";
            p.StartInfo.Arguments = "--offline-mode";
            p.Start();

            if (checkBox1.Checked)
            {
                Application.Exit();
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            CustomUrl c_url = new CustomUrl(checkBox1.Checked);
            c_url.Show();
        }

        private void label3_Click(object sender, EventArgs e)
        {
            Process.Start("https://github.com/H4x0r-000");
        }
    }
}
