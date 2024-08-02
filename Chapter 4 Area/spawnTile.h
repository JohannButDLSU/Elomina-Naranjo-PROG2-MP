#pragma once

#include "../_Global Folder/player_struct_manager.h"
#include "../_Global Folder/areaStructures.h"
#include "../Chapter 5/enemy_battle.h"


void runSpawnTile(int* nCollectedRunes, int* nRunning, struct sAreaData* sArea, Player* player);
void displayTreasureScreen(int nMoneyEarned);
void runTreasureTile(int* nCollectedRunes, struct sAreaData* sArea, Player* player);