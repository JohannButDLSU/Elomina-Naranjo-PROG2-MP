#include "character_creation.h"

void runCharacterCreation(){
    struct Player player = setPlayer();
    char cInput = ' ';
    do{
        displayCharacterCreation(player);
        processCharacterCreationInput(&player, &cInput);
    } while (cInput != '0');
}

void displayCharacterCreation(struct Player player){
    printf("Pretend this is the epic character screen!!!\n");
    printf("Name : %s\n", player.strName);
    printf("Class : %s\n", player.strJobClass);

    printf("Level : %d\n", player.nLevel);
    printf("HP : %d\n", player.nHealth);
    printf("Endurance : %d\n", player.nEndurance);
    printf("Dexterity : %d\n", player.nDexterity);
    printf("Strength : %d\n", player.nStrength);
    printf("Intelligence : %d\n", player.nIntelligence);
    printf("Faith : %d\n", player.nFaith);
    printf("\n");
    printf("[1] Change Name\n");
    printf("[2] Change Class\n");
    printf("[0] Back\n");
    printf("[INPUT] : ");
}

void processCharacterCreationInput(struct Player* player, char* cInput){
    scanf(" %c", cInput);

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
        case '0':
            runTitle();       
        default:
            break;
    }
}

struct Player setPlayerJobClass(struct Player player, int cInput){
    struct JobClass vagabond = setJobClass("Vagabond", 9, 15, 11, 13, 14, 9, 9);
    struct JobClass samurai = setJobClass("Samurai", 9, 12, 13, 15, 12, 9, 8);
    struct JobClass warrior = setJobClass("Warrior", 8, 11, 11, 16, 10, 10, 8);
    struct JobClass hero = setJobClass("Hero", 7, 14, 12, 9, 16, 7, 8);
    struct JobClass astrologer = setJobClass("Astrologer", 6, 9, 9, 12, 8, 16, 7);
    struct JobClass prophet = setJobClass("Prophet", 7, 10, 8, 10, 11, 7, 16);

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