
#pragma once

#include <iostream>
#include <string>
#include "FBullCowGame.h"

//To mimic UNREAL engine types
using FText = std::string;
using int32 = int;

void printGameSummary();
void printIntro();
void playGameLoop();
FText getValidGuess();
bool askToplayAgain();

FBullCowGame BCGame;

int main()
{
	bool bPlayGame = true;
	while (bPlayGame)
	{
		printIntro();
		playGameLoop();
		bPlayGame = askToplayAgain();
	}
	return 0;
}

void playGameLoop()
{
	BCGame.reset();
	while (!BCGame.isGameWon() && BCGame.getCurrentTry() <= BCGame.getMaxTries())
	{		
		FText playersGuess = getValidGuess();
		FBullCowCount bullCowCount = BCGame.submitValidGuess(playersGuess);
		std::cout << "bulls: " << bullCowCount.bulls << std::endl;
		std::cout << "cows: " << bullCowCount.cows << std::endl << std::endl;	
	}
	printGameSummary();
}

void printGameSummary()
{
	if (BCGame.isGameWon())
	{
		std::cout << "Congratulations! You won the Game.\n\n";
	}
	else
	{
		std::cout << "You lost. Better luck next time!\n";
	}
}

void printIntro()
{
	const int32 WORD_LENGTH = BCGame.getHiddenWord().size();
	std::cout << "Welcome to Bulls and Cows, a fun word game!\n";
	std::cout << std::endl;
	std::cout << "                       " << std::endl;
	std::cout << "          }___{         ___ " << std::endl;
	std::cout << "          (o o)        (o o) " << std::endl;
	std::cout << "   /-------\\ /          \\ /-------\\ " << std::endl;
	std::cout << "  / | BULL |O            O| COW  | \\ " << std::endl;
	std::cout << " *  |-,--- |              |------|  * " << std::endl;
	std::cout << "    ^      ^              ^      ^ " << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n\n";
}

FText getValidGuess()
{
	FText playerGuess;
	EGuessValidity status = EGuessValidity::Invalid;
	while (status != EGuessValidity::Valid)
	{
		std::cout << "Try " << BCGame.getCurrentTry() << "/" << BCGame.getMaxTries() << " - Enter your guess: ";
		std::getline(std::cin, playerGuess);
		status = BCGame.isValidGuess(playerGuess);
		BCGame.printGuessValidationErrors(status);
	}
	return BCGame.makeLowerCase(playerGuess);
}

bool askToplayAgain()
{
	std::cout << "play again with the same hidden word? (y/n) ";
	FText playerResponse;
	std::getline(std::cin, playerResponse);
	std::cout << std::endl;
	return (toupper(playerResponse[0]) == 'Y') ? true: false;
}
