#include "Dialogue.h"

Dialogue::Dialogue()
{
}

Dialogue::~Dialogue()
{
}

string Dialogue::makeUppercase(string input)
{
	for (auto &letter : input)
	{
		letter = toupper(letter);
	}
	return input;
}

void Dialogue::waitForUserToPressEnter()
{
	cin.get();
}

void Dialogue::printDialogue(string dialogue)
{
	printGameMessage(dialogue);
	Dialogue::waitForUserToPressEnter();
}

void Dialogue::printGameMessage(string message)
{
	cout << message << endl << endl;
}

string Dialogue::getPlayerInput()
{
	string input;
	getline(cin, input);
	return Dialogue::makeUppercase(input);
}

string Dialogue::pluralCheck(Enemy *enemy)
{
	if (enemy->numberOfEnemies > 1)
	{
		return "s";
	}
	else
	{
		return  "";
	}
}

string Dialogue::itOrThemCheck(Enemy * enemy)
{
	if (enemy->numberOfEnemies > 1)
	{
		return "them?";
	}
	else
	{
		return "it?";
	}
}
