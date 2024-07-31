#include "enemy_battle.h"

void runEnemyBattle(struct sAreaData* sArea, Player* player, Enemy enemy){

    displayEnemyBattle(sArea, player, enemy);
    processEnemyBattle(sArea, player, enemy);
    displayEnemyBattle(sArea, player, enemy);

}

void processEnemyBattle(struct sAreaData* sArea, Player* player, Enemy enemy){
    player->nHealth -= enemyAttack(sArea->nAreaIndex, enemy);
}

void displayEnemyBattle(struct sAreaData* sArea, Player* player, Enemy enemy){
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

    Bar playerHealthBar;
    Bar enemyHealthBar;

    printf("Name : %s\n", player->strName);
    printf("HP   : %d\n", player->nHealth);
    printf("Enemy Name : %s\n", enemy.strName);
    printf("Enemy Type : %d\n", enemy.nType);
    printf("Enemy Health : %d\n", enemy.nHealth);
}