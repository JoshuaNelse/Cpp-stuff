#pragma once
#include <string>
#include <vector>
#include "combatObject.h"



using namespace std;

class Enemy : public combatObject
{
public:
	Enemy();
	~Enemy();

	string type;
	vector<string> types;
	int numberOfEnemies;
	int enemyDamage;
	bool hasShield;
	bool enemysTurn;

	void generateEnemy();
	void setEnemyHP();
	void setEnemyDamage();

	int getExperienceReward();
	int getCoinReward();
};

