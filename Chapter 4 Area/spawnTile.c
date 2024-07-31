#include "spawnTile.h"

void displayTreasureScreen(int nMoneyEarned){
    printf("\n\n+-------------------------+\n");
    printf("|  You got...             |\n");
    printf("|  %3d moneys             |\n", nMoneyEarned);
    printf("|  Press '0' to continue  |\n");
    printf("+-------------------------+\n");
    printf(" > ");
}

void runTreasureTile(int nLandedSpawnTile, struct sAreaData* sArea, Player* player){
    char cInput=' ';
    int nMoneyEarned=15;
    (player->nRunes)+=nMoneyEarned;

    do{
        displayTreasureScreen(nMoneyEarned);
        scanf(" %c", &cInput);
    }while(cInput!='0');
}

void runSpawnTile(struct sAreaData* sArea, Player* player){
    // Randomize 75% Enemy 25% treasure
    // runTreasureTile(nLandedSpawnTile, sArea, player);

    Enemy enemy;
    int nEnemyType = (rand() % (3 - 1 + 1) + 1);

    enemy = initializeEnemy(sArea->nAreaIndex + 1, nEnemyType);
    runEnemyBattle(sArea, player, enemy);
    // runEnemyBattle(sArea, player); // hi zivv could u find a way to put enemy here? I don't wanna mess up chap4 too hard, but I tried to put logic in chap5
    sArea->sFloors[player->nPlayerPos[2]].nLayout[player->nPlayerPos[0]][player->nPlayerPos[1]]=3;
}