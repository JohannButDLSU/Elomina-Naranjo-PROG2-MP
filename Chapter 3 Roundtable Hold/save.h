#pragma once
#include "../_Global Folder/player_struct_manager.h"

void loadSave(int nTotalSaveFiles, int *nCursor, Player *player);
void saveCurrentGameState(int nTotalSaveFiles, int *nCursor, Player *player);
void printFileBox(Player *arrListOfSaves, int nFileExists, int nBoxLine, int nIndex, int nSelected);
void displaySaveMenu(int nAllowSaving, Player *arrListOfSaves, int nTotalSaveFiles, int nCursor);
void processInputSaveMenu(int* nGameLoaded, int* nRunning, int nAllowSaving, Player *player, int nTotalSaveFiles, int* nCursor, char cInput);
void runSaveMenu(int* nGameLoaded, int nSavingAllowed, Player *player);