#include "stdio.h"
#include "dungeon.h"
#include "conio.h"
#include "windows.h"

void renderDungeon(int* map, int* dungeonDimension, int playerPosX, int playerPosY){
    int row=0, col=0;
    printf("\t╭");
    for (row=0;row<dungeonDimension[1];row++) printf("╌╌╌");
    printf("╮\n");
    for (row=0; row<dungeonDimension[1]; row++){
        printf("\t╎");
        for(col=0; col<dungeonDimension[0]; col++){
            if (row==playerPosY&&col==playerPosX){ 
                printf(" 🗡");
            } else{
                switch (*(map+(row*dungeonDimension[0])+col)){
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
    for (row=0;row<dungeonDimension[1];row++) printf("╌╌╌");
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
            if (*playerPosX>0&&(*(map+((*playerPosY)*dungeonDimension[0])+(*playerPosX)-1))!=2) (*playerPosX)--; 
            break;
        case 'd':
        case 'D':
            if (*playerPosX<dungeonDimension[0]-1&&(*(map+((*playerPosY)*dungeonDimension[0])+(*playerPosX)+1))!=2) (*playerPosX)++; 
            break;
        case 'w':
        case 'W':
            if (*playerPosY>0&&(*(map+(((*playerPosY)-1)*dungeonDimension[1])+(*playerPosX)))!=2) (*playerPosY)--; 
            break;
        case 's':
        case 'S':
            if (*playerPosY<dungeonDimension[1]-1&&(*(map+(((*playerPosY)+1)*dungeonDimension[1])+(*playerPosX)))!=2) (*playerPosY)++; 
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
    char cInput=',';
    int playerPosX=6, playerPosY=14;
    int dungeonDimension[2]={0,0};
    dungeonDimension[0]=sizeof(courtyard[0])/sizeof(courtyard[0][0]); // Gets X or how many columns (number of elements in first array)
    dungeonDimension[1]=sizeof(courtyard)/sizeof(courtyard[0]); // Gets Y or how many rows (number of arrays in map array)
    
    do{
        // printf(" X %d ; Y %d\n", dungeonDimension[0], dungeonDimension[1]);
        renderDungeon(*courtyard, dungeonDimension, playerPosX, playerPosY);
        cInput=getch();
        processInput(cInput, &playerPosX, &playerPosY, dungeonDimension, *courtyard);
        system("CLS");
    }while(cInput!='0');

}