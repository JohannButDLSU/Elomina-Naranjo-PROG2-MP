#pragma once

#include "../_Global Folder/player_struct_manager.h"
#include "areaStructures.h"


void displayTreasureScreen(int nMoneyEarned);
void runTreasureTile(int nLandedSpawnTile, struct sAreaData* sArea, Player* player);
void runSpawnTile(struct sAreaData* sArea, Player* player);