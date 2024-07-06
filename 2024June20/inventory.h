#pragma once

void runInventoryMenu(int *aTestInventory);
void displayInventory(int nTestWeaponSelectedIndex, int *aCursorPos, int *inventory, int nNumRow, int nNumCol);
void processInputInventoryMenu(int *aTestInventory, int *nTestWeaponSelectedIndex, char cInput, int *aCursorPos, int nNumRow, int nNumCol);