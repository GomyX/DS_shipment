#pragma once
#include <iostream>
using namespace std;
class UI
{
private:
	string mode;
public:
	UI();
	void setMode(string s);
	string getMode();
	void playmode();

	void playInteractive();
	void playstep();
	void playSilence();
};

