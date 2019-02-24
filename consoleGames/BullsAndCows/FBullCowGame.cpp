#pragma once

#include "FBullCowGame.h"
#include <iostream>
#include <vector>

FBullCowGame::FBullCowGame()
{
	this->reset();
}

void FBullCowGame::reset()
{
	constexpr int32 MAX_TRIES = 8;
	constexpr int32 FIRST_TRY = 1;
	const FString HIDDEN_WORD = "wizard"; //This must be an isogram 

	this->maxTries = MAX_TRIES;
	this->CurrentTry = FIRST_TRY;
	this->hiddenWord = HIDDEN_WORD;
}

int32 FBullCowGame::getMaxTries() const
{
	TMap<int32, int32> wordLengthTomaxTriesMap{ {3,5}, {4,6}, {5,8}, {6,10}, {7,15} };
	return wordLengthTomaxTriesMap[getHiddenWord().size()];
}

int32 FBullCowGame::getCurrentTry() const
{
	return this->CurrentTry;
}

FString FBullCowGame::getHiddenWord() const
{
	return this->hiddenWord;
}

bool FBullCowGame::isGameWon() const
{
	return this->bGameIsWon;
}

bool FBullCowGame::isIsogram(FString playerGuess) const
{
	TVector<char> previousLetters;
	for (char letter: playerGuess)
	{
		for (char previousLetter: previousLetters)
		{
			if (letter == previousLetter)
			{
				return false;
			}
		}
		previousLetters.push_back(letter);
	}
	return true;
}

EGuessValidity FBullCowGame::isValidGuess(FString guess) const
{
	EGuessValidity validity = EGuessValidity::Valid;
	(this->isIsogram(guess)) ? EGuessValidity::Valid : validity = EGuessValidity::Not_Isogram;
	(this->getHiddenWord().size() == guess.size()) ? EGuessValidity::Valid : validity = EGuessValidity::Not_correctLength;
	return validity;
}

void FBullCowGame::printGuessValidationErrors(EGuessValidity status)
{
	switch (status)
	{
	case EGuessValidity::Not_correctLength:
		std::cout << "Please enter a " << this->getHiddenWord().size() << " letter word.\n\n";
		break;
	case EGuessValidity::Not_Isogram:
		std::cout << "Please enter a word without repeating letters\n\n";
		break;
	default:
		break;
	}
}

void FBullCowGame::incrementCurrentTry()
{
	++(this->CurrentTry);
}

FBullCowCount FBullCowGame::submitValidGuess(FString validGuess)
{
	this->incrementCurrentTry();
	FBullCowCount bullCowCount;
	FString hiddenWord = this->getHiddenWord();
	
	for (int32 i = 0; i < hiddenWord.size(); ++i)
	{
		for (int32 j = 0; j < validGuess.size(); ++j)
		{
			if (hiddenWord[i] == validGuess[j]) {
				(i == j) ? ++bullCowCount.bulls : ++bullCowCount.cows;
			}
		}
	}
	this->submitGameIsWonStatus(bullCowCount);
	return bullCowCount;
}

void FBullCowGame::submitGameIsWonStatus(FBullCowCount bullCowCount)
{
	int32 hiddenWordSize = this->getHiddenWord().size();
	if (bullCowCount.bulls == hiddenWordSize)
	{
		this->bGameIsWon = true;
	}
	else
	{
		this->bGameIsWon = false;
	}
}

FString FBullCowGame::makeLowerCase(FString textString)
{
	for (char &letter : textString)
	{
		letter = tolower(letter);
	}
	return textString;
}
