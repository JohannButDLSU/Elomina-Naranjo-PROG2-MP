#include "save.h"
#include "stdlib.h"

void runSaveMenu(int* nGameLoaded, int nAllowSaving, Player *player){
    // Depending on where the player access this function (title screen or roundtable), the player should not always be allowed to save. However, they can always load
    // Bool: 0 = FALSE; 1 = TRUE
    // int nTotalSaveFiles=3; // < VOLATILE! > add anymore saves to the total(3), and those beyond the 3rd will be broken and will not save
    // Player *arrListOfSaves;
    // arrListOfSaves=malloc(sizeof(Player)*nTotalSaveFiles);
    int nRunning=1;
    int nCursor=0;
    int nOminousMessage=1;
    char cInput=' ';
    char saveSlots[3][31]={"memoryCard/saveFile1.dat","memoryCard/saveFile2.dat","memoryCard/saveFile3.dat"};

    for (int nSaveFile=0; nSaveFile<3; nSaveFile++){
        FILE *filePointer;
        if ((filePointer=fopen(saveSlots[nSaveFile],"rb"))==NULL){
            filePointer=fopen(saveSlots[nSaveFile],"wb");
            Player emptySave;
            strcpy(emptySave.strName,"EMPTY");
            strcpy(emptySave.strJobClass,"EMPTY");
            fwrite(&emptySave, sizeof(Player), 1, filePointer);
            fclose(filePointer);
        }
        fclose(filePointer);
    }

    do{
    displaySaveMenu(nOminousMessage, nAllowSaving, saveSlots, nCursor);
    // cInput=getch();
    printf(" > ");
    scanf(" %c", &cInput);
    processInputSaveMenu(&nOminousMessage, saveSlots, nGameLoaded, &nRunning, nAllowSaving, player, &nCursor, cInput);
    } while (nRunning==1);
}

void loadSave(char (*saveSlots)[31], int *nCursor, Player *player){
    Player sStoredOnFile;
    FILE *filePointer;
    filePointer=fopen(saveSlots[*nCursor],"rb");
    fread(&sStoredOnFile, sizeof(Player), 1, filePointer);
    (*player)=sStoredOnFile;
    fclose(filePointer);
}

void saveCurrentGameState(char (*saveSlots)[31], int *nCursor, Player *player){
    FILE *filePointer;
    filePointer=fopen(saveSlots[*nCursor],"wb");
    fwrite(player, (sizeof(Player)+(sizeof(int)*player->nInventorySize)), 1, filePointer);
    fclose(filePointer);
}

void printFileBox(Player sStoredOnFile, int nSaveExists, int nBoxLine, int nIndex, int nSelected){
    if (nSelected==1&&nBoxLine!=1&&nBoxLine!=2&&nBoxLine!=14){
        printc(0,15,"║ ");
    } else if (nBoxLine!=1&&nBoxLine!=2&&nBoxLine!=14){
        printc(0,8,"│ ");
    }

    if (nSaveExists==0&&nBoxLine==8){
        nBoxLine=(-1);
    } else if(nSaveExists==0&&nBoxLine!=1&&nBoxLine!=2&&nBoxLine!=14) {
        nBoxLine=0;
    }   

    switch (nBoxLine){
        case -1:
            printf("                No Data                 ");
            break;
        case 0:
            printf("                                        ");
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
            fprintf(stdout,"Name    : %-*s",30,sStoredOnFile.strName);
            break;
        case 4:
            fprintf(stdout,"Class   : %-*s",30,sStoredOnFile.strJobClass);
            break;
        case 5:
            printf("                                        ");
            break;
        case 6:
            printf("    Shards                              ");
            break;
        case 7:
            printf("   ");
            for (int nShards=0; nShards<6; nShards++){
                if (sStoredOnFile.nShards[nShards]==1){
                    printf(" ◆");
                } else {
                    printf(" ◇");
                }
            }
            printf("                         ");   
            break;
        case 8:
        printf("                                        ");
            break;
        case 9:
            fprintf(stdout,"       LVL %3d      RUNES ❖ %6d      ",sStoredOnFile.nHealth,sStoredOnFile.nEndurance);
            break;
        case 10:
            printf("                                        ");
            break;
        case 11:
            fprintf(stdout,"       HTP %3d❤️     END %3d🗿           ",sStoredOnFile.nHealth,sStoredOnFile.nEndurance);
            break;
        case 12:
            fprintf(stdout,"       FTH %3d🕯️     DEX %3d⚡          ",sStoredOnFile.nFaith,sStoredOnFile.nDexterity);
            break;
        case 13:
            fprintf(stdout,"       STR %3d💪    INT %3d🧠           ",sStoredOnFile.nFaith,sStoredOnFile.nDexterity);
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

void displaySaveMenu(int nOminousMessage, int nAllowSaving, char (*saveSlots)[31], int nCursor){
    int nSelected=0;
    int nSaveExists=0;
    Player sStoredOnFile;

    printf("\n\n");
    for (int nBoxLine=1; nBoxLine<15; nBoxLine++){
        for (int nIndex=0; nIndex<3; nIndex++){
            FILE *filePointer;
            filePointer=fopen(saveSlots[nIndex],"rb");

            if (filePointer==NULL){
                printf("error\n");
            } else{
                fread(&sStoredOnFile, sizeof(Player), 1, filePointer);

                if (0!=strcmp(sStoredOnFile.strJobClass,"EMPTY")&&0!=strcmp(sStoredOnFile.strName,"EMPTY")){
                    nSaveExists=1;
                }
                if (nCursor==nIndex){
                    nSelected=1;
                }
                printFileBox(sStoredOnFile, nSaveExists, nBoxLine, nIndex, nSelected);
                nSelected=0;
                nSaveExists=0;
            }
  
            fclose(filePointer);
        }
        printf("\n");
    }

    printf("\n");
    if (nAllowSaving==1){
        printf("(1) Save\n");
    }
    printf("(2) Load\n");
    if (nAllowSaving==1&&nOminousMessage==1){
        printf("(0) Continue without saving\n");
    } else{
        printf("(0) Back\n");
    }
}

void processInputSaveMenu(int *nOminousMessage, char (*saveSlots)[31], int* nGameLoaded, int* nRunning, int nAllowSaving, Player *player, int* nCursor, char cInput){
    Player sStoredOnFile;
    char cContinue;

    FILE *filePointer;

    switch (cInput){
        case 'A':
        case 'a':
            if ((*nCursor)>0){
                (*nCursor)--;
            };
            break;
        case 'D':
        case 'd':
            if ((*nCursor)<(3-1)){
                (*nCursor)++;
            };
            break;
        case '1':
            if (nAllowSaving==1){
                saveCurrentGameState(saveSlots, nCursor, player);
                (*nOminousMessage)=0;
            }
            break;
        case '2':
            filePointer=fopen(saveSlots[*nCursor],"rb");
            fread(&sStoredOnFile, sizeof(Player), 1, filePointer);
            if (0!=strcmp(sStoredOnFile.strName,"EMPTY")&&0!=strcmp(sStoredOnFile.strJobClass,"EMPTY")){
                loadSave(saveSlots, nCursor, player);
                (*nRunning)=0;
                (*nGameLoaded)=1;
            }
            fclose(filePointer);
            break;
        case '0':
            cContinue=' ';
            if (nAllowSaving==1&&(*nOminousMessage)==1){
                printf("\n\n\n\nYou will regret this later\n\n\n\n");
                // getch();
                scanf(" %c", &cContinue);
            }
            (*nRunning)=0;
            break;
    }
}

