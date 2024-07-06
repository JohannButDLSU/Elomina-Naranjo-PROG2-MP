#pragma once

void processInputFastTravelMenu(char cInput);
void displayFastTravelMenu();
void runFastTravelMenu();

void processInputLevelUpMenu(int *nTestRunes, struct Player *TESTplayer, int nLevelUpRuneCost, char cInput);
void displayLevelUpMenu(int nLevelUpRuneCost, int *nTestRunes, struct Player *TESTplayer);
void runLevelUpMenu(int *nTestRunes, struct Player *TESTplayer);

void runRoundTable(struct Player *TESTplayer, int *nTestRunes, int *aTestInventory);
void displayRoundTable(struct Player *TESTplayer, int *nTestRunes);
void processInputRoundTable(struct Player *TESTplayer, int *nTestRunes, int *aTestInventory, char cInput);