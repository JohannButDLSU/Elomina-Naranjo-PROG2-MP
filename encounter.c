#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "encounter.h"

void showItem1(){
    printf("\t│     ╔═══╗     │\n"); 
    printf("\t│     ║█▄█║     │\n"); 
    printf("\t│     ╚═══╝     │\n"); 
    printf("\t│    ITEM 01    │\n");
}
void showItem2(){
    printf("\t│     ╔═══╗     │\n"); 
    printf("\t│     ║█▀█║     │\n"); 
    printf("\t│     ╚═══╝     │\n"); 
    printf("\t│    ITEM 02    │\n");
}
void showItem3(){
    printf("\t│     ╔═══╗     │\n"); 
    printf("\t│     ║▄▀▄║     │\n"); 
    printf("\t│     ╚═══╝     │\n"); 
    printf("\t│    ITEM 03    │\n");
}
void playerDamageHP(){
    printf("\t│     ╔═══╗     │\n"); 
    printf("\t│     ║ □ ║     │\n"); 
    printf("\t│     ╚═══╝     │\n"); 
    printf("\t│    DAMAGED!   │\n");
}

int checkInventory(int item, int inventorySize, int* inventory){
    int i=0, full=0;

        for (i=0;i<inventorySize; i++){
            if (inventory[i]==0){
                inventory[i]=item;
                i=inventorySize; //Ends loop once a space for item is found
            };
            if (i==inventorySize-1){
                printf("\t│               │\n"); 
                printf("\t│    NOTHING!   │\n"); 
                printf("\t│Inventory Full!│\n"); 
                printf("\t│               │\n");
                full=1;
            };
        };
    return full;
}

void displayEncounter(int* playerHP, int inventorySize, int* inventory){
    //Taken from the internet
    srand(time(NULL));
    int r = rand();
    int difficulty=4, full=0; //'difficulty' determines the random number max
    int event = r%difficulty;

    // printf("%d", event);
    switch (event){
        case 1: full=checkInventory(1, inventorySize, inventory);
                if (full==0) showItem1();
                break;
        case 2: full=checkInventory(2, inventorySize, inventory);
                if (full==0) showItem2();
                break;
        case 3: full=checkInventory(3, inventorySize, inventory);
                if (full==0) showItem3();
                break;
        default: playerDamageHP();
                (*playerHP)--;
                break;
    }
}

void runEncounter(int* playerHP, int inventorySize, int* inventory){
    char enterAnyKeyToContinue=',';
    printf("\t┌───────────────┐\n");
    printf("\t│ YOU GOT...    │\n"); 
    printf("\t├───────────────┤\n"); 
    displayEncounter(playerHP, inventorySize, inventory);
    printf("\t├───────────────┤\n"); 
    printf("\t└───────────────┘\n"); 
    printf("\t[Enter any key to continue] : ");
    scanf(" %c", &enterAnyKeyToContinue);
}