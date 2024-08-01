#pragma once
#include "../_Global Folder/player_struct_manager.h"

void runSaveMenu(int* nGameLoaded, int nAllowSaving, Player *player);
void loadSave(char (*saveSlots)[31],int *nCursor, Player *player);
void saveCurrentGameState(char (*saveSlots)[31], int *nCursor, Player *player);
void printFileBox(Player sStoredOnFile, int nSaveExists, int nBoxLine, int nIndex, int nSelected);
void displaySaveMenu(int nOminousMessage, int nAllowSaving, char (*saveSlots)[31], int nCursor);
void processInputSaveMenu(int* nOminousMessage, char (*saveSlots)[31], int* nGameLoaded, int* nRunning, int nAllowSaving, Player *player, int* nCursor, char cInput);