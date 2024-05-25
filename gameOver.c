#include "stdio.h"
#include "gameOver.h"

void runGameOver(){
    char enterAnyKeyToContinue=',';
    printf("\t┌───────────────┐\n");
    printf("\t│ ╔═══════════╗ │\n");
    printf("\t│ ║           ║ │\n");
    printf("\t│ ║           ║ │\n");
    printf("\t│ ║ GAME OVER ║ │\n");
    printf("\t│ ║           ║ │\n");
    printf("\t│ ║           ║ │\n");
    printf("\t│ ╚═══════════╝ │\n");
    printf("\t└───────────────┘\n");
    printf("\t[Enter any key to continue] : ");
    scanf(" %c", &enterAnyKeyToContinue);
}