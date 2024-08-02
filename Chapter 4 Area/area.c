#include "area.h"

void runArea(Player* player, int nAreaIndex){
    char cInput=' ';
    int nRunning=1; // 0 = FALSE, 1 = TRUE. Running area; exits when 0.

    // at the START of the area is where I'll initialize player stuff, so here xddd
    // will include health, potions
    player->nBattleMaxHealth = (100 * (player->nMaxHealth + player->sEquippedWeapon.nHealth) / 2);
    player->nBattleCurrentHealth = player->nBattleMaxHealth;
    player->nPotions = 8;

    struct sAreaData sArea;
    switch (nAreaIndex){
        case 1:
            sArea=initializeStormveilCastle();
            // Player Spawn Coordinates
            player->nPlayerPos[0]=sArea.sFastTravels[0].nLocation[0];
            player->nPlayerPos[1]=sArea.sFastTravels[0].nLocation[1];
            player->nPlayerPos[2]=sArea.sFastTravels[0].nLocation[2];
            sArea.nAreaIndex=nAreaIndex;
            break;
        case 2:
            sArea=initializeRayaLucaria();
            // Player Spawn Coordinates
            player->nPlayerPos[0]=sArea.sFastTravels[0].nLocation[0];
            player->nPlayerPos[1]=sArea.sFastTravels[0].nLocation[1];
            player->nPlayerPos[2]=sArea.sFastTravels[0].nLocation[2];
            sArea.nAreaIndex=nAreaIndex;
            break;
        case 3:
            sArea=initializeRedmaneCastle();
            // Player Spawn Coordinates
            player->nPlayerPos[0]=sArea.sFastTravels[0].nLocation[0];
            player->nPlayerPos[1]=sArea.sFastTravels[0].nLocation[1];
            player->nPlayerPos[2]=sArea.sFastTravels[0].nLocation[2];
            sArea.nAreaIndex=nAreaIndex;
            break;
        case 4:
            sArea=initializeVolcanoManor();
            // Player Spawn Coordinates
            player->nPlayerPos[0]=sArea.sFastTravels[0].nLocation[0];
            player->nPlayerPos[1]=sArea.sFastTravels[0].nLocation[1];
            player->nPlayerPos[2]=sArea.sFastTravels[0].nLocation[2];
            sArea.nAreaIndex=nAreaIndex;
            break;
        case 5:
            sArea=initializeLeyndellRoyalCapital();
            // Player Spawn Coordinates
            player->nPlayerPos[0]=sArea.sFastTravels[0].nLocation[0];
            player->nPlayerPos[1]=sArea.sFastTravels[0].nLocation[1];
            player->nPlayerPos[2]=sArea.sFastTravels[0].nLocation[2];
            sArea.nAreaIndex=nAreaIndex;
            break;
        case 6:
            sArea=initializeEldenThrone();
            // Player Spawn Coordinates
            player->nPlayerPos[0]=sArea.sFastTravels[0].nLocation[0];
            player->nPlayerPos[1]=sArea.sFastTravels[0].nLocation[1];
            player->nPlayerPos[2]=sArea.sFastTravels[0].nLocation[2];
            sArea.nAreaIndex=nAreaIndex;
            break;
    }

    int nCollectedRunes=0;
    do{
        printf("Runes: ❖ %d", nCollectedRunes); // Delete me
        displayArea(player, sArea);
        printRepeatedly(5,"\t");
        printf("> ");
        scanf(" %c", &cInput);
        processUserInputArea(&nCollectedRunes, &nRunning, &sArea, player, cInput);
    }while(nRunning==1);
}

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
    char sJobClassSpriteTEST[10][10]={"᭶","🗡"};
    char sBossSprite[6][10]={"⌘","℧","࿃","֎","۞","ᛝ"};

    int nSideMargin=(15-sArea.sFloors[player->nPlayerPos[2]].nDimensions[1])/2;
    int nUpperLowerMargin=(15-sArea.sFloors[player->nPlayerPos[2]].nDimensions[0])/2;
    int nPlayerLanding=0;
    int nAreaSizeLimit=15;
    int nFastTravelIndex;

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
                            printf("└%s┘",sJobClassSpriteTEST[0]);
                        }
                        break;
                    case 1:
                        if (nBoxLine==0){
                            printf("╒⇳╕");
                        } else if (nBoxLine==1&&nPlayerLanding==0){
                            printf("╘═╛");
                        } else{
                            printf("╘%s╛",sJobClassSpriteTEST[0]);
                        }
                        break;
                    case 2:
                        if (nBoxLine==0){
                            printf("╓?╖");
                        } else if (nBoxLine==1&&nPlayerLanding==0){
                            printf("╙─╜");
                        } else{
                            printf("╙%s╜",sJobClassSpriteTEST[0]);
                        }
                        break;
                    case 3:
                        if (nBoxLine==0){
                            printf("╓ ╖");
                        } else if (nBoxLine==1&&nPlayerLanding==0){
                            printf("╙ ╜");
                        } else{
                            printf("╙%s╜",sJobClassSpriteTEST[0]);
                        }
                        break;
                    case 4:
                        if (nBoxLine==0){
                            printf("╆%s╅", sBossSprite[sArea.nAreaIndex-1]);
                        } else if (nBoxLine==1&&nPlayerLanding==0){
                            printf("╄┄╃");
                        } else{
                            printf("╄%s╃",sJobClassSpriteTEST[0]);
                        }
                        break;
                    case 5:
                        nFastTravelIndex=0;
                        for (int nFastTravelTile=0; nFastTravelTile<sArea.nTotalFastTravelTiles; nFastTravelTile++){
                            if (sArea.sFastTravels[nFastTravelTile].nLocation[2]==player->nPlayerPos[2]){
                                nFastTravelIndex=nFastTravelTile;
                            }
                        }
                        if (nBoxLine==0&&sArea.sFastTravels[nFastTravelIndex].nLocked==1){
                            printf("╭╥╮");
                        } else if (nBoxLine==0&&sArea.sFastTravels[nFastTravelIndex].nLocked==0){
                            printf("╭└╮");
                        } else if (nBoxLine==1&&nPlayerLanding==0){
                            printf("╰╨╯");
                        }else{
                            printf("╰%s╯",sJobClassSpriteTEST[0]);
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

void processUserInputArea(int*nCollectedRunes, int* nRunning, struct sAreaData* sArea, Player* player,  char cInput){

    int nLandedFastTravel;
    int nLandedBossTile;

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
                    doorTravel(sArea, player); // Updates player position [row][col][floor]
                    break;
                case 2: // Spawn tile
                    runSpawnTile(nCollectedRunes, nRunning, sArea, player);
                    break;
                case 3: // Consumed spawn tile
                    break;
                case 4: // Boss Tile
                    nLandedBossTile=0;
                    for (int nBossTile=0; nBossTile<sArea->nTotalBossTiles; nBossTile++){
                        if (sArea->sBosses[nBossTile].nLocation[0]==player->nPlayerPos[0]&&sArea->sBosses[nBossTile].nLocation[1]==player->nPlayerPos[1]&&sArea->sBosses[nBossTile].nLocation[2]==player->nPlayerPos[2]){
                            nLandedBossTile=nBossTile;
                        }
                    }
                
                    if (sArea->sBosses[nLandedBossTile].nEnabled==1){
                        // runBossBattle();
                        printf("\n\n\nGRRRRR runBossBattle() Rawr uwu~\nLet's Assume you beat the boss and the fast trvel tile is unlocked uwu\n\n\n");
                        sArea->sBosses[nLandedBossTile].nEnabled=0; // Whether you win or lose a boss, it will be deactivated or uninteractible again because the player either wins and deactivates the boss or loses and goes back to rountable                    
                        if (strcmp(sArea->strAreaName,"Elden Throne")==0&&sArea->sBosses[0].nEnabled==0&&sArea->sBosses[1].nEnabled==0){ // In the Elden Throne, there are 2 bosses that come one after the other. The fast travel only opens when both are slain
                            sArea->sBosses[1].nEnabled=1;
                            // runBossBattle(Elden Beast);
                            sArea->sBosses[1].nEnabled=0;
                        }
                    }

                    int nAllBossesSlainCheck=0;
                    for (int nBosses=0; nBosses<sArea->nTotalBossTiles; nBosses++){
                        nAllBossesSlainCheck+=sArea->sBosses[nBosses].nEnabled; //nEnabled is an integer 0 being FALSE and 1 being TRUE. If any one boss is still alive/enabled it makes check var > 0
                    }

                    if (nAllBossesSlainCheck<=0){
                        for (int nFastTravelTile=0; nFastTravelTile<(sArea->nTotalFastTravelTiles); nFastTravelTile++){
                            sArea->sFastTravels[nFastTravelTile].nLocked=0;
                        } // Unlocks all fast travel tiles upon defeat of all bosses
                     }
                    break;
                case 5:
                    nLandedFastTravel=0;
                    int nCounter=0;
                    for (int nFastTravelTile=0; nFastTravelTile<sArea->nTotalFastTravelTiles; nFastTravelTile++){
                        for (int nCoordinate=0; nCoordinate<3; nCoordinate++){
                            if (sArea->sFastTravels[nFastTravelTile].nLocation[nCoordinate]==player->nPlayerPos[nCoordinate]){
                                nCounter++;
                            } else{
                                nCounter=0;
                            }
                            if (nCounter==3){
                                nLandedFastTravel=nFastTravelTile;
                            }
                        }
                    }
                    if (sArea->sFastTravels[nLandedFastTravel].nLocked==0){
                        (*nRunning)=0; // end runArea
                        player->nRunes=(*nCollectedRunes);
                        if (sArea->sBosses[0].nEnabled==0){ // Player does not get the shard if the boss is not defeated
                            player->nShards[sArea->nAreaIndex-1]=1;
                        }
                        if (strcmp(sArea->strAreaName,"Elden Throne")==0){
                            runCreditsTile();
                        }
                    }
                    break;
                default:
                    break;
            }
            break;
    }
}
