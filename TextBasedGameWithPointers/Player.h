#pragma once
#include <iostream>
#include <string>
#include "Weapon.h"
#include "Enemy.h"
#include "Dialogue.h"

using namespace std;

class Player
{
public:
	Player();
	~Player();

	string name;
	int level;
	int exp;
	int expToNextLevel;
	int coins;
	int dayCounter;
    int hp;
    int maxHP;
	bool playerDidNotLeave;

	Weapon PlayersWeapon = Weapon("none");

	void setCoins(int*);
	void setExp(int*);
	void setExpToNextLevel();
	void setMaxHP();
	void setName();

	void levelUP();
	void resetHP();
	void showLootAfterBattle(Enemy*);
	void printPlayerStats();
	void doDamageOnEnemy(string, Enemy*);
	void processPlayerBeingDefeated();
	void printAvailableAttacks();
	void reset_playerDidNotLeave();
	void playerIsLeaving();
    
    string getHPbar();

	bool isValidMove(string);
};

