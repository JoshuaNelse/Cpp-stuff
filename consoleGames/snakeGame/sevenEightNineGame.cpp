#include <iostream>
#include <stdio.h>
#include <vector>
#include <ctime>
#include <conio.h>
using namespace std;

struct playerStruct {
	int location;
	bool loadLastSave;
	vector<int> PathToTurnIntoWalls;
};

struct tile {
	int location;
	bool isCoin;
	bool isWall;
	bool isPlayer;
};

struct coin {
	int location;
	bool isCollected;
};

struct gameValues {
	size_t score = 0;
	size_t mapLength = 20;
	size_t mapSize = mapLength * mapLength;
	size_t coinTimer;
	vector<coin> vectorOfCoins;
};

int playerMoveCollisionCheck(vector<vector<tile> >, int, playerStruct, gameValues&);
void initializeMap(gameValues, vector<vector<tile> >&, playerStruct&);
void drawMap(vector<vector<tile> >, gameValues);
void coinSpawner(gameValues&, vector<vector<tile> >&);

int main() {
	gameValues game = {};
	//game.mapLength = 20;
	game.coinTimer = 0;
	vector<vector<tile> >vectorOfMaps;
	playerStruct player = {};
	int playerStart = game.mapLength * game.mapLength / 2 - game.mapLength/2;
	player.location = playerStart;

	initializeMap(game, vectorOfMaps, player);
	coinSpawner(game, vectorOfMaps);
	initializeMap(game, vectorOfMaps, player);

	bool pizzaTastesGood = true;
	while (pizzaTastesGood) {
		auto input = _getch();
		int requestedMove;

		switch (input) {
		case 119:	requestedMove = game.mapLength * -1;	player.location = playerMoveCollisionCheck(vectorOfMaps, requestedMove, player, game); break;
		case 115:	requestedMove = game.mapLength * 1;		player.location = playerMoveCollisionCheck(vectorOfMaps, requestedMove, player, game); break;
		case 97:	requestedMove = -1;						player.location = playerMoveCollisionCheck(vectorOfMaps, requestedMove, player, game); break;
		case 100:	requestedMove = 1;						player.location = playerMoveCollisionCheck(vectorOfMaps, requestedMove, player, game); break;
		case 120:	player.loadLastSave = true;			break;
		}

		coinSpawner(game,vectorOfMaps);
		initializeMap(game, vectorOfMaps, player);

		if (game.score == game.mapSize * .05) {
			break;
		}
	}
	cout << "YOU WIN!!!" << endl << "Press Enter to leave.";
	cin.get();
	return 0;
}

void coinSpawner(gameValues &game, vector<vector<tile> > &vectorOfMaps) {
	if (game.vectorOfCoins.size() < game.mapSize * .05) {
		auto map = vectorOfMaps[vectorOfMaps.size() - 1];

		if (!game.coinTimer) {
			coin coin = {};
			coin.location = (rand() * 101) % game.mapSize;

			while (map[coin.location].isWall || map[coin.location].isPlayer || map[coin.location].isCoin) {
				coin.location = (rand() * 101) % game.mapSize;
			}
			game.vectorOfCoins.push_back(coin);
			game.coinTimer = 5;
		}
		else game.coinTimer--;
	}
}

int playerMoveCollisionCheck(vector<vector<tile> > vectorOfMaps, int requestedMove, playerStruct player, gameValues &game) {
	int newLocation = player.location + requestedMove;
	auto map = vectorOfMaps[size(vectorOfMaps) - 1];

	if (map[newLocation].isCoin) {
		for (coin &control : game.vectorOfCoins) {
			if (newLocation == control.location)  control.isCollected = true;
		}
		game.score++;
	}
	if (map[newLocation].isWall) return player.location;
	else return newLocation;
}

void initializeMap(gameValues game, vector<vector<tile> > &vectorOfMaps, playerStruct &player) {
	vector<tile> map;

	if (player.loadLastSave && vectorOfMaps.size() > 1) {
		auto mapBeforeLast = vectorOfMaps[size(vectorOfMaps) - 2];
		for (auto tile : mapBeforeLast) {
			if (tile.isPlayer) player.location = tile.location;
		}
		vectorOfMaps.pop_back();
		vectorOfMaps.pop_back();
		player.PathToTurnIntoWalls.pop_back();
		player.PathToTurnIntoWalls.pop_back();
		player.loadLastSave = false;
	}

	for (int i = 0; i < game.mapLength; i++) {
		for (int j = 0; j < game.mapLength; j++) {

			tile mapTile = {};
			mapTile.location = (i * game.mapLength) + j;

			for (auto playersPreviousPath : player.PathToTurnIntoWalls) {
				if (mapTile.location == playersPreviousPath && playersPreviousPath != player.location) mapTile.isWall = true;
			}

			if (i == 0 || i == game.mapLength - 1 || j == 0 || j == game.mapLength - 1) mapTile.isWall = true;
			else if (mapTile.location == player.location) mapTile.isPlayer = true;

			for (coin control : game.vectorOfCoins) {
				if (mapTile.location == control.location && !control.isCollected) {
					mapTile.isCoin = true;
				}
			}

			map.push_back(mapTile);
		}
	}
	player.PathToTurnIntoWalls.push_back(player.location);
	vectorOfMaps.push_back(map);
	drawMap(vectorOfMaps, game);
}

void drawMap(vector<vector<tile> > vectorOfMaps, gameValues game) {
	cout << "\033[2J\033[1;1H"; //clearing the screen 
	vector<tile> map = vectorOfMaps[vectorOfMaps.size() - 1];

	for (int i = 0; i < game.mapLength; i++) {
		if (i != 0) cout << endl;
		for (int j = 0; j < game.mapLength; j++) {

			int location = (i * game.mapLength) + j;
			auto *mapTile = &map[location];

			if (mapTile->isWall) cout << "# ";
			else if (mapTile->isPlayer) cout << "7 ";
			else if (mapTile->isCoin) cout << "9 ";
			else cout << "  ";
		}
	}
	cout << endl;
	cout << "Score: " << game.score << endl;
}