#include "title.h"

void runTitle(){
    char cInput = ' ';
    do{
        displayTitle();
        processTitleInput(&cInput);
    } while (cInput != '0');
}

void displayTitle(){
    printf("Pretend this is the epic title!!!\n");
    
    printf("[1] Start\n");
    printf("[2] Continue\n");
    printf("[0] Exit\n");
    printf("[INPUT] : ");
}

void processTitleInput(char* cInput){
    scanf(" %c", cInput);

    switch (*cInput)
    {
    case '1':
        printf("Game started!");
        runCharacterCreation();
        break;
    case '2':
        printf("Game continued!");
        break;
    case '0':
        printf("Game Exit!");
        exit(0);       
    default:
        break;
    }
}