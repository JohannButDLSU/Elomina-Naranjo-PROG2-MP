#pragma once

#include "../Chapter 1/title.h"

void runCharacterCreation();

void displayCharacterCreation(Player player);

void processCharacterCreationInput(Player* player, char* cInput);

Player setPlayerJobClass(Player player, int cInput);