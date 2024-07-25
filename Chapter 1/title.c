#include "title.h"

void runTitle(){
    char cInput = ' ';
    do{
        displayTitle();
        processTitleInput(&cInput);
    } while (cInput != '0');
}

void displayTitle(){
    printYBorder1();
    printMiddleBorder1("EEEEE L     DDD   EEEEE N   N   RRRR ");
    printMiddleBorder1("E     L     D  D  E     NN  N   R   R");
    printMiddleBorder1("EEEEE L     D   D EEEEE N N N   RRRR ");
    printMiddleBorder1("E     L     D  D  E     N  NN   R  R ");
    printMiddleBorder1("EEEEE LLLLL DDD   EEEEE N   N   R   R");
    printMiddleBorder1("^ TEMPORARY TITLE XD");
    printYBorder1();
    printf("\n");
    printChoiceBorder1("[1] New Game", 4);
    printChoiceBorder1("[2] Load Game", 4);
    printChoiceBorder1("[0] Exit", 4);
    printChoiceBorderless1("[INPUT] : ");
}

void processTitleInput(char* cInput){
    scanf(" %c", cInput);

    Player player;

    int nSavingAllowed;
    int nGameLoaded;

    int aTestInventory[24]={1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //Each index represents a weapon in MP specs, Appendix C
    int nTestRunes;

    switch (*cInput)
    {
    case '1':
        printf("Game started!\n");
        runCharacterCreation();
        break;
    case '2': // Continue Feature. Player can select a save, load, and continue their game from roundtable
        player =setPlayer();
        nSavingAllowed=0;
        nGameLoaded=0; // Checks if the player player actually loaded a game or just opted to go back to the title screen. 0 = Back; 1 = Load
        runSaveMenu(&nGameLoaded, nSavingAllowed, &player); // nSavingAllowed = 0. Players cannot save from the title screen; only load
        printf("Game continued!\n");
        if(nGameLoaded==1){
            nTestRunes=100000;
            runRoundTable(&player, &nTestRunes, aTestInventory);
        }
        break;
    case '0':
        printf("Game Exit!\n");
        exit(0);       
    default:
        break;
    }
}