#include "enemy_battle.h"

void runEnemyBattle(struct sAreaData* sArea, Player* player, Enemy enemy){
    printf("runEnemyBattle\n\n");
    printf("Name : %s\n", player->strName);
    printf("HP   : %d\n", player->nHealth);

    processEnemyBattle(sArea, player, enemy); // this is temporary, all it does is damage the player to make sure the thing works
}

void processEnemyBattle(struct sAreaData* sArea, Player* player, Enemy enemy){
    player->nHealth -= enemyAttack(sArea->nAreaIndex, enemy);
}

void displayEnemyBattle(){

}