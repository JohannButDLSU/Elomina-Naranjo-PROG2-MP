#include "dungeonFloors.h"

struct dungeonFloorTag initializeDungeonFloor(int dungeonNum){
    struct dungeonFloorTag dungeonFloor;
    switch (dungeonNum){
        case 1:
            dungeonFloor.nRows=3;
            dungeonFloor.nCols=5;
            dungeonFloor.floorName[21]="level1Leyndell";
            dungeonFloor->floorLayout=malloc(sizeof(int)*dungeonFloor.nRows*dungeonFloor.nCols);
            break;
            
    }
}