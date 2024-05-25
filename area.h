#pragma once

void displayAreaArray(int playerHP, int playerMaxHP, int* playerPos, int* board, int boardSize);
void displayElements(int* playerPos, int* board, int boardSize);
void processInput(int* playerHP, int inventorySize, int* inventory, char cInput, int* playerPosX, int* playerPos, int boardSize);
void displayPlayerHP(int playerHP, int playerMaxHP);
void runArea();