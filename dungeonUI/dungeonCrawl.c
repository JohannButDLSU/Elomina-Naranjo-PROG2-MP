#include "dungeonCrawl.h"
#include "dungeonFloors.h"

// void displayDungeonFloor(int dungeonNum){
//     struct dungeonFloorTag displayFloor;
//     displayFloor=initializeDungeonFloor(dungeonNum);

//     for (int i=0; i<nRows; i++){
//         printf("\t");
//         for (int j=0; j<nCols; j++){
//             printf(" %c ", floorlayout[i][j]);
//         }
//         printf("\n");
//     }
// }

void runDungeonCrawl(int dungeonNum){
    char cInput=' ';
    
    do{
        // displayDungeonFloor(1);
        printf("\tDungeonCrawl initiated\n");
        cInput=getch();
    }while(cInput!='0');
}
