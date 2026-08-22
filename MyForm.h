#pragma once
#include <cstdlib>
#include <ctime>
#include "Serpiente.h"
#include "NODOMANZA.h"

namespace Serpientejuego
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		SERPIENTE* SESI;
		NODOMANZA* manza;
		bool iniciar, up, down, left, rigth;
		Bitmap^ fondo;
		Bitmap^ serp;
		Bitmap^ manzana;
		Bitmap^ n1;
		Bitmap^ n2;
		Bitmap^ n3;
		Bitmap^ n4;
		Bitmap^ ro;
		Graphics^ g;
		BufferedGraphics^ gb;

	private: System::Windows::Forms::Timer^ timer;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ iNICIARToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ rapidoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ intermedioToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ lentoToolStripMenuItem;

		   // Controles para el Menú Principal
	private: System::Windows::Forms::Panel^ panelMenu;
	private: System::Windows::Forms::Label^ lblTitulo;
	private: System::Windows::Forms::Label^ lblDificultad;
	private: System::Windows::Forms::ComboBox^ cmbDificultad;
	private: System::Windows::Forms::Button^ btnEmpezar;

	private: System::ComponentModel::IContainer^ components;

	public:
		MyForm(void) // constructor 
		{
			SESI = new SERPIENTE();
			manza = new NODOMANZA(0, 25);
			fondo = gcnew Bitmap("fondo.png");
			serp = gcnew Bitmap("nodo.png");
			manzana = gcnew Bitmap("manzana.png");
			ro = gcnew Bitmap("rojo.png");
			n1 = gcnew Bitmap("nodo1.png");
			n2 = gcnew Bitmap("nodo2.png");
			n3 = gcnew Bitmap("nodo3.png");
			n4 = gcnew Bitmap("nodo4.png");
			up = down = left = rigth = false;

			// Inicia desactivado hasta presionar "Empezar"
			iniciar = false;

			InitializeComponent();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}

			if (SESI != nullptr)
			{
				delete SESI;
			}

			if (manza != nullptr)
			{
				delete manza;
			}
		}

	private:
#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->iNICIARToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->rapidoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->intermedioToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lentoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->panelMenu = (gcnew System::Windows::Forms::Panel());
			this->lblTitulo = (gcnew System::Windows::Forms::Label());
			this->lblDificultad = (gcnew System::Windows::Forms::Label());
			this->cmbDificultad = (gcnew System::Windows::Forms::ComboBox());
			this->btnEmpezar = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->panelMenu->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer
			// 
			this->timer->Interval = 200;
			this->timer->Tick += gcnew System::EventHandler(this, &MyForm::timer_Tick);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->iNICIARToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(600, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// iNICIARToolStripMenuItem
			// 
			this->iNICIARToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->rapidoToolStripMenuItem,
					this->intermedioToolStripMenuItem, this->lentoToolStripMenuItem
			});
			this->iNICIARToolStripMenuItem->Name = L"iNICIARToolStripMenuItem";
			this->iNICIARToolStripMenuItem->Size = System::Drawing::Size(60, 20);
			this->iNICIARToolStripMenuItem->Text = L"INICIAR";
			// 
			// rapidoToolStripMenuItem
			// 
			this->rapidoToolStripMenuItem->Name = L"rapidoToolStripMenuItem";
			this->rapidoToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			this->rapidoToolStripMenuItem->Text = L"Rapido";
			this->rapidoToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::rapidoToolStripMenuItem_Click);
			// 
			// intermedioToolStripMenuItem
			// 
			this->intermedioToolStripMenuItem->Name = L"intermedioToolStripMenuItem";
			this->intermedioToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			this->intermedioToolStripMenuItem->Text = L"Intermedio";
			this->intermedioToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::intermedioToolStripMenuItem_Click);
			// 
			// lentoToolStripMenuItem
			// 
			this->lentoToolStripMenuItem->Name = L"lentoToolStripMenuItem";
			this->lentoToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			this->lentoToolStripMenuItem->Text = L"Lento";
			this->lentoToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::lentoToolStripMenuItem_Click);
			// 
			// panelMenu
			// 
			this->panelMenu->BackColor = System::Drawing::Color::DarkGreen;
			this->panelMenu->Controls->Add(this->lblTitulo);
			this->panelMenu->Controls->Add(this->lblDificultad);
			this->panelMenu->Controls->Add(this->cmbDificultad);
			this->panelMenu->Controls->Add(this->btnEmpezar);
			this->panelMenu->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelMenu->Location = System::Drawing::Point(0, 24);
			this->panelMenu->Name = L"panelMenu";
			this->panelMenu->Size = System::Drawing::Size(600, 601);
			this->panelMenu->TabIndex = 1;
			// 
			// lblTitulo
			// 
			this->lblTitulo->AutoSize = true;
			this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 22, System::Drawing::FontStyle::Bold));
			this->lblTitulo->ForeColor = System::Drawing::Color::White;
			this->lblTitulo->Location = System::Drawing::Point(34, 101);
			this->lblTitulo->Name = L"lblTitulo";
			this->lblTitulo->Size = System::Drawing::Size(540, 41);
			this->lblTitulo->TabIndex = 0;
			this->lblTitulo->Text = L"¡Bienvenido al Juego de la Serpiente!";
			// 
			// lblDificultad
			// 
			this->lblDificultad->AutoSize = true;
			this->lblDificultad->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->lblDificultad->ForeColor = System::Drawing::Color::White;
			this->lblDificultad->Location = System::Drawing::Point(215, 220);
			this->lblDificultad->Name = L"lblDificultad";
			this->lblDificultad->Size = System::Drawing::Size(172, 21);
			this->lblDificultad->TabIndex = 1;
			this->lblDificultad->Text = L"Seleccione la Dificultad:";
			this->lblDificultad->Click += gcnew System::EventHandler(this, &MyForm::lblDificultad_Click);
			// 
			// cmbDificultad
			// 
			this->cmbDificultad->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbDificultad->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			this->cmbDificultad->FormattingEnabled = true;
			this->cmbDificultad->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Lento", L"Intermedio", L"Rápido" });
			this->cmbDificultad->Location = System::Drawing::Point(215, 255);
			this->cmbDificultad->Name = L"cmbDificultad";
			this->cmbDificultad->Size = System::Drawing::Size(170, 28);
			this->cmbDificultad->TabIndex = 2;
			// 
			// btnEmpezar
			// 
			this->btnEmpezar->BackColor = System::Drawing::Color::ForestGreen;
			this->btnEmpezar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnEmpezar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
			this->btnEmpezar->ForeColor = System::Drawing::Color::White;
			this->btnEmpezar->Location = System::Drawing::Point(215, 330);
			this->btnEmpezar->Name = L"btnEmpezar";
			this->btnEmpezar->Size = System::Drawing::Size(170, 50);
			this->btnEmpezar->TabIndex = 3;
			this->btnEmpezar->Text = L"Empezar Juego";
			this->btnEmpezar->UseVisualStyleBackColor = false;
			this->btnEmpezar->Click += gcnew System::EventHandler(this, &MyForm::btnEmpezar_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(600, 625);
			this->Controls->Add(this->panelMenu);
			this->Controls->Add(this->menuStrip1);
			this->KeyPreview = true;
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Serpientejuego";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::FrmJuego_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::FrmJuego_KeyDown);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->panelMenu->ResumeLayout(false);
			this->panelMenu->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void btnEmpezar_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Ajustar la velocidad según la selección del ComboBox
		if (cmbDificultad->SelectedIndex == 0) // Lento
			timer->Interval = 300;
		else if (cmbDificultad->SelectedIndex == 1) // Intermedio
			timer->Interval = 200;
		else if (cmbDificultad->SelectedIndex == 2) // Rápido
			timer->Interval = 100;

		// Ocultar la pantalla de bienvenida y arrancar la partida
		panelMenu->Visible = false;
		iniciar = true;
		timer->Enabled = true;
		this->Focus(); // Asegurar que el teclado responda de inmediato
	}

	private: System::Void FrmJuego_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
	{
		g = this->CreateGraphics();
		BufferedGraphicsContext^ bft = BufferedGraphicsManager::Current;

		gb = bft->Allocate(g, this->ClientRectangle);
	}

	private: System::Void FrmJuego_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
	{
		// Ignorar teclas de movimiento mientras el menú esté activo
		if (!iniciar) return;

		if (e->KeyCode == Keys::Up && down == false)
		{
			up = true;
			down = false;
			left = false;
			rigth = false;
		}
		if (e->KeyCode == Keys::Down && up == false)
		{
			up = false;
			down = true;
			left = false;
			rigth = false;
		}
		if (e->KeyCode == Keys::Left && rigth == false)
		{
			up = false;
			down = false;
			left = true;
			rigth = false;
		}
		if (e->KeyCode == Keys::Right && left == false)
		{
			up = false;
			down = false;
			left = false;
			rigth = true;
		}
	}

	private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		int puntos = SESI->puntos();
		this->Text = "Puntos: " + puntos.ToString();

		manza->setviva(!SESI->comer(manza->x, manza->y));

		if (iniciar)
		{
			if (up == true)
			{
				if (SESI->getposicion_y() - 50 >= 0)
					SESI->Mover(SESI->getposicion_x(), SESI->getposicion_y() - 50, manza->getviva());
				else
					SESI->setperder(true);
			}
			if (down == true)
			{
				if (SESI->getposicion_y() + 50 <= 600)
					SESI->Mover(SESI->getposicion_x(), SESI->getposicion_y() + 50, manza->getviva());
				else
					SESI->setperder(true);
			}
			if (left == true)
			{
				if (SESI->getposicion_x() - 50 >= 0)
					SESI->Mover(SESI->getposicion_x() - 50, SESI->getposicion_y(), manza->getviva());
				else
					SESI->setperder(true);
			}
			if (rigth == true)
			{
				if (SESI->getposicion_x() + 50 <= 550)
					SESI->Mover(SESI->getposicion_x() + 50, SESI->getposicion_y(), manza->getviva());
				else
					SESI->setperder(true);
			}

			gb->Graphics->DrawImage(fondo, 0, 25, 600, 600);

			if (manza->getviva() == false)
			{
				manza->x = (rand() % 12) * 50;
				manza->y = (rand() % 12) * 50 + 25;
			}
			manza->Dibujar(gb, manzana);
			SESI->Dibujar(gb, serp, ro, n1, n2, n3, n4);
			gb->Render(g);

			if (SESI->getperder() == true)
			{
				timer->Enabled = false;

				MessageBox::Show("¡Game Over! Conseguiste " + puntos.ToString() + " puntos.", "Fin del Juego");

				delete SESI;
				SESI = new SERPIENTE();

				up = down = left = rigth = false;

				// Al perder, volvemos a mostrar el menú principal
				iniciar = false;
				panelMenu->Visible = true;
				return;
			}
		}
	}

	private: System::Void rapidoToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		timer->Interval = 100;
	}
	private: System::Void intermedioToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		timer->Interval = 200;
	}
	private: System::Void lentoToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		timer->Interval = 300;
	}
	private: System::Void lblDificultad_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
