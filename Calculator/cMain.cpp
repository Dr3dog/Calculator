#include "cMain.h"
wxBEGIN_EVENT_TABLE(cMain, wxFrame)
EVT_BUTTON(10001, OnButtonClicked)
wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(30, 30), wxSize(800, 600)) {
	// = new wxButton(this, 10001, "1", wxPoint(25, 100), wxSize(75, 75));
	//m_txt1 = new wxTextCtrl(this, wxID_ANY, "text box", wxPoint(25, 10), wxSize(725, 75));
	btn = new wxButton * [nWidth * nHeight];
	wxGridSizer* grid = new wxGridSizer(nWidth, nHeight, 0, 0);

	for (size_t x = 0; x < nWidth; x++)
	{
		for (size_t y = 0; y < nHeight; y++)
		{
			btn[y * nWidth + x] = new wxButton(this, 100 + (y*nWidth +x));
			grid->Add(btn[y * nWidth + x], 1, wxEXPAND | wxALL);
		}
	}

	this->SetSizer(grid);
	grid->Layout();
}

cMain::~cMain() {

}

void cMain::OnButtonClicked(wxCommandEvent& evt) {

	evt.Skip();
}