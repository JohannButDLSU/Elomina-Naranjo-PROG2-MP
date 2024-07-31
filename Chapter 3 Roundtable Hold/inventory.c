#include "inventory.h"

void runInventoryMenu(Player* player){
    char cInput=' ';
    int nWeaponSelectedIndex=0;
    int aCursorPos[2]={0,0};
    int nNumRow=3, nNumCol=8;

    // TEST TEMPORARY
    player->nInventorySize=3;
    player->nInventory=malloc(sizeof(int)*player->nInventorySize);
    player->nInventory[0]=1;
    player->nInventory[1]=2;
    player->nInventory[2]=5;
    do{
        displayInventory(player, nWeaponSelectedIndex, aCursorPos, nNumRow, nNumCol);
        // cInput=getch();
        scanf(" %c", &cInput);
        processInputInventoryMenu(player, &nWeaponSelectedIndex, cInput, aCursorPos, nNumRow, nNumCol);
    }while(cInput!='0');
}
void displayInventory(Player* player, int nTestWeaponSelectedIndex, int *aCursorPos, int nNumRow, int nNumCol){
    printRepeatedly(7,"\t");
    printf("Inventory\n\n");

    printRepeatedly(5,"\t");
    printf("┏");
    printRepeatedly((nNumCol*5)+2,"━");
    printf("┓\n");
    for (int nRow=0; nRow<nNumRow; nRow++){
        for (int nBoxLine=0; nBoxLine<3; nBoxLine++){
            printRepeatedly(5,"\t");
            printf("┃ ");
            for (int nCol=0; nCol<nNumCol; nCol++){
                if (aCursorPos[0]==nRow&&aCursorPos[1]==nCol){
                    switch (nBoxLine){
                        case 0:
                            printf("┏━━━┓");
                            break;
                        case 1:
                            if ((nRow*nNumCol)+nCol<player->nInventorySize){
                                printf("┃ %d ┃", player->nInventory[(nRow*nNumCol)+nCol]);
                            } else{
                                printf("┃   ┃");
                            }
                            break;
                        case 2:
                            printf("┗━━━┛");
                            break;
                    }
                } else{
                    switch (nBoxLine){
                        case 0:
                            printf("┌┄┄┄┐");
                            break;
                        case 1:
                            if ((nRow*nNumCol)+nCol<player->nInventorySize){
                                printf("┆ %d ┆", player->nInventory[(nRow*nNumCol)+nCol]);
                            } else{
                                printf("┆   ┆");
                            }
                            break;
                        case 2:
                            printf("└┄┄┄┘");
                            break;
                    }
                }
            }
            if (nBoxLine==1&&(nNumRow/2)==nRow){
                printf(" ┃  > (E) next page\n");
            } else{
                printf(" ┃\n");
            }
        }
    }
    printRepeatedly(5,"\t");
    printf("┗");
    printRepeatedly((nNumCol*5)+2,"━");
    printf("┛\n");

    if(player->nInventory[(nNumCol*aCursorPos[1])+aCursorPos[0]]==NULL){
        printf("Nada Data\n");
    } else{
        printRepeatedly(5,"\t");
        printf("       Name :   %s\n", strWeaponNames[player->nInventory[(aCursorPos[0]*nNumCol)+aCursorPos[1]]-1]);
        printRepeatedly(5,"\t");
        printRepeatedly((nNumCol*5)+4,"┄");
        printf("\n");
        printRepeatedly(5,"\t");
        printf("       HTP %3d❤️      END %3d🗿\n", nWeaponStats[player->nInventory[(aCursorPos[0]*nNumCol)+aCursorPos[1]]-1][2], nWeaponStats[player->nInventory[(aCursorPos[0]*nNumCol)+aCursorPos[1]]-1][3]);
        printRepeatedly(5,"\t");
        printf("       DEX %3d⚡     STR %3d💪\n", nWeaponStats[player->nInventory[(aCursorPos[0]*nNumCol)+aCursorPos[1]]-1][4], nWeaponStats[player->nInventory[(aCursorPos[0]*nNumCol)+aCursorPos[1]]-1][5]);
        printRepeatedly(5,"\t");
        printf("       INT %3d🧠     FTH %3d🕯️\n", nWeaponStats[player->nInventory[(aCursorPos[0]*nNumCol)+aCursorPos[1]]-1][6], nWeaponStats[player->nInventory[(aCursorPos[0]*nNumCol)+aCursorPos[1]]-1][7]);
    }

    printRepeatedly(5,"\t");
    printRepeatedly((nNumCol*5)+4,"┄");
    printf("\n");

    if (strcmp(player->sEquippedWeapon.strName,"EMPTY")==0){
        printRepeatedly(5,"\t");
        printf("                 ┌┄┄┄┐\n");
        printRepeatedly(5,"\t");
        printf("Weapon Equipped  ┆   ┆ : No weapon\n");
        printRepeatedly(5,"\t");
        printf("                 └┄┄┄┘\n");
    } else{
        printRepeatedly(5,"\t");
        printf("                 ┏━━━┓\n");
        printRepeatedly(5,"\t");
        printf("Weapon Equipped  ┃ %d ┃ : %s\n",player->sEquippedWeapon.nWeaponIndex, player->sEquippedWeapon.strName);
        printRepeatedly(5,"\t");
        printf("                 ┗━━━┛\n");
    }

    printRepeatedly(5,"\t");
    printRepeatedly((nNumCol*5)+4,"━");
    printf("\n");
    printRepeatedly(5,"\t");
    printf("(1) Select Weapon\n");
    printRepeatedly(5,"\t");
    printf("(0) Back\n");
    printRepeatedly(5,"\t");
    printf("    > ");
}
void processInputInventoryMenu(Player* player,  int *nTestWeaponSelectedIndex, char cInput, int *aCursorPos, int nNumRow, int nNumCol){
    switch (cInput){
        case 'w':
        case 'W':
            if (aCursorPos[0]>0) aCursorPos[0]-=1; 
            break;
        case 'a':
        case 'A':
            if (aCursorPos[1]>0) aCursorPos[1]-=1; 
            break;
        case 's':
        case 'S':
            if (aCursorPos[0]<(nNumRow-1)) aCursorPos[0]+=1; 
            break;
        case 'd':
        case 'D':
            if (aCursorPos[1]<(nNumCol-1)) aCursorPos[1]+=1; 
            break;
        case '1': 
            if (player->nInventory[(aCursorPos[0]*nNumCol)+aCursorPos[1]]>0){ 
                player->sEquippedWeapon=setWeaponStats(strWeaponNames[player->nInventory[(aCursorPos[0]*nNumCol)+aCursorPos[1]]-1], nWeaponStats[player->nInventory[(aCursorPos[0]*nNumCol)+aCursorPos[1]]-1]);
            };
            break;
        case '0':
            printf("Back to Roundtable\n"); 
            break;
        default: printf("Invalid Input\n"); break;
    }
}
