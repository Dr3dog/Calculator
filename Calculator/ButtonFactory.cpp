#include "ButtonFactory.h"
#include "cMain.h"


using namespace std;

ButtonFactory::ButtonFactory(cMain* _addy, int _width) {
	addy = _addy;
	width = _width;
}
ButtonFactory::~ButtonFactory() {
}
wxButton* ButtonFactory::CreateNumberButtons(int _buttonval, int _x, int _y) {
	int xCoords = 25 + (155 * _x);
	int yCoords = 125 * (_y + 1);
	string label = to_string(_buttonval);
	return new wxButton(addy, 100 + (_y * width + _x), label, wxPoint(xCoords, yCoords), wxSize(100, 50));
}
wxButton* ButtonFactory::CreateFunctionNumber(wxString _funcs[], int _index, int _x, int _y) {
	int xCoords = 25 + (155 * _x);
	int yCoords = 125 * (_y + 1);
	wxString label = _funcs[_index];
	return new wxButton(addy, 100 + (_y * width + _x), label, wxPoint(xCoords, yCoords), wxSize(100, 50));
}
