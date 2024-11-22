namespace try2
{
    partial class Form1
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
            this.commSelector = new System.Windows.Forms.ComboBox();
            this.connectionStatus = new System.Windows.Forms.Label();
            this.refreshBtn = new System.Windows.Forms.Button();
            this.connectBtn = new System.Windows.Forms.Button();
            this.disconnectBtn = new System.Windows.Forms.Button();
            this.readBtn = new System.Windows.Forms.Button();
            this.modeLabel = new System.Windows.Forms.Label();
            this.modeSelector = new System.Windows.Forms.GroupBox();
            this.radioButton1 = new System.Windows.Forms.RadioButton();
            this.autoRBTN = new System.Windows.Forms.RadioButton();
            this.manualRBTN = new System.Windows.Forms.RadioButton();
            this.LowerTemp = new System.Windows.Forms.TextBox();
            this.upperTemp = new System.Windows.Forms.TextBox();
            this.button2 = new System.Windows.Forms.Button();
            this.tempBoundariesGroup = new System.Windows.Forms.GroupBox();
            this.button5 = new System.Windows.Forms.Button();
            this.button4 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.lampBoundariesGroup = new System.Windows.Forms.GroupBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.lampReset = new System.Windows.Forms.RadioButton();
            this.lampOff = new System.Windows.Forms.RadioButton();
            this.lampOn = new System.Windows.Forms.RadioButton();
            this.label3 = new System.Windows.Forms.Label();
            this.speedTextField = new System.Windows.Forms.TextBox();
            this.speedSendBtn = new System.Windows.Forms.Button();
            this.fanBoundariesGroup = new System.Windows.Forms.GroupBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.fanReset = new System.Windows.Forms.RadioButton();
            this.fanOff = new System.Windows.Forms.RadioButton();
            this.fanOn = new System.Windows.Forms.RadioButton();
            this.button1 = new System.Windows.Forms.Button();
            this.statusLabel = new System.Windows.Forms.Label();
            this.button6 = new System.Windows.Forms.Button();
            this.modeSelector.SuspendLayout();
            this.tempBoundariesGroup.SuspendLayout();
            this.lampBoundariesGroup.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.fanBoundariesGroup.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // commSelector
            // 
            this.commSelector.FormattingEnabled = true;
            this.commSelector.Location = new System.Drawing.Point(58, 39);
            this.commSelector.Name = "commSelector";
            this.commSelector.Size = new System.Drawing.Size(253, 24);
            this.commSelector.TabIndex = 0;
            this.commSelector.SelectedIndexChanged += new System.EventHandler(this.comboBox1_SelectedIndexChanged);
            // 
            // connectionStatus
            // 
            this.connectionStatus.AutoSize = true;
            this.connectionStatus.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.connectionStatus.Location = new System.Drawing.Point(341, 34);
            this.connectionStatus.Name = "connectionStatus";
            this.connectionStatus.Size = new System.Drawing.Size(167, 29);
            this.connectionStatus.TabIndex = 1;
            this.connectionStatus.Text = "Disconnected";
            // 
            // refreshBtn
            // 
            this.refreshBtn.Location = new System.Drawing.Point(88, 89);
            this.refreshBtn.Name = "refreshBtn";
            this.refreshBtn.Size = new System.Drawing.Size(177, 45);
            this.refreshBtn.TabIndex = 2;
            this.refreshBtn.Text = "Refresh";
            this.refreshBtn.UseVisualStyleBackColor = true;
            this.refreshBtn.Click += new System.EventHandler(this.button1_Click);
            // 
            // connectBtn
            // 
            this.connectBtn.Location = new System.Drawing.Point(283, 89);
            this.connectBtn.Name = "connectBtn";
            this.connectBtn.Size = new System.Drawing.Size(177, 45);
            this.connectBtn.TabIndex = 3;
            this.connectBtn.Text = "Connect";
            this.connectBtn.UseVisualStyleBackColor = true;
            this.connectBtn.Click += new System.EventHandler(this.connectBtn_Click);
            // 
            // disconnectBtn
            // 
            this.disconnectBtn.Location = new System.Drawing.Point(494, 89);
            this.disconnectBtn.Name = "disconnectBtn";
            this.disconnectBtn.Size = new System.Drawing.Size(177, 45);
            this.disconnectBtn.TabIndex = 4;
            this.disconnectBtn.Text = "Disconnect";
            this.disconnectBtn.UseVisualStyleBackColor = true;
            this.disconnectBtn.Click += new System.EventHandler(this.disconnectBtn_Click);
            // 
            // readBtn
            // 
            this.readBtn.Location = new System.Drawing.Point(179, 484);
            this.readBtn.Name = "readBtn";
            this.readBtn.Size = new System.Drawing.Size(132, 24);
            this.readBtn.TabIndex = 8;
            this.readBtn.Text = "read";
            this.readBtn.UseVisualStyleBackColor = true;
            this.readBtn.Click += new System.EventHandler(this.readBtn_Click);
            // 
            // modeLabel
            // 
            this.modeLabel.AutoSize = true;
            this.modeLabel.Font = new System.Drawing.Font("Arial", 11F, System.Drawing.FontStyle.Bold);
            this.modeLabel.Location = new System.Drawing.Point(76, 166);
            this.modeLabel.Name = "modeLabel";
            this.modeLabel.Size = new System.Drawing.Size(62, 22);
            this.modeLabel.TabIndex = 10;
            this.modeLabel.Text = "Mode";
            this.modeLabel.Click += new System.EventHandler(this.label1_Click);
            // 
            // modeSelector
            // 
            this.modeSelector.Controls.Add(this.radioButton1);
            this.modeSelector.Controls.Add(this.autoRBTN);
            this.modeSelector.Controls.Add(this.manualRBTN);
            this.modeSelector.Location = new System.Drawing.Point(144, 151);
            this.modeSelector.Name = "modeSelector";
            this.modeSelector.Size = new System.Drawing.Size(200, 100);
            this.modeSelector.TabIndex = 11;
            this.modeSelector.TabStop = false;
            this.modeSelector.Enter += new System.EventHandler(this.groupBox1_Enter);
            // 
            // radioButton1
            // 
            this.radioButton1.AutoSize = true;
            this.radioButton1.Location = new System.Drawing.Point(16, 76);
            this.radioButton1.Name = "radioButton1";
            this.radioButton1.Size = new System.Drawing.Size(64, 20);
            this.radioButton1.TabIndex = 17;
            this.radioButton1.TabStop = true;
            this.radioButton1.Text = "Reset";
            this.radioButton1.UseVisualStyleBackColor = true;
            this.radioButton1.CheckedChanged += new System.EventHandler(this.radioButton1_CheckedChanged);
            // 
            // autoRBTN
            // 
            this.autoRBTN.AutoSize = true;
            this.autoRBTN.Location = new System.Drawing.Point(16, 48);
            this.autoRBTN.Name = "autoRBTN";
            this.autoRBTN.Size = new System.Drawing.Size(87, 20);
            this.autoRBTN.TabIndex = 16;
            this.autoRBTN.TabStop = true;
            this.autoRBTN.Text = "Automatic";
            this.autoRBTN.UseVisualStyleBackColor = true;
            this.autoRBTN.CheckedChanged += new System.EventHandler(this.autoRBTN_CheckedChanged);
            // 
            // manualRBTN
            // 
            this.manualRBTN.AutoSize = true;
            this.manualRBTN.Location = new System.Drawing.Point(16, 21);
            this.manualRBTN.Name = "manualRBTN";
            this.manualRBTN.Size = new System.Drawing.Size(72, 20);
            this.manualRBTN.TabIndex = 15;
            this.manualRBTN.TabStop = true;
            this.manualRBTN.Text = "Manual";
            this.manualRBTN.UseVisualStyleBackColor = true;
            this.manualRBTN.CheckedChanged += new System.EventHandler(this.manualRBTN_CheckedChanged);
            // 
            // LowerTemp
            // 
            this.LowerTemp.Location = new System.Drawing.Point(57, 30);
            this.LowerTemp.Name = "LowerTemp";
            this.LowerTemp.Size = new System.Drawing.Size(101, 31);
            this.LowerTemp.TabIndex = 6;
            this.LowerTemp.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.LowerTemp.TextChanged += new System.EventHandler(this.LowerTemp_TextChanged);
            // 
            // upperTemp
            // 
            this.upperTemp.Location = new System.Drawing.Point(62, 69);
            this.upperTemp.Name = "upperTemp";
            this.upperTemp.Size = new System.Drawing.Size(96, 31);
            this.upperTemp.TabIndex = 7;
            this.upperTemp.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.upperTemp.TextChanged += new System.EventHandler(this.textBox3_TextChanged);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(164, 74);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(94, 31);
            this.button2.TabIndex = 13;
            this.button2.Text = "send";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // tempBoundariesGroup
            // 
            this.tempBoundariesGroup.Controls.Add(this.button5);
            this.tempBoundariesGroup.Controls.Add(this.button4);
            this.tempBoundariesGroup.Controls.Add(this.button3);
            this.tempBoundariesGroup.Controls.Add(this.button2);
            this.tempBoundariesGroup.Controls.Add(this.upperTemp);
            this.tempBoundariesGroup.Controls.Add(this.LowerTemp);
            this.tempBoundariesGroup.Font = new System.Drawing.Font("Arial Rounded MT Bold", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.tempBoundariesGroup.Location = new System.Drawing.Point(389, 151);
            this.tempBoundariesGroup.Name = "tempBoundariesGroup";
            this.tempBoundariesGroup.Size = new System.Drawing.Size(294, 142);
            this.tempBoundariesGroup.TabIndex = 12;
            this.tempBoundariesGroup.TabStop = false;
            this.tempBoundariesGroup.Text = "Temprature boundries";
            this.tempBoundariesGroup.Visible = false;
            // 
            // button5
            // 
            this.button5.Location = new System.Drawing.Point(0, 66);
            this.button5.Name = "button5";
            this.button5.Size = new System.Drawing.Size(58, 34);
            this.button5.TabIndex = 16;
            this.button5.Text = "max";
            this.button5.UseVisualStyleBackColor = true;
            this.button5.Click += new System.EventHandler(this.button5_Click);
            // 
            // button4
            // 
            this.button4.Location = new System.Drawing.Point(0, 30);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(58, 34);
            this.button4.TabIndex = 15;
            this.button4.Text = "min";
            this.button4.UseVisualStyleBackColor = true;
            this.button4.Click += new System.EventHandler(this.button4_Click);
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(164, 30);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(94, 31);
            this.button3.TabIndex = 14;
            this.button3.Text = "send";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // lampBoundariesGroup
            // 
            this.lampBoundariesGroup.Controls.Add(this.groupBox2);
            this.lampBoundariesGroup.Font = new System.Drawing.Font("Arial Rounded MT Bold", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lampBoundariesGroup.Location = new System.Drawing.Point(389, 307);
            this.lampBoundariesGroup.Name = "lampBoundariesGroup";
            this.lampBoundariesGroup.Size = new System.Drawing.Size(282, 139);
            this.lampBoundariesGroup.TabIndex = 18;
            this.lampBoundariesGroup.TabStop = false;
            this.lampBoundariesGroup.Text = "AC lamp";
            this.lampBoundariesGroup.Visible = false;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.lampReset);
            this.groupBox2.Controls.Add(this.lampOff);
            this.groupBox2.Controls.Add(this.lampOn);
            this.groupBox2.Location = new System.Drawing.Point(35, 24);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(184, 109);
            this.groupBox2.TabIndex = 19;
            this.groupBox2.TabStop = false;
            // 
            // lampReset
            // 
            this.lampReset.AutoSize = true;
            this.lampReset.Location = new System.Drawing.Point(16, 76);
            this.lampReset.Name = "lampReset";
            this.lampReset.Size = new System.Drawing.Size(87, 27);
            this.lampReset.TabIndex = 17;
            this.lampReset.TabStop = true;
            this.lampReset.Text = "Reset";
            this.lampReset.UseVisualStyleBackColor = true;
            this.lampReset.CheckedChanged += new System.EventHandler(this.lampReset_CheckedChanged);
            // 
            // lampOff
            // 
            this.lampOff.AutoSize = true;
            this.lampOff.Location = new System.Drawing.Point(16, 48);
            this.lampOff.Name = "lampOff";
            this.lampOff.Size = new System.Drawing.Size(71, 27);
            this.lampOff.TabIndex = 16;
            this.lampOff.TabStop = true;
            this.lampOff.Text = "OFF";
            this.lampOff.UseVisualStyleBackColor = true;
            this.lampOff.CheckedChanged += new System.EventHandler(this.lampOff_CheckedChanged);
            // 
            // lampOn
            // 
            this.lampOn.AutoSize = true;
            this.lampOn.Location = new System.Drawing.Point(16, 21);
            this.lampOn.Name = "lampOn";
            this.lampOn.Size = new System.Drawing.Size(62, 27);
            this.lampOn.TabIndex = 15;
            this.lampOn.TabStop = true;
            this.lampOn.Text = "ON";
            this.lampOn.UseVisualStyleBackColor = true;
            this.lampOn.CheckedChanged += new System.EventHandler(this.lampOn_CheckedChanged);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Arial Narrow", 10.8F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(6, 154);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(53, 22);
            this.label3.TabIndex = 20;
            this.label3.Text = "Speed";
            // 
            // speedTextField
            // 
            this.speedTextField.Location = new System.Drawing.Point(65, 145);
            this.speedTextField.Name = "speedTextField";
            this.speedTextField.Size = new System.Drawing.Size(112, 31);
            this.speedTextField.TabIndex = 18;
            this.speedTextField.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // speedSendBtn
            // 
            this.speedSendBtn.Font = new System.Drawing.Font("Arial Rounded MT Bold", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.speedSendBtn.Location = new System.Drawing.Point(188, 145);
            this.speedSendBtn.Name = "speedSendBtn";
            this.speedSendBtn.Size = new System.Drawing.Size(85, 33);
            this.speedSendBtn.TabIndex = 19;
            this.speedSendBtn.Text = "send";
            this.speedSendBtn.UseVisualStyleBackColor = true;
            this.speedSendBtn.Click += new System.EventHandler(this.speedSendBtn_Click);
            // 
            // fanBoundariesGroup
            // 
            this.fanBoundariesGroup.Controls.Add(this.groupBox1);
            this.fanBoundariesGroup.Controls.Add(this.speedSendBtn);
            this.fanBoundariesGroup.Controls.Add(this.speedTextField);
            this.fanBoundariesGroup.Controls.Add(this.label3);
            this.fanBoundariesGroup.Font = new System.Drawing.Font("Arial Rounded MT Bold", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.fanBoundariesGroup.Location = new System.Drawing.Point(29, 267);
            this.fanBoundariesGroup.Name = "fanBoundariesGroup";
            this.fanBoundariesGroup.Size = new System.Drawing.Size(282, 179);
            this.fanBoundariesGroup.TabIndex = 16;
            this.fanBoundariesGroup.TabStop = false;
            this.fanBoundariesGroup.Text = "DC Fan";
            this.fanBoundariesGroup.Visible = false;
            this.fanBoundariesGroup.Enter += new System.EventHandler(this.groupBox1_Enter_1);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.fanReset);
            this.groupBox1.Controls.Add(this.fanOff);
            this.groupBox1.Controls.Add(this.fanOn);
            this.groupBox1.Location = new System.Drawing.Point(18, 30);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(218, 104);
            this.groupBox1.TabIndex = 18;
            this.groupBox1.TabStop = false;
            // 
            // fanReset
            // 
            this.fanReset.AutoSize = true;
            this.fanReset.Location = new System.Drawing.Point(16, 76);
            this.fanReset.Name = "fanReset";
            this.fanReset.Size = new System.Drawing.Size(87, 27);
            this.fanReset.TabIndex = 17;
            this.fanReset.TabStop = true;
            this.fanReset.Text = "Reset";
            this.fanReset.UseVisualStyleBackColor = true;
            this.fanReset.CheckedChanged += new System.EventHandler(this.radioButton2_CheckedChanged);
            // 
            // fanOff
            // 
            this.fanOff.AutoSize = true;
            this.fanOff.Location = new System.Drawing.Point(16, 48);
            this.fanOff.Name = "fanOff";
            this.fanOff.Size = new System.Drawing.Size(71, 27);
            this.fanOff.TabIndex = 16;
            this.fanOff.TabStop = true;
            this.fanOff.Text = "OFF";
            this.fanOff.UseVisualStyleBackColor = true;
            this.fanOff.CheckedChanged += new System.EventHandler(this.radioButton3_CheckedChanged);
            // 
            // fanOn
            // 
            this.fanOn.AutoSize = true;
            this.fanOn.Location = new System.Drawing.Point(16, 21);
            this.fanOn.Name = "fanOn";
            this.fanOn.Size = new System.Drawing.Size(62, 27);
            this.fanOn.TabIndex = 15;
            this.fanOn.TabStop = true;
            this.fanOn.Text = "ON";
            this.fanOn.UseVisualStyleBackColor = true;
            this.fanOn.CheckedChanged += new System.EventHandler(this.radioButton4_CheckedChanged);
            // 
            // button1
            // 
            this.button1.Font = new System.Drawing.Font("Arial Rounded MT Bold", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button1.Location = new System.Drawing.Point(598, 461);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(85, 33);
            this.button1.TabIndex = 21;
            this.button1.Text = "send";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Visible = false;
            this.button1.Click += new System.EventHandler(this.button1_Click_2);
            // 
            // statusLabel
            // 
            this.statusLabel.AutoSize = true;
            this.statusLabel.Font = new System.Drawing.Font("Arial Rounded MT Bold", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.statusLabel.Location = new System.Drawing.Point(213, 461);
            this.statusLabel.Name = "statusLabel";
            this.statusLabel.Size = new System.Drawing.Size(61, 20);
            this.statusLabel.TabIndex = 22;
            this.statusLabel.Text = "Status";
            this.statusLabel.Click += new System.EventHandler(this.statusLabel_Click);
            // 
            // button6
            // 
            this.button6.Location = new System.Drawing.Point(424, 480);
            this.button6.Name = "button6";
            this.button6.Size = new System.Drawing.Size(120, 23);
            this.button6.TabIndex = 23;
            this.button6.Text = "Change Mode";
            this.button6.UseVisualStyleBackColor = true;
            this.button6.Click += new System.EventHandler(this.button6_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(718, 515);
            this.Controls.Add(this.button6);
            this.Controls.Add(this.statusLabel);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.lampBoundariesGroup);
            this.Controls.Add(this.fanBoundariesGroup);
            this.Controls.Add(this.tempBoundariesGroup);
            this.Controls.Add(this.modeSelector);
            this.Controls.Add(this.modeLabel);
            this.Controls.Add(this.readBtn);
            this.Controls.Add(this.disconnectBtn);
            this.Controls.Add(this.connectBtn);
            this.Controls.Add(this.refreshBtn);
            this.Controls.Add(this.connectionStatus);
            this.Controls.Add(this.commSelector);
            this.Name = "Form1";
            this.Text = "Form1";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.Form1_FormClosed);
            this.Load += new System.EventHandler(this.Form1_Load);
            this.modeSelector.ResumeLayout(false);
            this.modeSelector.PerformLayout();
            this.tempBoundariesGroup.ResumeLayout(false);
            this.tempBoundariesGroup.PerformLayout();
            this.lampBoundariesGroup.ResumeLayout(false);
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.fanBoundariesGroup.ResumeLayout(false);
            this.fanBoundariesGroup.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ComboBox commSelector;
        private System.Windows.Forms.Label connectionStatus;
        private System.Windows.Forms.Button refreshBtn;
        private System.Windows.Forms.Button connectBtn;
        private System.Windows.Forms.Button disconnectBtn;
        private System.Windows.Forms.Button readBtn;
        private System.Windows.Forms.Label modeLabel;
        private System.Windows.Forms.GroupBox modeSelector;
        private System.Windows.Forms.RadioButton autoRBTN;
        private System.Windows.Forms.RadioButton manualRBTN;
        private System.Windows.Forms.TextBox LowerTemp;
        private System.Windows.Forms.TextBox upperTemp;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.GroupBox tempBoundariesGroup;
        private System.Windows.Forms.GroupBox lampBoundariesGroup;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox speedTextField;
        private System.Windows.Forms.GroupBox fanBoundariesGroup;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button speedSendBtn;
        private System.Windows.Forms.Label statusLabel;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.RadioButton radioButton1;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.RadioButton fanReset;
        private System.Windows.Forms.RadioButton fanOff;
        private System.Windows.Forms.RadioButton fanOn;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.RadioButton lampReset;
        private System.Windows.Forms.RadioButton lampOff;
        private System.Windows.Forms.RadioButton lampOn;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.Button button5;
        private System.Windows.Forms.Button button6;
    }
}

