#pragma once

void showItem1();
void showItem2();
void showItem3();
void playerDamageHP();
int checkInventory(int item, int inventorySize, int* inventory);
void runEncounter(int* playerHP, int inventorySize, int* inventory);
void displayEncounter(int* playerHP, int inventorySize, int* inventory);