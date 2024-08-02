#include "character_creation.h"

    // printf("\t▩═════════════════▩\n");
    // ║
    
void runCharacterCreation(){
    Player player = setPlayer();
    char cInput = ' ';
    do{
        displayCharacterCreation(player);
        processCharacterCreationInput(&player, &cInput);
    } while (cInput != '0');
}

void displayCharacterCreation(Player player){
    printf("\n");
    printYBorder(0, WHITE, BORDER_2_LENGTH); printYBorderPlayer(); printf("\n");
    if (strcmp(player.strJobClass, "Jobless :(")){
        printMiddleBorder(0, WHITE, "", BORDER_2_LENGTH);                                           printMiddleBorderPlayer(player, 0);     printf("\n");
        printMiddleBorder(0, WHITE, player.strName, BORDER_2_LENGTH);                               printMiddleBorderPlayer(player, 1);     printf("\n");
        printMiddleBorder(0, WHITE, player.strJobClass, BORDER_2_LENGTH);                           printMiddleBorderPlayer(player, 2);     printf("\n");
        printMiddleBorder(0, WHITE, "", BORDER_2_LENGTH);                                           printMiddleBorderPlayer(player, 3);     printf("\n");
        printMiddleBorder(0, WHITE, "", BORDER_2_LENGTH);                                           printMiddleBorderPlayer(player, 4);     printf("\n");
        printWintMiddleBorder(0, WHITE, "Level : ", player.nLevel, BORDER_2_LENGTH);                printMiddleBorderPlayer(player, 5);     printf("\n");
        printMiddleBorder(0, WHITE, "", BORDER_2_LENGTH);                                           printMiddleBorderPlayer(player, 6);     printf("\n");
        printMiddleBorder(0, WHITE, "", BORDER_2_LENGTH);                                           printMiddleBorderPlayer(player, 7);     printf("\n");
        printWintMiddleBorder(0, WHITE, "Health : ", player.nHealth, BORDER_2_LENGTH);              printMiddleBorderPlayer(player, 8);     printf("\n");
        printWintMiddleBorder(0, WHITE, "Endurance : ", player.nEndurance, BORDER_2_LENGTH);        printMiddleBorderPlayer(player, 9);     printf("\n");
        printWintMiddleBorder(0, WHITE, "Dexterity : ", player.nDexterity, BORDER_2_LENGTH);        printMiddleBorderPlayer(player, 10);    printf("\n");
        printWintMiddleBorder(0, WHITE, "Strength : ", player.nStrength, BORDER_2_LENGTH);          printMiddleBorderPlayer(player, 11);    printf("\n");
        printWintMiddleBorder(0, WHITE, "Intelligence : ", player.nIntelligence, BORDER_2_LENGTH);  printMiddleBorderPlayer(player, 12);    printf("\n");
        printWintMiddleBorder(0, WHITE, "Faith : ", player.nFaith, BORDER_2_LENGTH);                printMiddleBorderPlayer(player, 13);    printf("\n");
        printMiddleBorder(0, WHITE, "", BORDER_2_LENGTH);                                           printMiddleBorderPlayer(player, 14);    printf("\n");
        printMiddleBorder(0, WHITE, "", BORDER_2_LENGTH);                                           printMiddleBorderPlayer(player, 15);    printf("\n");
    }
    else{
        printMiddleBorder(0, WHITE, "Hey You! Get a Job Class! (Press [2])", BORDER_2_LENGTH);      printf("║  Your character will be here!  ║\n");
    }
    printYBorder(0, WHITE, BORDER_2_LENGTH); printYBorderPlayer();  printf("\n");
    printChoiceBorder(0, WHITE, "[1] Change Name", 3, BORDER_2_LENGTH);
    printChoiceBorder(0, WHITE, "[2] Change Class", 3, BORDER_2_LENGTH);
    printChoiceBorder(0, GREEN, "[3] Continue", 3, BORDER_2_LENGTH);
    printChoiceBorder(0, GRAY, "[0] Back", 3, BORDER_2_LENGTH);
    printChoiceBorderless("[INPUT] : ", BORDER_2_LENGTH);
}

void processCharacterCreationInput(Player* player, char* cInput){
    scanf(" %c", cInput);
    
    switch (*cInput)
    {
        case '1':
            printf("\n");
            printCentered("Enter a new name!", BORDER_2_LENGTH);
            printChoiceBorderless("[INPUT] : ", BORDER_2_LENGTH);

            String strNewName;
            scanf(" %[^\n]%*c", strNewName);
            strNewName[25] = '\0';
            strcpy(player->strName, strNewName);

            break;
        case '2':
            printf("\n");
            printCentered("   Choose a Job Class!", BORDER_2_LENGTH);
            printf("\n");
            printChoiceBorder(0, DEEP_MAGENTA, "[1] Vagabond", 3, BORDER_2_LENGTH);
            printChoiceBorder(0, DEEP_YELLOW, "[2] Samurai", 3, BORDER_2_LENGTH);
            printChoiceBorder(0, DEEP_CYAN, "[3] Warrior", 3, BORDER_2_LENGTH);
            printChoiceBorder(0, BLUE, "[4] Hero", 5, BORDER_2_LENGTH);
            printChoiceBorder(0, MAGENTA, "[5] Astrologer", 2, BORDER_2_LENGTH);
            printChoiceBorder(0, DEEP_ORANGE, "[6] Prophet", 3, BORDER_2_LENGTH);
            printf("\n");
            printChoiceBorder(0, GRAY, "[0] Back", 3, BORDER_2_LENGTH);
            printChoiceBorderless("[INPUT] : ", BORDER_2_LENGTH);
            char cJobClassInput = ' ';
            scanf(" %c", &cJobClassInput);
            *player = setPlayerJobClass(*player, cJobClassInput);
            break;
        case '3':
            if (strcmp(player->strJobClass, "Jobless :(") == 0){
                printf("\n");
                printCentered("You need to have a Job Class to proceed!", BORDER_2_LENGTH);
                break;
            }
            else if (strcmp(player->strName, "Unnamed Bozo xD") == 0){
                printf("\n");
                printCentered("You are an unnamed bozo! Choose a name to proceed.", BORDER_2_LENGTH);
                break;
            }
            else{
                printf("\n");
                printcCentered(0, RED, "---IMPORTANT NOTICE---", BORDER_2_LENGTH);
                printf("\n");
                String strToPrint = "You will be known as: ";
                strcat(strToPrint, player->strName);
                strcat(strToPrint, ", the ");
                strcat(strToPrint, player->strJobClass);
                strcat(strToPrint, ".");

                printcCentered(0, WHITE, strToPrint, BORDER_2_LENGTH);

                printf("\n");
                printChoiceBorder(0, GREEN, "[1] Proceed", 3, BORDER_2_LENGTH);
                printChoiceBorder(0, GRAY, "[0] Go back", 3, BORDER_2_LENGTH);
                printf("\n");
                printChoiceBorderless("[INPUT] : ", BORDER_2_LENGTH);

                char tempInput;
                scanf(" %c", &tempInput);

                if (tempInput == '1'){
                    runRoundTable(player); // There is no "break;"" line. From roundtable, the screen should exit to the title screen and not the character creation screen
                }
                if (tempInput == '0'){
                    *cInput = '3';
                    break;
                }
            }
        //imaginary break;
        case '0':
            runTitle();       
        default:
            break;
    }
}

Player setPlayerJobClass(Player player, int cInput){ // this was made before I put the sprite in player LMAO I giv up
    JobClass vagabond = setJobClass("Vagabond", 9, 15, 11, 13, 14, 9, 9);
    JobClass samurai = setJobClass("Samurai", 9, 12, 13, 15, 12, 9, 8);
    JobClass warrior = setJobClass("Warrior", 8, 11, 11, 16, 10, 10, 8);
    JobClass hero = setJobClass("Hero", 7, 14, 12, 9, 16, 7, 8);
    JobClass astrologer = setJobClass("Astrologer", 6, 9, 9, 12, 8, 16, 7);
    JobClass prophet = setJobClass("Prophet", 7, 10, 8, 10, 11, 7, 16);

    switch (cInput)
    {
    case '1': case 'V': case 'v':
        player = statCopy(player, vagabond);
        break;
    case '2': case 'S': case 's':
        player = statCopy(player, samurai);
        break;
    case '3': case 'W': case 'w':
        player = statCopy(player, warrior);
        break;
    case '4': case 'H': case 'h':
        player = statCopy(player, hero);
        break;
    case '5': case 'A': case 'a':
        player = statCopy(player, astrologer);
        break;
    case '6': case 'P': case 'p':
        player = statCopy(player, prophet);
        break;
    default:
        break;
    }

    return player;
}