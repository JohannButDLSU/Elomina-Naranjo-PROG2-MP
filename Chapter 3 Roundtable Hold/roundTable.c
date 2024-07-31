#include "roundTable.h"

void runRoundTable(Player *player, int *nTestRunes, int *aTestInventory){
    char cInput=' ';
    do{
        displayRoundTable(player, nTestRunes);
        // cInput=getch();
        scanf(" %c", &cInput);
        printf("\n");
        processInputRoundTable(player, nTestRunes, aTestInventory, cInput);
    }while(cInput!='0');
}

//Fast Travel Menu
void processInputFastTravelMenu(Player* player, char cInput){
    // Imma put variables here again to fix da stupig 
    int nShardsCompleted;

    switch (cInput){
        case '1': 
            runArea(player, 1); // Stormveil Castle
            break;
        case '2':
            runArea(player, 2); // Raya Lucaria
            break;
        case '3':
            runArea(player, 3); // Redmane Castle
            break;
        case '4':
            runArea(player, 4); // Volcano Manor
            break;
        case '5': //Leyndell Royal Capital
            nShardsCompleted=0;
            for (int nShards=0; nShards<6; nShards++){
                if (player->nShards[nShards]==1){
                    nShardsCompleted++;
                }
            }
            if (nShardsCompleted>=2){
                printf("runLeyndellRoyalCapital\n");
                runArea(player, 5);
            }
            break;
        case '6': 
            if (player->nShards[4]==1){
                printf("runEldenThrone\n");
                runArea(player, 6);
            }
            break;
        case '0': printf("Back to RoundTable\n"); break;
        default: printf("Invalid Input\n"); break;
    }
}
void displayFastTravelMenu(Player* player){
    printf("Fast Travel Menu\n\n");
    printf("(1) Stormveil Castle\n");
    printf("(2) Ray Lucaria Academy\n");
    printf("(3) Redmane Castle\n");
    printf("(4) Volcano Manor\n");
    // Print Leyndell Royal Capital
    int nShardsCompleted=0;
    for (int nShards=0; nShards<7; nShards++){
        if (player->nShards[nShards]==1){
            nShardsCompleted++;
        }
    }
    if (nShardsCompleted>=2){
        printf("(5) Leyndell Royal Capital\n");
    } else{
        printc(0,233,"(~) Leyndell Royal Capital (Locked)");
        printf("\n");
    }

    //Print Elden Throne
    if (player->nShards[4]==1){
        printf("(6) Elden Throne\n");
    } else{
        printc(0,233,"(~) Elden Throne (Locked)\n"); // Find character for a lock
    }
    printf("(0) Back\n");
    printf("\n");
    printf("    > ");
}
void runFastTravelMenu(Player* player){
    char cInput=' ';
    do{
        displayFastTravelMenu(player);
        // cInput=getch();
        scanf(" %c", &cInput);
        printf("\n");
        processInputFastTravelMenu(player, cInput);
    }while(cInput!='0'&&cInput!='1'&&cInput!='2'&&cInput!='3'&&cInput!='4'&&cInput!='5'&&cInput!='6'&&cInput!='7');
}

//Level Up Menu (Subscreen)
void processInputLevelUpMenu(int *nTestRunes, Player *player, int nLevelUpRuneCost, char cInput){
    if ((*nTestRunes)>=nLevelUpRuneCost){
        switch (cInput){
            case '1':
                printf("Upgrade Health\n");
                player->nHealth++;
                (*nTestRunes)-=nLevelUpRuneCost;
                //Upgrade Health here
                break;
            case '2':
                printf("Upgrade Endurance\n");
                player->nEndurance++;
                (*nTestRunes)-=nLevelUpRuneCost;
                //Upgrade Endurance here
                break;
            case '3':
                printf("Upgrade Dexterity\n");
                player->nDexterity++;
                (*nTestRunes)-=nLevelUpRuneCost;
                //Upgrade Dexterity here
                break;
            case '4':
                printf("Upgrade Strength\n");
                player->nStrength++;
                (*nTestRunes)-=nLevelUpRuneCost;
                break;
            case '5':
                printf("Upgrade Intelligence\n");
                player->nIntelligence++;
                (*nTestRunes)-=nLevelUpRuneCost;
                break;
            case '6':
                printf("Upgrade Faith\n");
                player->nFaith++;
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
void displayLevelUpMenu(int nLevelUpRuneCost, int *nTestRunes, Player *player){
    printf("Level Up Menu\n");
    printf("%d ❖ Runes\n", *nTestRunes);
    printf("\n");
    printf("Level Up Cost : %d ❖\n", nLevelUpRuneCost);
    printf("(1) Health          (%d) + 1\n", player->nHealth);
    printf("(2) Endurance       (%d) + 1\n", player->nEndurance);
    printf("(3) Dexterity       (%d) + 1\n", player->nDexterity);
    printf("(4) Strength        (%d) + 1\n", player->nStrength);
    printf("(5) Intelligence    (%d) + 1\n", player->nIntelligence);
    printf("(6) Faith           (%d) + 1\n", player->nFaith);
    printf("(0) Back\n");
    printf("    > ");
}
void runLevelUpMenu(int *nTestRunes, Player *player){
    char cInput=' ';

        do{
            int nLevelUpRuneCost=(player->nLevel*100)/2;
            displayLevelUpMenu(nLevelUpRuneCost, nTestRunes, player);
            // cInput=getch();
            scanf(" %c", &cInput);
            printf("\n");
            processInputLevelUpMenu(nTestRunes, player, nLevelUpRuneCost, cInput);
            
        }while(cInput!='0');
}

//RoundTable
void displayRoundTable(Player *player, int *nTestRunes){
    int nNameSpace=strlen(player->strName);
    int nJobClassSpace=strlen(player->strJobClass);
    int nLevelSpace=9;
    int nRunesSpace=9;
    int nIncrement=100000000;

    printf("\t▜▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▛\n");
    printf("\t▐▐╱╲▌▌╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳▐▐╱╲▌▌\n");
    printf("\t▐▐╲╱▌▛▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▜▐╲╱▌▌\n");
    printf("\t▐▐╱╲▌▌             𐂂   𝑹 𝑶 𝑼 𝑵 𝑫 ◌ 𝑻 𝑨 𝑩 𝑳 𝑬   𓅃                        ▐▐╱╲▌▌\n");
    printf("\t▐▐╲╱▌▌       ╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌   ❖ %d", *nTestRunes); // Runes should be maxxed at 999,999,999
    while(((*nTestRunes)/nIncrement)<=0){
        if (((*nTestRunes)/nIncrement)<=0){
            nIncrement/=10;
            nRunesSpace-=1;
        }
    }
    for (int nSpacing=0; nSpacing<(14-nRunesSpace); nSpacing++){
        printf(" ");
    }
    printf("▐▐╲╱▌▌\n");

    printf("\t▐▐╱╲▌▌        Name    %s", player->strName);
    for (int nSpacing=0; nSpacing<(50-nNameSpace); nSpacing++){
        printf(" ");
    }

    printf("▐▐╱╲▌▌\n");

    printf("\t▐▐╲╱▌▌        Class   %s", player->strJobClass);
    for (int nSpacing=0; nSpacing<(50-nJobClassSpace); nSpacing++){
        printf(" ");
    }
    printf("▐▐╲╱▌▌\n");

    nIncrement=100000000;
    while(((player->nLevel)/nIncrement)<=0){
        if (((player->nLevel)/nIncrement)<=0){
            nIncrement/=10;
            nLevelSpace-=1;
        }
    }
    printf("\t▐▐╱╲▌▌        Level   %d", player->nLevel);
    for (int nSpace=0; nSpace<(50-nLevelSpace);nSpace++){
        printf(" ");
    }
    printf("▐▐╱╲▌▌\n");
    
    // printf("\t▐▐╲╱▌▌        Shards  ◈ ◆ ◈ ◈ ◇ ◇                                       ▐▐╲╱▌▌\n");
    printf("\t▐▐╲╱▌▌        Shards ");
    for (int nShards=0; nShards<6; nShards++){
        if (player->nShards[nShards]==1){
            printf(" ◆");
        } else {
            printf(" ◇");
        }
    }
    printf("                                       ▐▐╲╱▌▌\n");
    printf("\t▐▐╱╲▌▌       ╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌                   ▐▐╱╲▌▌\n");
    printf("\t▐▐╲╱▌▌        1▸ Fast Travel        4▸ Shop                             ▐▐╲╱▌▌\n");
    printf("\t▐▐╱╲▌▌        2▸ Level Up           5▸ Save                             ▐▐╱╲▌▌\n");
    printf("\t▐▐╲╱▌▌        3▸ Inventory          0▸ Quit Game                        ▐▐╲╱▌▌\n");
    printf("\t▐▐╱╲▌▌                                                                  ▐▐╱╲▌▌\n");
    printf("\t▐▐╲╱▌▙▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▟▐╲╱▌▌\n");
    printf("\t▐▐╱╲▌▌╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳▐▐╱╲▌▌\n");
    printf("\t▟▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▙\n");
    printf("\n");
    printf("\t> ");
}
void processInputRoundTable(Player *player, int *nTestRunes, int *aTestInventory, char cInput){

    int nSavingAllowed;
    int nDummyGameLoaded;

    switch (cInput){
        case '1': 
            runFastTravelMenu(player); 
            break;
        case '2': 
            runLevelUpMenu(nTestRunes, player);
            break;
        case '3': 
            runInventoryMenu(player);
            break;
        case '4': 
            runShopMenu(nTestRunes, aTestInventory);
            break;
        case '5': 
            nSavingAllowed=1;
            nDummyGameLoaded=0; // This is just a dummy variable
            printf("runSave()\n");
            runSaveMenu(&nDummyGameLoaded, nSavingAllowed, player); 
            break;
        default: printf("Invalid Input\n"); break;
    }
}
