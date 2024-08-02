#include "roundTable.h"

void runRoundTable(Player *player){
    char cInput=' ';
    do{
        displayRoundTable(player);
        // cInput=getch();
        scanf(" %c", &cInput);
        printf("\n");
        processInputRoundTable(player, cInput);
    }while(cInput!='0');
}

void runFastTravelMenu(Player* player){
    char cInput=' ';
    int nRunning=1;
    do{
        displayFastTravelMenu(player);
        // cInput=getch();
        scanf(" %c", &cInput);
        printf("\n");
        processInputFastTravelMenu(&nRunning, player, cInput);
    }while(nRunning==1);
}

void runLevelUpMenu(Player *player){
    char cInput=' ';

        do{
            int nLevelUpRuneCost=(player->nLevel*100)/2;
            displayLevelUpMenu(nLevelUpRuneCost, player);
            // cInput=getch();
            scanf(" %c", &cInput);
            printf("\n");
            processInputLevelUpMenu(player, nLevelUpRuneCost, cInput);
            
        }while(cInput!='0');
}

//Fast Travel Menu
void processInputFastTravelMenu(int* nRunning, Player* player, char cInput){
    // Imma put variables here again to fix da stupig 
    int nShardsCompleted;

    switch (cInput){
        case '1': 
            runArea(player, 1); // Stormveil Castle
            (*nRunning)=0;
            break;
        case '2':
            runArea(player, 2); // Raya Lucaria
            (*nRunning)=0;
            break;
        case '3':
            runArea(player, 3); // Redmane Castle
            (*nRunning)=0;
            break;
        case '4':
            runArea(player, 4); // Volcano Manor
            (*nRunning)=0;
            break;
        case '5': //Leyndell Royal Capital
            nShardsCompleted=0;
            for (int nShards=0; nShards<6; nShards++){
                if (player->nShards[nShards]==1){
                    nShardsCompleted++;
                }
            }
            if (nShardsCompleted>=2){
                runArea(player, 5);
                (*nRunning)=0;
            }else{
                printRepeatedly(4,"\t");
                printf("You need at least 2 shards to enter the Leyndell Royal Capital\n"); 
            }
            break;
        case '6': //Elden Throne
            if (player->nShards[4]==1){
                runArea(player, 6);
                (*nRunning)=0;
            } else{
                printRepeatedly(3,"\t");
                printf("You need the shard from Leyndell Royal Capital to enter the Elden Throne\n"); 
            }
            break;
        case '0': 
            (*nRunning)=0;
            break;
        default:    
            printRepeatedly(5,"\t");
            printf("Invalid Input\n"); 
            break;
    }
}
void displayFastTravelMenu(Player* player){
    printRepeatedly(6,"\t");
    printf("     Fast Travel Menu\n\n");
    printRepeatedly(5,"\t");
    printf("╔═════════════════════════════════════════╗\n");
    printRepeatedly(5,"\t");
    printf("║                                         ║\n");
    printRepeatedly(5,"\t");
    printf("║   (1) Stormveil Castle                  ║\n");
    printRepeatedly(5,"\t");
    printf("║   (2) Ray Lucaria Academy               ║\n");
    printRepeatedly(5,"\t");
    printf("║   (3) Redmane Castle                    ║\n");
    printRepeatedly(5,"\t");
    printf("║   (4) Volcano Manor                     ║\n");
    // Print Leyndell Royal Capital
    int nShardsCompleted=0;
    for (int nShards=0; nShards<6; nShards++){
        if (player->nShards[nShards]==1){
            nShardsCompleted++;
        }
    }
    if (nShardsCompleted>=2){
        printRepeatedly(5,"\t");
        printf("║   (5) Leyndell Royal Capital            ║\n");
    } else{
        printRepeatedly(5,"\t");
        printf("║   ");
        printc(0,233,"(~) Leyndell Royal Capital (Locked)");
        printf("   ║\n");
    }

    //Print Elden Throne
    if (player->nShards[4]==1){
        printRepeatedly(5,"\t");
        printf("║   (6) Elden Throne                      ║\n");
    } else{
        printRepeatedly(5,"\t");
        printf("║   ");
        printc(0,233,"(~) Elden Throne (Locked)"); // Find character for a lock
        printf("             ║\n");
    }
    printRepeatedly(5,"\t");
    printf("║                                         ║\n");
    printRepeatedly(5,"\t");
    printf("║   (0) Back                              ║\n");
    printRepeatedly(5,"\t");
    printf("║                                         ║\n");
    printRepeatedly(5,"\t");
    printf("╚═════════════════════════════════════════╝\n");
    printf("\n");
    printRepeatedly(5,"\t");
    printf("    > ");
}

//Level Up Menu (Subscreen)
void processInputLevelUpMenu(Player *player, int nLevelUpRuneCost, char cInput){
    if ((player->nRunes)>=nLevelUpRuneCost){
        switch (cInput){
            case '1':
                if (player->nHealth<50){
                    player->nHealth++;
                    (player->nRunes)-=nLevelUpRuneCost;
                    //Upgrade Health here
                } else{
                    printf("\n\n\n");
                    printRepeatedly(5,"\t");
                    printf("You already reached the MAX Health\n\n\n");
                }
                break;
            case '2':
                if(player->nEndurance<50){
                    player->nEndurance++;
                    (player->nRunes)-=nLevelUpRuneCost;
                    //Upgrade Endurance here
                } else{
                    printf("\n\n\n");
                    printRepeatedly(5,"\t");
                    printf("You already reached the MAX Endurance\n\n\n");
                }
                break;
            case '3':
                if(player->nDexterity<50){
                    player->nDexterity++;
                    (player->nRunes)-=nLevelUpRuneCost;
                    //Upgrade Dexterity here
                } else{
                    printf("\n\n\n");
                    printRepeatedly(5,"\t");
                    printf("You already reached the MAX Dexterity\n\n\n");
                }
                break;
            case '4':
                if (player->nStrength<50){
                    player->nStrength++;
                    (player->nRunes)-=nLevelUpRuneCost;
                } else{
                    printf("\n\n\n");
                    printRepeatedly(5,"\t");
                    printf("You already reached the MAX Strength\n\n\n");
                }
                break;
            case '5':
                if(player->nIntelligence<50){
                    player->nIntelligence++;
                    (player->nRunes)-=nLevelUpRuneCost;
                } else{
                    printf("\n\n\n");
                    printRepeatedly(5,"\t");
                    printf("You already reached the MAX Intelligence\n\n\n");
                }
                break;
            case '6':
                if(player->nFaith<50){
                    player->nFaith++;
                    (player->nRunes)-=nLevelUpRuneCost;
                } else{
                    printf("\n\n\n");
                    printRepeatedly(5,"\t");
                    printf("You already reached the MAX Faith\n\n\n");
                }
                break;
            case '0':
                break;
        }
        player->nLevel++;
    } else if (cInput!='0'&&cInput!='1'&&cInput!='2'&&cInput!='3'&&cInput!='4'&&cInput!='5'&&cInput!='6'){
        printf("\n\n\n");
        printRepeatedly(5,"\t");
        printf("Invalid Input\n\n\n");
    } else{
        printf("\n\n\n");
        printRepeatedly(5,"\t");
        printf("You do not have enough ❖ runes for that\n\n\n");
    }
}
void displayLevelUpMenu(int nLevelUpRuneCost, Player *player){
    printRepeatedly(7,"\t");
    printf("Level Up Menu\n\n");
    printRepeatedly(5,"\t");
    printf("╔══════════════════════════════════════════╗\n");
    printRepeatedly(5,"\t");
    printf("║                                          ║\n");
    printRepeatedly(5,"\t");
    if (player->nHealth<50){
        printf("║  (1) Health          (%02d) + 1            ║\n", player->nHealth);
    } else{    
        printf("║  (1) Health          [%02d] MAXXED         ║\n", player->nHealth);
    }
    printRepeatedly(5,"\t");
    if (player->nEndurance<50){
        printf("║  (2) Endurance       (%02d) + 1            ║\n", player->nEndurance);
    } else{    
        printf("║  (2) Endurance       [%02d] MAXXED         ║\n", player->nEndurance);
    }
    printRepeatedly(5,"\t");
    if (player->nDexterity<50){
        printf("║  (3) Dexterity       (%02d) + 1            ║\n", player->nDexterity);
    } else{    
        printf("║  (3) Dexterity       [%02d] MAXXED         ║\n", player->nDexterity);
    }
    printRepeatedly(5,"\t");
    if (player->nStrength<50){
        printf("║  (4) Strength        (%02d) + 1            ║\n", player->nStrength);
    } else{    
        printf("║  (4) Strength        [%02d] MAXXED         ║\n", player->nStrength);
    }
    printRepeatedly(5,"\t");
    if (player->nIntelligence<50){
        printf("║  (5) Intelligence    (%02d) + 1            ║\n", player->nIntelligence);
    } else{    
        printf("║  (5) Intelligence    [%02d] MAXXED         ║\n", player->nIntelligence);
    }
    printRepeatedly(5,"\t");
    if (player->nFaith<50){
        printf("║  (6) Faith           (%02d) + 1            ║\n", player->nFaith);
    } else{    
        printf("║  (6) Faith           [%02d] MAXXED         ║\n", player->nFaith);
    }
    printRepeatedly(5,"\t");
    printf("║                                          ║\n");
    printRepeatedly(5,"\t");
    printf("║  (0) Back                                ║\n");
    printRepeatedly(5,"\t");
    printf("║                                          ║\n");
    printRepeatedly(5,"\t");
    printf("╚══════════════════════════════════════════╝\n");
    printf("\n");
    printRepeatedly(5,"\t");
    printf("    Runes              : ❖ %d \n", player->nRunes);
    printRepeatedly(5,"\t");
    printf("    Level Up Rune Cost : ❖ %d \n", nLevelUpRuneCost);
    printf("\n");
    printRepeatedly(5,"\t");
    printf(" - - - - - - - - - - - - - - - - - - - - - - \n");
    printf("\n");
    printRepeatedly(5,"\t");
    printf("    > ");
}

//RoundTable
void displayRoundTable(Player *player){
    int nNameSpace=strlen(player->strName);
    int nJobClassSpace=strlen(player->strJobClass);
    int nLevelSpace=9;
    int nRunesSpace=0;
    int nIncrement=1;
    
    printRepeatedly(2,"\t");
    printf("\t▜▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▙▟▛\n");
    printRepeatedly(2,"\t");
    printf("\t▐▐╱╲▌▌╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳▐▐╱╲▌▌\n");
    printRepeatedly(2,"\t");
    printf("\t▐▐╲╱▌▛▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▜▐╲╱▌▌\n");
    printRepeatedly(2,"\t");
    printf("\t▐▐╱╲▌▌             𐂂   𝑹 𝑶 𝑼 𝑵 𝑫 ◌ 𝑻 𝑨 𝑩 𝑳 𝑬   𓅃                        ▐▐╱╲▌▌\n");
    printRepeatedly(2,"\t");
    printf("\t▐▐╲╱▌▌       ╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌   ❖ %d", player->nRunes); // Runes should be maxxed at 999,999,999
    while(((player->nRunes)/nIncrement)>0&&player->nRunes!=nIncrement&&(player->nRunes>=(10*nIncrement))){
        nIncrement*=10;
        nRunesSpace++;
    };
    printRepeatedly(13-nRunesSpace," ");
    printf("▐▐╲╱▌▌\n");
    printRepeatedly(2,"\t");
    printf("\t▐▐╱╲▌▌        Name    %s", player->strName);
    for (int nSpacing=0; nSpacing<(50-nNameSpace); nSpacing++){
        printf(" ");
    }
    printf("▐▐╱╲▌▌\n");
    printRepeatedly(2,"\t");
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
    printRepeatedly(2,"\t");
    printf("\t▐▐╱╲▌▌        Level   %d", player->nLevel);
    for (int nSpace=0; nSpace<(50-nLevelSpace);nSpace++){
        printf(" ");
    }
    printf("▐▐╱╲▌▌\n");
    printRepeatedly(2,"\t");
    printf("\t▐▐╲╱▌▌        Shards ");
    for (int nShards=0; nShards<6; nShards++){
        if (player->nShards[nShards]==1){
            printf(" ◆");
        } else {
            printf(" ◇");
        }
    }
    printf("                                       ▐▐╲╱▌▌\n");
    printRepeatedly(2,"\t");
    printf("\t▐▐╱╲▌▌       ╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌                   ▐▐╱╲▌▌\n");
    printRepeatedly(2,"\t");
    printf("\t▐▐╲╱▌▌        1▸ Fast Travel        4▸ Shop                             ▐▐╲╱▌▌\n");
    printRepeatedly(2,"\t");
    printf("\t▐▐╱╲▌▌        2▸ Level Up           5▸ Save                             ▐▐╱╲▌▌\n");
    printRepeatedly(2,"\t");
    printf("\t▐▐╲╱▌▌        3▸ Inventory          0▸ Quit Game                        ▐▐╲╱▌▌\n");
    printRepeatedly(2,"\t");
    printf("\t▐▐╱╲▌▌                                                                  ▐▐╱╲▌▌\n");
    printRepeatedly(2,"\t");
    printf("\t▐▐╲╱▌▙▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▟▐╲╱▌▌\n");
    printRepeatedly(2,"\t");
    printf("\t▐▐╱╲▌▌╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳╳▐▐╱╲▌▌\n");
    printRepeatedly(2,"\t");
    printf("\t▟▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▛▜▙\n");
    printf("\n");
    printRepeatedly(2,"\t");
    printf("\t> ");
}
void processInputRoundTable(Player *player, char cInput){

    int nSavingAllowed;
    int nDummyGameLoaded;

    switch (cInput){
        case '1': 
            runFastTravelMenu(player); 
            break;
        case '2': 
            runLevelUpMenu(player);
            break;
        case '3': 
            runInventoryMenu(player);
            break;
        case '4': 
            runShopMenu(player);
            break;
        case '5': 
            nSavingAllowed=1;
            nDummyGameLoaded=0; // This is just a dummy variable
            runSaveMenu(&nDummyGameLoaded, nSavingAllowed, player); 
            break;
        default:
            printRepeatedly(5,"\t");
            printf("Invalid Input\n"); 
            break;
    }
}
