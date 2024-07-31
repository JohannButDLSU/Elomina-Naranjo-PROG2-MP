#pragma once
#include "../_Global Folder/player_struct_manager.h"
#include "../_Global Folder/weapon_details.h"

void runInventoryMenu(Player* player);
void displayInventory(Player* player, int nTestWeaponSelectedIndex, int *aCursorPos, int nNumRow, int nNumCol);
void processInputInventoryMenu(Player* player, int *nTestWeaponSelectedIndex, char cInput, int *aCursorPos, int nNumRow, int nNumCol);