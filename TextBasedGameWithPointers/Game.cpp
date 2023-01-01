#include "Game.h"
#include "Dialogue.h"
#include "main.h"


Game::Game()
{
	inGameLoop = true;
}

Game::~Game()
{
}

void Game::processEndOfTheDay()
{
	++this->player.dayCounter;
	this->player.resetHP();
	this->player.reset_playerDidNotLeave();
}

void Game::printManual()
{
	cout << "-----------MANUAL-----------\n"
		<< "Everything in all caps on this page can be entered into the action bar prompt.\n"
		<< "Currently there are 3 places to go to in this game: HOME, TRAIN, and QUEST.\n"
		<< "No QUEST have been built so i made the location a dead end.\n"
		<< "TRAIN is somewhere you can go to level up.\n"
		<< "HOME is a safeplace and a HUB of sorts.\n"
		<< "To progress through dialogue boxes use \"Enter\"\n"
		<< "prompt for user input is always precursored by the \"action bar\" seen below.\n"
		<< "Example: \"___________________________________________________________________PLAYER:\"\n"
		<< "the \"HOME\" command should always return you to home.\n"
		<< "STATS will show player stats.\n"
		<< "--------End of Manual-------\n";
}

void Game::processEnemysTurn(Enemy* enemy)
{
	if (enemy->enemysTurn)
	{
		this->player.hp -= enemy->enemyDamage;
		Dialogue::printGameMessage("Your enemy retaliates!");
		enemy->enemysTurn = false;
	}
}

void Game::processEnemyBeingDefeated(Enemy* enemy)
{
	if (enemy->hp <= 0)
	{
		Dialogue::printGameMessage("You win!");
		this->player.showLootAfterBattle(enemy);
		this->player.playerIsLeaving();
	}
}

void Game::printTrainingHUD(Enemy *enemy)
{
	string playerHPbar = this->player.getHPbar();
	string enemyHPbar = enemy->getHPbar();
	string moreThanOneCheck;
	(enemy->numberOfEnemies > 1) ? moreThanOneCheck = to_string(enemy->numberOfEnemies) + " - "
		: moreThanOneCheck = "";

	cout << endl << this->player.name << ":\n"
		<< playerHPbar << endl
		<< moreThanOneCheck << enemy->type << Dialogue::pluralCheck(&(*enemy)) << endl
		<< enemyHPbar << endl;
}

void Game::handlePlayerInput_homeLoop()
{
	string playerInput = Dialogue::getPlayerInput();

	if (playerInput == "HOME")
	{
		Dialogue::printGameMessage("> You are already HOME.");
	}
	else if (playerInput == "MANUAL")
	{
		this->printManual();
	}
	else if (playerInput == "QUEST")
	{
		Dialogue::printGameMessage("> No Quests available.");

	}
	else if (playerInput == "TRAIN")
	{
		this->gameContext = playerInput;
		trainingLoop(this);
	}
	else if (playerInput == "STATS")
	{
		this->player.printPlayerStats();
	}
	else if (playerInput == "QUIT")
	{
		this->inGameLoop = false;
		Dialogue::printGameMessage("> Leaving Game... ");
	}
	else
	{
		Dialogue::printGameMessage("> Cannot do this action from HOME.");
	}
}

void Game::handlePlayerInput_trainingLoop(Enemy *enemy)
{
	string playerInput;
	playerInput = Dialogue::getPlayerInput();

	if (playerInput == "HOME" || playerInput == "QUIT" || playerInput == "RUN")
	{
		this->player.playerIsLeaving();
	}
	else if (this->player.isValidMove(playerInput))
	{
		this->player.doDamageOnEnemy(playerInput, &(*enemy));
		enemy->enemysTurn = true;
	}
	else if (playerInput == "MOVES")
	{
		this->player.printAvailableAttacks();
	}
	else if (playerInput == "")
	{
		Dialogue::printDialogue("You foolishly hesitate and your enemy gives you a good smacking around...");
		Dialogue::printGameMessage("After the struggle, you've made some room between you and your oppenent.");
		enemy->enemysTurn = true;
	}
	else
	{
		Dialogue::printGameMessage("You cannot do that during battle!");
	}
}

bool Game::handlePlayerInput_lookForEnemyLoop(Game *game, Enemy *enemyToFight, Enemy *foundEnemy, int *encounterCounter)
{
	string playerInput = Dialogue::getPlayerInput();
	if (playerInput == "HOME" || playerInput == "QUIT" || (playerInput == "N" && (*encounterCounter >= 3)))
	{
		game->player.playerIsLeaving();
		return false;
	}
	else if (playerInput == "N")
	{
		++(*encounterCounter);
        foundEnemy = new Enemy();
		Dialogue::printDialogue("You avoid the possible conflict and head in a different direction.");
        return true;
	}
	else if (playerInput == "Y")
	{
		*enemyToFight = *foundEnemy;
		Dialogue::printGameMessage("To view your move set, say \"MOVES\".");
		return false;
	}
	else
	{
		Dialogue::printDialogue("You waited to long. The "
			+ foundEnemy->type
			+ Dialogue::pluralCheck(&(*foundEnemy))
			+ " ran out of sight.");
		++(*encounterCounter);
        return false;
	}
}
