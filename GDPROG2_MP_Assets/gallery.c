#include "stdio.h"
#include "assets.h"
#include "gallery.h"

void printOptions(char assCat[][51]){
    int i=0;

    printf("\n");
    printf("\tEnter the letter of the category you want to see\n");
    for (i=0;i<6;i++) printf("\t %c - %s\n", 'A'+i, assCat[i]);
    printf("\n\t'0' - Quit\n\n");
}

void welcomeText(){
    printf("\n");
    printf("\tWelcome to the assets gallery for our GDPROG2 MP\n");
    printf("\tUnicode taken from: https://symbl.cc/en/unicode-table/\n");
}

void processInput(char cInput){
    switch (cInput){
        case '0':
            break;
        case 'A':
        case 'a':
            runRoundtable();break;
        case 'f':
        case 'F':
            runMiscellaneous();
        default: printf(" huh? "); break;
    }
}

void runGallery(){
    char cInput=',';
    char assCat[10][51]={"ROUNDTABLE","HUD","SHOP","MAP","ENEMIES","MISCELLANEOUS"}; //Asset Catgories

    do{
    welcomeText();
    printOptions(assCat);
    printf("\t[Input] : ");
    scanf(" %c", &cInput);
    processInput(cInput);
    }while(cInput!='0');
}