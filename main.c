#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "_Global Folder/gen_struct_manager.h"
#include "_Global Folder/player_struct_manager.h"
#include "_Global Folder/color.c"

#include "Chapter 1/title.c"

#include "Chapter 2/job_class.c"
#include "Chapter 2/character_creation.c"

#include "Chapter 3 Roundtable Hold/roundTable.c"
#include "Chapter 3 Roundtable Hold/inventory.c"
#include "Chapter 3 Roundtable Hold/shop.c"
#include "Chapter 3 Roundtable Hold/save.c"

#include "Chapter 4 Area/areaStructures.h"
#include "Chapter 4 Area/area.c"
#include "Chapter 4 Area/initializeAreaData.c"
#include "Chapter 4 Area/spawnTile.c"

int main(){
    runTitle();
    return 0;
}