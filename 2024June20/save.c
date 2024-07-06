#include "save.h"
#include "stdlib.h"

void saveCurrentGameState(int nTotalSaveFiles, int *nCursor, struct Player *TESTplayer){
    printf("Save the current game state here\n");
    struct Player *arrTempList;
    struct Player *storedOnFile;
    arrTempList=malloc(sizeof(struct Player)*nTotalSaveFiles);
    storedOnFile=malloc(sizeof(struct Player)*nTotalSaveFiles);

    FILE *filePointer;

    filePointer=fopen("playerSaves.dat","rb");
    fread(storedOnFile, sizeof(struct Player), nTotalSaveFiles, filePointer);
    for (int nIndex=0; nIndex<nTotalSaveFiles; nIndex++){
        arrTempList[nIndex]=storedOnFile[nIndex];
    }
    fclose(filePointer);
    arrTempList[(*nCursor)]=(*TESTplayer);

    filePointer=fopen("playerSaves.dat","wb");
    fwrite(arrTempList,sizeof(struct Player), 3, filePointer);
    fclose(filePointer);
}

void printFileBox(struct Player *arrListOfSaves, int nFileExists, int nBoxLine, int nIndex, int nSelected){
    if (nSelected==1&&nBoxLine!=1&&nBoxLine!=2&&nBoxLine!=13){
        printf("║ ");
    } else if (nBoxLine!=1&&nBoxLine!=2&&nBoxLine!=13){
        printf("| ");
    }

    switch (nBoxLine){
        case -1:
            printf("            No Data           ");
            break;
        case 0:
            printf("                              ");
            break;
        case 1:
            printf("           Save File %d           ", nIndex+1);
            break;
        case 2:
            if (nSelected==1){
                printf("╔════════════════════════════════╗");
            } else {
                printf("┌────────────────────────────────┐");
            }
            break;
        case 3:
            printf("Name                          ");
            break;
        case 4:
            fprintf(stdout,"%-*s",30,arrListOfSaves[nIndex].strName);
            break;
        case 5:
            printf("Class                         ");
            break;
        case 6:
            fprintf(stdout,"%-*s",30,arrListOfSaves[nIndex].strJobClass);   
            break;
        case 7:
            printf("Runes                         ");
            break;
        case 8:
            printf("                              ");
            break;
        case 9:
            printf("Shards                        ");
            break;
        case 10:
            printf("                              ");
            break;
        case 11:
            printf("                              ");
            // fprintf(stdout,"LVL %d HTP %d END %d FTH %d",arrListOfSaves[nIndex].nLevel,arrListOfSaves[nIndex].nHealth,arrListOfSaves[nIndex].nEndurance,arrListOfSaves[nIndex].nFaith);
            break;
        case 12:
            printf("                              ");
            // fprintf(stdout,"DEX %d STR %d INT %d       ",arrListOfSaves[nIndex].nDexterity,arrListOfSaves[nIndex].nStrength,arrListOfSaves[nIndex].nIntelligence);
            break;
        case 13:
            if (nSelected==1){
                printf("╚════════════════════════════════╝");
            } else {
                printf("└────────────────────────────────┘");
            }
            break;
    }
    if (nSelected==1&&nBoxLine!=1&&nBoxLine!=2&&nBoxLine!=13){
        printf(" ║");
    } else if (nBoxLine!=1&&nBoxLine!=2&&nBoxLine!=13){
        printf(" |");
    }
}
void displaySaveMenu(struct Player *arrListOfSaves, int nTotalSaveFiles, int nCursor){
    int nSelected=0;
    int nFileExists=0;
    printf("Save Progress\n\n");
    for (int nBoxLine=1; nBoxLine<14; nBoxLine++){
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
    printf("(1) Save\n");
    printf("(0) Continue without saving\n");

}
void processInputSaveMenu(struct Player *TESTplayer, int nTotalSaveFiles, int* nCursor, char cInput){
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
            printf("SaveCurrentState\n");
            saveCurrentGameState(nTotalSaveFiles, nCursor, TESTplayer);
            break;
        case '0':
            printf("\n\n\n\nYou will regret this later\n\n\n\n");
            getch();
            break;
    }
}

void runSaveMenu(struct Player *TESTplayer){
    int nTotalSaveFiles=3;
    struct Player *arrListOfSaves;
    arrListOfSaves=malloc(sizeof(struct Player)*nTotalSaveFiles);

    char cInput=' ';
    int nCursor=0;

    FILE *filePointer;
    if ((filePointer=fopen("playerSaves.dat","rb"))==NULL){
        filePointer=fopen("playerSaves.dat","wb");
        struct Player emptySave;
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
        fwrite(arrListOfSaves,sizeof(struct Player), nTotalSaveFiles, filePointer);
        fclose(filePointer);
    }

    filePointer=fopen("playerSaves.dat","rb");
    fread(arrListOfSaves, sizeof(struct Player), nTotalSaveFiles, filePointer);

    /*
    //TEST
    struct Player cheatSave;
    strcpy(cheatSave.strName, "The Goat");
    strcpy(cheatSave.strJobClass, "Pog Champion");
    cheatSave.nLevel = 99;
    cheatSave.nHealth = 99;
    cheatSave.nEndurance = 99;
    cheatSave.nDexterity = 99;
    cheatSave.nStrength = 99;
    cheatSave.nIntelligence = 99;
    cheatSave.nFaith = 99;
    
    fwrite(arrListOfSaves,sizeof(struct Player), nTotalSaveFiles, filePointer);
    fclose(filePointer);
    struct Player *arrTempList;
    struct Player *storedOnFile;
    arrTempList=malloc(sizeof(struct Player)*nTotalSaveFiles);
    storedOnFile=malloc(sizeof(struct Player)*nTotalSaveFiles);

    filePointer=fopen("playerSaves.dat","rb");
    fread(storedOnFile, sizeof(struct Player), nTotalSaveFiles, filePointer);
    for (int nIndex=0; nIndex<nTotalSaveFiles; nIndex++){
        arrTempList[nIndex]=storedOnFile[nIndex];
    }
    fclose(filePointer);
    arrTempList[nCursor]=cheatSave;

    filePointer=fopen("playerSaves.dat","wb");
    fwrite(arrTempList,sizeof(struct Player), 3, filePointer);
    fclose(filePointer);
    //TEST
    */

    do{
    displaySaveMenu(arrListOfSaves, nTotalSaveFiles, nCursor);
    cInput=getch();
    processInputSaveMenu(TESTplayer, nTotalSaveFiles, &nCursor, cInput);
    } while (cInput!='1'&&cInput!='0');
    fclose(filePointer);
}