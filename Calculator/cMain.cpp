#include "cMain.h"
#include <string>
#include "ButtonFactory.h"
using namespace std;
wxBEGIN_EVENT_TABLE(cMain, wxFrame)
EVT_BUTTON(10001, OnButtonClicked)
wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(30, 30), wxSize(800, 600)) {
	// = new wxButton(this, 10001, "1", wxPoint(25, 100), wxSize(75, 75));
	m_txt1 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(25, 25), wxSize(725, 75));
	btn = new wxButton * [nWidth * nHeight];
	wxString funcButtons[10] = { "Mod","Bin","Hex","Dec","C","+","-","*","/","=" };
	ButtonFactory testing(this,nWidth);
	int x = 0;
	int y = 0;
	for (size_t i = 0; i < 10; i++)
	{
		btn[y * nWidth + x] = testing.CreateNumberButtons(i, x, y);
		btn[y * nWidth + x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::OnButtonClicked, this);
		if (x == 4)
		{
			y++;
			x = 0;
		}
		else
		{
			x++;
		}
	}
	y = 2;
	x = 0;
	for (size_t j = 0; j < 10; j++)
	{
		btn[y * nWidth + x] = testing.CreateFunctionNumber(funcButtons, j, x, y);
		btn[y * nWidth + x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::OnButtonClicked, this);
		if (x == 4)
		{
			y++;
			x = 0;
		}
		else
		{
			x++;
		}
	}
	/*int numberButtons = 0;
	int funcIndex = 0;
	string funcButtons[10] = { "Mod","Bin","Hex","Dec","C","+","-","*","/","=" };
	for (size_t x = 0; x < nWidth; x++, numberButtons++)
	{
		for (size_t y = 0; y < nHeight; y++)
		{
			int xCoords = 25 + (155 * x);
			int yCoords = 125 * (y + 1);
			if (y == 0)
			{
				string label = to_string(numberButtons);
				btn[y * nWidth + x] = new wxButton(this, 100 + (y * nWidth + x), label, wxPoint(xCoords, yCoords), wxSize(100, 50));
			}
			else if (y == 1)
			{
				string label = to_string(numberButtons + 5);
				btn[y * nWidth + x] = new wxButton(this, 100 + (y * nWidth + x), label, wxPoint(xCoords, yCoords), wxSize(100, 50));
			}
			else
			{
				btn[y * nWidth + x] = new wxButton(this, 100 + (y * nWidth + x), funcButtons[funcIndex], wxPoint(xCoords, yCoords), wxSize(100, 50));
				funcIndex++;
			}
			btn[y * nWidth + x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::OnButtonClicked, this);
		}
	}*/
}

cMain::~cMain() {
	delete[] btn;
}

void cMain::OnButtonClicked(wxCommandEvent& evt) {
	//gets coords of the button
	int x = (evt.GetId() - 100) % nWidth;
	int y = (evt.GetId() - 100) / nWidth;
	int index = y * nWidth + x;
	m_txt1->AppendText(btn[index]->GetLabel());
	evt.Skip();
}