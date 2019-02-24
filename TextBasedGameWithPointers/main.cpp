#include "main.h"

int main()
{
	Game game = {};
	initStory(&game);

	while (game.inGameLoop)
	{
		game.gui.setActionbar("HOME");
		game.gui.printActionBar();
		game.handlePlayerInput_homeLoop();
	}
	return 0;
}

void initStory(Game* game)
{
	Dialogue::printDialogue("A long long time ago . . .");
	Dialogue::printDialogue("Yada yada yada . . . Lets skip this part. ");
	Dialogue::printGameMessage("What is your name?");
	game->gui.printActionBar();
	game->player.setName();
	Dialogue::printDialogue("Your character has been created \"" + game->player.name + "\" Have fun!\n");
	Dialogue::printGameMessage("You can always open the manual using the \"MANUAL\" command");
}

void trainingLoop(Game* game)
{
	game->gui.setActionbar(game->gameContext);

	Enemy enemyToFight;
	bool inBattleLoop = findBattle(&(*game), &enemyToFight);

	while (inBattleLoop && game->player.playerDidNotLeave)
	{
		game->processEnemysTurn(&enemyToFight);
		game->printTrainingHUD(&enemyToFight);
		game->gui.printActionBar();
		game->handlePlayerInput_trainingLoop(&enemyToFight);
		game->player.processPlayerBeingDefeated();
		game->processEnemyBeingDefeated(&enemyToFight);
	}
	Dialogue::printGameMessage("You head home for the day.");
	game->processEndOfTheDay();
}

bool findBattle(Game* game, Enemy* enemyToFight)
{
	int encounterCounter = 1;
	Dialogue::printDialogue("You make your way out into the woods to train...");
	bool playerSaysNo = true;
	while (playerSaysNo)
	{
		Enemy foundEnemy = {};
		Dialogue::printGameMessage("After some time you spot "
			+ to_string(foundEnemy.numberOfEnemies)
			+ " "
			+ foundEnemy.type
			+ Dialogue::pluralCheck(&foundEnemy)
			+ ". Do you want to challenge "
			+ Dialogue::itOrThemCheck(&foundEnemy));
		Dialogue::printGameMessage("Y or N ?");
		game->gui.printActionBar();
		playerSaysNo = game->handlePlayerInput_lookForEnemyLoop(&(*game), &(*enemyToFight), &foundEnemy, &encounterCounter);
	}
	return (encounterCounter >= 3 || !game->player.playerDidNotLeave) ? false : true;
}