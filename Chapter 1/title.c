#include "title.h"

void runTitle(){
    char cInput = ' ';
    do{
        displayTitle();
        processTitleInput(&cInput);
    } while (cInput != '0');
}

void displayTitle(){
    printYBorder(0, WHITE, BORDER_1_LENGTH);
    printf("\n");
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
    printYBorder(0, WHITE, BORDER_1_LENGTH);
    printf("\n");
    printChoiceBorder(0, WHITE, "[1] New Game ", 4, BORDER_1_LENGTH);
    printChoiceBorder(0, WHITE, "[2] Load Game", 4, BORDER_1_LENGTH);
    printChoiceBorder(0, GRAY, "[0] Exit     ", 4, BORDER_1_LENGTH);
    printChoiceBorderless("[INPUT] : ", BORDER_1_LENGTH);
}

void processTitleInput(char* cInput){
    scanf(" %c", cInput);

    Player player;

    int nSavingAllowed;
    int nGameLoaded;
    switch (*cInput)
    {
    case '1':
        printf("\n\n\n\n\n");
        runCharacterCreation();
        break;
    case '2': // Continue Feature. Player can select a save, load, and continue their game from roundtable
        printf("\n\n\n\n\n");
        player=setPlayer();
        nSavingAllowed=0;
        nGameLoaded=0; // Checks if the player player actually loaded a game or just opted to go back to the title screen. 0 = Back; 1 = Load
        runSaveMenu(&nGameLoaded, nSavingAllowed, &player); // nSavingAllowed = 0. Players cannot save from the title screen; only load
        if(nGameLoaded==1){
            runRoundTable(&player);
        }
        break;
    case '0':
        // printf("Game Exit!\n");
        exit(0);       
    default:
        printRepeatedly(6,"\t");
        printf("     Invalid Input\n\n\n");
        break;
    }
}