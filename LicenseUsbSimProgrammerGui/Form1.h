#pragma once


namespace LicenseUsbSimProgrammerGui
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary> 
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the 
	///          'Resource File Name' property for the managed resource compiler tool 
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public __gc class Form1 : public System::Windows::Forms::Form
	{	
	public:
		Form1(void)
		{
			InitializeComponent();

			m_consoleArguments = __gc new System::String(S"");
      m_fileNameConfigurationFile = __gc new System::String(
        S"S:\\projekte\\Perseus\\tools\\LicenseSimProgrammer\\ValidLicensesConfig.csv");
      m_fileNameConsoleApplication = __gc new System::String(
        S"S:\\projekte\\Perseus\\tools\\LicenseSimProgrammer\\S14_LicenseSimProgrammer.exe");
		}
  
	protected:
		void Dispose(Boolean disposing)
		{
			if (disposing && components)
			{
				components->Dispose();
			}
			__super::Dispose(disposing);
		}

	private: System::Windows::Forms::TextBox *  textBoxConsoleOutput;


	private: System::Windows::Forms::Button *  buttonAdd;
	private: System::Windows::Forms::Button *  buttonRemove;
	private: System::Windows::Forms::Button *  buttonBurnList;
	private: System::Windows::Forms::ListBox *  listBoxValidLicenses;
	private: System::Windows::Forms::ListBox *  listBoxLicensesToBeBurned;
	private: System::Windows::Forms::Button *  buttonProgram;
	private: System::Windows::Forms::Button *  buttonErase;
	private: System::Windows::Forms::Button *  buttonDump;
  private: System::Windows::Forms::Button *  buttonClear;
  private: System::Windows::Forms::ProgressBar *  progressBar;










  private: System::Windows::Forms::CheckBox *  checkBoxUserDefinedLicense;
  private: System::Windows::Forms::ComboBox *  comboBoxBinding;
  private: System::Windows::Forms::ComboBox *  comboBoxValidity;
  private: System::Windows::Forms::ComboBox *  comboBoxDirection;
  private: System::Windows::Forms::ComboBox *  comboBoxInstance;
  private: System::Windows::Forms::TextBox *  textBoxComponent;
  private: System::Windows::Forms::TextBox *  textBoxNumber;
  private: System::Windows::Forms::Button *  buttonBurnUserDefinedLicense;
  private: System::Windows::Forms::GroupBox *  groupBoxUserDefinedLicense;
  private: System::Windows::Forms::Label *  label1;
  private: System::Windows::Forms::Label *  label2;
  private: System::Windows::Forms::Label *  label3;
  private: System::Windows::Forms::Label *  label4;
  private: System::Windows::Forms::Label *  label5;
  private: System::Windows::Forms::Label *  label6;
  private: System::Windows::Forms::MainMenu *  mainMenu;
  private: System::Windows::Forms::MenuItem *  menuItemSettings;
  private: System::Windows::Forms::MenuItem *  menuItemConsoleApplication;
  private: System::Windows::Forms::MenuItem *  menuItemConfigurationFile;
  private: System::Windows::Forms::OpenFileDialog *  openFileDialogConsoleApplication;
  private: System::Windows::Forms::OpenFileDialog *  openFileDialogConfigurationFile;
  private: System::Windows::Forms::Button *  buttonInfo;
  private: System::Windows::Forms::Label *  label7;
  private: System::Windows::Forms::NumericUpDown *  numericUpDownQuantity;









	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container * components;

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
      System::Resources::ResourceManager *  resources = new System::Resources::ResourceManager(__typeof(LicenseUsbSimProgrammerGui::Form1));
      this->buttonBurnList = new System::Windows::Forms::Button();
      this->textBoxConsoleOutput = new System::Windows::Forms::TextBox();
      this->listBoxValidLicenses = new System::Windows::Forms::ListBox();
      this->listBoxLicensesToBeBurned = new System::Windows::Forms::ListBox();
      this->buttonAdd = new System::Windows::Forms::Button();
      this->buttonRemove = new System::Windows::Forms::Button();
      this->buttonProgram = new System::Windows::Forms::Button();
      this->buttonErase = new System::Windows::Forms::Button();
      this->buttonDump = new System::Windows::Forms::Button();
      this->buttonClear = new System::Windows::Forms::Button();
      this->progressBar = new System::Windows::Forms::ProgressBar();
      this->groupBoxUserDefinedLicense = new System::Windows::Forms::GroupBox();
      this->label6 = new System::Windows::Forms::Label();
      this->label5 = new System::Windows::Forms::Label();
      this->label4 = new System::Windows::Forms::Label();
      this->label3 = new System::Windows::Forms::Label();
      this->label2 = new System::Windows::Forms::Label();
      this->label1 = new System::Windows::Forms::Label();
      this->buttonBurnUserDefinedLicense = new System::Windows::Forms::Button();
      this->textBoxNumber = new System::Windows::Forms::TextBox();
      this->textBoxComponent = new System::Windows::Forms::TextBox();
      this->comboBoxInstance = new System::Windows::Forms::ComboBox();
      this->comboBoxDirection = new System::Windows::Forms::ComboBox();
      this->comboBoxValidity = new System::Windows::Forms::ComboBox();
      this->comboBoxBinding = new System::Windows::Forms::ComboBox();
      this->checkBoxUserDefinedLicense = new System::Windows::Forms::CheckBox();
      this->mainMenu = new System::Windows::Forms::MainMenu();
      this->menuItemSettings = new System::Windows::Forms::MenuItem();
      this->menuItemConsoleApplication = new System::Windows::Forms::MenuItem();
      this->menuItemConfigurationFile = new System::Windows::Forms::MenuItem();
      this->openFileDialogConsoleApplication = new System::Windows::Forms::OpenFileDialog();
      this->openFileDialogConfigurationFile = new System::Windows::Forms::OpenFileDialog();
      this->buttonInfo = new System::Windows::Forms::Button();
      this->label7 = new System::Windows::Forms::Label();
      this->numericUpDownQuantity = new System::Windows::Forms::NumericUpDown();
      this->groupBoxUserDefinedLicense->SuspendLayout();
      (__try_cast<System::ComponentModel::ISupportInitialize *  >(this->numericUpDownQuantity))->BeginInit();
      this->SuspendLayout();
      // 
      // buttonBurnList
      // 
      this->buttonBurnList->Anchor = System::Windows::Forms::AnchorStyles::Right;
      this->buttonBurnList->Location = System::Drawing::Point(568, 280);
      this->buttonBurnList->Name = S"buttonBurnList";
      this->buttonBurnList->Size = System::Drawing::Size(72, 24);
      this->buttonBurnList->TabIndex = 0;
      this->buttonBurnList->Text = S"Burn List";
      this->buttonBurnList->Click += new System::EventHandler(this, buttonStart_Click);
      // 
      // textBoxConsoleOutput
      // 
      this->textBoxConsoleOutput->Anchor = (System::Windows::Forms::AnchorStyles)((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left) 
        | System::Windows::Forms::AnchorStyles::Right);
      this->textBoxConsoleOutput->Font = new System::Drawing::Font(S"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)0);
      this->textBoxConsoleOutput->Location = System::Drawing::Point(8, 576);
      this->textBoxConsoleOutput->Multiline = true;
      this->textBoxConsoleOutput->Name = S"textBoxConsoleOutput";
      this->textBoxConsoleOutput->ReadOnly = true;
      this->textBoxConsoleOutput->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
      this->textBoxConsoleOutput->Size = System::Drawing::Size(712, 224);
      this->textBoxConsoleOutput->TabIndex = 1;
      this->textBoxConsoleOutput->Text = S"";
      // 
      // listBoxValidLicenses
      // 
      this->listBoxValidLicenses->Anchor = (System::Windows::Forms::AnchorStyles)((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
        | System::Windows::Forms::AnchorStyles::Left);
      this->listBoxValidLicenses->Location = System::Drawing::Point(8, 16);
      this->listBoxValidLicenses->Name = S"listBoxValidLicenses";
      this->listBoxValidLicenses->SelectionMode = System::Windows::Forms::SelectionMode::MultiExtended;
      this->listBoxValidLicenses->Size = System::Drawing::Size(272, 290);
      this->listBoxValidLicenses->TabIndex = 2;
      this->listBoxValidLicenses->DoubleClick += new System::EventHandler(this, listBoxValidLicenses_DoubleClick);
      // 
      // listBoxLicensesToBeBurned
      // 
      this->listBoxLicensesToBeBurned->Anchor = (System::Windows::Forms::AnchorStyles)((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
        | System::Windows::Forms::AnchorStyles::Right);
      this->listBoxLicensesToBeBurned->Location = System::Drawing::Point(368, 16);
      this->listBoxLicensesToBeBurned->Name = S"listBoxLicensesToBeBurned";
      this->listBoxLicensesToBeBurned->SelectionMode = System::Windows::Forms::SelectionMode::MultiExtended;
      this->listBoxLicensesToBeBurned->Size = System::Drawing::Size(272, 251);
      this->listBoxLicensesToBeBurned->TabIndex = 3;
      this->listBoxLicensesToBeBurned->DoubleClick += new System::EventHandler(this, listBoxLicensesToBeBurned_DoubleClick);
      // 
      // buttonAdd
      // 
      this->buttonAdd->Anchor = (System::Windows::Forms::AnchorStyles)((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
        | System::Windows::Forms::AnchorStyles::Right);
      this->buttonAdd->Image = (__try_cast<System::Drawing::Image *  >(resources->GetObject(S"buttonAdd.Image")));
      this->buttonAdd->Location = System::Drawing::Point(288, 16);
      this->buttonAdd->Name = S"buttonAdd";
      this->buttonAdd->Size = System::Drawing::Size(72, 32);
      this->buttonAdd->TabIndex = 4;
      this->buttonAdd->Click += new System::EventHandler(this, buttonAdd_Click);
      // 
      // buttonRemove
      // 
      this->buttonRemove->Anchor = (System::Windows::Forms::AnchorStyles)((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left) 
        | System::Windows::Forms::AnchorStyles::Right);
      this->buttonRemove->Image = (__try_cast<System::Drawing::Image *  >(resources->GetObject(S"buttonRemove.Image")));
      this->buttonRemove->Location = System::Drawing::Point(288, 272);
      this->buttonRemove->Name = S"buttonRemove";
      this->buttonRemove->Size = System::Drawing::Size(72, 32);
      this->buttonRemove->TabIndex = 5;
      this->buttonRemove->Click += new System::EventHandler(this, buttonRemove_Click);
      // 
      // buttonProgram
      // 
      this->buttonProgram->Anchor = (System::Windows::Forms::AnchorStyles)(System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right);
      this->buttonProgram->Location = System::Drawing::Point(648, 16);
      this->buttonProgram->Name = S"buttonProgram";
      this->buttonProgram->Size = System::Drawing::Size(72, 24);
      this->buttonProgram->TabIndex = 6;
      this->buttonProgram->Text = S"Program";
      this->buttonProgram->Click += new System::EventHandler(this, buttonProgram_Click);
      // 
      // buttonErase
      // 
      this->buttonErase->Anchor = (System::Windows::Forms::AnchorStyles)(System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right);
      this->buttonErase->Location = System::Drawing::Point(648, 48);
      this->buttonErase->Name = S"buttonErase";
      this->buttonErase->Size = System::Drawing::Size(72, 24);
      this->buttonErase->TabIndex = 7;
      this->buttonErase->Text = S"Erase";
      this->buttonErase->Click += new System::EventHandler(this, buttonErase_Click);
      // 
      // buttonDump
      // 
      this->buttonDump->Anchor = (System::Windows::Forms::AnchorStyles)(System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right);
      this->buttonDump->Location = System::Drawing::Point(648, 80);
      this->buttonDump->Name = S"buttonDump";
      this->buttonDump->Size = System::Drawing::Size(72, 24);
      this->buttonDump->TabIndex = 8;
      this->buttonDump->Text = S"Dump";
      this->buttonDump->Click += new System::EventHandler(this, buttonDump_Click);
      // 
      // buttonClear
      // 
      this->buttonClear->Anchor = (System::Windows::Forms::AnchorStyles)(System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left);
      this->buttonClear->Location = System::Drawing::Point(8, 808);
      this->buttonClear->Name = S"buttonClear";
      this->buttonClear->Size = System::Drawing::Size(72, 24);
      this->buttonClear->TabIndex = 9;
      this->buttonClear->Text = S"Clear";
      this->buttonClear->Click += new System::EventHandler(this, buttonClear_Click);
      // 
      // progressBar
      // 
      this->progressBar->Anchor = (System::Windows::Forms::AnchorStyles)((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left) 
        | System::Windows::Forms::AnchorStyles::Right);
      this->progressBar->Location = System::Drawing::Point(8, 320);
      this->progressBar->Name = S"progressBar";
      this->progressBar->Size = System::Drawing::Size(712, 23);
      this->progressBar->Step = 1;
      this->progressBar->TabIndex = 10;
      // 
      // groupBoxUserDefinedLicense
      // 
      this->groupBoxUserDefinedLicense->Anchor = (System::Windows::Forms::AnchorStyles)((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left) 
        | System::Windows::Forms::AnchorStyles::Right);
      this->groupBoxUserDefinedLicense->Controls->Add(this->label6);
      this->groupBoxUserDefinedLicense->Controls->Add(this->label5);
      this->groupBoxUserDefinedLicense->Controls->Add(this->label4);
      this->groupBoxUserDefinedLicense->Controls->Add(this->label3);
      this->groupBoxUserDefinedLicense->Controls->Add(this->label2);
      this->groupBoxUserDefinedLicense->Controls->Add(this->label1);
      this->groupBoxUserDefinedLicense->Controls->Add(this->buttonBurnUserDefinedLicense);
      this->groupBoxUserDefinedLicense->Controls->Add(this->textBoxNumber);
      this->groupBoxUserDefinedLicense->Controls->Add(this->textBoxComponent);
      this->groupBoxUserDefinedLicense->Controls->Add(this->comboBoxInstance);
      this->groupBoxUserDefinedLicense->Controls->Add(this->comboBoxDirection);
      this->groupBoxUserDefinedLicense->Controls->Add(this->comboBoxValidity);
      this->groupBoxUserDefinedLicense->Controls->Add(this->comboBoxBinding);
      this->groupBoxUserDefinedLicense->Controls->Add(this->checkBoxUserDefinedLicense);
      this->groupBoxUserDefinedLicense->Location = System::Drawing::Point(8, 360);
      this->groupBoxUserDefinedLicense->Name = S"groupBoxUserDefinedLicense";
      this->groupBoxUserDefinedLicense->Size = System::Drawing::Size(712, 200);
      this->groupBoxUserDefinedLicense->TabIndex = 11;
      this->groupBoxUserDefinedLicense->TabStop = false;
      this->groupBoxUserDefinedLicense->Text = S"UserDefinedLicense";
      // 
      // label6
      // 
      this->label6->Anchor = (System::Windows::Forms::AnchorStyles)(System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right);
      this->label6->Location = System::Drawing::Point(400, 120);
      this->label6->Name = S"label6";
      this->label6->TabIndex = 14;
      this->label6->Text = S"Number:";
      // 
      // label5
      // 
      this->label5->Anchor = (System::Windows::Forms::AnchorStyles)(System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right);
      this->label5->Location = System::Drawing::Point(400, 88);
      this->label5->Name = S"label5";
      this->label5->TabIndex = 13;
      this->label5->Text = S"Component:";
      // 
      // label4
      // 
      this->label4->Anchor = (System::Windows::Forms::AnchorStyles)(System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right);
      this->label4->Location = System::Drawing::Point(400, 56);
      this->label4->Name = S"label4";
      this->label4->TabIndex = 12;
      this->label4->Text = S"Instance:";
      // 
      // label3
      // 
      this->label3->Location = System::Drawing::Point(40, 120);
      this->label3->Name = S"label3";
      this->label3->TabIndex = 11;
      this->label3->Text = S"Direction:";
      // 
      // label2
      // 
      this->label2->Location = System::Drawing::Point(40, 88);
      this->label2->Name = S"label2";
      this->label2->TabIndex = 10;
      this->label2->Text = S"Validity:";
      // 
      // label1
      // 
      this->label1->Location = System::Drawing::Point(40, 56);
      this->label1->Name = S"label1";
      this->label1->TabIndex = 9;
      this->label1->Text = S"Binding:";
      // 
      // buttonBurnUserDefinedLicense
      // 
      this->buttonBurnUserDefinedLicense->Anchor = (System::Windows::Forms::AnchorStyles)(System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right);
      this->buttonBurnUserDefinedLicense->Location = System::Drawing::Point(624, 168);
      this->buttonBurnUserDefinedLicense->Name = S"buttonBurnUserDefinedLicense";
      this->buttonBurnUserDefinedLicense->TabIndex = 8;
      this->buttonBurnUserDefinedLicense->Text = S"Burn this!";
      this->buttonBurnUserDefinedLicense->Click += new System::EventHandler(this, buttonBurnUserDefinedLicense_Click);
      // 
      // textBoxNumber
      // 
      this->textBoxNumber->Anchor = (System::Windows::Forms::AnchorStyles)(System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right);
      this->textBoxNumber->Location = System::Drawing::Point(512, 120);
      this->textBoxNumber->Name = S"textBoxNumber";
      this->textBoxNumber->Size = System::Drawing::Size(120, 20);
      this->textBoxNumber->TabIndex = 7;
      this->textBoxNumber->Text = S"0";
      // 
      // textBoxComponent
      // 
      this->textBoxComponent->Anchor = (System::Windows::Forms::AnchorStyles)(System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right);
      this->textBoxComponent->Location = System::Drawing::Point(512, 88);
      this->textBoxComponent->Name = S"textBoxComponent";
      this->textBoxComponent->Size = System::Drawing::Size(120, 20);
      this->textBoxComponent->TabIndex = 6;
      this->textBoxComponent->Text = S"0x301";
      // 
      // comboBoxInstance
      // 
      this->comboBoxInstance->Anchor = (System::Windows::Forms::AnchorStyles)(System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right);
      System::Object* __mcTemp__1[] = new System::Object*[3];
      __mcTemp__1[0] = S"0";
      __mcTemp__1[1] = S"1";
      __mcTemp__1[2] = S"2";
      this->comboBoxInstance->Items->AddRange(__mcTemp__1);
      this->comboBoxInstance->Location = System::Drawing::Point(512, 56);
      this->comboBoxInstance->Name = S"comboBoxInstance";
      this->comboBoxInstance->Size = System::Drawing::Size(121, 21);
      this->comboBoxInstance->TabIndex = 4;
      this->comboBoxInstance->Text = S"0";
      // 
      // comboBoxDirection
      // 
      System::Object* __mcTemp__2[] = new System::Object*[2];
      __mcTemp__2[0] = S"Install";
      __mcTemp__2[1] = S"Uninstall";
      this->comboBoxDirection->Items->AddRange(__mcTemp__2);
      this->comboBoxDirection->Location = System::Drawing::Point(152, 120);
      this->comboBoxDirection->Name = S"comboBoxDirection";
      this->comboBoxDirection->Size = System::Drawing::Size(120, 21);
      this->comboBoxDirection->TabIndex = 3;
      this->comboBoxDirection->Text = S"Install";
      // 
      // comboBoxValidity
      // 
      System::Object* __mcTemp__3[] = new System::Object*[6];
      __mcTemp__3[0] = S"Permanent";
      __mcTemp__3[1] = S"Timer";
      __mcTemp__3[2] = S"EndDate";
      __mcTemp__3[3] = S"PerUsage";
      __mcTemp__3[4] = S"PerPatient";
      __mcTemp__3[5] = S"PerCase";
      this->comboBoxValidity->Items->AddRange(__mcTemp__3);
      this->comboBoxValidity->Location = System::Drawing::Point(152, 88);
      this->comboBoxValidity->Name = S"comboBoxValidity";
      this->comboBoxValidity->Size = System::Drawing::Size(121, 21);
      this->comboBoxValidity->TabIndex = 2;
      this->comboBoxValidity->Text = S"Permanent";
      // 
      // comboBoxBinding
      // 
      System::Object* __mcTemp__4[] = new System::Object*[3];
      __mcTemp__4[0] = S"NodeLocked";
      __mcTemp__4[1] = S"Moveable";
      __mcTemp__4[2] = S"Floating";
      this->comboBoxBinding->Items->AddRange(__mcTemp__4);
      this->comboBoxBinding->Location = System::Drawing::Point(152, 56);
      this->comboBoxBinding->Name = S"comboBoxBinding";
      this->comboBoxBinding->Size = System::Drawing::Size(121, 21);
      this->comboBoxBinding->TabIndex = 1;
      this->comboBoxBinding->Text = S"NodeLocked";
      // 
      // checkBoxUserDefinedLicense
      // 
      this->checkBoxUserDefinedLicense->Checked = true;
      this->checkBoxUserDefinedLicense->CheckState = System::Windows::Forms::CheckState::Checked;
      this->checkBoxUserDefinedLicense->Location = System::Drawing::Point(16, 24);
      this->checkBoxUserDefinedLicense->Name = S"checkBoxUserDefinedLicense";
      this->checkBoxUserDefinedLicense->Size = System::Drawing::Size(136, 24);
      this->checkBoxUserDefinedLicense->TabIndex = 0;
      this->checkBoxUserDefinedLicense->Text = S"User defined License";
      this->checkBoxUserDefinedLicense->CheckedChanged += new System::EventHandler(this, checkBoxUserDefinedLicense_CheckedChanged);
      // 
      // mainMenu
      // 
      System::Windows::Forms::MenuItem* __mcTemp__5[] = new System::Windows::Forms::MenuItem*[1];
      __mcTemp__5[0] = this->menuItemSettings;
      this->mainMenu->MenuItems->AddRange(__mcTemp__5);
      // 
      // menuItemSettings
      // 
      this->menuItemSettings->Index = 0;
      System::Windows::Forms::MenuItem* __mcTemp__6[] = new System::Windows::Forms::MenuItem*[2];
      __mcTemp__6[0] = this->menuItemConsoleApplication;
      __mcTemp__6[1] = this->menuItemConfigurationFile;
      this->menuItemSettings->MenuItems->AddRange(__mcTemp__6);
      this->menuItemSettings->Text = S"&Settings";
      // 
      // menuItemConsoleApplication
      // 
      this->menuItemConsoleApplication->Index = 0;
      this->menuItemConsoleApplication->Text = S"Console &Application...";
      this->menuItemConsoleApplication->Click += new System::EventHandler(this, menuItemConsoleApplication_Click);
      // 
      // menuItemConfigurationFile
      // 
      this->menuItemConfigurationFile->Index = 1;
      this->menuItemConfigurationFile->Text = S"Configuration &File...";
      this->menuItemConfigurationFile->Click += new System::EventHandler(this, menuItemConfigurationFile_Click);
      // 
      // buttonInfo
      // 
      this->buttonInfo->Anchor = (System::Windows::Forms::AnchorStyles)(System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right);
      this->buttonInfo->Location = System::Drawing::Point(648, 112);
      this->buttonInfo->Name = S"buttonInfo";
      this->buttonInfo->Size = System::Drawing::Size(72, 24);
      this->buttonInfo->TabIndex = 12;
      this->buttonInfo->Text = S"Info";
      this->buttonInfo->Click += new System::EventHandler(this, buttonInfo_Click);
      // 
      // label7
      // 
      this->label7->Anchor = System::Windows::Forms::AnchorStyles::Right;
      this->label7->Location = System::Drawing::Point(368, 280);
      this->label7->Name = S"label7";
      this->label7->Size = System::Drawing::Size(136, 16);
      this->label7->TabIndex = 13;
      this->label7->Text = S"Quantity for each License:";
      // 
      // numericUpDownQuantity
      // 
      this->numericUpDownQuantity->Anchor = System::Windows::Forms::AnchorStyles::Right;
      this->numericUpDownQuantity->Location = System::Drawing::Point(512, 280);
      System::Int32 __mcTemp__7[] = new System::Int32[4];
      __mcTemp__7[0] = 120;
      __mcTemp__7[1] = 0;
      __mcTemp__7[2] = 0;
      __mcTemp__7[3] = 0;
      this->numericUpDownQuantity->Maximum = System::Decimal(__mcTemp__7);
      this->numericUpDownQuantity->Name = S"numericUpDownQuantity";
      this->numericUpDownQuantity->Size = System::Drawing::Size(48, 20);
      this->numericUpDownQuantity->TabIndex = 14;
      System::Int32 __mcTemp__8[] = new System::Int32[4];
      __mcTemp__8[0] = 1;
      __mcTemp__8[1] = 0;
      __mcTemp__8[2] = 0;
      __mcTemp__8[3] = 0;
      this->numericUpDownQuantity->Value = System::Decimal(__mcTemp__8);
      // 
      // Form1
      // 
      this->AutoScaleBaseSize = System::Drawing::Size(5, 13);
      this->ClientSize = System::Drawing::Size(728, 859);
      this->Controls->Add(this->numericUpDownQuantity);
      this->Controls->Add(this->label7);
      this->Controls->Add(this->buttonInfo);
      this->Controls->Add(this->groupBoxUserDefinedLicense);
      this->Controls->Add(this->progressBar);
      this->Controls->Add(this->buttonClear);
      this->Controls->Add(this->buttonDump);
      this->Controls->Add(this->buttonErase);
      this->Controls->Add(this->buttonProgram);
      this->Controls->Add(this->buttonRemove);
      this->Controls->Add(this->buttonAdd);
      this->Controls->Add(this->listBoxLicensesToBeBurned);
      this->Controls->Add(this->listBoxValidLicenses);
      this->Controls->Add(this->textBoxConsoleOutput);
      this->Controls->Add(this->buttonBurnList);
      this->Icon = (__try_cast<System::Drawing::Icon *  >(resources->GetObject(S"$this.Icon")));
      this->Menu = this->mainMenu;
      this->MinimumSize = System::Drawing::Size(736, 893);
      this->Name = S"Form1";
      this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
      this->Text = S"LicenseUsbSimProgrammerGui";
      this->Load += new System::EventHandler(this, Form1_Load);
      this->groupBoxUserDefinedLicense->ResumeLayout(false);
      (__try_cast<System::ComponentModel::ISupportInitialize *  >(this->numericUpDownQuantity))->EndInit();
      this->ResumeLayout(false);

    }

	
	private: __value enum State {
             Idle, Busy, CouldGetBusy};
	private: __value enum Event {
             BurnList, BurnUserDefinedLic, Erase, Program, Dump, Info, Remove, AddLicensesToBurnList, RemoveLicensesFromBurnList};
	private: System::String* m_consoleArguments;
  private: System::String* m_fileNameConsoleApplication;
  private: System::String* m_fileNameConfigurationFile;
	private: State m_myState;

	private:
		System::Void SetEvent(Event e)
		{

      if(e == Event::AddLicensesToBurnList)
      {
        while(this->listBoxValidLicenses->SelectedItem)
			  {
				  this->listBoxLicensesToBeBurned->Items->Add(
					  this->listBoxValidLicenses->SelectedItem);
				  this->listBoxValidLicenses->SetSelected(
					  this->listBoxValidLicenses->SelectedIndex,
					  false);
			  }
        return;
      }

      if(e ==  Event::RemoveLicensesFromBurnList)
      {
			  while(this->listBoxLicensesToBeBurned->SelectedItem)
			  {
				  this->listBoxLicensesToBeBurned->Items->Remove(
					  this->listBoxLicensesToBeBurned->SelectedItem);
			  }
        return;
      }

      this->Cursor->Current = System::Windows::Forms::Cursors::WaitCursor;
      this->progressBar->Value = 0;

			if(e == Event::BurnList)
			{
        int numOfLics = this->listBoxLicensesToBeBurned->Items->Count;
        this->progressBar->Maximum = numOfLics;
        this->progressBar->Value = 0;
				for(int i = 0; i < numOfLics; i++)
				{
          m_consoleArguments = System::String::Format("--quantity {0}", this->numericUpDownQuantity->Value.ToString());
          m_consoleArguments = System::String::Format("{0} --add NodeLocked:Permanent:", m_consoleArguments);
          System::String* s = ";";
          System::Char delimiter[] = s->ToCharArray();
          System::String* split[] =
            this->listBoxLicensesToBeBurned->Items->get_Item(i)->ToString()->Split(
              delimiter);
          m_consoleArguments = System::String::Format(
            "{0}{1}:0:0x301:{2}", m_consoleArguments, split[1], split[2]);

          this->UpdateConsoleOutput(m_consoleArguments);
					this->StartAndWaitForProcess();
          this->progressBar->Value = (i + 1);
				}
			}
			else
			{
				switch(e)
				{
				case Event::BurnUserDefinedLic:
          m_consoleArguments = System::String::Format("--add {0}:{1}:{2}",
            this->comboBoxBinding->Text, this->comboBoxValidity->Text,
            this->comboBoxDirection->Text);
          m_consoleArguments = System::String::Format("{0}:{1}:{2}", m_consoleArguments,
            this->comboBoxInstance->Text, this->textBoxComponent->Text);
          m_consoleArguments = System::String::Format("{0}:{1}", m_consoleArguments,
            this->textBoxNumber->Text);
					break;
				case Event::Erase:
					m_consoleArguments = S"--erase";
					break;
				case Event::Program:
					m_consoleArguments = S"--program";
					break;
				case Event::Dump:
					m_consoleArguments = S"--dump";
					break;
        case Event::Info:
          m_consoleArguments = S"--info";
          break;
				default:
					return;
				}
        this->UpdateConsoleOutput(m_consoleArguments);
				this->StartAndWaitForProcess();
			}

      this->Cursor->Current = System::Windows::Forms::Cursors::Arrow;
		}

  private:
    System::Void StartAndWaitForProcess()
    {
		  try
		  {
			  System::Diagnostics::Process* proc = __gc new System::Diagnostics::Process();
			  proc->StartInfo->Arguments = m_consoleArguments;
        proc->StartInfo->FileName = m_fileNameConsoleApplication;
			  proc->StartInfo->UseShellExecute = false;
			  proc->StartInfo->CreateNoWindow = true;
			  proc->StartInfo->RedirectStandardOutput = true;
        proc->StartInfo->RedirectStandardError = true;
  			
        this->SetState(State::Busy);
			  proc->Start();
			  proc->WaitForExit();
        this->SetState(State::Idle);
  			
			  this->UpdateConsoleOutput(
				  proc->StandardOutput->ReadToEnd());
        this->UpdateConsoleOutput(
          proc->StandardError->ReadToEnd());
			  m_consoleArguments = System::String::Empty;
		  }
		  catch(System::ComponentModel::Win32Exception* exp)
		  {
			  this->textBoxConsoleOutput->AppendText(exp->Message);
		  }
    }

	private:
		System::Void UpdateConsoleOutput(System::String* text)
		{
      if(System::String::Empty != text)
      {
        this->textBoxConsoleOutput->AppendText(System::String::Format(
          "{0}{1}", text, System::Environment::NewLine));
			  this->Update();
      }
		}

  private:
    System::Void SetState(State newState)
    {
      switch(newState)
      {
      case State::Idle:
        this->buttonAdd->Enabled = true;
        this->buttonBurnList->Enabled = true;
        this->buttonDump->Enabled = true;
        this->buttonClear->Enabled = true;
        this->buttonErase->Enabled = true;
        this->buttonProgram->Enabled = true;
        this->buttonRemove->Enabled = true;
        this->buttonInfo->Enabled = true;
        this->groupBoxUserDefinedLicense->Enabled = true;
        break;
      case State::Busy:
        this->buttonAdd->Enabled = false;
        this->buttonBurnList->Enabled = false;
        this->buttonDump->Enabled = false;
        this->buttonClear->Enabled = false;
        this->buttonErase->Enabled = false;
        this->buttonProgram->Enabled = false;
        this->buttonRemove->Enabled = false;
        this->buttonInfo->Enabled = false;
        this->groupBoxUserDefinedLicense->Enabled = false;
        break;
      case State::CouldGetBusy:
        break;
      default:
        break;
      }
    }

  private:
    System::Void UpdateListBoxValidLicenses()
    {
      System::IO::StreamReader* reader = __gc new System::IO::StreamReader(
        System::IO::File::OpenRead(m_fileNameConfigurationFile));

      this->listBoxValidLicenses->Items->Clear();

      System::String* input;
      while((input = reader->ReadLine()) != NULL)
      {
        if(input != System::String::Empty)
        {
          this->listBoxValidLicenses->Items->Add(input);
        }
      }
    }

	private:
		System::Void buttonStart_Click(System::Object *  sender, System::EventArgs *  e)
		{
			this->SetEvent(Event::BurnList);
		}

	private:
		System::Void buttonAdd_Click(System::Object *  sender, System::EventArgs *  e)
		{
      this->SetEvent(Event::AddLicensesToBurnList);
		}

	private:
		System::Void buttonRemove_Click(System::Object *  sender, System::EventArgs *  e)
		{
      this->SetEvent(Event::RemoveLicensesFromBurnList);
		}

	private:
		System::Void buttonProgram_Click(System::Object *  sender, System::EventArgs *  e)
		{
			this->SetEvent(Event::Program);
		}

	private:
		System::Void buttonErase_Click(System::Object *  sender, System::EventArgs *  e)
		{
			this->SetEvent(Event::Erase);
		}

	private:
		System::Void buttonDump_Click(System::Object *  sender, System::EventArgs *  e)
		{
			this->SetEvent(Event::Dump);
		}

  private:
    System::Void buttonClear_Click(System::Object *  sender, System::EventArgs *  e)
    {
      this->textBoxConsoleOutput->Clear();
    }

  private:
    System::Void Form1_Load(System::Object *  sender, System::EventArgs *  e)
    {
      this->UpdateListBoxValidLicenses();
      this->checkBoxUserDefinedLicense->Checked = false;
    }

  private:
    System::Void checkBoxUserDefinedLicense_CheckedChanged(System::Object *  sender, System::EventArgs *  e)
    {
      bool checked = this->checkBoxUserDefinedLicense->Checked;
      
      this->comboBoxBinding->Enabled = checked;
      this->comboBoxDirection->Enabled = checked;
      this->comboBoxInstance->Enabled = checked;
      this->comboBoxValidity->Enabled = checked;
      this->textBoxComponent->Enabled = checked;
      this->textBoxNumber->Enabled = checked;
      this->buttonBurnUserDefinedLicense->Enabled = checked;
    }

  private:
    System::Void buttonBurnUserDefinedLicense_Click(System::Object *  sender, System::EventArgs *  e)
    {
      this->SetEvent(Event::BurnUserDefinedLic);
    }

  private:
    System::Void menuItemConsoleApplication_Click(System::Object *  sender, System::EventArgs *  e)
    {
      if(this->openFileDialogConsoleApplication->ShowDialog() ==
        System::Windows::Forms::DialogResult::OK)
      {
        m_fileNameConsoleApplication =
          this->openFileDialogConsoleApplication->get_FileName();
      }
    }

  private:
    System::Void menuItemConfigurationFile_Click(System::Object *  sender, System::EventArgs *  e)
    {
      if(this->openFileDialogConfigurationFile->ShowDialog() ==
        System::Windows::Forms::DialogResult::OK)
      {
        m_fileNameConfigurationFile = 
          this->openFileDialogConfigurationFile->get_FileName();
        this->UpdateListBoxValidLicenses();
      }
    }

  private:
    System::Void buttonInfo_Click(System::Object *  sender, System::EventArgs *  e)
    {
      this->SetEvent(Event::Info);
    }

  private:
    System::Void listBoxValidLicenses_DoubleClick(System::Object *  sender, System::EventArgs *  e)
    {
      this->SetEvent(Event::AddLicensesToBurnList);
    }

  private:
    System::Void listBoxLicensesToBeBurned_DoubleClick(System::Object *  sender, System::EventArgs *  e)
    {
      this->SetEvent(Event::RemoveLicensesFromBurnList);
    }

};
}


