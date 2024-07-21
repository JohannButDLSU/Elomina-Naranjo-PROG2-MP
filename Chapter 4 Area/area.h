#pragma once
#include "initializeAreaData.h"
#include "../_Global Folder/player_struct_manager.h"

void doorTravel(struct sAreaData* sArea, int* nPlayerPosRow, int* nPlayerPosCol);
void displayArea(int nPlayerPosRow, int nPlayerPosCol, struct sAreaData sArea);
void processUserInputArea(struct sAreaData* sArea, int* nPlayerMoney, int* nPlayerPosRow, int* nPlayerPosCol, char cInput);
void runArea(Player* player, int nAreaID);