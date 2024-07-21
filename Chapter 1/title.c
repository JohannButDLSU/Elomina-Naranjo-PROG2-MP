#include "title.h"

void runTitle(){
    char cInput = ' ';
    do{
        displayTitle();
        processTitleInput(&cInput);
    } while (cInput != '0');
}

void displayTitle(){
    printf("\n");
    printf("\n");
    printf("\n");
    printf("Pretend this is the epic title!!!\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("[1] New Game\n");
    printf("[2] Continue\n");
    printf("[0] Exit\n");
    printf("[INPUT] : ");
}

void processTitleInput(char* cInput){
    // printf("\033[?25h \033[6A \033[47C");
    scanf(" %c", cInput);
    // printf("\033[6B \033[47D");

    switch (*cInput)
    {
    case '1':
        printf("Game started!\n");
        runCharacterCreation();
        break;
    case '2': // Continue Feature. Player can select a save, load, and continue their game from roundtable
        Player player =setPlayer();
        int nSavingAllowed=0;
        int nGameLoaded=0; // Checks if the player player actually loaded a game or just opted to go back to the title screen. 0 = Back; 1 = Load
        runSaveMenu(&nGameLoaded, nSavingAllowed, &player); // nSavingAllowed = 0. Players cannot save from the title screen; only load
        printf("Game continued!\n");
        if(nGameLoaded==1){
            int aTestInventory[24]={1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //Each index represents a weapon in MP specs, Appendix C
            int nTestRunes=100000;
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