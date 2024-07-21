#pragma once

#include "areaStructures.h"


void displayTreasureScreen(int nMoneyEarned);
void runTreasureTile(int nLandedSpawnTile, struct sAreaData* sArea, int* nPlayerMoney, int* nPlayerPosRow, int* nPlayerPosCol);
void runSpawnTile(struct sAreaData* sArea, int* nPlayerMoney, int* nPlayerPosRow, int* nPlayerPosCol);