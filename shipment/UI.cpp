#include "UI.h"

UI::UI() {
	playmode();
}

void UI::playmode()
{
	string s;
	cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
	cout << "--------------------------------------------Hallo-------------------------------------------------------" << endl;
	cout << "//////////////////////////////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;
	cout << "-----------------enter the mode you want to run on !-->>>>    (interactive,silence,step-by-step)" << endl;
	cin >> s;
	//while (s != "interactive" || s != "step-by-step" || s != "silence") {
	//	cout << "-----------------enter the mode you want to run on !-->>>>    (interactive,silence,step-by-step)" << endl;
	//	cin >> s;
	//}
	if (s == "interactive") {
		playInteractive();
	}
	if (s == "step-by-step") {
		playstep();
	}
	if (s == "silence") {
		playSilence();
	}
}

void UI::playInteractive()
{

}

void UI::playstep()
{

}

void UI::playSilence()
{

}

void UI::setMode(string s) {
	mode = s;
}

string UI::getMode()
{
	return mode;
}

