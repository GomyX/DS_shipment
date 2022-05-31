#include "UI.h"

UI::UI() {
	playmode();
}

void UI::playmode()
{
	string s;
	cout << "//////////////////////////////////////////////////////" << endl;
	cout << "enter the mode you want to run on !    (interactive,silence,step-by-step)" << endl;
	cin >> s;
	setMode(s);
}

void UI::setMode(string s) {
	mode = s;
}

string UI::getMode()
{
	return mode;
}

