#pragma once

#include "../_Global Folder/player_struct_manager.h"
#include "../_Global Folder/areaStructures.h"
#include "../Chapter 5/enemy_battle.h"

void displayTreasureScreen(int nMoneyEarned);
void runTreasureTile(int nLandedSpawnTile, struct sAreaData* sArea, Player* player);
void runSpawnTile(struct sAreaData* sArea, Player* player);