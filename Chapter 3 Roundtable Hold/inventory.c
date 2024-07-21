#include "inventory.h"

void runInventoryMenu(int *aTestInventory){
    char cInput=' ';
    int nTestWeaponSelectedIndex=0;
    int aCursorPos[2]={0,0};
    int nNumRow=3, nNumCol=8;

    do{
        //printf("aCursorPos X : %d   aCursorPos Y : %d\n", aCursorPos[0], aCursorPos[1]);
        displayInventory(nTestWeaponSelectedIndex, aCursorPos, aTestInventory, nNumRow, nNumCol);
        // cInput=getch();
        scanf(" %c", &cInput);
        printf("\nDevMsg: ");
        processInputInventoryMenu(aTestInventory, &nTestWeaponSelectedIndex, cInput, aCursorPos, nNumRow, nNumCol);
    }while(cInput!='0');
}
void displayInventory(int nTestWeaponSelectedIndex, int *aCursorPos, int *inventory, int nNumRow, int nNumCol){
    char sTestWeaponSelected[24][36]={"Short Sword", "Rogier's Rapier", "Coded Sword", "Sword of Night and Flame", "Uchigatana", "Moonveil"};
    char cCursor=' ';

    printf("Inventory\n\n");
    printf("Weapon Selected : %s\n\n", sTestWeaponSelected[nTestWeaponSelectedIndex]);
    for (int row=0; row<nNumRow; row++){
        for (int col=0; col<nNumCol;col++){
            if (*(aCursorPos)==col && *(aCursorPos+1)==row){
                cCursor='>';
            }else{
                cCursor=' ';
            }
            printf("%c %d  ",cCursor , *(inventory+col+(row*nNumCol)));
        }
        printf("\n");
    }
    printf("\n");
    printf("%s\n", sTestWeaponSelected[(*(aCursorPos+1))*nNumCol+*(aCursorPos)]);
    printf("<Weapons Stats go here>\n\n");
    printf("(1) Select Weapon\n");
    printf("(0) Back\n");
    printf("    > ");
}
void processInputInventoryMenu(int *aTestInventory, int *nTestWeaponSelectedIndex, char cInput, int *aCursorPos, int nNumRow, int nNumCol){
    switch (cInput){
        case 'a':
        case 'A':
            if (*(aCursorPos)>0) *(aCursorPos)-=1; 
            break;
        case 'd':
        case 'D':
            if (*(aCursorPos)<(nNumCol-1)) *(aCursorPos)+=1; 
            break;
        case 'w':
        case 'W':
            if (*(aCursorPos+1)>0) *(aCursorPos+1)-=1; 
            break;
        case 's':
        case 'S':
            if (*(aCursorPos+1)<(nNumRow-1)) *(aCursorPos+1)+=1; 
            break;
        case '1': 
            if (*(aTestInventory+(*(aCursorPos+1))*nNumCol+*(aCursorPos))>0){
                printf("You selected a weapon!\n"); 
                *nTestWeaponSelectedIndex=(*(aCursorPos+1))*nNumCol+*(aCursorPos);
            };
            break;
        case '0':
            printf("Back to Roundtable\n"); 
            break;
        default: printf("Invalid Input\n"); break;
    }
}
