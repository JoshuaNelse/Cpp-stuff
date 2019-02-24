#pragma once
#include <iostream>
#include <string>
#include "Gui.h"
#include "Player.h"
#include "Enemy.h"

using namespace std;

class Game
{
public:
	Game();
	~Game();

	const string main = "main";
	const string quest = "quest";
	const string battle = "battle";

	void processEndOfTheDay();
	void printManual();
	void printTrainingHUD(Enemy*);
	void handlePlayerInput_homeLoop();
	void handlePlayerInput_trainingLoop(Enemy*);
	void processEnemysTurn(Enemy*);
	void processEnemyBeingDefeated(Enemy*);

	bool handlePlayerInput_lookForEnemyLoop(Game*, Enemy*, Enemy*, int*);
	bool inGameLoop;

	Player player;
	Gui gui;
	string gameContext;
};

