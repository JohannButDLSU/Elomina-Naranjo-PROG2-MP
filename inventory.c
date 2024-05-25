#include "stdio.h"
#include "inventory.h"

void displayEmptyBox(int line){
    char emptyBox[3][15]={
    // {"Upper"},
    // {"Midle"},
    // {"Lower"}};
    {"┌───┐"},
    {"|   |"}, 
    {"└───┘"}};
    int i=0;
    for (i=0;i<15;i++) printf("%c", emptyBox[line][i]);
    // Unicode takes up 3 bytes of memory
}

void displayItem1(int line){
    char item1[3][15]={
    {"╔═══╗"},
    {"║█▄█║"}, 
    {"╚═══╝"}};
    int i=0;
    for (i=0;i<15;i++) printf("%c", item1[line][i]);
    // Unicode takes up 3 or 4... bytes of memmory
}
void displayItem2(int line){
    char item2[3][15]={
    {"╔═══╗"},
    {"║█▀█║"}, 
    {"╚═══╝"}};
    int i=0;
    for (i=0;i<15;i++) printf("%c", item2[line][i]);
    // Unicode takes up 3 or 4... bytes of memmory
}
void displayItem3(int line){
    char item3[3][15]={
    {"╔═══╗"},
    {"║▄▀▄║"}, 
    {"╚═══╝"}};
    int i=0;
    for (i=0;i<15;i++) printf("%c", item3[line][i]);
    // Unicode takes up 3 or 4... bytes of memmory
}

void displayInventory(int* inventory, int inventorySize){
    int i=0,j=0, inventoryIndex=0;
    int boxHeight=3; //This assumes all boxes displayed are 3 lines high.
    int numOfCol=3;
    int rows=0;
    int over=0;

    // How do I express 'round up' as a mathematical statement?
    // I wanted to condense 'over' into one equation but I couldnt figure it out :( Buuwomp
    if (inventorySize%numOfCol>0) over=1;

    rows=boxHeight*((inventorySize/numOfCol)+over);

    for (i=0;i<rows;i++){
        printf("\t");
        for (j=0;j<numOfCol;j++) {
            switch (inventory[((inventoryIndex/(numOfCol*boxHeight))*numOfCol)+j]){
                case 1: displayItem1((i)%boxHeight); break;
                case 2: displayItem2((i)%boxHeight); break;
                case 3: displayItem3((i)%boxHeight); break;
                default: displayEmptyBox((i)%boxHeight); break;
            }
            inventoryIndex++;
        };
        printf("\n");
    };
    printf("\n");
}

void runInventory(int* inventory, int inventorySize){
    char pressAnyKeyToContinue=',';

    printf("\n");
	printf("\t╔════════════════════╗\n");
	printf("\t|     INVENTORY      │\n");
	printf("\t╚════════════════════╝\n");

    displayInventory(inventory, inventorySize);
    printf("\t[Enter any key to continue] : ");
    scanf(" %c", &pressAnyKeyToContinue);
}