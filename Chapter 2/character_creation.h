#pragma once

#include "title.h"

void runCharacterCreation();

void displayCharacterCreation(struct Player player);

void processCharacterCreationInput(struct Player* player, char* cInput);

struct Player setPlayerJobClass(struct Player player, int cInput);