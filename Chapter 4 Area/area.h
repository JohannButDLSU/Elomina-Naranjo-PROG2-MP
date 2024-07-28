#pragma once
#include "../_Global Folder/areaStructures.h"
#include "../_Global Folder/player_struct_manager.h"
#include "initializeAreaData.h"
#include "spawnTile.h"
#include "creditsTile.h"

void runArea(Player* player, int nAreaID);
void doorTravel(struct sAreaData* sArea, Player* player);
void displayArea(Player* player, struct sAreaData sArea);
void processUserInputArea(int nAreaIndex, int* nRunning, struct sAreaData* sArea, Player* player, char cInput);