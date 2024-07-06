#include "dungeonSelectScreen.h"
#include "dungeonCrawl.h"

void runDungeonSelectScreen(){
    char cInput=' ';

    do{
        printf("\tThis is the dungeon select screen\n");
        printf("\tPick your dungeon: 1-Leyndell 2-Asphodel\n");
        cInput=getch();

        switch (cInput){
            case '1':
                runDungeonCrawl(1); break;
            default: break;
        }
    }while (cInput!='0');
}