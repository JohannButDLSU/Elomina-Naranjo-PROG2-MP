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

    int nCanPotion = 1; // 1 is yes, 0 is no
    int nPotionHeal = -1;

    scanf(" %c", &cInput);
    switch (cInput)
    {
        case '1': // Attack
            printf("[1] Physical\n");
            printf("[2] Sorcery\n");
            printf("[3] Incantation\n");
            
            printf("[INPUT] : ");
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
            if (nCanPotion == 0) return; // guard clause
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

    // Checks
    if (player->nBattleCurrentHealth >= player->nBattleMaxHealth) player->nBattleCurrentHealth = player->nBattleMaxHealth;

    // Print the battle output here :)

    if (player->nBattleCurrentHealth <= 0) printf("\nYou Died.\n");
    else if (enemy->nHealth <= 0) printf("\nEnemy Felled.\n");


    // to do:
    //  - end of battle screen
    //  - kick player back to roundtable if they lose (need zivv to connect sArea and nRunning)
    //  - center everything
    //  - 8 potions only
    //  - SHOW rewards after killing
    //  - SHOW damage u dealt and enemy after the turn
    //  - PROLLY A LOT MORE AUGHHH
}

void displayEnemyBattle(struct sAreaData* sArea, Player* player, Enemy* enemy){
    // I will not str playerHealthBar !!! bc I typedef'd it so I treat it more like a ui image
    Bar playerHealthBar = "████████████████████████████████████████████████████████████████████████████████████████████████████";
    playerHealthBar[(int) ((float)player->nBattleCurrentHealth / (float)player->nBattleMaxHealth * 100) + 1] = '\0';
    Bar enemyHealthBar =  "████████████████████████████████████████████████████████████████████████████████████████████████████";
    enemyHealthBar[(int) ((float)enemy->nHealth / (float)enemy->nMaxHealth * 100) + 1] = '\0';

    printf("Player : %s", player->strName);
    printf("\n");
    printc(0, DEEP_GREEN, playerHealthBar); printf(" %%");
    printf("\n");
    printf("HP: %4d / %4d", player->nBattleCurrentHealth, player->nBattleMaxHealth);
    printf("\n");
    printf("\n");
    printf("\n");
    printf("Enemy : %s", enemy->strName);
    printf("\n");
    printc(0, DEEP_RED, enemyHealthBar); printf(" %%");
    printf("\n");
    printf("HP: %4d / %4d", enemy->nHealth, enemy->nMaxHealth);
    printf("\n");
    printf("\n");
    printf("\n");
    printf("Choose a battle option\n");
    printf("(Enemy will deal %d damage)\n", enemyAttack(sArea->nAreaIndex, *enemy));
    printf("[1] Attack\n");
    printf("[2] Dodge\n");
    printf("[3] Drink Potion\n");
    printf("[INPUT] : ");
}