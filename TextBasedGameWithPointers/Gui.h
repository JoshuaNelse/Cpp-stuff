#pragma once
#include <iostream>
#include <string>
using namespace std;

class Gui
{
public:
	string actionBar;
	void initActionBar();
	void printActionBar();
	void setActionbar(string);

	Gui();
	~Gui();
};

