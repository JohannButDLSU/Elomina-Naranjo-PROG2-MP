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
    scanf(" %c", &cInput);
    switch (cInput)
    {
        case '1':
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
        default:
            break;
    }

    
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
    printf ("HP: %4d / %4d", player->nBattleCurrentHealth, player->nBattleMaxHealth);
    printf("\n");
    printf("\n");
    printf("\n");
    printf("Enemy : %s", enemy->strName);
    printf("\n");
    printc(0, DEEP_RED, enemyHealthBar); printf(" %%");
    printf("\n");
    printf ("HP: %4d / %4d", enemy->nHealth, enemy->nMaxHealth);
    printf("\n");
    printf("\n");
    printf("\n");
    printf("What do?\n");
    printf("[1] Attack\n");
    printf("[2] Dodge\n");
    printf("[3] Drink Potion\n");
    printf("[INPUT] : ");
}