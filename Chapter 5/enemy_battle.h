#pragma once
#include "../_Global Folder/player_struct_manager.h"
#include "../_Global Folder/areaStructures.h"

void runEnemyBattle(struct sAreaData* sArea, Player* player, Enemy* enemy);

void processEnemyBattle(struct sAreaData* sArea, Player* player, Enemy* enemy);

void displayEnemyBattle(struct sAreaData* sArea, Player* player, Enemy* enemy);