#pragma once
#include "wx/wx.h"

class cMain : public wxFrame
{
public:
	cMain();
	~cMain();

public:
	int nHeight = 4;
	int nWidth = 5;
	wxButton** btn = nullptr;
	wxTextCtrl *m_txt1 = nullptr;
	void OnButtonClicked(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
};

