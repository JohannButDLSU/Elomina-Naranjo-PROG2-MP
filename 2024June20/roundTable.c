#include "TESTplayer.h"

#include "roundTable.h"
#include "inventory.h"
#include "shop.h"
#include "save.h"

//Fast Travel Menu
void processInputFastTravelMenu(char cInput){
    switch (cInput){
        case '1': printf("runStormVeil\n"); break;
        case '2': printf("runRayaLucariaAcademy\n"); break;
        case '6': printf("runEldenThrone\n"); break;
        case '0': printf("Back to RoundTable\n"); break;
        default: printf("Invalid Input\n"); break;
    }
}
void displayFastTravelMenu(){
    printf("Fast Travel Menu\n\n");
    printf("(1) Stormveil Castle\n");
    printf("(2) Ray Lucaria Academy\n");
    printf("(6) Elden Throne (Locked) \n"); // Find character for a lock
    printf("(0) Back\n");
    printf("\n");
    printf("    > ");
}
void runFastTravelMenu(){
    char cInput=' ';
    do{
        displayFastTravelMenu();
        cInput=getch();
        printf("\n");
        printf("DevMsg: ");
        processInputFastTravelMenu(cInput);
    }while(cInput!='0'&&cInput!='1'&&cInput!='2'&&cInput!='3'&&cInput!='4'&&cInput!='5'&&cInput!='6');
}

//Level Up Menu (Subscreen)
void processInputLevelUpMenu(int *nTestRunes, struct Player *TESTplayer, int nLevelUpRuneCost, char cInput){
    if ((*nTestRunes)>=nLevelUpRuneCost){
        switch (cInput){
            case '1':
                printf("Upgrade Health\n");
                TESTplayer->nHealth++;
                (*nTestRunes)-=nLevelUpRuneCost;
                //Upgrade Health here
                break;
            case '2':
                printf("Upgrade Endurance\n");
                TESTplayer->nEndurance++;
                (*nTestRunes)-=nLevelUpRuneCost;
                //Upgrade Endurance here
                break;
            case '3':
                printf("Upgrade Dexterity\n");
                TESTplayer->nDexterity++;
                (*nTestRunes)-=nLevelUpRuneCost;
                //Upgrade Dexterity here
                break;
            case '4':
                printf("Upgrade Strength\n");
                TESTplayer->nStrength++;
                (*nTestRunes)-=nLevelUpRuneCost;
                break;
            case '5':
                printf("Upgrade Intelligence\n");
                TESTplayer->nIntelligence++;
                (*nTestRunes)-=nLevelUpRuneCost;
                break;
            case '6':
                printf("Upgrade Faith\n");
                TESTplayer->nFaith++;
                (*nTestRunes)-=nLevelUpRuneCost;
                break;
            case '0':
                printf("Back to Roundtable\n");
                //Go Back to Roundtable
                break;
            default:
                printf("Invalid Input\n"); break;
        }
    } else if (cInput!='0'){
        printf("You do not have enough <> runes for that\n");
    }
}
void displayLevelUpMenu(int nLevelUpRuneCost, int *nTestRunes, struct Player *TESTplayer){
    printf("Level Up Menu\n");
    printf("%d <> Runes\n", *nTestRunes);
    printf("\n");
    printf("Level Up Cost : %d <>\n", nLevelUpRuneCost);
    printf("(1) Health          (%d) + 1\n", TESTplayer->nHealth);
    printf("(2) Endurance       (%d) + 1\n", TESTplayer->nEndurance);
    printf("(3) Dexterity       (%d) + 1\n", TESTplayer->nDexterity);
    printf("(4) Strength        (%d) + 1\n", TESTplayer->nStrength);
    printf("(5) Intelligence    (%d) + 1\n", TESTplayer->nIntelligence);
    printf("(6) Faith           (%d) + 1\n", TESTplayer->nFaith);
    printf("(0) Back\n");
    printf("    > ");
}
void runLevelUpMenu(int *nTestRunes, struct Player *TESTplayer){
    char cInput=' ';

        do{
            int nLevelUpRuneCost=(TESTplayer->nLevel*100)/2;
            displayLevelUpMenu(nLevelUpRuneCost, nTestRunes, TESTplayer);
            cInput=getch();
            printf("\n");
            printf("DevMsg: ");
            processInputLevelUpMenu(nTestRunes, TESTplayer, nLevelUpRuneCost, cInput);
            
        }while(cInput!='0');
}

//RoundTable
void displayRoundTable(struct Player *TESTplayer, int *nTestRunes){
    printf("Round Table\n");
    printf("%s | %s | Lvl. %d                <> %d\n", TESTplayer->strName, TESTplayer->strJobClass, TESTplayer->nLevel, *nTestRunes);
    printf("Shards: @ @ @ @ @ @ @\n");
    printf("\n");
    printf("(1) Fast Travel\n");
    printf("(2) Level Up\n");
    printf("(3) Inventory\n");
    printf("(4) Shop\n");
    printf("(5) Save\n");
    printf("(0) Quit Game\n"); // Go to title screen
    printf("\n");
    printf("    > ");
}
void processInputRoundTable(struct Player *TESTplayer, int *nTestRunes, int *aTestInventory, char cInput){
    switch (cInput){
        case '1': 
            printf("runFastTravelMenu()\n");
            runFastTravelMenu(); 
            break;
        case '2': 
            printf("runLevelUp()\n");
            runLevelUpMenu(nTestRunes, TESTplayer);
            break;
        case '3': 
            printf("runInventory()\n"); 
            runInventoryMenu(aTestInventory);
            break;
        case '4': 
            printf("runShopMenu()\n");
            runShopMenu(nTestRunes, aTestInventory);
            break;
        case '5': 
            printf("runSave()\n");
            runSaveMenu(TESTplayer); 
            break;
        case '0': printf("runTitleScreen()\n"); break;
        default: printf("Invalid Input\n"); break;
    }
}
void runRoundTable(struct Player *TESTplayer, int *nTestRunes, int *aTestInventory){
    char cInput=' ';
    do{
        displayRoundTable(TESTplayer, nTestRunes);
        cInput=getch();
        printf("\n");
        printf("DevMsg: ");
        processInputRoundTable(TESTplayer, nTestRunes, aTestInventory, cInput);
    }while(cInput!='0');
}