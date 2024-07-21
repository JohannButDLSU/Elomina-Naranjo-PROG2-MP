#include "save.h"
#include "stdlib.h"

void loadSave(int nTotalSaveFiles, int *nCursor, Player *player){
    printf("Load the save here\n");
    Player *arrTempList;
    Player *storedOnFile;
    arrTempList=malloc(sizeof(Player)*nTotalSaveFiles);
    storedOnFile=malloc(sizeof(Player)*nTotalSaveFiles);

    FILE *filePointer;

    filePointer=fopen("playerSaves.dat","rb");
    fread(storedOnFile, sizeof(Player), nTotalSaveFiles, filePointer);
    for (int nIndex=0; nIndex<nTotalSaveFiles; nIndex++){
        arrTempList[nIndex]=storedOnFile[nIndex];
    }
    fclose(filePointer);
    (*player)=arrTempList[(*nCursor)];
}

void saveCurrentGameState(int nTotalSaveFiles, int *nCursor, Player *player){
    printf("Save the current game state here\n");
    Player *arrTempList;
    Player *storedOnFile;
    arrTempList=malloc(sizeof(Player)*nTotalSaveFiles);
    storedOnFile=malloc(sizeof(Player)*nTotalSaveFiles);

    FILE *filePointer;

    filePointer=fopen("playerSaves.dat","rb");
    fread(storedOnFile, sizeof(Player), nTotalSaveFiles, filePointer);
    for (int nIndex=0; nIndex<nTotalSaveFiles; nIndex++){
        arrTempList[nIndex]=storedOnFile[nIndex];
    }
    fclose(filePointer);
    arrTempList[(*nCursor)]=(*player);

    filePointer=fopen("playerSaves.dat","wb");
    fwrite(arrTempList,sizeof(Player), 3, filePointer);
    fclose(filePointer);
}

void printFileBox(Player *arrListOfSaves, int nFileExists, int nBoxLine, int nIndex, int nSelected){
    if (nSelected==1&&nBoxLine!=1&&nBoxLine!=2&&nBoxLine!=14){
        printc(0,15,"║ ");
    } else if (nBoxLine!=1&&nBoxLine!=2&&nBoxLine!=14){
        printc(0,8,"│ ");
    }

    switch (nBoxLine){
        case -1:
            printf("               No Data                 ");
            break;
        case 0:
            printf("                                       ");
            break;
        case 1:
            printf("                Save File %d                 ", nIndex+1);
            break;
        case 2:
            if (nSelected==1){
                printc(0,15,"╔══════════════════════════════════════════╗");
            } else {
                printc(0,8,"┌──────────────────────────────────────────┐");
            }
            break;
        case 3:
            fprintf(stdout,"Name    : %-*s",30,arrListOfSaves[nIndex].strName);
            break;
        case 4:
            fprintf(stdout,"Class   : %-*s",30,arrListOfSaves[nIndex].strJobClass);
            break;
        case 5:
            printf("                                        ");
            break;
        case 6:
            printf("    Shards                              ");
            break;
        case 7:
            printf("    ♢ ♦ ♦ ♢ ♢ ♢ ♢                       ");   
            break;
        case 8:
        printf("                                        ");
            break;
        case 9:
            fprintf(stdout,"       LVL %3d      RUNES %6d ❖      ",arrListOfSaves[nIndex].nHealth,arrListOfSaves[nIndex].nEndurance);
            break;
        case 10:
            printf("                                        ");
            break;
        case 11:
            fprintf(stdout,"       HTP %3d❤️     END %3d🗿           ",arrListOfSaves[nIndex].nHealth,arrListOfSaves[nIndex].nEndurance);
            break;
        case 12:
            fprintf(stdout,"       FTH %3d🕯️     DEX %3d⚡          ",arrListOfSaves[nIndex].nFaith,arrListOfSaves[nIndex].nDexterity);
            break;
        case 13:
            fprintf(stdout,"       STR %3d💪    INT %3d🧠           ",arrListOfSaves[nIndex].nFaith,arrListOfSaves[nIndex].nDexterity);
            break;
        case 14:
            if (nSelected==1){
                printc(0,15,"╚══════════════════════════════════════════╝");
            } else {
                printc(0,8,"└──────────────────────────────────────────┘");
            }
            break;
    }
    if (nSelected==1&&nBoxLine!=1&&nBoxLine!=2&&nBoxLine!=14){
        printc(0,15," ║");
    } else if (nBoxLine!=1&&nBoxLine!=2&&nBoxLine!=14){
        printc(0,8," │");
    }
}
void displaySaveMenu(int nAllowSaving, Player *arrListOfSaves, int nTotalSaveFiles, int nCursor){
    int nSelected=0;
    int nFileExists=0;

    printf("\n\n");
    for (int nBoxLine=1; nBoxLine<15; nBoxLine++){
        for (int nIndex=0; nIndex<nTotalSaveFiles; nIndex++){
            
            if (nCursor==nIndex){
                nSelected=1;
            }
            printFileBox(arrListOfSaves, nFileExists, nBoxLine, nIndex, nSelected);
            nSelected=0;
        }
        printf("\n");
    }
    printf("\n");
    if (nAllowSaving==1){
        printf("(1) Save\n");
    }
    printf("(2) Load\n");
    if (nAllowSaving==1){
        printf("(0) Continue without saving\n");
    } else{
        printf("(0) Back\n");
    }

}
void processInputSaveMenu(int* nGameLoaded, int* nRunning, int nAllowSaving, Player *player, int nTotalSaveFiles, int* nCursor, char cInput){
    switch (cInput){
        case 'A':
        case 'a':
            if ((*nCursor)>0){
                (*nCursor)--;
            };
            break;
        case 'D':
        case 'd':
            if ((*nCursor)<(nTotalSaveFiles-1)){
                (*nCursor)++;
            };
            break;
        case '1':
            if (nAllowSaving==1){
                printf("SaveCurrentState\n");
                saveCurrentGameState(nTotalSaveFiles, nCursor, player);
                (*nRunning)=0;
            }
            break;
        case '2':
            loadSave(nTotalSaveFiles, nCursor, player);
            (*nRunning)=0;
            (*nGameLoaded)=1;
            break;
        case '0':
            char cContinue=' ';
            if (nAllowSaving==1){
                printf("\n\n\n\nYou will regret this later\n\n\n\n");
                // getch();
                scanf(" %c", &cContinue);
            }
            (*nRunning)=0;
            break;
    }
}

void runSaveMenu(int* nGameLoaded, int nSavingAllowed, Player *player){
    int nAllowSaving=nSavingAllowed; // Depending on where the player access this function (title screen or roundtable), the player should not always be allowed to save. However, they can always load
    // Bool: 0 = FALSE; 1 = TRUE
    int nRunning=1;
    int nTotalSaveFiles=3; // < VOLATILE! > add anymore saves to the total(3), and those beyond the 3rd will be broken and will not save
    Player *arrListOfSaves;
    arrListOfSaves=malloc(sizeof(Player)*nTotalSaveFiles);

    char cInput=' ';
    int nCursor=0;

    FILE *filePointer;
    if ((filePointer=fopen("playerSaves.dat","rb"))==NULL){
        filePointer=fopen("playerSaves.dat","wb");
        Player emptySave;
        strcpy(emptySave.strName, " ");
        strcpy(emptySave.strJobClass, " ");
        emptySave.nLevel = 0;
        emptySave.nHealth = 0;
        emptySave.nEndurance = 0;
        emptySave.nDexterity = 0;
        emptySave.nStrength = 0;
        emptySave.nIntelligence = 0;
        emptySave.nFaith = 0;
        for (int nIndex=0; nIndex<nTotalSaveFiles; nIndex++){
            arrListOfSaves[nIndex]=emptySave;
        }
        fwrite(arrListOfSaves,sizeof(Player), nTotalSaveFiles, filePointer);
        fclose(filePointer);
    }

    filePointer=fopen("playerSaves.dat","rb");
    fread(arrListOfSaves, sizeof(Player), nTotalSaveFiles, filePointer);

    do{
    displaySaveMenu(nAllowSaving, arrListOfSaves, nTotalSaveFiles, nCursor);
    // cInput=getch();
    scanf(" %c", &cInput);
    processInputSaveMenu(nGameLoaded, &nRunning, nAllowSaving, player, nTotalSaveFiles, &nCursor, cInput);
    } while (nRunning==1);
    fclose(filePointer);
}