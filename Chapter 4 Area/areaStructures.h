#pragma once

/*struct sDoorTileData{ // If you want to do something like this -> https://youtu.be/niHLcQSj9k8?si=Y4hYVaEEZgY43S_u&t=27 
    int nLocked; // 0 unlocked/interactible, 1 locked
    int nLocation[3]; // arrLocation[]=(row coordinate, col coordinate, nFloor coordinate)
    int nDestination[3]; // arrDestination[]=(row coordinate destination, col coordinate destination, floor coordinate)
};*/

struct sDoorPairData{
    int nEndpoints[2][4]; // [endpoint A, endpoint B][Row coordinate, Col coordinate, Room coordinate, Locked Boolean]
     // Locked boolean: 0 = FALSE, unlocked. 1 = TRUE, locked/innaccesible
};

struct sFloorData{
    int nDimensions[2]; // nDimensions[] = {n,m}, where nLayout[n][m]
    int nLayout[17][17]; 
};

struct sSpawnTileData{
    int nAreaIndex; // Index of the area
    int nLocation[3]; // [row coordinate, column coordinate, floor coordinate]
    int nActive; // bool: 0 = FALSE, 1 = TRUE. "When a spawn tile has been triggered, it remains disabled until the player leaves the area"
};

struct sBossTileData{
    int nLocation[3];
    int nEnabled; // bool: 0 = FALSE, 1 = TRUE. You cant fight a boss twice in a run
};

struct sFastTravelTileData{
    int nLocation[3]; // [row coordinate, column coordinate, floor coordinate]
    int nLocked; // Locked boolean: 0 = FALSE, unlocked. 1 = TRUE, locked/innaccesible
};

struct sAreaData{ // Area Data
    int nTotalFloors; // How many floors in this area
    int nTotalDoorPairs; // How many doors in this area
    int nTotalSpawnTiles; // How many spawn tiles in area
    int nTotalBossTiles; // How many boss tiles in area
    int nTotalFastTravelTiles; // How many fast travel tiles in area
    char strAreaName[31]; // The name of the Area
    struct sFloorData* sFloors; // an array of floor layouts
    struct sDoorPairData* sDoors; // an array of structs Doors
    struct sSpawnTileData* sSpawns; // an array of structs Spawn tile
    struct sBossTileData* sBosses; // an array of structs Boss tile
    struct sFastTravelTileData* sFastTravels; // an array of structs fast travel tile
};





