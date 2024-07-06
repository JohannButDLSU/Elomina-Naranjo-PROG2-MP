#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"

#include "roundTable.c"
#include "inventory.c"
#include "shop.c"
#include "save.c"
#include "TESTplayer.h"

int main(){
    int aTestInventory[24]={1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //Each index represents a weapon in MP specs, Appendix C
    int nTestRunes=500;

    struct Player TESTplayer;
    strcpy(TESTplayer.strName, "Goofy Goober");
    strcpy(TESTplayer.strJobClass, "Jobless :(");
    TESTplayer.nLevel = 1;
    TESTplayer.nHealth = 1;
    TESTplayer.nEndurance = 1;
    TESTplayer.nDexterity = 1;
    TESTplayer.nStrength = 1;
    TESTplayer.nIntelligence = 1;
    TESTplayer.nFaith = 1;

    runRoundTable(&TESTplayer, &nTestRunes, aTestInventory);
    return 0;
}