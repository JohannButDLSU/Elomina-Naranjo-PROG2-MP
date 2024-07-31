#include "enemy_battle.h"

void runEnemyBattle(struct sAreaData* sArea, Player* player, Enemy* enemy){

    displayEnemyBattle(sArea, player, enemy);
    processEnemyBattle(sArea, player, enemy);
    displayEnemyBattle(sArea, player, enemy);

}

void processEnemyBattle(struct sAreaData* sArea, Player* player, Enemy* enemy){
    player->nHealth -= enemyAttack(sArea->nAreaIndex, *enemy);
    enemy->nHealth -= 15;
}

void displayEnemyBattle(struct sAreaData* sArea, Player* player, Enemy* enemy){
    // apparently supposed to show the following

    /*
        Screen Header

        Player Name
        Player Health Bar | Player Health Value
        Player Sprite

        Enemy Name
        Enemy Health Bar | Enemy Health Value
        Enemy Sprite

        System Messages
    */
   
    // I will not str playerHealthBar !!! bc I typedef'd it so I treat it more like a ui image
    Bar playerHealthBar = "████████████████████████████████████████████████████████████████████████████████████████████████████";
    playerHealthBar[(int) ((float)player->nHealth / (float)player->nMaxHealth * 100) + 1] = '\0';
    Bar enemyHealthBar =  "████████████████████████████████████████████████████████████████████████████████████████████████████";
    enemyHealthBar[(int) ((float)enemy->nHealth / (float)enemy->nMaxHealth * 100) + 1] = '\0';

    printf("Player : %s", player->strName);
    printf("\n");
    printc(0, DEEP_GREEN, playerHealthBar);
    printf("\n");
    printf ("HP: %d / %d", player->nHealth, player->nMaxHealth);
    printf("\n");
    printf("\n");
    printf("\n");
    printf("Enemy : %s", enemy->strName);
    printf("\n");
    printc(0, DEEP_RED, enemyHealthBar);
    printf("\n");
    printf ("HP: %d / %d", enemy->nHealth, enemy->nMaxHealth);
    printf("\n");
    printf("\n");
    printf("\n");
}