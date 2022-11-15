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
    public partial class CustomUrl : Form
    {
        private bool checkbox = false;

        public CustomUrl(bool checkbox_state)
        {
            InitializeComponent();
            checkbox = checkbox_state;
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            Process p = new Process();
            p.StartInfo.FileName = ".\\viewer.exe";
            p.StartInfo.Arguments = "--url=\"" + textBox1.Text + "\"";
            p.Start();

            if (checkbox)
            {
                Application.Exit();
            }
        }

        private void button2_Click_1(object sender, EventArgs e)
        {
            Close();
        }
    }
}
