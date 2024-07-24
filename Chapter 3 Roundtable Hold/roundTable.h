#pragma once

#include "../_Global Folder/player_struct_manager.h"
#include "../Chapter 4 Area/area.h"
#include "inventory.h"
#include "shop.h"
#include "save.h"


void processInputFastTravelMenu(Player* player, char cInput);
void displayFastTravelMenu(Player* player);
void runFastTravelMenu(Player* player);

void processInputLevelUpMenu(int *nTestRunes, Player *player, int nLevelUpRuneCost, char cInput);
void displayLevelUpMenu(int nLevelUpRuneCost, int *nTestRunes, Player *player);
void runLevelUpMenu(int *nTestRunes, Player *player);

void runRoundTable(Player *player, int *nTestRunes, int *aTestInventory);
void displayRoundTable(Player *player, int *nTestRunes);
void processInputRoundTable(Player *player, int *nTestRunes, int *aTestInventory, char cInput);