#pragma once
#include <iostream>
#include <string>
#include "Enemy.h"


using namespace std;

class Dialogue
{
private:
	static string makeUppercase(string);
	static void waitForUserToPressEnter();

public:
	Dialogue();
	~Dialogue();

	static void printDialogue(string);
	static void printGameMessage(string);
	static string getPlayerInput();
	static string pluralCheck(Enemy*);
	static string itOrThemCheck(Enemy*);
};

