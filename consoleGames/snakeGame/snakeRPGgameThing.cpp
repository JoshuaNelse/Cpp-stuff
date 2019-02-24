//Use the W,A,S,D keys to move.
//Each move has to be followed by enter to submit.
//You can submit more than one move at once.
//Use the X key to recall 1 move.
//gather all 10 coins to win!

#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

//Header Functions
void readInput(vector<char>, int, vector<vector<char> >&, vector<int> &, vector<int> &, int &, int &);
void drawMap(vector<char> &, int, vector<vector<char> > &, vector<int> &, int& , vector<int> &, int);
void loadLastPlayerLocation(vector<int> &, int*);
void loadLastSave(vector<vector<char> >&);
int coinSpawner(vector<char>);
int collisionCheck(vector<char>, vector<int> &, int &, int, int);

//Global Const stuff
constexpr int GLOBALmapWidth = 20;
constexpr int GLOBALmapHeight = 10;
constexpr int GLOBALmapSize = GLOBALmapWidth * GLOBALmapHeight;
constexpr int GLOBALplayerStartLocation = (GLOBALmapSize / 2 - GLOBALmapWidth / 2) - 1;
const char GLOBALmapPlayer = '8';
const char GLOBALmapFloor = ' ';
const char GLOBALmapWall = '#';
const char GLOBALmapCoin = '@';




int main() {
	vector<vector<char> > saveVector;
	vector<int> savePlayerLocation{GLOBALplayerStartLocation};
	vector<char> mapVector(GLOBALmapSize, ' ');
	vector<int> coinKeeper;
	int playerLocation = GLOBALplayerStartLocation;
	int coinsPrinted = 0;
	int score = 0;

	drawMap(mapVector, playerLocation, saveVector, coinKeeper, coinsPrinted, savePlayerLocation, score); //Initalizing map
	readInput(mapVector, playerLocation, saveVector, savePlayerLocation, coinKeeper, coinsPrinted, score); //primary game loop

	return 0; 
}


//p is 112 << to close game loop. doesnt work atm. haha)
//w is 119 //a is 97 //s is 115 //d is 100 //x is 120
void readInput(vector<char> vectorOfMap, int playerLocation, vector<vector<char> > &vectorOfSaves,vector<int> &vectorOfPlayerLocations, vector<int> &vectorOfCoins, int &coinsPrinted, int &score) {
	int input = 0;
	int movePlayer;

	while (input != 122) {
		movePlayer = 0;
		input = getchar();

		switch (input) {
		case 115: movePlayer = collisionCheck(vectorOfMap, vectorOfCoins, score, playerLocation, GLOBALmapWidth);	break;
		case 119: movePlayer = collisionCheck(vectorOfMap, vectorOfCoins, score, playerLocation,-GLOBALmapWidth);	break;
		case 100: movePlayer = collisionCheck(vectorOfMap, vectorOfCoins, score, playerLocation, 1);				break;
		case 97:  movePlayer = collisionCheck(vectorOfMap, vectorOfCoins, score, playerLocation,-1);				break;
		case 120: loadLastSave(vectorOfSaves); loadLastPlayerLocation(vectorOfPlayerLocations, &playerLocation); break;
		}

		if (movePlayer != 0) {
			vectorOfPlayerLocations.push_back(playerLocation);
			playerLocation += movePlayer;
			drawMap(vectorOfMap, playerLocation, vectorOfSaves, vectorOfCoins, coinsPrinted, vectorOfPlayerLocations, score);
			cout << endl;
			cout << coinsPrinted << endl;
		}
		if (score == 10) {
			cout << "YOU WIN!!!" << endl;
		}
	}
}




void drawMap(vector<char> &mapVector, int playerLocation, vector<vector<char> > &vectorOfSaves, vector<int> &coinKeeper, int &coinsPrinted, vector<int> &vectorOfPlayerLocations, int score){

	const int lineThreshold = GLOBALmapWidth-1;
	int lineLength = 0;
	int coinLocation;
	char drawChar;
	bool newCoin = false;
	bool printCoin = false;

	if ((size(vectorOfSaves) % 5) == 0 && coinsPrinted < 10) {
		newCoin = true;
	}

	for (int i = 0; i < GLOBALmapSize; i++) {
		if (i == playerLocation) {
			drawChar = GLOBALmapPlayer;
		} else if (i < lineThreshold || i >= (GLOBALmapSize-lineThreshold) || lineLength == 0 || lineLength == lineThreshold) {
			drawChar = GLOBALmapWall;
		} else {
			drawChar = GLOBALmapFloor;
		}
		if (vectorOfPlayerLocations.size() > 1) {
			for (int j = 0; j < (vectorOfPlayerLocations.size() - 1); j++) {
				if (i == vectorOfPlayerLocations[j]) {
					drawChar = GLOBALmapWall;
				}
			}
		}

		if (newCoin) {
			coinLocation = coinSpawner(mapVector);
			newCoin = false;
			printCoin = true;
		}
		if(printCoin){
			if (i == coinLocation) {
				coinKeeper.push_back(coinLocation);
				coinsPrinted++;
				printCoin = false;
			}
		}
		for (auto coin : coinKeeper) {
			if (i == coin) {
				drawChar = GLOBALmapCoin;
			}
		}

		mapVector[i] = drawChar;
		cout << mapVector[i];

		if (lineLength == lineThreshold) {
			cout << endl;
			lineLength = 0;
		} else {
			lineLength++;
		}
	}
	vectorOfSaves.push_back(mapVector);
	cout << endl;
	cout << "SCORE: " << score << endl;
}




void loadLastPlayerLocation(vector<int> &playerLocationArray, int *playerLocation) {
	if (size(playerLocationArray) != 1) {
		int lastPlayerLocation = playerLocationArray[size(playerLocationArray) - 2];
		*playerLocation = lastPlayerLocation;
		playerLocationArray.pop_back();
	}
}




void loadLastSave(vector<vector<char> > &vetorOfSaves) {
	if (size(vetorOfSaves) == 1) {
		cout << "No previous saves!" << endl;
	}
	else {
		const int lineThreshold = GLOBALmapWidth - 1;
		int lineLength = 0;
		vector<char> lastSave = vetorOfSaves[size(vetorOfSaves) - 2];
		for (auto control : lastSave) {
			cout << control;
			if (lineLength == lineThreshold) {
				cout << endl;
				lineLength = 0;
			}
			else {
				lineLength++;
			}
		}
		cout << endl;
		cout << "Previous save Loaded" << endl;
		vetorOfSaves.pop_back();
	}
}




int coinSpawner(vector<char> mapVector) {
	srand(time(NULL));
	int coinLocation = (rand() * 101) % GLOBALmapSize;
	while (mapVector[coinLocation] == GLOBALmapWall || mapVector[coinLocation] == GLOBALmapPlayer || mapVector[coinLocation] == GLOBALmapCoin) {
		coinLocation = (rand() * 101) % GLOBALmapSize;
	}
	return coinLocation;
}




int collisionCheck(vector<char> vectorOfMap, vector<int> &vectorOfCoins, int &score, int playerLocation, int requestedMove) {
	int newPlayerLocation = playerLocation + requestedMove;
	if (vectorOfMap[newPlayerLocation] == GLOBALmapCoin) {
		for (int i = 0; i < size(vectorOfCoins); i++) {
			if (vectorOfCoins[i] == newPlayerLocation) {
				vectorOfCoins.erase(vectorOfCoins.begin() + i);
				score++;
			}
		}
	}
	if (vectorOfMap[newPlayerLocation] == GLOBALmapWall) {
		return 0;
	}
	return requestedMove;
}