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
    int randoNum = Utilities::chooseRandom(int(Enemy::types.size()));
	Enemy::type = Enemy::types[randoNum];
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

string Enemy::getHPbar()
{
    int hpBarLength = this->maxHP > 50 ? 50 : this->maxHP;
    string hpBarString = "";
    float hpRemaingingPercent = float(this->hp)/float(this->maxHP);
    
    for (int i = 0; i <= hpBarLength ; i++) {
        
        auto barRemainingPercent = float(i)/float(hpBarLength);
        if ( hpRemaingingPercent >= barRemainingPercent ) {
            hpBarString += "/";
        } else {
            hpBarString += " ";
        }
    }
    return "|" + hpBarString + "|";
}

int Enemy::getCoinReward()
{
    return this->numberOfEnemies * 10;
}


