#include "area.h"
#include "spawnTile.h"

void doorTravel(struct sAreaData* sArea, Player* player){
    int nLandedDoorPair=0;
    for (int nDoorPair=0; nDoorPair<(sArea->nTotalDoorPairs); nDoorPair++){
        for (int nDoorPartner=0; nDoorPartner<2; nDoorPartner++){
            if (sArea->sDoors[nDoorPair].nEndpoints[nDoorPartner][0]==(player->nPlayerPos[0])&&sArea->sDoors[nDoorPair].nEndpoints[nDoorPartner][1]==(player->nPlayerPos[1])&&sArea->sDoors[nDoorPair].nEndpoints[nDoorPartner][2]==(player->nPlayerPos[2])){
                nLandedDoorPair=nDoorPair; // Send nLandedDoorPair to the door pair the player is currently in
            } // Checks if the player coordinates [row, col, floor] match the index of nDoorPair[row, col, floor]
        } // Goes through all door pairs
    }
    if (player->nPlayerPos[2]==sArea->sDoors[nLandedDoorPair].nEndpoints[0][2]){ // If the current floor matches the floor coordinate of the current door pair,...
        player->nPlayerPos[2]=sArea->sDoors[nLandedDoorPair].nEndpoints[1][2]; // ...set the current floor to the connecting door floor coordinate
        player->nPlayerPos[0]=sArea->sDoors[nLandedDoorPair].nEndpoints[1][0]; // same with player pos row
        player->nPlayerPos[1]=sArea->sDoors[nLandedDoorPair].nEndpoints[1][1]; // and player pos col
    } else{
        player->nPlayerPos[2]=sArea->sDoors[nLandedDoorPair].nEndpoints[0][2]; // otherwise, use the other connecting floor coordinate
        player->nPlayerPos[0]=sArea->sDoors[nLandedDoorPair].nEndpoints[0][0];
        player->nPlayerPos[1]=sArea->sDoors[nLandedDoorPair].nEndpoints[0][1];
    }
}

void displayArea(Player* player, struct sAreaData sArea){
    printf("\n");
    printRepeatedly(7,"\t");
    printf("%s\n", sArea.strAreaName);
    printf("\n");
    
    // TEST TEMPORARY
    char jobClassSpriteTEST[10][10]={"1","🗡"};

    int nSideMargin=(15-sArea.sFloors[player->nPlayerPos[2]].nDimensions[1])/2;
    int nUpperLowerMargin=(15-sArea.sFloors[player->nPlayerPos[2]].nDimensions[0])/2;
    int nPlayerLanding=0;
    int nAreaSizeLimit=15;

    for (int nRow=0; nRow<nAreaSizeLimit; nRow++){
        for (int nBoxLine=0; nBoxLine<2; nBoxLine++){
            printRepeatedly(5,"\t");
            for (int nCol=0; nCol<nAreaSizeLimit; nCol++){
                nPlayerLanding=0;
                if (nRow==(nUpperLowerMargin+player->nPlayerPos[0])&&nCol==(nSideMargin+player->nPlayerPos[1])) nPlayerLanding=1;
                if (nRow>=(nUpperLowerMargin)&&nRow<(nUpperLowerMargin+sArea.sFloors[player->nPlayerPos[2]].nDimensions[0])&&nCol>=(nSideMargin)&&nCol<(nSideMargin+sArea.sFloors[player->nPlayerPos[2]].nDimensions[1])){
                    switch(sArea.sFloors[player->nPlayerPos[2]].nLayout[nRow-nUpperLowerMargin][nCol-nSideMargin]){
                    case 0:
                        if (nBoxLine==0){
                            printf("┌─┐");
                        } else if (nBoxLine==1&&nPlayerLanding==0){
                            printf("└─┘");
                        } else{
                            printf("└%s┘",jobClassSpriteTEST[0]);
                        }
                        break;
                    case 1:
                        if (nBoxLine==0){
                            printf("╒⇳╕");
                        } else if (nBoxLine==1&&nPlayerLanding==0){
                            printf("╘═╛");
                        } else{
                            printf("╘%s╛",jobClassSpriteTEST[0]);
                        }
                        break;
                    case 2:
                        if (nBoxLine==0){
                            printf("╓?╖");
                        } else if (nBoxLine==1&&nPlayerLanding==0){
                            printf("╙─╜");
                        } else{
                            printf("╙%s╜",jobClassSpriteTEST[0]);
                        }
                        break;
                    case 3:
                        if (nBoxLine==0){
                            printf("╓ ╖");
                        } else if (nBoxLine==1&&nPlayerLanding==0){
                            printf("╙ ╜");
                        } else{
                            printf("╙%s╜",jobClassSpriteTEST[0]);
                        }
                        break;
                    case 4:
                        if (nBoxLine==0){
                            printf("╆ᛝ╅");
                        } else if (nBoxLine==1&&nPlayerLanding==0){
                            printf("╄┄╃");
                        } else{
                            printf("╄%s╃",jobClassSpriteTEST[0]);
                        }
                        break;
                    case 5:
                        if (nBoxLine==0&&sArea.sFastTravels[0].nLocked==1){
                            printf("╭╥╮");
                        } else if (nBoxLine==0&&sArea.sFastTravels[0].nLocked==0){
                            printf("╭└╮");
                        } else if (nBoxLine==1&&nPlayerLanding==0){
                            printf("╰╨╯");
                        }else{
                            printf("╰%s╯",jobClassSpriteTEST[0]);
                        }
                        break;
                    case 6:
                        printf("░░░");
                        break;
                    }
                } else{
                    printf("░░░");
                }
            }
        printf("\n");
        }
    }

}

void processUserInputArea(int* nRunning, struct sAreaData* sArea, Player* player,  char cInput){
    switch (cInput){
        case 'a':
        case 'A':
            if ((player->nPlayerPos[1])>0&&(sArea->sFloors[player->nPlayerPos[2]].nLayout[player->nPlayerPos[0]][(player->nPlayerPos[1])-1])!=6){
                (player->nPlayerPos[1])-=1;
            }
            break;
        case 'd':
        case 'D':
            if ((player->nPlayerPos[1])<((sArea->sFloors[player->nPlayerPos[2]].nDimensions[1])-1)&&(sArea->sFloors[player->nPlayerPos[2]].nLayout[player->nPlayerPos[0]][(player->nPlayerPos[1])+1])!=6){
                (player->nPlayerPos[1])+=1;
            }
            break;
        case 'w':
        case 'W':
            if ((player->nPlayerPos[0])>0&&(sArea->sFloors[player->nPlayerPos[2]].nLayout[(player->nPlayerPos[0])-1][player->nPlayerPos[1]])!=6){
                (player->nPlayerPos[0])-=1;
            }
            break;
        case 's':
        case 'S':
            if ((player->nPlayerPos[0])<((sArea->sFloors[player->nPlayerPos[2]].nDimensions[0])-1)&&(sArea->sFloors[player->nPlayerPos[2]].nLayout[(player->nPlayerPos[0])+1][player->nPlayerPos[1]])!=6){
                (player->nPlayerPos[0])+=1;
            }
            break;
        case 'e':
        case 'E':
            switch (sArea->sFloors[player->nPlayerPos[2]].nLayout[player->nPlayerPos[0]][player->nPlayerPos[1]]){ // Logic checks what kind of tile the player is currently on
                case 1: // Door tile
                    doorTravel(sArea, player); // Updates the current room and player position [row][col]
                    break;
                case 2: // Spawn tile
                    runSpawnTile(sArea, player);
                    break;
                case 4: // Boss Tile
                    // runBossBattle();
                    printf("\n\n\nGRRRRR runBossBattle() Rawr uwu~\nLet's Assume you beat the boss and the fast trvel tile is unlocked uwu\n\n\n");
                    for (int nFastTravelTile=0; nFastTravelTile<(sArea->nTotalFastTravelTiles); nFastTravelTile++){
                        sArea->sFastTravels[nFastTravelTile].nLocked=0;
                    } // Unlocks all fast travel tiles upon defeat of boss
                    break;
                case 5:
                    if (sArea->sFastTravels[0].nLocked==0){
                        (*nRunning)=0;
                    }
                    break;
                default:
                    break;
            }
            break;
    }
}
void runArea(Player* player, int nAreaIndex){
    char cInput=' ';
    int nRunning=1; // 0 = FALSE, 1 = TRUE. Running area; exits when 0.

    struct sAreaData sArea;
    switch (nAreaIndex){
        case 0:
            sArea=initializeStormveilCastle();
            player->nPlayerPos[0]=sArea.sFastTravels[1].nLocation[0];
            player->nPlayerPos[1]=sArea.sFastTravels[1].nLocation[1];
            player->nPlayerPos[2]=sArea.sFastTravels[1].nLocation[2];
            break;
    }
    do{
        printf("Player Money: %d", player->nRunes); // Delete me
        displayArea(player, sArea);
        printf("> ");
        scanf(" %c", &cInput);
        processUserInputArea(&nRunning, &sArea, player, cInput);
    }while(cInput!='0'&&nRunning==1);
}