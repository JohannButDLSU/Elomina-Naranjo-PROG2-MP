#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "_Global Folder/colors.h"

#include "_Global Folder/areaStructures.h"
#include "_Global Folder/gen_struct_manager.h"
#include "_Global Folder/job_class_sprites.h"
#include "_Global Folder/enemy_sprites.h"
#include "_Global Folder/player_struct_manager.h"
#include "_Global Folder/enemy_details.h"
#include "_Global Folder/more_prints.h"
#include "_Global Folder/weapon_details.h"

#include "Chapter 1/title.c"

#include "Chapter 2/character_creation.c"

#include "Chapter 3 Roundtable Hold/roundTable.c"
#include "Chapter 3 Roundtable Hold/inventory.c"
#include "Chapter 3 Roundtable Hold/shop.c"
#include "Chapter 3 Roundtable Hold/save.c"

#include "Chapter 4 Area/area.c"
#include "Chapter 4 Area/initializeAreaData.c"
#include "Chapter 4 Area/spawnTile.c"
#include "Chapter 4 Area/creditsTile.c"

#include "Chapter 5/enemy_battle.c"

int main(){
    system("cls"); // Remove this if error
    system("chcp 65001"); // Remove this if error
    system("cls"); // Remove this if error
    // printAllColours();
    runTitle();
    return 0;
}