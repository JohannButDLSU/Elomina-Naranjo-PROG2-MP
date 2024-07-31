#include "shop.h"

void runShopMenu(Player* player){
    char cInput=' ';
    //TEST
    player->nRunes=10000;
    //TEST
    int aShopItems[24]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; //Each index represents a weapon in MP specs, Appendix C
    int nTestWeaponSelectedIndex=0;
    int aCursorPos[2]={0,0};
    int nNumRow=6, nNumCol=4;

    do{
        displayShop(player, aCursorPos, nNumRow, nNumCol);
        // cInput=getch();
        scanf(" %c", &cInput);
        processInputShopMenu(player, cInput, aCursorPos, nNumRow, nNumCol);
    }while(cInput!='0');
}

void runSell(Player* player){
    char cInput=' ';
    int nNumRow=3, nNumCol=8;
    int aCursorPos[2]={0,0};
    int nPage=0;
    do{
        displayInventory(nPage, player, aCursorPos, nNumRow, nNumCol);
    }while(cInput!='0');
}

void displayShop(Player* player, int *aCursorPos, int nNumRow, int nNumCol){
    int nPadding=0;
    printRepeatedly(10,"\t");
    printf("❖ %d\n", player->nRunes);
    printRepeatedly(5,"\t");
    printf("┏");
    printRepeatedly((nNumCol*12),"━");
    printf("┓\n");

    for (int nRow=0; nRow<nNumRow; nRow++){
        for (int nBoxLine=0; nBoxLine<2; nBoxLine++){
            printRepeatedly(5,"\t");
            printf("┃ ");
            for (int nCol=0; nCol<nNumCol; nCol++){
                if (aCursorPos[0]==nRow&&aCursorPos[1]==nCol){
                    switch (nBoxLine){
                        case 0:    
                            printf("┏%02d┓", (nRow*nNumCol)+nCol+1);
                            break;
                        case 1:
                            printf("┗━━┛");
                            break;

                    }
                }else{
                    switch (nBoxLine){
                        case 0:    
                            printf("┌%02d┐", (nRow*nNumCol)+nCol+1);
                            break;
                        case 1:
                            printf("└┄┄┘");
                            break;

                    }
                }
            }
            printf(" ┆");
            switch ((nRow*2)+nBoxLine){
                case 0:
                    printf("            Shop            ");
                    break;
                case 1:
                    printf("╟┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄╢");
                    break;
                case 2:
                    printf("  %s", strWeaponNames[(aCursorPos[0]*nNumCol)+aCursorPos[1]]);
                    nPadding=26-strlen(strWeaponNames[(aCursorPos[0]*nNumCol)+aCursorPos[1]]);
                    printRepeatedly(nPadding," ");
                    // printf(" %36s", strWeaponNames[(aCursorPos[0]*nNumCol)+aCursorPos[1]]);
                    break;
                case 3:
                    printf("                            ");
                    break;
                case 4:
                    printf(" Rune Cost: ❖ %6d        ", nWeaponStats[(aCursorPos[0]*nNumCol)+aCursorPos[1]][1]);
                    break;
                case 5:
                    printf("                            ");
                    break;
                case 6:
                    printf(" Dexterity Requirement: %3d ", nWeaponStats[(aCursorPos[0]*nNumCol)+aCursorPos[1]][4]);
                    break;
                case 7:
                    printf("                            ");
                    break;
                case 8:
                    printf(" HTP: %3d        END: %3d   ", nWeaponStats[(aCursorPos[0]*nNumCol)+aCursorPos[1]][2], nWeaponStats[(aCursorPos[0]*nNumCol)+aCursorPos[1]][3]);
                    break;
                case 9:
                    printf(" STR: %3d        INT: %3d   ", nWeaponStats[(aCursorPos[0]*nNumCol)+aCursorPos[1]][5], nWeaponStats[(aCursorPos[0]*nNumCol)+aCursorPos[1]][6]);
                    break;
                case 10:
                    printf(" FTH: %3d                   ", nWeaponStats[(aCursorPos[0]*nNumCol)+aCursorPos[1]][7]);
                    break;
                case 11:
                    printf("                            ");
                    break;
            }
            printf(" ┃\n");
        }
    }
    printRepeatedly(5,"\t");
    printf("┗");
    printRepeatedly((nNumCol*12),"━");
    printf("┛\n");

    printRepeatedly(5,"\t");
    printf("(1) Purchase weapon\n");
    printRepeatedly(5,"\t");
    printf("(2) Sell weapon\n");
    printRepeatedly(5,"\t");
    printf("(0) Back\n");
    printRepeatedly(5,"\t");
    printf("    > ");
}
void processInputShopMenu(Player* player, char cInput, int *aCursorPos, int nNumRow, int nNumCol){
    // int* nTempInventory;
    switch (cInput){
        case 'a':
        case 'A':
            if (aCursorPos[1]>0) aCursorPos[1]-=1; 
            break;
        case 'd':
        case 'D':
            if (aCursorPos[1]<(nNumCol-1)) aCursorPos[1]+=1;
            break;
        case 'w':
        case 'W':
            if (aCursorPos[0]>0) aCursorPos[0]-=1; 
            break;
        case 's':
        case 'S':
            if (aCursorPos[0]<(nNumRow-1)) aCursorPos[0]+=1; 
            break;
        case '1': 
            if (player->nRunes>=nWeaponStats[(aCursorPos[0]*nNumCol)+aCursorPos[1]][1]){
                player->nInventorySize+=1;
                player->nInventory=realloc(player->nInventory, player->nInventorySize*sizeof(int));
                player->nInventory[player->nInventorySize-1]=nWeaponStats[(aCursorPos[0]*nNumCol)+aCursorPos[1]][0];
                player->nRunes-=nWeaponStats[(aCursorPos[0]*nNumCol)+aCursorPos[1]][1];
                printRepeatedly(5,"\t");
                printf("Weapon Purchased!\n");
            } else{
                printRepeatedly(5,"\t");
                printf("You lack the Runes ❖ for that weapon\n");
            }
            break;
        case '2':
            runSell(player);
            break;
        default: 
            printRepeatedly(5,"\t");
            printf("Invalid Input\n"); 
            break;
    }
}