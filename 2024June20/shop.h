#pragma once

void runShopMenu(int *nTestRunes, int *aTestInventory);
void displayShop(int *nTestRunes, int nTestWeaponSelectedIndex, int *aCursorPos, int *inventory, int nNumRow, int nNumCol);
void processInputShopMenu(int *nTestRunes, int *aTestInventory, int *aShopItems,  int *nTestWeaponSelectedIndex, char cInput, int *aCursorPos, int nNumRow, int nNumCol);