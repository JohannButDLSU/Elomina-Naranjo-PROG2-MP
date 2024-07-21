#include "spawnTile.h"

void displayTreasureScreen(int nMoneyEarned){
    printf("\n\n+-------------------------+\n");
    printf("|  You got...             |\n");
    printf("|  %3d moneys             |\n", nMoneyEarned);
    printf("|  Press '0' to continue  |\n");
    printf("+-------------------------+\n");
    printf(" > ");
}

void runTreasureTile(int nLandedSpawnTile, struct sAreaData* sArea, int* nPlayerMoney, int* nPlayerPosRow, int* nPlayerPosCol){
    char cInput=' ';
    int nMoneyEarned=15;
    (*nPlayerMoney)+=nMoneyEarned;
    sArea->sFloors[sArea->nCurrentFloor].nLayout[*nPlayerPosRow][*nPlayerPosCol]=3;
    sArea->sSpawns[nLandedSpawnTile].nActive=0;

    do{
        displayTreasureScreen(nMoneyEarned);
        scanf(" %c", &cInput);
    }while(cInput!='0');
}

void runSpawnTile(struct sAreaData* sArea, int* nPlayerMoney, int* nPlayerPosRow, int* nPlayerPosCol){
    // First check which spawn tile it is based on coordinates
    int nLandedSpawnTile=0;
    for (int nSpawnTile=0; nSpawnTile<(sArea->nTotalSpawnTiles); nSpawnTile++){
        if (sArea->sSpawns[nSpawnTile].nLocation[0]==(*nPlayerPosRow)&&sArea->sSpawns[nSpawnTile].nLocation[1]==(*nPlayerPosCol)&&sArea->sSpawns[nSpawnTile].nLocation[2]==(sArea->nCurrentFloor)){
            nLandedSpawnTile=nSpawnTile; // Get the index of the spawntile the player landed on
        }
    }

    if (sArea->sSpawns[nLandedSpawnTile].nActive==1){
        runTreasureTile(nLandedSpawnTile, sArea, nPlayerMoney, nPlayerPosRow, nPlayerPosCol);
    }
}