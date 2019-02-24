#pragma once
#include <string>
#include <map>

//To mimic UNREAL engine types
#define TMap std::map
#define TVector std::vector
using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 bulls = 0;
	int32 cows = 0;
};

enum class EGuessValidity
{
	Invalid,
	Valid,
	Not_Isogram,
	Not_correctLength
};

class FBullCowGame {

public:
	FBullCowGame();
 
	int32 getMaxTries() const;
	int32 getCurrentTry() const;
	FString getHiddenWord() const;
	bool isGameWon() const;
	EGuessValidity isValidGuess(FString) const;
	void printGuessValidationErrors(EGuessValidity);
	
	void reset();
	void incrementCurrentTry();
	FString makeLowerCase(FString);
	FBullCowCount submitValidGuess(FString);


private:
	int32 maxTries;
	int32 CurrentTry;
	FString hiddenWord;
	bool bGameIsWon;

	bool isIsogram(FString) const;
	void submitGameIsWonStatus(FBullCowCount);
};
