#pragma once
#include "../_Global Folder/areaStructures.h"


void initializeFloorDimensions(int (*arrFloorDimensions)[2], struct sAreaData* sTempArea);
void initializeBossTile(int (*arrBossTileData)[4], struct sAreaData* sTempArea);
void initializeDoorPairTile(int (*arrDoorPairData)[2][4], struct sAreaData* sTempArea);
void initializeFloorLayout(int (*nFloorLayout)[15][15], struct sAreaData* sTempArea);
struct sAreaData initializeStormveilCastle();
struct sAreaData initializeRayaLucaria();
struct sAreaData initializeRedmaneCastle();
struct sAreaData initializeVolcanoManor();
struct sAreaData initializeLeyndellRoyalCapital();
struct sAreaData initializeEldenThrone();