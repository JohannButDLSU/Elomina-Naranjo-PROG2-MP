#include "initializeAreaData.h"

struct sAreaData initializeStormveilCastle(){
    struct sAreaData sTempArea;

    sTempArea.nCurrentFloor=0;
    strcpy(sTempArea.strAreaName,"Stormveil Castle");
    sTempArea.nTotalFloors=3;
    sTempArea.nTotalDoorPairs=2;
    sTempArea.nTotalSpawnTiles=10;
    sTempArea.nTotalBossTiles=1;
    sTempArea.nTotalFastTravelTiles=2;
    sTempArea.sFloors=malloc(sizeof(struct sFloorData)*sTempArea.nTotalFloors);
    sTempArea.sDoors=malloc(sizeof(struct sDoorPairData)*sTempArea.nTotalDoorPairs);
    sTempArea.sSpawns=malloc(sizeof(struct sSpawnTileData)*sTempArea.nTotalSpawnTiles);
    sTempArea.sBosses=malloc(sizeof(struct sBossTileData)*sTempArea.nTotalBossTiles);
    sTempArea.sFastTravels=malloc(sizeof(struct sFastTravelTileData)*sTempArea.nTotalFastTravelTiles);

    int arrFloorDimensions[3][2]={{7,3},{7,7},{7,5}}; // Floor Data
    for (int nFloorIndex=0; nFloorIndex<sTempArea.nTotalFloors;nFloorIndex++){
        sTempArea.sFloors[nFloorIndex].nDimensions[0]=arrFloorDimensions[nFloorIndex][0];
        sTempArea.sFloors[nFloorIndex].nDimensions[1]=arrFloorDimensions[nFloorIndex][1];
        for (int nRow=0; nRow<sTempArea.sFloors[nFloorIndex].nDimensions[0]; nRow++){
            for (int nCol=0; nCol<sTempArea.sFloors[nFloorIndex].nDimensions[1]; nCol++){
                sTempArea.sFloors[nFloorIndex].nLayout[nRow][nCol]=0;
            }
        }
    }

    // Initialize the Door data
    // [endpoint A, endpoint B][Row coordinate, Col coordinate, Room coordinate, Locked Boolean]
    int arrDoorPairData[2][2][4]={{{0,1,0,0},{6,3,1,0}},{{0,3,1,0},{6,2,2,0}}};
    for (int nDoorPair=0; nDoorPair<sTempArea.nTotalDoorPairs; nDoorPair++){
        for(int nDoorPartner=0; nDoorPartner<2; nDoorPartner++){
            for(int nDoorPartnerData=0; nDoorPartnerData<4; nDoorPartnerData++){
                sTempArea.sDoors[nDoorPair].nEndpoints[nDoorPartner][nDoorPartnerData]=arrDoorPairData[nDoorPair][nDoorPartner][nDoorPartnerData];
            }
        // v v v Assigns the door partner coordinate to the floor layout for display/printing in area.c
        sTempArea.sFloors[sTempArea.sDoors[nDoorPair].nEndpoints[nDoorPartner][2]].nLayout[sTempArea.sDoors[nDoorPair].nEndpoints[nDoorPartner][0]][sTempArea.sDoors[nDoorPair].nEndpoints[nDoorPartner][1]]=1;
        }
    }

    // [row coordinate, column coordinate, floor coordinate], nActivated
    int arrSpawnTileData[10][4]={{1,0,0,1},{1,2,0,1},{1,3,1,1},{3,0,1,1},{3,2,1,1},{3,3,1,1},{3,4,1,1},{3,6,1,1},{5,2,1,1},{5,4,1,1}};
    for (int nSpawnTile=0; nSpawnTile<(sTempArea.nTotalSpawnTiles); nSpawnTile++){
        sTempArea.sSpawns[nSpawnTile].nLocation[0]=arrSpawnTileData[nSpawnTile][0]; // Row 
        sTempArea.sSpawns[nSpawnTile].nLocation[1]=arrSpawnTileData[nSpawnTile][1]; // Column
        sTempArea.sSpawns[nSpawnTile].nLocation[2]=arrSpawnTileData[nSpawnTile][2]; // Floor
        sTempArea.sSpawns[nSpawnTile].nActive=arrSpawnTileData[nSpawnTile][3]; // bool: 0 = FALSE, 1 = TRUE
        sTempArea.sFloors[arrSpawnTileData[nSpawnTile][2]].nLayout[arrSpawnTileData[nSpawnTile][0]][arrSpawnTileData[nSpawnTile][1]]=2; // Place the spawn tile on the floor layout
    }

    // [row coordinate, column coordinate, floor coordinaate, is it locked?]
    int arrBossTileData[1][4]={{3,2,2,1}};
    for (int nBossTile=0; nBossTile<(sTempArea.nTotalBossTiles); nBossTile++){
        sTempArea.sBosses[nBossTile].nLocation[0]=arrBossTileData[nBossTile][0]; // Row
        sTempArea.sBosses[nBossTile].nLocation[1]=arrBossTileData[nBossTile][1]; // Column
        sTempArea.sBosses[nBossTile].nLocation[2]=arrBossTileData[nBossTile][2]; // Floor
        sTempArea.sBosses[nBossTile].nEnabled=arrBossTileData[nBossTile][3]; // Whether boss is accessible/active
        sTempArea.sFloors[sTempArea.sBosses[nBossTile].nLocation[2]].nLayout[sTempArea.sBosses[nBossTile].nLocation[0]][sTempArea.sBosses[nBossTile].nLocation[1]]=4;
    }

    // [row coordinate, column coordinate, floor coordinate, is it locked?]
    int arrFastTravelTileData[2][4]={{0,2,2,1},{6,1,0,1}};
    for (int nFastTravelTile=0; nFastTravelTile<(sTempArea.nTotalFastTravelTiles); nFastTravelTile++){
        sTempArea.sFastTravels[nFastTravelTile].nLocation[0]=arrFastTravelTileData[nFastTravelTile][0]; // Row
        sTempArea.sFastTravels[nFastTravelTile].nLocation[1]=arrFastTravelTileData[nFastTravelTile][1]; // Column
        sTempArea.sFastTravels[nFastTravelTile].nLocation[2]=arrFastTravelTileData[nFastTravelTile][2]; // Floor
        sTempArea.sFastTravels[nFastTravelTile].nLocked=arrFastTravelTileData[nFastTravelTile][3]; // Whether it is locked or unlocked to the player
        sTempArea.sFloors[sTempArea.sFastTravels[nFastTravelTile].nLocation[2]].nLayout[sTempArea.sFastTravels[nFastTravelTile].nLocation[0]][sTempArea.sFastTravels[nFastTravelTile].nLocation[1]]=5;
    }

    // Manually set the walls of the floor
    // [Number of floors][the highest possible number of ROWS in any given floor of the area][the highest possible number of CLOUMNS in any given floor of the area]
    int nWalls[3][7][7]={ // 0, cell to be ignored, 6 cell becomes wall
        {{0,0,0},
        {0,0,0},
        {0,0,0},
        {0,0,0},
        {0,0,0},
        {0,0,0},
        {0,0,0}},

        {{6,0,0,0,0,0,6},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {6,0,0,0,0,0,6}},

        {{6,0,0,0,6},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {6,0,0,0,6}}
    };

    for (int nFloor=0; nFloor<(sTempArea.nTotalFloors); nFloor++){
        for (int nRow=0; nRow<(sTempArea.sFloors[nFloor].nDimensions[0]); nRow++){
            for (int nCol=0; nCol<(sTempArea.sFloors[nFloor].nDimensions[1]); nCol++){
                if (nWalls[nFloor][nRow][nCol]==6){
                    sTempArea.sFloors[nFloor].nLayout[nRow][nCol]=6;
                }
            }
        }
    }
    
    return sTempArea;
}