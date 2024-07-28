#include "initializeAreaData.h"

void initializeFloorDimensions(int (*arrFloorDimensions)[2], struct sAreaData* sTempArea){
    for (int nFloorIndex=0; nFloorIndex<sTempArea->nTotalFloors;nFloorIndex++){
        sTempArea->sFloors[nFloorIndex].nDimensions[0]=arrFloorDimensions[nFloorIndex][0];
        sTempArea->sFloors[nFloorIndex].nDimensions[1]=arrFloorDimensions[nFloorIndex][1];
        for (int nRow=0; nRow<sTempArea->sFloors[nFloorIndex].nDimensions[0]; nRow++){
            for (int nCol=0; nCol<sTempArea->sFloors[nFloorIndex].nDimensions[1]; nCol++){
                sTempArea->sFloors[nFloorIndex].nLayout[nRow][nCol]=0;
            }
        }
    }
}

void initializeBossTile(int (*arrBossTileData)[4], struct sAreaData* sTempArea){
    for (int nBossTile=0; nBossTile<(sTempArea->nTotalBossTiles); nBossTile++){
        sTempArea->sBosses[nBossTile].nLocation[0]=arrBossTileData[nBossTile][0]; // Row
        sTempArea->sBosses[nBossTile].nLocation[1]=arrBossTileData[nBossTile][1]; // Column
        sTempArea->sBosses[nBossTile].nLocation[2]=arrBossTileData[nBossTile][2]; // Floor
        sTempArea->sBosses[nBossTile].nEnabled=arrBossTileData[nBossTile][3]; // Whether boss is accessible/active
        sTempArea->sFloors[sTempArea->sBosses[nBossTile].nLocation[2]].nLayout[sTempArea->sBosses[nBossTile].nLocation[0]][sTempArea->sBosses[nBossTile].nLocation[1]]=4;
    }
}

void initializeFastTravelTile(int (*arrFastTravelTileData)[4], struct sAreaData* sTempArea){
    for (int nFastTravelTile=0; nFastTravelTile<(sTempArea->nTotalFastTravelTiles); nFastTravelTile++){
        sTempArea->sFastTravels[nFastTravelTile].nLocation[0]=arrFastTravelTileData[nFastTravelTile][0]; // Row
        sTempArea->sFastTravels[nFastTravelTile].nLocation[1]=arrFastTravelTileData[nFastTravelTile][1]; // Column
        sTempArea->sFastTravels[nFastTravelTile].nLocation[2]=arrFastTravelTileData[nFastTravelTile][2]; // Floor
        sTempArea->sFastTravels[nFastTravelTile].nLocked=arrFastTravelTileData[nFastTravelTile][3]; // Whether it is locked or unlocked to the player
        sTempArea->sFloors[sTempArea->sFastTravels[nFastTravelTile].nLocation[2]].nLayout[sTempArea->sFastTravels[nFastTravelTile].nLocation[0]][sTempArea->sFastTravels[nFastTravelTile].nLocation[1]]=5;
    }
}

void initializeDoorPairTile(int (*arrDoorPairData)[2][4], struct sAreaData* sTempArea){
    for (int nDoorPair=0; nDoorPair<sTempArea->nTotalDoorPairs; nDoorPair++){
        for(int nDoorPartner=0; nDoorPartner<2; nDoorPartner++){
            for(int nDoorPartnerData=0; nDoorPartnerData<4; nDoorPartnerData++){
                sTempArea->sDoors[nDoorPair].nEndpoints[nDoorPartner][nDoorPartnerData]=arrDoorPairData[nDoorPair][nDoorPartner][nDoorPartnerData];
            }
        // v v v Assigns the door partner coordinate to the floor layout for display/printing in area.c
        sTempArea->sFloors[sTempArea->sDoors[nDoorPair].nEndpoints[nDoorPartner][2]].nLayout[sTempArea->sDoors[nDoorPair].nEndpoints[nDoorPartner][0]][sTempArea->sDoors[nDoorPair].nEndpoints[nDoorPartner][1]]=1;
        }
    }
}

void initializeFloorLayout(int (*nFloorLayout)[15][15], struct sAreaData* sTempArea){
    for (int nFloor=0; nFloor<(sTempArea->nTotalFloors); nFloor++){
            for (int nRow=0; nRow<(sTempArea->sFloors[nFloor].nDimensions[0]); nRow++){
                for (int nCol=0; nCol<(sTempArea->sFloors[nFloor].nDimensions[1]); nCol++){
                    if (nFloorLayout[nFloor][nRow][nCol]==6){
                        sTempArea->sFloors[nFloor].nLayout[nRow][nCol]=6;
                    } else if (nFloorLayout[nFloor][nRow][nCol]==2){
                        sTempArea->sFloors[nFloor].nLayout[nRow][nCol]=2;
                    }
                }
            }
        }
}

struct sAreaData initializeStormveilCastle(){
    struct sAreaData sTempArea;

    strcpy(sTempArea.strAreaName,"Stormveil Castle");
    sTempArea.nTotalFloors=3;
    sTempArea.nTotalDoorPairs=2;
    sTempArea.nTotalBossTiles=1;
    sTempArea.nTotalFastTravelTiles=2;
    sTempArea.sFloors=malloc(sizeof(struct sFloorData)*sTempArea.nTotalFloors);
    sTempArea.sDoors=malloc(sizeof(struct sDoorPairData)*sTempArea.nTotalDoorPairs);
    sTempArea.sBosses=malloc(sizeof(struct sBossTileData)*sTempArea.nTotalBossTiles);
    sTempArea.sFastTravels=malloc(sizeof(struct sFastTravelTileData)*sTempArea.nTotalFastTravelTiles);

    // Initilialize layout of each room based on their corresponding dimensions
    int arrFloorDimensions[3][2]={{7,3},{7,7},{7,5}}; // Floor Data
    initializeFloorDimensions(arrFloorDimensions, &sTempArea);

    // Initialize the Door data
    // [endpoint A, endpoint B][Row coordinate, Col coordinate, Room coordinate, Locked Boolean]
    int arrDoorPairData[2][2][4]={{{0,1,0,0},{6,3,1,0}},{{0,3,1,0},{6,2,2,0}}};
    initializeDoorPairTile(arrDoorPairData, &sTempArea);

    // Initialize the boss data
    // [row coordinate, column coordinate, floor coordinaate, is it locked?]
    int arrBossTileData[1][4]={{3,2,2,1}};
    initializeBossTile(arrBossTileData, &sTempArea);

    // Initialize the fast travel tiles
    // [row coordinate, column coordinate, floor coordinate, is it locked?]
    int arrFastTravelTileData[2][4]={{6,1,0,0},{0,2,2,1}};
    initializeFastTravelTile(arrFastTravelTileData, &sTempArea);

    // Manually set the walls of the floor
    // [Number of floors][the highest possible number of ROWS in any given floor of the area][the highest possible number of CLOUMNS in any given floor of the area]
    //[Number of rooms][15 is the highest possible number of rows in the game][15 is the highest possible number of columns in the game]
    int nFloorLayout[3][15][15]={ // 0, cell to be ignored, 2 cell becomes spawn tile,  6 cell becomes wall
        {{0,0,0},
        {2,0,2},
        {0,0,0},
        {0,0,0},
        {0,0,0},
        {0,0,0},
        {0,0,0}},

        {{0,0,0,0,0,0,0},
        {0,0,0,2,0,0,0},
        {0,0,0,0,0,0,0},
        {2,0,2,2,2,0,2},
        {0,0,0,0,0,0,0},
        {0,0,2,0,2,0,0},
        {0,0,0,0,0,0,0}},

        {{0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}}
    };
    initializeFloorLayout(nFloorLayout, &sTempArea);

    return sTempArea;
}

//======================================================================================================

struct sAreaData initializeRayaLucaria(){
    struct sAreaData sTempArea;

    strcpy(sTempArea.strAreaName,"Raya Lucaria");
    sTempArea.nTotalFloors=5;
    sTempArea.nTotalDoorPairs=4;
    sTempArea.nTotalBossTiles=1;
    sTempArea.nTotalFastTravelTiles=2;
    sTempArea.sFloors=malloc(sizeof(struct sFloorData)*sTempArea.nTotalFloors);
    sTempArea.sDoors=malloc(sizeof(struct sDoorPairData)*sTempArea.nTotalDoorPairs);
    sTempArea.sBosses=malloc(sizeof(struct sBossTileData)*sTempArea.nTotalBossTiles);
    sTempArea.sFastTravels=malloc(sizeof(struct sFastTravelTileData)*sTempArea.nTotalFastTravelTiles);

    int arrFloorDimensions[5][2]={{5,5},{7,3},{7,5},{5,6},{8,7}}; // Floor Data
    initializeFloorDimensions(arrFloorDimensions, &sTempArea);

    // Initialize the Door data
    // [endpoint A, endpoint B][Row coordinate, Col coordinate, Room coordinate, Locked Boolean]
    int arrDoorPairData[4][2][4]={{{4,2,0,0},{0,1,1,0}},{{3,2,1,0},{3,0,2,0}},{{3,4,2,0},{2,0,3,0}},{{0,2,2,0},{7,3,4,0}}};
    initializeDoorPairTile(arrDoorPairData, &sTempArea);

    // [row coordinate, column coordinate, floor coordinaate, is it locked?]
    int arrBossTileData[1][4]={{4,3,4,1}};
    initializeBossTile(arrBossTileData, &sTempArea);

    // [row coordinate, column coordinate, floor coordinate, is it locked?]
    int arrFastTravelTileData[2][4]={{0,2,0,0},{0,3,4,1}};
    initializeFastTravelTile(arrFastTravelTileData, &sTempArea);

    // Manually set the walls of the floor
    // [Number of floors][the highest possible number of ROWS in any given floor of the area][the highest possible number of CLOUMNS in any given floor of the area]
    int nFloorLayout[5][15][15]={ // 0, cell to be ignored, 6 cell becomes wall
        {
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,2,0,2,0},
            {0,0,0,0,0}
        },
        {
            {0,0,0},
            {2,0,0},
            {0,0,0},
            {2,0,0},
            {0,0,0},
            {2,0,0},
            {0,0,0}
        },
        {
            {6,0,0,0,6},
            {6,0,2,0,6},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {6,0,2,0,6},
            {6,0,0,0,6}
        },
        {
            {6,0,0,0,0,0},
            {0,0,2,0,2,0},
            {0,0,0,0,0,0},
            {0,0,2,0,2,0},
            {6,0,0,0,0,0}
        },
        {
            {6,6,0,0,0,6,6},
            {0,0,0,0,0,0,0},
            {0,2,0,2,0,2,0},
            {0,0,0,0,0,0,0},
            {0,2,0,0,0,2,0},
            {0,0,0,0,0,0,0},
            {0,2,0,0,0,2,0},
            {0,0,0,0,0,0,0},
        }

    };
    initializeFloorLayout(nFloorLayout, &sTempArea);
    return sTempArea;
}

// ==================================================================

struct sAreaData initializeRedmaneCastle(){
    struct sAreaData sTempArea;

    strcpy(sTempArea.strAreaName,"RedMane Castle");
    sTempArea.nTotalFloors=7;
    sTempArea.nTotalDoorPairs=6;
    sTempArea.nTotalBossTiles=1;
    sTempArea.nTotalFastTravelTiles=2;
    sTempArea.sFloors=malloc(sizeof(struct sFloorData)*sTempArea.nTotalFloors);
    sTempArea.sDoors=malloc(sizeof(struct sDoorPairData)*sTempArea.nTotalDoorPairs);
    sTempArea.sBosses=malloc(sizeof(struct sBossTileData)*sTempArea.nTotalBossTiles);
    sTempArea.sFastTravels=malloc(sizeof(struct sFastTravelTileData)*sTempArea.nTotalFastTravelTiles);

    int arrFloorDimensions[7][2]={{3,5},{3,7},{5,5},{5,7},{3,5},{9,4},{5,7}}; // Floor Data
    initializeFloorDimensions(arrFloorDimensions, &sTempArea);

    // Initialize the Door data
    // [endpoint A, endpoint B][Row coordinate, Col coordinate, Room coordinate, Locked Boolean]
    int arrDoorPairData[6][2][4]={
        {{1,4,0,0},{1,0,1,0}},
        {{1,6,1,0},{2,0,2,0}},
        {{0,2,2,0},{4,3,3,0}},
        {{2,0,3,0},{1,4,4,0}},
        {{1,0,4,0},{7,3,5,0}},
        {{1,3,5,0},{2,0,6,0}}
        };
    initializeDoorPairTile(arrDoorPairData, &sTempArea);

    // [row coordinate, column coordinate, floor coordinaate, is it Enabled?]
    int arrBossTileData[1][4]={{2,3,6,0}};
    initializeBossTile(arrBossTileData, &sTempArea);

    // [row coordinate, column coordinate, floor coordinate, is it locked?]
    int arrFastTravelTileData[2][4]={{1,0,0,0},{2,6,6,1}};
    initializeFastTravelTile(arrFastTravelTileData, &sTempArea);

    // Manually set the walls of the floor
    // [Number of floors][the highest possible number of ROWS in any given floor of the area][the highest possible number of CLOUMNS in any given floor of the area]
    int nFloorLayout[7][15][15]={ // 0, cell to be ignored, 6 cell becomes wall
        {
            {0,0,0,0,0},
            {0,0,2,0,0},
            {0,0,0,0,0}
        },
        {
            {0,2,0,2,0,2,0},
            {0,0,0,0,0,0,0},
            {0,2,0,2,0,2,0}
        },
        {
            {0,0,0,0,0},
            {0,0,0,0,2},
            {0,0,0,0,0},
            {0,0,0,0,2},
            {0,2,0,2,0}
        },
        {
            {0,0,0,2,0,0,0},
            {0,2,0,0,0,2,0},
            {0,2,0,2,0,2,0},
            {0,2,0,0,0,2,0},
            {0,0,0,0,0,0,0}
        },
        {
            {0,0,0,0,0},
            {0,0,2,0,0},
            {0,0,0,0,0}
        },
        {
            {0,0,0,0},
            {0,2,0,0},
            {0,0,0,0},
            {2,0,2,6},
            {0,0,0,6},
            {2,0,2,6},
            {0,0,0,0},
            {0,2,0,0},
            {0,0,0,0}
        },
        {
            {0,0,0,0,0,0,0},
            {0,2,0,0,0,2,0},
            {0,0,0,0,0,0,0},
            {0,2,0,0,0,2,0},
            {0,0,0,0,0,0,0}
        }
    };
    initializeFloorLayout(nFloorLayout, &sTempArea);
    return sTempArea;
}

// ==================================================================

struct sAreaData initializeVolcanoManor(){
    struct sAreaData sTempArea;

    strcpy(sTempArea.strAreaName,"Volcano Manor");
    sTempArea.nTotalFloors=7;
    sTempArea.nTotalDoorPairs=6;
    sTempArea.nTotalBossTiles=1;
    sTempArea.nTotalFastTravelTiles=2;
    sTempArea.sFloors=malloc(sizeof(struct sFloorData)*sTempArea.nTotalFloors);
    sTempArea.sDoors=malloc(sizeof(struct sDoorPairData)*sTempArea.nTotalDoorPairs);
    sTempArea.sBosses=malloc(sizeof(struct sBossTileData)*sTempArea.nTotalBossTiles);
    sTempArea.sFastTravels=malloc(sizeof(struct sFastTravelTileData)*sTempArea.nTotalFastTravelTiles);

    int arrFloorDimensions[7][2]={{5,5},{7,7},{5,5},{5,7},{4,3},{8,3},{7,5}}; // Floor Data
    initializeFloorDimensions(arrFloorDimensions, &sTempArea);

    // Initialize the Door data
    // [endpoint A, endpoint B][Row coordinate, Col coordinate, Room coordinate, Locked Boolean]
    int arrDoorPairData[6][2][4]={
        {{0,2,0,0},{6,3,1,0}},
        {{3,0,1,0},{2,4,2,0}},
        {{3,6,1,0},{2,0,3,0}},
        {{0,3,3,0},{3,1,4,0}},
        {{0,3,1,0},{7,1,5,0}},
        {{0,1,5,0},{6,2,6,0}}
        };
    initializeDoorPairTile(arrDoorPairData, &sTempArea);

    // [row coordinate, column coordinate, floor coordinaate, is it Enabled?]
    int arrBossTileData[1][4]={{3,2,6,0}};
    initializeBossTile(arrBossTileData, &sTempArea);

    // [row coordinate, column coordinate, floor coordinate, is it locked?]
    int arrFastTravelTileData[2][4]={{4,2,0,0},{0,2,6,1}};
    initializeFastTravelTile(arrFastTravelTileData, &sTempArea);

    // Manually set the walls of the floor
    // [Number of floors][the highest possible number of ROWS in any given floor of the area][the highest possible number of CLOUMNS in any given floor of the area]
    int nFloorLayout[7][15][15]={ // 0, cell to be ignored, 6 cell becomes wall
        {
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,2,2,2,0},
            {0,0,0,0,0},
            {0,0,0,0,0}
        },
        {
            {0,0,0,0,0,0,0},
            {0,0,0,2,0,0,0},
            {0,0,0,0,0,0,0},
            {0,2,0,2,0,2,0},
            {0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0}
        },
        {
            {6,0,2,0,0},
            {0,0,0,0,0},
            {2,0,2,0,0},
            {0,0,0,0,0},
            {6,0,2,0,0}
        },
        {
            {6,0,0,0,0,0,6},
            {0,0,2,0,2,0,0},
            {0,0,0,0,0,0,2},
            {0,0,2,0,2,0,0},
            {6,0,0,0,0,0,6}
        },
        {
            {0,0,0},
            {0,2,0},
            {0,0,0},
            {6,0,6}
        },
        {
            {0,0,0},
            {0,2,0},
            {2,0,2},
            {0,0,0},
            {0,0,0},
            {2,0,2},
            {0,0,0},
            {0,0,0}
        },
        {
            {0,0,0,0,0},
            {0,0,0,0,0},
            {2,0,0,0,2},
            {2,0,0,0,2},
            {2,0,0,0,2},
            {0,0,0,0,0},
            {0,0,0,0,0}
        }
    };
    initializeFloorLayout(nFloorLayout, &sTempArea);
    return sTempArea;
}

//=============================================================================================

struct sAreaData initializeLeyndellRoyalCapital(){
    struct sAreaData sTempArea;

    strcpy(sTempArea.strAreaName,"Leyndell Royal Capital");
    sTempArea.nTotalFloors=14;
    sTempArea.nTotalDoorPairs=17;
    sTempArea.nTotalBossTiles=1;
    sTempArea.nTotalFastTravelTiles=2;
    sTempArea.sFloors=malloc(sizeof(struct sFloorData)*sTempArea.nTotalFloors);
    sTempArea.sDoors=malloc(sizeof(struct sDoorPairData)*sTempArea.nTotalDoorPairs);
    sTempArea.sBosses=malloc(sizeof(struct sBossTileData)*sTempArea.nTotalBossTiles);
    sTempArea.sFastTravels=malloc(sizeof(struct sFastTravelTileData)*sTempArea.nTotalFastTravelTiles);

    int arrFloorDimensions[14][2]={{4,3},{7,3},{5,5},{3,5},{4,15},{3,3},{7,3},{7,3},{7,3},{4,15},{13,13},{3,3},{3,3},{7,5}}; // Floor Data
    initializeFloorDimensions(arrFloorDimensions, &sTempArea);

    // Initialize the Door data
    // [endpoint A, endpoint B][Row coordinate, Col coordinate, Room coordinate, Locked Boolean]
    int arrDoorPairData[17][2][4]={
        {{0,1,0,0},{6,1,1,0}},
        {{0,1,1,0},{4,2,2,0}},
        {{2,4,2,0},{1,0,3,0}},
        {{0,2,3,0},{3,13,4,0}},
        {{0,13,4,0},{6,1,8,0}},
        {{0,7,4,0},{6,1,7,0}},
        {{0,1,4,0},{6,1,6,0}},
        {{3,1,4,0},{0,1,5,0}},
        {{3,2,6,0},{3,0,7,0}},
        {{3,2,7,0},{3,0,8,0}},
        {{0,1,6,0},{3,1,9,0}},
        {{0,1,7,0},{3,7,9,0}},
        {{0,1,8,0},{3,13,9,0}},
        {{0,7,9,0},{12,6,10,0}},
        {{9,0,10,0},{1,2,11,0}},
        {{9,12,10,0},{1,0,12,0}},
        {{1,6,10,0},{0,2,13,0}}
        };
    initializeDoorPairTile(arrDoorPairData, &sTempArea);

    // [row coordinate, column coordinate, floor coordinaate, is it locked?]
    int arrBossTileData[1][4]={{3,2,13,1}};
    initializeBossTile(arrBossTileData, &sTempArea);

    // [row coordinate, column coordinate, floor coordinate, is it locked?]
    int arrFastTravelTileData[2][4]={{3,1,0,0},{6,2,13,1}};
    initializeFastTravelTile(arrFastTravelTileData, &sTempArea);

    // Manually set the walls of the floor
    // [Number of floors][the highest possible number of ROWS in any given floor of the area][the highest possible number of CLOUMNS in any given floor of the area]
    int nFloorLayout[14][15][15]={ // 0, cell to be ignored, 6 cell becomes wall
        {
            {0,0,0,0},
            {0,0,0,0},
            {0,0,0,0},
            {0,0,0,0}
        },
        {
            {0,0,0},
            {2,0,2},
            {0,0,0},
            {2,0,2},
            {0,0,0},
            {2,0,2},
            {0,0,0}
        },
        {
            {0,0,2,0,0},
            {0,6,6,6,0},
            {2,6,6,6,0},
            {0,6,6,6,0},
            {0,0,0,0,0}
        },
        {
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,2,0,2,0}
        },
        {
            {2,0,2,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,2,0,0,2,0,2,0,2,0,2,0,0,0,0},
            {0,0,0,6,6,6,6,6,6,6,6,6,0,0,0},
            {0,0,0,6,6,6,6,6,6,6,6,6,0,0,0}
        },
        {
            {0,0,0},
            {0,0,0},
            {2,2,2}
        },
        {
            {6,0,6},
            {2,2,2},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {2,2,2},
            {6,0,6}
        },
        {
            {6,0,6},
            {2,0,2},
            {2,0,2},
            {0,0,0},
            {2,0,2},
            {2,0,2},
            {6,0,6}
        },
        {
            {6,0,6},
            {2,2,2},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {2,2,2},
            {6,0,6}
        },
        {
            {0,0,0,2,0,0,0,0,0,0,0,2,0,0,0},
            {0,0,0,2,0,0,0,0,0,0,0,2,0,0,0},
            {0,0,0,2,0,0,0,0,0,0,0,2,0,0,0},
            {0,0,0,2,0,0,0,0,0,0,0,2,0,0,0}
        },
        {
            {2,0,0,2,0,0,0,0,6,6,6,6,6},
            {0,0,0,2,0,0,0,0,6,6,6,6,6},
            {2,0,6,6,6,6,6,6,6,6,6,6,6},
            {0,0,6,6,6,0,0,0,6,6,6,6,6},
            {2,0,6,6,0,0,0,0,0,6,6,6,6},
            {0,0,6,6,0,0,0,0,0,6,6,6,6},
            {2,0,6,6,0,0,0,0,0,6,6,6,6},
            {0,0,6,6,0,0,0,0,0,6,6,6,6},
            {2,0,6,6,0,0,0,0,0,6,6,0,2},
            {0,0,6,6,6,0,0,0,6,6,6,0,0},
            {2,0,6,6,6,6,6,6,6,6,6,0,2},
            {0,0,0,0,0,0,0,0,0,0,0,0,0},
            {2,0,0,0,0,2,0,2,0,0,0,0,2}
        },
        {
            {0,0,0},
            {2,0,0},
            {0,0,0}
        },{
            {0,0,0},
            {0,0,2},
            {0,0,0}
        },
        {
            {6,0,0,0,6},
            {2,0,0,0,2},
            {0,0,0,0,0},
            {2,0,0,0,2},
            {0,0,0,0,0},
            {2,0,0,0,2},
            {6,0,0,0,6}
        },
    };

    initializeFloorLayout(nFloorLayout, &sTempArea);
    return sTempArea;
}

// ==================================================================

struct sAreaData initializeEldenThrone(){
    struct sAreaData sTempArea;

    strcpy(sTempArea.strAreaName,"Elden Throne");
    sTempArea.nTotalFloors=3;
    sTempArea.nTotalDoorPairs=2;
    sTempArea.nTotalBossTiles=2;
    sTempArea.nTotalFastTravelTiles=2;
    sTempArea.sFloors=malloc(sizeof(struct sFloorData)*sTempArea.nTotalFloors);
    sTempArea.sDoors=malloc(sizeof(struct sDoorPairData)*sTempArea.nTotalDoorPairs);
    sTempArea.sBosses=malloc(sizeof(struct sBossTileData)*sTempArea.nTotalBossTiles);
    sTempArea.sFastTravels=malloc(sizeof(struct sFastTravelTileData)*sTempArea.nTotalFastTravelTiles);

    int arrFloorDimensions[3][2]={{9,3},{7,7},{9,3}}; // Floor Data
    initializeFloorDimensions(arrFloorDimensions, &sTempArea);

    // Initialize the Door data
    // [endpoint A, endpoint B][Row coordinate, Col coordinate, Room coordinate, Locked Boolean]
    int arrDoorPairData[2][2][4]={
        {{0,1,0,0},{6,3,1,0}},
        {{0,3,1,0},{8,1,2,0}}
        };
    initializeDoorPairTile(arrDoorPairData, &sTempArea);

    // [row coordinate, column coordinate, floor coordinaate, is it Enabled?]
    int arrBossTileData[2][4]={{4,1,0,1},{3,3,1,0}};
    initializeBossTile(arrBossTileData, &sTempArea);

    // [row coordinate, column coordinate, floor coordinate, is it locked?]
    int arrFastTravelTileData[2][4]={{8,1,0,0},{0,1,2,1}};
    initializeFastTravelTile(arrFastTravelTileData, &sTempArea);

    // Manually set the walls of the floor
    // [Number of floors][the highest possible number of ROWS in any given floor of the area][the highest possible number of CLOUMNS in any given floor of the area]
    int nFloorLayout[3][15][15]={ // 0, cell to be ignored, 6 cell becomes wall
        {
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {0,0,0},
            {0,0,0}
        },
        {
            {6,0,0,0,0,0,6},
            {0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0},
            {6,0,0,0,0,0,6}
        },
        {
            {0,0,0},
            {2,0,2},
            {0,0,0},
            {2,0,2},
            {0,0,0},
            {2,0,2},
            {0,0,0},
            {2,0,2},
            {0,0,0}
        }
    };
    initializeFloorLayout(nFloorLayout, &sTempArea);
    return sTempArea;
}