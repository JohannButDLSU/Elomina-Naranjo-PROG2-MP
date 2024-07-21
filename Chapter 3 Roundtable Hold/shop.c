#include "shop.h"

void runShopMenu(int *nTestRunes, int *aTestInventory){
    char cInput=' ';
    int aShopItems[24]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; //Each index represents a weapon in MP specs, Appendix C
    int nTestWeaponSelectedIndex=0;
    int aCursorPos[2]={0,0};
    int nNumRow=6, nNumCol=4;

    do{
        displayShop(nTestRunes, nTestWeaponSelectedIndex, aCursorPos, aShopItems, nNumRow, nNumCol);
        // cInput=getch();
        scanf(" %c", &cInput);
        printf("\nDevMsg: ");
        processInputShopMenu(nTestRunes, aTestInventory, aShopItems, &nTestWeaponSelectedIndex, cInput, aCursorPos, nNumRow, nNumCol);
    }while(cInput!='0');
}
void displayShop(int *nTestRunes, int nTestWeaponSelectedIndex, int *aCursorPos, int *aShopItems, int nNumRow, int nNumCol){
    char sTestWeaponSelected[24][36]={"Short Sword", "Rogier's Rapier", "Coded Sword", "Sword of Night and Flame", "Uchigatana", "Moonveil"};
    char cCursor=' ';

    printf("Shop\n");
    printf("<> %d\n\n", *nTestRunes);
    for (int row=0; row<nNumRow; row++){
        for (int col=0; col<nNumCol;col++){
            if (*(aCursorPos)==col && *(aCursorPos+1)==row){
                cCursor='>';
            }else{
                cCursor=' ';
            }
            printf("%c %d  ",cCursor , *(aShopItems+col+(row*nNumCol)));
        }
        printf("\n");
    }
    printf("\n");
    printf("%s\n", sTestWeaponSelected[(*(aCursorPos+1))*nNumCol+*(aCursorPos)]);
    printf("<Weapons Stats go here>\n\n");
    printf("(1) Purchase Weapon\n");
    printf("(0) Back\n");
    printf("    > ");
}
void processInputShopMenu(int *nTestRunes, int *aTestInventory, int *aShopItems, int *nTestWeaponSelectedIndex, char cInput, int *aCursorPos, int nNumRow, int nNumCol){
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
            if (*nTestRunes>=100){
                printf("Weapon Purchased!\n"); 
                *(aTestInventory+(*(aCursorPos+1))*nNumCol+*(aCursorPos))+=1;
                *(nTestRunes)-=100;
            };
            break;
        case '0':
            printf("Back to Roundtable\n"); 
            break;
        default: printf("Invalid Input\n"); break;
    }
}