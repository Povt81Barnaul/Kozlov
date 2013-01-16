#pragma once
#include "StdAfx.h"
#include "Field.h"
#include "Player.h"


namespace MyFootball {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::IO;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	
	/// @class Form1
	/// This is the main form for application
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private: 
		/// "Start" button
		System::Windows::Forms::Button^  startButton;
		/// Panel for drawing
		private: System::Windows::Forms::Panel^  drawPanel;
		/// "Exit" button
		System::Windows::Forms::Button^  exitButton;
		/// String which displays game score
		System::Windows::Forms::Label^  scoreLabel;
		/// Blue team string
		System::Windows::Forms::Label^  blueLabel;
		/// Red team string
		System::Windows::Forms::Label^  redLabel;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->startButton = (gcnew System::Windows::Forms::Button());
			this->drawPanel = (gcnew System::Windows::Forms::Panel());
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->scoreLabel = (gcnew System::Windows::Forms::Label());
			this->blueLabel = (gcnew System::Windows::Forms::Label());
			this->redLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// startButton
			// 
			this->startButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->startButton->Location = System::Drawing::Point(12, 12);
			this->startButton->Name = L"startButton";
			this->startButton->Size = System::Drawing::Size(86, 28);
			this->startButton->TabIndex = 1;
			this->startButton->Text = L"Старт";
			this->startButton->UseVisualStyleBackColor = true;
			this->startButton->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// drawPanel
			// 
			this->drawPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"drawPanel.BackgroundImage")));
			this->drawPanel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->drawPanel->Location = System::Drawing::Point(12, 73);
			this->drawPanel->Name = L"drawPanel";
			this->drawPanel->Size = System::Drawing::Size(600, 400);
			this->drawPanel->TabIndex = 3;
			// 
			// exitButton
			// 
			this->exitButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->exitButton->Location = System::Drawing::Point(526, 12);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(86, 28);
			this->exitButton->TabIndex = 4;
			this->exitButton->Text = L"Выход";
			this->exitButton->UseVisualStyleBackColor = true;
			this->exitButton->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// scoreLabel
			// 
			this->scoreLabel->AutoSize = true;
			this->scoreLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->scoreLabel->Location = System::Drawing::Point(290, 46);
			this->scoreLabel->Name = L"scoreLabel";
			this->scoreLabel->Size = System::Drawing::Size(50, 24);
			this->scoreLabel->TabIndex = 7;
			this->scoreLabel->Text = L"0 : 0";
			// 
			// blueLabel
			// 
			this->blueLabel->AutoSize = true;
			this->blueLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->blueLabel->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->blueLabel->Location = System::Drawing::Point(192, 46);
			this->blueLabel->Name = L"blueLabel";
			this->blueLabel->Size = System::Drawing::Size(67, 24);
			this->blueLabel->TabIndex = 9;
			this->blueLabel->Text = L"Синие";
			// 
			// redLabel
			// 
			this->redLabel->AutoSize = true;
			this->redLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->redLabel->ForeColor = System::Drawing::Color::Red;
			this->redLabel->Location = System::Drawing::Point(356, 46);
			this->redLabel->Name = L"redLabel";
			this->redLabel->Size = System::Drawing::Size(88, 24);
			this->redLabel->TabIndex = 10;
			this->redLabel->Text = L"Красные";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(621, 486);
			this->Controls->Add(this->redLabel);
			this->Controls->Add(this->blueLabel);
			this->Controls->Add(this->scoreLabel);
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->drawPanel);
			this->Controls->Add(this->startButton);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"Form1";
			this->Text = L"Футбольный симулятор";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: 
	/// Players list
	List<Player^>^ players;
	/// Player's threads list
	List<Thread^>^ iThread;
	/// Random number generator
	Random^ rand;
	/// Pictureboxes which used for drawing players and ball
	List<PictureBox^>^ picBox;
	/// Football field
	Field* field; 
	/// Main drawing thread
	Thread^ oThread;
	/// Mutex handle
	HANDLE hMutex;
	/// Running game flag
	bool FlagPlay;
	/// Blue's score
	int score1;
	/// Red's score
	int score2;
	/// @name Resources
	/// {@
	static String^ bluePlayerImage = "1.png"; 
	static String^ redPlayerImage = "2.png"; 
	static String^ ballImage = "ball.png"; 
	/// @}
public: 
	/// Draws field and players
	System::Void DrawField() {
		while(1) {
			 WaitForSingleObject(hMutex, INFINITE);
             Thread::BeginCriticalRegion();
             try {
				//обработка положения мяча
				 if (field->position[0].X <= 15 && field->position[0].Y >= 100 && field->position[0].Y <= 300) {
					 field->position[0].X = 290;
					 field->position[0].Y = 190;
					 score2++;
					 this->scoreLabel->Text = score1.ToString() + " : " + score2.ToString();
				 }
				 else if (field->position[0].X >= 565 && field->position[0].Y >= 100 && field->position[0].Y <= 300) {
					 field->position[0].X = 290;
					 field->position[0].Y = 190;
					 score1++;
					 this->scoreLabel->Text = score1.ToString() + " : " + score2.ToString();
				 }
				 else if(field->position[0].X <= 0) {
					 field->position[0].X = 5;
				 }
				 else if (field->position[0].X >= 580) {
					 field->position[0].X = 575;
				 }
				 else if (field->position[0].Y >= 380) {
					 field->position[0].Y = 375;
				 }
				 else if (field->position[0].Y <= 0) {
					 field->position[0].Y = 5;
				 }
				 this->picBox[0]->Location = System::Drawing::Point(field->position[0].X, field->position[0].Y);
				 //обработка положения игроков
				 for (int i=1; i<=22; i++) {
					 for (int j=i+1;  j<=22; j++) {
						 int a = (field->position[i].X - field->position[j].X) *
								 (field->position[i].X - field->position[j].X) +
								 (field->position[i].Y - field->position[j].Y) *
								 (field->position[i].Y - field->position[j].Y);
						 if (a < 500) {//произошло столкновение
							 a = int(sqrt(double(a)));
							 field->position[i].X += 10 * (field->position[i].X - field->position[j].X) / a;
							 field->position[i].Y += 10 * (field->position[i].Y - field->position[j].Y) / a;
							 field->position[j].X -= 10 * (field->position[i].X - field->position[j].X) / a;
							 field->position[j].Y -= 10 * (field->position[i].Y - field->position[j].Y) / a;
						 }
					 }
				 }
				 for (int i=1; i<=22; i++) {
					 if (field->position[i].X <= 0) {
						 field->position[i].X = 5;
					 }
					 else if (field->position[i].X >= 580) {
						 field->position[i].X = 575;
					 }
					 else if (field->position[i].Y >= 380) {
						 field->position[i].Y = 375;
					 }
					 else if (field->position[i].Y <= 0) {
						 field->position[i].Y = 5;
					 }
					 this->picBox[i]->Location = System::Drawing::Point(field->position[i].X, field->position[i].Y);
				 }
             }
             __finally {
                 Thread::EndCriticalRegion();
             }
			 ReleaseMutex(hMutex);
             //Thread::Sleep(300);
		}
	}

private: 
	/// Main form loaded
	/// @param sender
	/// @param e
	System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		FlagPlay = false;
		field = new Field();
		this->picBox = gcnew List<PictureBox^>();
		this->players = gcnew List<Player^>();
		this->iThread = gcnew List<Thread^>();
		rand = gcnew Random();
		score1 = score2 = 0;

		//первоначальная расстановка
		for(int i=1; i<=22; i++) {
			if (i%2) 
				field->position[i].X = rand->Next(0, 290);
			else 
				field->position[i].X = rand->Next(290, 580);
			field->position[i].Y = rand->Next(0, 380);

			players->Add(gcnew Player(i, (i % 2 == 1), rand->Next(2, 4), field, hMutex));
			iThread->Add(gcnew Thread(gcnew ThreadStart(players[i-1], &Player::Play)));
		}
		
		//первоначальная отрисовка
		this->picBox->Add(gcnew System::Windows::Forms::PictureBox());
		this->drawPanel->Controls->Add(this->picBox[0]);
		this->picBox[0]->Location = System::Drawing::Point(field->position[0].X, field->position[0].Y);
		this->picBox[0]->Size = System::Drawing::Size(20, 20);
		
		this->SetStyle(ControlStyles::SupportsTransparentBackColor, true);
		this->picBox[0]->BackColor = Color::Transparent;
		this->picBox[0]->Load(ballImage);
		
		for(int i=1; i<=22; i++) {
			this->picBox->Add(gcnew System::Windows::Forms::PictureBox());
			this->drawPanel->Controls->Add(this->picBox[i]);
			this->picBox[i]->Location = System::Drawing::Point(field->position[i].X, field->position[i].Y);
			this->picBox[i]->Size = System::Drawing::Size(20, 20);
			this->picBox[i]->BackColor = Color::Transparent;

			if (i % 2)
				 this->picBox[i]->Load(bluePlayerImage);
			else 
				 this->picBox[i]->Load(redPlayerImage);
		}
	}

private: 
	/// Start button press
	/// @param sender
	/// @param e
	System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		FlagPlay=true;
		this->startButton->Enabled = false;
		oThread = gcnew Thread(gcnew ThreadStart(this, &Form1::DrawField));
		oThread->Start();
		for (int i=0; i<22; i++) {
			iThread[i]->Start();
		}
	}

private: 
	/// Exit button press
	/// @param sender
	/// @param e
	System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		if(FlagPlay) {
			oThread->Abort();
			for (int i=0; i<22; i++) {
				iThread[i]->Abort();
			}
		}
		this->Close();
	}
};
}

