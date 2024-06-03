#include "stdio.h"
#include "dungeon.h"
#include "conio.h"
#include "windows.h"

void renderDungeon(int* map, int* dungeonDimension, int playerPosX, int playerPosY){
    int row=0, col=0, element=0;
    // printf("\t╭");
    // for (row=0;row<dungeonDimension[0];row++) printf("╌╌╌");
    // printf("╮\n");
    // for (element=0; element<(dungeonDimension[0]*dungeonDimension[1]); element++){
    //     if (element%dungeonDimension[0]==0) printf("\t╎");
    //     if (element/dungeonDimension[1]==playerPosY&&element%dungeonDimension[0]==playerPosX){ printf(" 🗡");
    //     } else{
    //         switch (*(map+element)){
    //             case 2:
    //                 printf(" ▩ "); break;
    //             case 5:
    //                 printf(" ☠︎︎ "); break;
    //             default:
    //                 printf("   "); break;
    //         }
    //     }
    //     if (element%dungeonDimension[0]==dungeonDimension[0]-1) printf("╎\n");
    // }
    // printf("\t╰");
    // for (row=0;row<dungeonDimension[0];row++) printf("╌╌╌");
    // printf("╯\n");

    printf("\t╭");
    for (row=0;row<(dungeonDimension[0]*2)-1;row++) printf("╌");
    printf("╮\n");
    for (row=0; row<dungeonDimension[0]; row++){
        printf("\t╎");
        for(col=0; col<dungeonDimension[1]; col++){
            if (row==playerPosY&&col==playerPosX){ 
                printf(" 🗡");
            } else{
                switch (*(map+(row*dungeonDimension[1])+col)){
                    case 2:
                        printf(" ▩ "); break;
                    case 5:
                        printf(" ☠︎︎ "); break;
                    default:
                        printf("   "); break;
                }
            }
        }
        printf("╎\n");
    }
    printf("\t╰");
    for (row=0;row<(dungeonDimension[0]*2)-1;row++) printf("╌");
    printf("╯\n");

    // printf("\t╭───╮\n");
    // printf("\t|   |\n");
    // printf("\t╰───╯\n");
    // printf("\t┏┈┈┈┓\n");
    // printf("\t┊   ┊\n");
    // printf("\t┗┈┈┈┛\n");
    // printf("\t╭┈┈┈╮\n");
    // printf("\t┊   ┊\n");
    // printf("\t╰┈┈┈╯\n");
    // printf("\t┏╌╌╌┓\n");
    // printf("\t╎   ╎\n");
    // printf("\t┗╌╌╌┛\n");
    // printf("\t╭╌╌╌╮\n"); 
    // printf("\t╎   ╎\n"); // 0 Empty tile
    // printf("\t╰╌╌╌╯\n");
    // printf("\t╭───────────────╮\n");
    // printf("\t|               |\n");
    // printf("\t|               |\n");
    // printf("\t|               |\n");
    // printf("\t|               |\n");
    // printf("\t╰───────────────╯\n");
    // printf("\t Amongus 𐚑\n");
    // printf("\tEnter your name 🖎 🖌\n");
    // printf("\tAstrologer ⚝\n");
    // printf("\tVagabond 🗡\n");
    // printf("\tSamurai 侍\n");
    // printf("\tWarrior ✟\n");
    // printf("\tHero ♞\n");
    // printf("\tProphhet 👁\n");
}

void processInput(char cInput, int* playerPosX, int* playerPosY, int* dungeonDimension, int* map){
    switch (cInput){
        case 'a':
        case 'A':
            if (*playerPosX>0&&(*(map+((*playerPosY)*dungeonDimension[1])+(*playerPosX)-1))!=2) (*playerPosX)--; 
            break;
        case 'd':
        case 'D':
            if (*playerPosX<dungeonDimension[1]-1&&(*(map+((*playerPosY)*dungeonDimension[1])+(*playerPosX)+1))!=2) (*playerPosX)++; 
            break;
        case 'w':
        case 'W':
            if (*playerPosY>0&&(*(map+(((*playerPosY)-1)*dungeonDimension[1])+(*playerPosX)))!=2) (*playerPosY)--; 
            break;
        case 's':
        case 'S':
            if (*playerPosY<dungeonDimension[0]-1&&(*(map+(((*playerPosY)+1)*dungeonDimension[1])+(*playerPosX)))!=2) (*playerPosY)++; 
            break;
    }
}

void runDungeon(){
    /*
    0 Empty tile
    1 Player
    2 Out of Bounds/Wall
    3 Fast Travel
    4 Door tile
    5 Spawn/Encounter tile
    6 Boss tile
    */
   
    int courtyard[15][15]={ // Leyndell Royal Capital, Level 0
        {5,0,0,5,0,0,0,0,0,0,2,2,2,2,2},
        {0,0,0,5,0,0,0,0,0,0,2,2,2,2,2},
        {5,0,2,2,2,2,2,2,2,2,2,2,2,2,2},
        {0,0,2,2,2,2,2,2,2,2,2,2,2,2,2},
        {5,0,2,2,2,2,2,2,2,2,2,2,2,2,2},
        {0,0,2,2,2,2,2,2,2,2,2,2,2,2,2},
        {5,0,2,2,2,2,2,2,2,2,2,2,2,2,2},
        {0,0,2,2,2,2,2,2,2,2,2,2,2,2,2},
        {5,0,2,2,2,2,2,2,2,2,2,2,2,2,2},
        {0,0,2,2,2,2,2,2,2,2,2,2,2,2,2},
        {5,0,2,2,2,2,2,2,2,2,2,2,2,0,5},
        {0,0,2,2,2,2,2,2,2,2,2,2,2,0,0},
        {5,0,2,2,2,2,2,2,2,2,2,2,2,0,5},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {5,0,0,0,0,5,0,5,0,0,0,0,0,0,5}
    };

    int hall[8][5]={
        {2,0,0,0,2},
        {0,0,0,0,0},
        {0,5,0,5,0},
        {0,2,2,2,0},
        {0,2,2,2,0},
        {0,5,0,5,0},
        {0,0,0,0,0},
        {2,0,0,0,2},
    };

    char cInput=',';
    int playerPosX=2, playerPosY=0;
    int dungeonDimension[2]={0,0};
    dungeonDimension[1]=sizeof(hall[0])/sizeof(hall[0][0]); // Gets X or how many columns (number of elements in first array)
    dungeonDimension[0]=sizeof(hall)/sizeof(hall[0]); // Gets Y or how many rows (number of arrays in map array)
    // AGHHG! XYRowCOL really confuses me
    
    do{
        // printf(" X %d ; Y %d\n", dungeonDimension[0], dungeonDimension[1]);
        printf("rows %d ; columns %d", dungeonDimension[1], dungeonDimension[0]);
        renderDungeon(*hall, dungeonDimension, playerPosX, playerPosY);
        cInput=getch();
        processInput(cInput, &playerPosX, &playerPosY, dungeonDimension, *hall);
        system("CLS");
    }while(cInput!='0');

}