#include "spawnTile.h"

void runSpawnTile(int* nCollectedRunes, int* nRunning, struct sAreaData* sArea, Player* player){
    // Randomize 75% Enemy 25% treasure
    int nTresureOrEnemy=(rand()%4);
    if (nTresureOrEnemy==1){
        runTreasureTile(nCollectedRunes ,sArea, player);
    } else{
        Enemy enemy;
        int nEnemyType = (rand() % (3 - 1 + 1) + 1);

        enemy = initializeEnemy(sArea->nAreaIndex + 1, nEnemyType);
        runEnemyBattle(sArea, player, &enemy);
    }
    if (player->nBattleCurrentHealth<=0){
        (*nRunning)=0;
    }
    sArea->sFloors[player->nPlayerPos[2]].nLayout[player->nPlayerPos[0]][player->nPlayerPos[1]]=3;
}

void displayTreasureScreen(int nMoneyEarned){
    printRepeatedly(6,"\t");
    printf("╔═════════════════════════════╗\n");
    printRepeatedly(6,"\t");
    printf("║                             ║\n");
    printRepeatedly(6,"\t");
    printf("║   You got...                ║\n");
    printRepeatedly(6,"\t");
    printf("║   Runes ❖ %4d              ║\n", nMoneyEarned);
    printRepeatedly(6,"\t");
    printf("║   Press '0' to continue     ║\n");
    printRepeatedly(6,"\t");
    printf("║                             ║\n");
    printRepeatedly(6,"\t");
    printf("╚═════════════════════════════╝\n\n");
    printRepeatedly(6,"\t");
    printf("> ");
}

void runTreasureTile(int* nCollectedRunes, struct sAreaData* sArea, Player* player){
    char cInput=' ';
    int nLowerBound=50;
    int nUpperBound=150;
    int nMoneyEarned=(((rand()%(nUpperBound-nLowerBound+1))+nLowerBound)*sArea->nAreaIndex);
    (*nCollectedRunes)+=nMoneyEarned;

    do{
        displayTreasureScreen(nMoneyEarned);
        scanf(" %c", &cInput);
    }while(cInput!='0');
}