#include <iostream>
#include <vector>
#include <string>
#pragma once
#include <ctime>
#include <map>
#include "Game.h"
#include "Enemy.h"
#include "Player.h"
#include "Dialogue.h"

using namespace std;

void initStory(Game*);
void trainingLoop(Game*);
bool findBattle(Game*, Enemy*);
