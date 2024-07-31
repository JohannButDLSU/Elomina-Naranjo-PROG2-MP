#pragma once
#include "../_Global Folder/player_struct_manager.h"
#include "../_Global Folder/weapon_details.h"

void runInventoryMenu(Player* player);
void displayInventory(int nPage, Player* player, int *aCursorPos, int nNumRow, int nNumCol);
void processInputInventoryMenu(int* nPage, Player* player, char cInput, int *aCursorPos, int nNumRow, int nNumCol);