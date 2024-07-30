#pragma once
#include "../_Global Folder/weapon_details.h"

void runShopMenu(int *nTestRunes, int *aTestInventory);
void displayShop(int *nTestRunes, int nTestWeaponSelectedIndex, int *aCursorPos, int *inventory, int nNumRow, int nNumCol);
void processInputShopMenu(int *nTestRunes, int *aTestInventory, int *aShopItems,  int *nTestWeaponSelectedIndex, char cInput, int *aCursorPos, int nNumRow, int nNumCol);