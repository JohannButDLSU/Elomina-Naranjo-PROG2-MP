#pragma once

void saveCurrentGameState(int nTotalSaveFiles, int *nCursor, struct Player *TESTplayer);
void printFileBox(struct Player *arrListOfSaves, int nFileExists, int nBoxLine, int nIndex, int nSelected);
void displaySaveMenu(struct Player *arrListOfSaves, int nTotalSaveFiles, int nCursor);
void processInputSaveMenu(struct Player *TESTplayer, int nTotalSaveFiles, int* nCursor, char cInput);
void runSaveMenu(struct Player *TESTplayer);