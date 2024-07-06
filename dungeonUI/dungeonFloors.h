#pragma once

struct dungeonFloorTag{
    int nRows;
    int nCols;
    char floorName[21];
    int floorLayout[];
};

struct dungeonFloorTag initializeDungeonFloor(int dungeonNum);