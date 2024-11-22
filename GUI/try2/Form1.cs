using System;
using System.Drawing;
using System.IO.Ports;
using System.Windows.Forms;

namespace try2
{
    /*
     'M'-> Manual
     'A'->Auto
     'L'->lower Temp
     'H'->Higher Temp
    'F'->fan on
    'S' Fanspeed
    'X'->fan off
    'B'->Bulb On
     */
    public partial class Form1 : Form
    {

        SerialPort mySerialPort = null;
        String sendedFrame = "";
        String recievedData = "";
        bool frameStarted;
        bool manualMode= false;
        public Form1()
        {
            InitializeComponent();
            refreshComms();
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            refreshComms();
        }
        private void refreshComms()
        {
            commSelector.DataSource=SerialPort.GetPortNames();
        }

        private void connectBtn_Click(object sender, EventArgs e)
        {
            connectToPort();
        }
        private void connectToPort()
        {
            mySerialPort = new SerialPort(commSelector.SelectedItem.ToString());
            mySerialPort.DataReceived += new SerialDataReceivedEventHandler(data_rx_handler);
            mySerialPort.BaudRate = 9600;
            mySerialPort.DataBits = 8;
            mySerialPort.StopBits=StopBits.One;
            try
            {
                if(!mySerialPort.IsOpen)
                {
                    mySerialPort.Open();
                    
                    connectionStatus.Text = "Connected";
                    connectionStatus.ForeColor = Color.Green;
                 

                }

            }
            catch(Exception ex)
            {

            }
        }
        private void closeConnection()
        {
            try
            {
                if(mySerialPort.IsOpen) {
                mySerialPort.Close();
                    connectionStatus.Text = "Disconnected";
                    connectionStatus.ForeColor = Color.Red;
                }
            }
              catch (Exception ex) { }
        }
        private void sendData(String sendedData)
        {
            try
            {


                if (!mySerialPort.IsOpen)
                {
                    return;
                }
                mySerialPort.Write(sendedData);
            }
            catch (Exception ex) { }
        }
        private void data_rx_handler(Object sender, SerialDataReceivedEventArgs e)
        {
            SerialPort sp = (SerialPort)sender;
            String temp = sp.ReadExisting();
            /////chceck data here
            if (temp.Contains("H") || temp.Contains("L") || temp.Contains("N") || temp.Contains("B") || temp.Contains("C"))
            {
                frameStarted = true;
                
                //we recived whole frame let's handle it here
            }
            /*else if(temp.Contains("%"))
            {
                //make it for frame indentifier
            }*/
            if (frameStarted)
            {
                recievedData += temp;
                //MessageBox.Show(recievedData);

                if (recievedData.Contains("H"))
                 {
                     statusLabel.Invoke((MethodInvoker)(() => statusLabel.Text = "High Temprature"));
                     statusLabel.ForeColor = Color.Red;
                    recievedData = "";
                 }
                 else if (recievedData.Contains("L"))
                 {
                     statusLabel.Invoke((MethodInvoker)(() => statusLabel.Text = "Low Temprature"));
                     statusLabel.ForeColor = Color.Blue;
                  recievedData = "";
                 }
                 else if (recievedData.Contains("N"))
                 {
                     statusLabel.Invoke((MethodInvoker)(() => statusLabel.Text = "Normal Temprature"));
                     statusLabel.ForeColor = Color.Green;
                    
                    recievedData = "";
                 }
                else if (recievedData[0] == 'B')
                {
                    MessageBox.Show("Bad frame");
                }
                else if (recievedData[0] == 'C')
                {
                    MessageBox.Show("Complete frame");
                }
                //int indexOf1 = recievedData.IndexOf('@');
                frameStarted = false;

            }


            
        }
        private bool getSelectedMode()
        {
            if(manualRBTN.Checked)
            {
                manualMode = true;
            }
            else
            {
                manualMode= false;
            }
            return manualMode;
        }
        private void disconnectBtn_Click(object sender, EventArgs e)
        {
            closeConnection();
        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            closeConnection();
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            
        }

        private void button1_KeyDown(object sender, KeyEventArgs e)
        {
            if(e.KeyCode== Keys.Enter)
            {
                
            }
        }

        private void readBtn_Click(object sender, EventArgs e)
        {
           
            sendData("I");
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {        
                sendData(upperTemp.Text);          
        }

        private void manualRBTN_CheckedChanged(object sender, EventArgs e)
        {
            if (manualRBTN.Checked)
            {
                manualModeConfiguration();
                sendData("M");
                
            }
            else
            {
                autoModeConfiguration();
            }
        }

        private void autoRBTN_CheckedChanged(object sender, EventArgs e)
        {
            if (autoRBTN.Checked)
            {
                autoModeConfiguration();
                sendData("A");
                
            }
            else
            {
                manualModeConfiguration();
   
            }
        }
        private void manualModeConfiguration()
        {
            manualMode = true;
            tempBoundariesGroup.Visible = true;
            fanBoundariesGroup.Visible = true;
            lampBoundariesGroup.Visible = true;
           button1.Visible= true;
            button2.Visible= true;

        }
        private void autoModeConfiguration()
        {
            manualMode = false;
            tempBoundariesGroup.Visible = true;
            fanBoundariesGroup.Visible = false;
            lampBoundariesGroup.Visible = false;
            button1.Visible = false;
            button2.Visible = true;

        }

        private void groupBox1_Enter_1(object sender, EventArgs e)
        {

        }

        private void fanSwitch_CheckedChanged(object sender, EventArgs e)
        {
  
        }

        private void speedSendBtn_Click(object sender, EventArgs e)
        {
            if(fanOn.Checked)
            {
                sendData(speedTextField.Text);
            }



        }

        private void button1_Click_2(object sender, EventArgs e)
        {
            sendData("C");
        }

        private void lampSwitch_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void LowerTemp_TextChanged(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            sendData("q");
        }

        private void button3_Click(object sender, EventArgs e)
        {
            sendData(LowerTemp.Text);
           
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            //sendData("R");
            manualModeConfiguration();
        }

        private void radioButton4_CheckedChanged(object sender, EventArgs e)
        {
            if (fanOn.Checked)
            { sendData("F"); }
        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            if(fanReset.Checked)
            { sendData("H");
                speedTextField.Visible = false;
            }
        }

        private void radioButton3_CheckedChanged(object sender, EventArgs e)
        {
            if (fanOff.Checked)
            { 
                sendData("N");
                speedTextField.Visible=false;
            }
        }

        private void lampOn_CheckedChanged(object sender, EventArgs e)
        {
            if(lampOn.Checked)
            { 
                sendData("B"); 
            }
        }

        private void lampOff_CheckedChanged(object sender, EventArgs e)
        {
            if (lampOff.Checked)
            {
                sendData("X");
            }
        }

        private void lampReset_CheckedChanged(object sender, EventArgs e)
        {
            if (lampReset.Checked)
            {
                sendData("G");
            }
        }

        private void label1_Click_1(object sender, EventArgs e)
        {

        }

        private void button4_Click(object sender, EventArgs e)
        {
            sendData("n");
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void button5_Click(object sender, EventArgs e)
        {
            sendData("x");
        }

        private void statusLabel_Click(object sender, EventArgs e)
        {

        }

        private void button6_Click(object sender, EventArgs e)
        {
            sendData("Z");
        }
    }
}
