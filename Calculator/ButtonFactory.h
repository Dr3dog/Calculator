#pragma once
#include "cMain.h"
class ButtonFactory
{
private:
    cMain* addy = nullptr;
    int width = 0;
public:
    ButtonFactory(cMain* _addy, int _width);
    ~ButtonFactory();
    wxButton* CreateNumberButtons(int _buttonval, int _x, int _y);
    wxButton* CreateFunctionNumber(wxString _funcs[], int _index, int _x, int _y);
};

