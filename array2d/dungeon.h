#pragma once

void runDungeon();
void renderDungeon(int* map, int* dungeonDimension, int playerPosX, int playerPosY);
void processInput(char cInput, int* playerPosX, int* playerPosY, int* dungeonDimension, int* map);