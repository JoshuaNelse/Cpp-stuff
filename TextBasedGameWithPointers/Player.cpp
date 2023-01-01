#include "Player.h"
#include "Dialogue.h"

Player::Player()
{
	dayCounter = 0;
	level = 0;
	exp = 0;
	coins = 0;
	playerDidNotLeave = true;
	setExpToNextLevel();
	setMaxHP();
	resetHP(); 
}

Player::~Player()
{
}

void Player::reset_playerDidNotLeave()
{
	this->playerDidNotLeave = true;
}

void Player::playerIsLeaving()
{
	this->playerDidNotLeave = false;
}

void Player::doDamageOnEnemy(string playersAttack, Enemy *enemy)
{
	auto damageMap = this->PlayersWeapon.damageMap;
	string playersCurrentWeapon = this->PlayersWeapon.weaponType;

	enemy->hp -= damageMap[playersCurrentWeapon];
	Dialogue::printGameMessage("You landed your " + playersAttack + "!\n");
}

void Player::setCoins(int *addCoins)
{
	this->coins += *addCoins;
}

void Player::setExp(int *addExp)
{
	this->exp += *addExp;
	if (this->exp >= this->expToNextLevel)
	{
		Player::levelUP();
	}
}

void Player::levelUP()
{
	this->level += 1;
	this->setExpToNextLevel();
	this->setMaxHP();
	Dialogue::printGameMessage("You are now level " + to_string(this->level) + "!");
}

void Player::resetHP()
{
	this->hp = this->maxHP;
}

void Player::setExpToNextLevel()
{
	this->expToNextLevel = 100 + (this->level * 100 * this->level);
}

void Player::setMaxHP()
{
	this->maxHP = 10 + (this->level * 3);
}

void Player::setName()
{
	this->name = Dialogue::getPlayerInput();
}

void Player::processPlayerBeingDefeated()
{
	if (this->hp <= 0)
	{
		Dialogue::printDialogue("You are overcome by your enemy.");
		Dialogue::printGameMessage("You wake up hours later and notice you're missing your coins");
		int coinsStolen = this->coins * -1;
		this->setCoins(&coinsStolen);
		this->playerIsLeaving();
	}
}

bool Player::isValidMove(string playerInput)
{
	auto validMoveSet = this->PlayersWeapon.attackTypes[this->PlayersWeapon.weaponType];

	for (auto validMove : validMoveSet)
	{
		if (playerInput == validMove)
		{
			return true;
		}
	}
	return false;
}

void Player::showLootAfterBattle(Enemy *enemy)
{
	int coins = enemy->getCoinReward();
	int exp = enemy->getExperienceReward();

	this->setCoins(&coins);
	this->setExp(&exp);

	cout << "----------LOOT----------\n"
		<< "Coins gained: " << coins << endl
		<< "Total coins: " << this->coins << endl
		<< "EXP gained: " << exp << endl
		<< "Total EXP: " << this->exp << endl
		<< "EXP to next level: " << this->expToNextLevel << endl
		<< "------------------------\n";

	Dialogue::printDialogue("Press Enter to Continue...");
}

void Player::printPlayerStats()
{
	cout << "---------STATS----------\n"
		<< "Player name . :  " << this->name << endl
		<< "Level . . . . :  " << this->level << endl
		<< "HP  . . . . . :  " << this->hp << "/" << this->maxHP << endl
		<< "EXP Progress  :  " << this->exp << "/" << this->expToNextLevel << endl
		<< "Coins . . . . :  " << this->coins << endl
		<< "Weapon  . . . :  " << this->PlayersWeapon.weaponType << endl
		<< "Day . . . . . :  " << (this->dayCounter + 1) << endl
		<< "------------------------\n";
}

void Player::printAvailableAttacks()
{
	auto attackTypes = this->PlayersWeapon.attackTypes[this->PlayersWeapon.weaponType];
	cout << "---------MOVES----------\n";
	cout << "weapon: " << this->PlayersWeapon.weaponType << endl;

	for (int i = 0; i < attackTypes.size(); i++)
	{
		cout << i + 1 << ".) " << attackTypes[i] << endl;
	}
	cout << "------------------------\n";
}

string Player::getHPbar()
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
