#include "Gui.h"

Gui::Gui()
{
	initActionBar();
}

Gui::~Gui()
{
}

void Gui::initActionBar()
{
	Gui::actionBar = "___________________________________________________________________PLAYER:";
}

void Gui::printActionBar()
{
	cout << "\n" << Gui::actionBar;
}

void Gui::setActionbar(string gameContext)
{
	Gui::initActionBar();
	for (int i = 0; i < gameContext.size(); i++)
	{
		Gui::actionBar[i + 50] = gameContext[i];
	}
}