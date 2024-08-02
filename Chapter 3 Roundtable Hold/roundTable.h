#pragma once

#include "../_Global Folder/player_struct_manager.h"
#include "../Chapter 4 Area/area.h"
#include "inventory.h"
#include "shop.h"
#include "save.h"


void processInputFastTravelMenu(int* nRunning, Player* player, char cInput);
void displayFastTravelMenu(Player* player);
void runFastTravelMenu(Player* player);

void processInputLevelUpMenu(Player *player, int nLevelUpRuneCost, char cInput);
void displayLevelUpMenu(int nLevelUpRuneCost, Player *player);
void runLevelUpMenu(Player *player);

void runRoundTable(Player *player);
void displayRoundTable(Player *player);
void processInputRoundTable(Player *player, char cInput);