#include "stdio.h"
#include "conio.h"
#include "testGame.h"
#include "saveFile.h"

// When outside level, only transactions and currencies are recorded
// When inside level, currencies, playerPosXY, and state of level is recorded.

void roundTable(struct profileTag *player){
    printf("%s  |   %s\n", player->name, player->class);
    printf("LVL. %d\n", player->level);
    printf("Shards %d\n", player->stats.shards);
    printf("Runes %d\n", player->stats.runes);
    printf("\n"); 
    printf("1 : Dungeon\n");  
    printf("2 : Save\n");
    printf("3 : Overwrite Save\n");
    printf("4 : Append Save\n");
    printf("5 : Write Binary File\n");
    printf("6 : Print pointer variable (array) into Binary File\n");
    printf("7 : Write Struct to Binary File \n"); // SAVE Player State (struct profileTag)
    printf("8 : Read Struct Binary File\n"); // LOAD Player State (struct tempProfileTag) 
    printf("\n> ");
}

void dungeon(struct profileTag *player){
    int dungeonRunes=50;
    int dungeonShard=1;
    int playerCollectedRunes=0;
    int playerCollectedShards=0;
    char cInput=' ';
    printf("Press 1 to get dungeon runes XOR press 2 to get the dungeon shard\n> ");
    scanf(" %c", &cInput);
    switch (cInput){
        case '1':
            playerCollectedRunes+=dungeonRunes; break;
        case '2':
            playerCollectedShards+=dungeonShard; break;
    }
    player->stats.runes+=playerCollectedRunes;
    player->stats.shards+=playerCollectedShards;
    printf("You got %d runes, and %d shards\n", playerCollectedRunes, playerCollectedShards);
}

void characterCreation(struct profileTag *player){
    printf("Shade, what is your name?\n> ");
    scanf(" %s", player->name);
    printf("\n%s, what is your class?\n> ", player->name);
    scanf(" %s", player->class);
    player->level=1;
    player->stats.hp=3;
    player->stats.maxHP=3;
    player->stats.mana=5;
    player->stats.runes=500;
    player->stats.shards=0;
}

void runTestGame(){
    struct profileTag player;
    char cInput=' ';

    characterCreation(&player);
    do{
        printf("\n");
        roundTable(&player);
        cInput=getch();
        printf("\n");
        switch (cInput){
            case '1':
                dungeon(&player); break;
            case '2':
                runReadSaveFile();break;
            case '3':
                runWriteSaveFile();break;
            case '4':
                appendSaveFile(); break;
            case '5':
                chadBinarySaveFile(); break;
            case '6':
                dynamicArrayBinary(); break;
            case '7':
                structBinaryFile(&player); break; // SAVE
            case '8':
                readStructBinaryFile(); break; // LOAD
        }
    }while(cInput!='0');
}