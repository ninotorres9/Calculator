using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CalcWindow
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            textBox1.Text += "1";
        }

        private void button2_Click(object sender, EventArgs e)
        {
            textBox1.Text += "2";
        }

        private void button3_Click(object sender, EventArgs e)
        {
            textBox1.Text += "3";
        }

        private void button4_Click(object sender, EventArgs e)
        {
            textBox1.Text += "4";
        }

        private void button5_Click(object sender, EventArgs e)
        {
            textBox1.Text += "5";
        }

        private void button6_Click(object sender, EventArgs e)
        {
            textBox1.Text += "6";
        }

        private void button7_Click(object sender, EventArgs e)
        {
            textBox1.Text += "7";
        }

        private void button8_Click(object sender, EventArgs e)
        {
            textBox1.Text += "8";
        }

        private void button9_Click(object sender, EventArgs e)
        {
            textBox1.Text += "9";
        }

        private void button_div_Click(object sender, EventArgs e)
        {
            textBox1.Text += "/";
        }

        private void button_mul_Click(object sender, EventArgs e)
        {
            textBox1.Text += "*";
        }

        private void button_sub_Click(object sender, EventArgs e)
        {
            textBox1.Text += "-";
        }

        private void button_add_Click(object sender, EventArgs e)
        {
            textBox1.Text += "+";
        }

        private void button10_Click(object sender, EventArgs e)
        {
            textBox1.Text += "0";
        }


        private void button_dot_Click(object sender, EventArgs e)
        {
            textBox1.Text += ".";
        }

        private void button_equal_Click(object sender, EventArgs e)
        {

        }

        private void button_backspace_Click(object sender, EventArgs e)
        {
            if(textBox1.Text.Length > 0)
            {
                textBox1.Text = textBox1.Text.Substring(0, textBox1.Text.Length - 1);
            }
        }

        private void button_clear_Click(object sender, EventArgs e)
        {
            textBox1.Text = "";
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }


    }
}
