#pragma once
#include "../_Global Folder/weapon_details.h"
#include "inventory.h"

void runShopMenu(Player* player);
void runSell(Player* player);
void processInputSellMenu(int* nPage, Player* player, char cInput, int *aCursorPos, int nNumRow, int nNumCol);
void displayShop(Player* player, int *aCursorPos, int nNumRow, int nNumCol);
void processInputShopMenu(Player* player, char cInput, int *aCursorPos, int nNumRow, int nNumCol);