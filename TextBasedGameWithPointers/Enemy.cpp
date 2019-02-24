#include "Enemy.h"
#include "Utilities.h"

Enemy::Enemy()
{
	this->types = { "goblin", "rat", "spider" };
	generateEnemy();
	setEnemyHP();
	setEnemyDamage();
	enemysTurn = false;
}

Enemy::~Enemy()
{
}

void Enemy::generateEnemy()
{
	Enemy::type = Enemy::types[Utilities::chooseRandom(Enemy::types.size())];
	Enemy::numberOfEnemies = Utilities::chooseRandom(3) + 1;
	Enemy::hasShield = Utilities::chooseRandom(2);
}

void Enemy::setEnemyHP()
{
	this->maxHP = 5 * this->numberOfEnemies;
	this->hp = this->maxHP;
}

void Enemy::setEnemyDamage()
{
	this->enemyDamage = 1 * this->numberOfEnemies;
}

int Enemy::getExperienceReward()
{
	return this->numberOfEnemies * 25;
}

int Enemy::getCoinReward()
{
	return this->numberOfEnemies * 10;
}


