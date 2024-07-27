#include "title.h"

void runTitle(){
    char cInput = ' ';
    do{
        displayTitle();
        processTitleInput(&cInput);
    } while (cInput != '0');
}

void displayTitle(){
    printYBorder1(0, WHITE);
        printc(0, DEEP_RED, "                              ████████████  ██            ████████    ████████████  ████    ██  \n");
        printc(0, DEEP_RED, "                             ██████████    ████          ██████████  ██████████    ██████  ████\n");
        printc(0, DEEP_RED, "                            ████          ████          ████  ████  ████          ██████  ████\n");
             printc(0, RED, "                           ████████      ████          ████  ████  ████████      ████  ██████\n");
        printc(0, DEEP_RED, "                          ████          ████          ████  ████  ████          ████  ██████\n");
        printc(0, DEEP_RED, "                         ██████████    ████████████  ██████████  ██████████    ████    ████\n");
        printc(0, DEEP_RED, "                        ████████████  ████████████  ████████    ████████████    ██    ████\n");
        printf("\n");
          printc(0, ORANGE, "                               ██████████      ████████      ████████    ██        ██  ████████████\n");
          printc(0, ORANGE, "                              ████    ████  ████    ████  ████      ██  ████    ████  ██████████  \n");
          printc(0, ORANGE, "                             ████    ████  ████    ████  ████          ████    ████  ████        \n");
          printc(0, YELLOW, "                            ██████████    ████    ████  ████  ████    ████    ████  ████████    \n");
          printc(0, ORANGE, "                           ████  ████    ████    ████  ████    ████  ████    ████  ████        \n");
          printc(0, ORANGE, "                          ████    ████  ████    ████  ████    ████  ████    ████  ██████████  \n");
          printc(0, ORANGE, "                         ████      ████  ████████      ██████████    ████████    ████████████\n");
    printYBorder1(0, WHITE);
    printf("\n");
    printChoiceBorder1(0, WHITE, "[1] New Game", 4);
    printChoiceBorder1(0, WHITE, "[2] Load Game", 4);
    printChoiceBorder1(0, GRAY, "[0] Exit", 4);
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
        printf("\n\n\n\n\n");
        runCharacterCreation();
        break;
    case '2': // Continue Feature. Player can select a save, load, and continue their game from roundtable
        printf("\n\n\n\n\n");
        player =setPlayer();
        nSavingAllowed=0;
        nGameLoaded=0; // Checks if the player player actually loaded a game or just opted to go back to the title screen. 0 = Back; 1 = Load
        runSaveMenu(&nGameLoaded, nSavingAllowed, &player); // nSavingAllowed = 0. Players cannot save from the title screen; only load
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