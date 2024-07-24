#pragma once
#include "initializeAreaData.h"
#include "../_Global Folder/player_struct_manager.h"

void doorTravel(struct sAreaData* sArea, Player* player);
void displayArea(Player* player, struct sAreaData sArea);
void processUserInputArea(int nAreaIndex, int* nRunning, struct sAreaData* sArea, Player* player, char cInput);
void runArea(Player* player, int nAreaID);