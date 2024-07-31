#include "enemy_battle.h"

void runEnemyBattle(struct sAreaData* sArea, Player* player, Enemy* enemy){

    displayEnemyBattle(sArea, player, enemy);
    processEnemyBattle(sArea, player, enemy); // this is temporary, all it does is damage the player to make sure the thing works
    displayEnemyBattle(sArea, player, enemy);

}

void processEnemyBattle(struct sAreaData* sArea, Player* player, Enemy* enemy){
    player->nHealth -= enemyAttack(sArea->nAreaIndex, *enemy);
}

void displayEnemyBattle(struct sAreaData* sArea, Player* player, Enemy* enemy){
    printf("Name : %s\n", player->strName);
    printf("HP   : %d\n", player->nHealth);
    printf("Enemy Name : %s\n", enemy->strName);
    printf("Enemy Type : %d\n", enemy->nType);
    printf("Enemy Health : %d\n", enemy->nHealth);
}