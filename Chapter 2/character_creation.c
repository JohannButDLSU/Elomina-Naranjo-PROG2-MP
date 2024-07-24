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
    printf("\t▩═══════════════════════════════════════════════════════════════════════▩\n");
    printf("\t║\tcreate the dudes face on the right side\t\t\t\t║\n");
    printf("\t║\t\t\t\t\t\t\t\t\n");
    printf("\t║\tName : %s\n", player.strName);
    printf("\t║\tClass : %s\n", player.strJobClass);
    printf("\t║\n");
    printf("\t║\tLevel : %d\n", player.nLevel);
    printf("\t║\tHP : %d\n", player.nHealth);
    printf("\t║\tEndurance : %d\n", player.nEndurance);
    printf("\t║\tDexterity : %d\n", player.nDexterity);
    printf("\t║\tStrength : %d\n", player.nStrength);
    printf("\t║\tIntelligence : %d\n", player.nIntelligence);
    printf("\t║\tFaith : %d\n", player.nFaith);
    printf("\t║\n");
    printf("\t▩═════════════════════════════════════════════════════════════════════▩\n");
    printf("\t\t[1] Change Name\n");
    printf("\t\t[2] Change Class\n");
    printf("\t\t[3] Continue\n");
    printf("\t\t[0] Back\n");
    printf("\t\t[INPUT] : ");
}

void processCharacterCreationInput(Player* player, char* cInput){
    scanf(" %c", cInput);

    int aTestInventory[24]={1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //Each index represents a weapon in MP specs, Appendix C
    int nTestRunes;

    switch (*cInput)
    {
        case '1':
            printf("enter new name : ");
            char strNewName[26];
            scanf(" %[^\n]%*c", strNewName);
            strcpy((*player).strName, strNewName);
            break;
        case '2':
            printf("Choose a Job Class\n");
            printf("[1] Vagabond\n");
            printf("[2] Samurai\n");
            printf("[3] Warrior\n");
            printf("[4] Hero\n");
            printf("[5] Astrologer\n");
            printf("[6] Prophet\n");
            printf("[0] Back\n");
            printf("[INPUT] : ");
            char cJobClassInput = ' ';
            scanf(" %c", &cJobClassInput);
            *player = setPlayerJobClass(*player, cJobClassInput);
            break;
        case '3':
            nTestRunes=500;
            runRoundTable(player, &nTestRunes, aTestInventory);
            // There is no "break;"" line. From roundtable, the screen should exit to the title screen and not the character creation screen
        case '0':
            runTitle();       
        default:
            break;
    }
}

Player setPlayerJobClass(Player player, int cInput){
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