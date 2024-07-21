#include "color.h"

void printc(int colorBG, int colorFG, char* flavorText){
    printf("\033[1m\x1b[48;5;%dm\x1b[38;5;%dm%s\x1b[0m", colorBG, colorFG, flavorText);
}

void printRepeatedly(int nRepetition, char* flavorText){
    for (int nRepeat=0; nRepeat<nRepetition; nRepeat++){
        printf("%s", flavorText);
    }
}