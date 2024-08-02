#include "enemy_battle.h"

void runEnemyBattle(struct sAreaData* sArea, Player* player, Enemy* enemy){
    // Battle Setups
    do{
        displayEnemyBattle(sArea, player, enemy);
        processEnemyBattle(sArea, player, enemy);
    } while(player->nBattleCurrentHealth > 0 && enemy->nHealth > 0);

}

void processEnemyBattle(struct sAreaData* sArea, Player* player, Enemy* enemy){
    char cInput = ' ';

    int nDodge = 0; // 1 is u dodged, 0 is u didn't
    int nDodgeRate = -1;

    int nPotionHeal = -1;

    scanf(" %c", &cInput);
    switch (cInput)
    {
        case '1': // Attack
            printChoiceBorder(0, ORANGE, "[1] Physical", 4, BORDER_5_LENGTH);
            printf("\n");
            printChoiceBorder(0, MAGENTA, "[2] Sorcery", 4, BORDER_5_LENGTH);
            printf("\n");
            printChoiceBorder(0, YELLOW, "[3] Incantation", 4, BORDER_5_LENGTH);
            printf("\n");
            
            printChoiceBorderless("[INPUT] : ", BORDER_5_LENGTH);
            char cInput2;
            scanf(" %c", &cInput2);
            switch (cInput2)
            {
                case '1':
                    enemy->nHealth -= (player->nStrength + player->sEquippedWeapon.nStrength) * (1 - enemy->fPhysDef);
                    break;
                case '2':
                    enemy->nHealth -= (player->nIntelligence + player->sEquippedWeapon.nIntelligence) * (1 - enemy->fSorcDef);
                    break;
                case '3':
                    enemy->nHealth -= (player->nFaith + player->sEquippedWeapon.nFaith) * (1 - enemy->fIncaDef);
                    break;
                default:
                    printf("ERROR cInput2 IS %c!!!\n", cInput2);
                    break;
            }
            break;
        case '2': // Dodge
            nDodgeRate = 20 + ((player->nEndurance + player->sEquippedWeapon.nEndurance) / 2);
            if ((rand() % (99 - 0 + 1) + 0) < nDodgeRate) nDodge = 1;
            else (nDodge = 0);
            break;
        case '3': // Drink Potion
            if (player->nPotions <= 0) return; // guard clause
            nPotionHeal = (rand() % (50 - 25 + 1)) + 25;
            nPotionHeal = (int) (((float)nPotionHeal * (float)player->nBattleMaxHealth) / 100);
            player->nBattleCurrentHealth += nPotionHeal;
            player->nPotions --;
            printf("\nyou healed %d !\n", nPotionHeal);
            break;
        default:
            return;
            break;
    }
    if (!nDodge) player->nBattleCurrentHealth -= enemyAttack(sArea->nAreaIndex, *enemy);

    // Limits the health
    if (player->nBattleCurrentHealth >= player->nBattleMaxHealth) player->nBattleCurrentHealth = player->nBattleMaxHealth;

    if (player->nBattleCurrentHealth <= 0) printf("\nYou Died.\n");
    else if (enemy->nHealth <= 0) printf("\nEnemy Felled.\n");


    // to do:
    //  - end of battle screen
    //  - kick player back to roundtable if they lose (need zivv to connect sArea and nRunning)
    //  - center everything
    //  DONE - 8 potions only
    //  - SHOW rewards after killing
    //  - SHOW damage u dealt and enemy after the turn
    //  - PROLLY A LOT MORE AUGHHH
}

void displayEnemyBattle(struct sAreaData* sArea, Player* player, Enemy* enemy){
    // I will not str playerHealthBar !!! bc I typedef'd it so I treat it more like a ui image
    Bar playerHealthBar = "==================================================";
    playerHealthBar[(int) ((float)player->nBattleCurrentHealth / (float)player->nBattleMaxHealth * 50) + 1] = '\0';
    Bar enemyHealthBar =  "||||||||||||||||||||||||||||||||||||||||||||||||||";
    enemyHealthBar[(int) ((float)enemy->nHealth / (float)enemy->nMaxHealth * 50)] = '\0';

    printYBorder(0, WHITE, BORDER_5_LENGTH); printYBorder(0, WHITE, BORDER_5_LENGTH); printf("\n");
    printMiddleBorder(0, WHITE, player->strName, BORDER_5_LENGTH);  printMiddleBorder(0, WHITE, enemy->strName, BORDER_5_LENGTH);
    printf("\n");
    printMiddleBorder(0, DEEP_GREEN, playerHealthBar, BORDER_5_LENGTH); printMiddleBorder(0, DEEP_RED, enemyHealthBar, BORDER_5_LENGTH);
    printf("\n");
    printWintMiddleBorder(0, WHITE, "Current Health : ", player->nBattleCurrentHealth, BORDER_5_LENGTH); printWintMiddleBorder(0, WHITE, "Current Health : ", enemy->nHealth, BORDER_5_LENGTH);
    printf("\n");
    printWintMiddleBorder(0, WHITE, "Max Health : ", player->nBattleMaxHealth, BORDER_5_LENGTH); printWintMiddleBorder(0, WHITE, "Max Health : ", enemy->nMaxHealth, BORDER_5_LENGTH);
    printf("\n");
    printf("\n");
    printMiddleBorder(0, 0, "Choose a battle option", BORDER_5_LENGTH); printWintMiddleBorder(0, WHITE, "Enemy damage this turn : ", enemyAttack(sArea->nAreaIndex, *enemy), BORDER_5_LENGTH); printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printChoiceBorder(0, WHITE, "[1] Attack", 4, BORDER_5_LENGTH);
    printChoiceBorder(0, WHITE, "[2] Dodge", 4, BORDER_5_LENGTH);
    printChoiceBorder(0, WHITE, "[3] Drink Potion", 4, BORDER_5_LENGTH);
    printChoiceBorderless("[INPUT] : ", BORDER_5_LENGTH);
}