#include "title.h"

void runTitle(){
    char cInput = ' ';
    do{
        displayTitle();
        processTitleInput(&cInput);
    } while (cInput != '0');
}

void displayTitle(){
    printf("\n");
    printf("\n");
    printf("\n");
    printf("Pretend this is the epic title!!!\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("[1] Start\n");
    printf("[2] Continue\n");
    printf("[0] Exit\n");
    printf("[INPUT] : ");
}

void processTitleInput(char* cInput){
    // printf("\033[?25h \033[6A \033[47C");
    scanf(" %c", cInput);
    // printf("\033[6B \033[47D");

    switch (*cInput)
    {
    case '1':
        printf("Game started!\n");
        runCharacterCreation();
        break;
    case '2':
        printf("Game continued!\n");
        break;
    case '0':
        printf("Game Exit!\n");
        exit(0);       
    default:
        break;
    }
}