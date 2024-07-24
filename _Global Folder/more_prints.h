/*
THIS FILE WILL CONTAIN FUNCTIONS TO MAKE OUR PRINTING EASIER !!!
*/

// void cursorPos(int nXPos, int nYPos){ // THIS FUNCTION MOVES CURSOR
//     printf("\033[%d;%dH", nYPos, nXPos);
// }
// commented out, may not use bc glitchy

void printc(int colorBG, int colorFG, char* flavorText){
    printf("\033[1m\x1b[48;5;%dm\x1b[38;5;%dm%s\x1b[0m", colorBG, colorFG, flavorText);
}

void printRepeatedly(int nRepetition, char* flavorText){
    for (int nRepeat=0; nRepeat<nRepetition; nRepeat++){
        printf("%s", flavorText);
    }
}

// BORDERS IN PRINTING, USEFUL FOR PRETTIFYING THE PRINTING OF CHAPTERS
#define CHAPTER_1_BORDER_LENGTH 100
#define CHAPTER_1_CHOICE_BORDER_LENGTH 24


void printYBorder1(){
    for (int i = 0; i < CHAPTER_1_BORDER_LENGTH; i++){
        if (i == 0 || i == CHAPTER_1_BORDER_LENGTH - 1) printf("▩");
        else printf("═");
    }
    printf("\n");
}

void printMiddleBorder1(String strTextToPrint){
    printf("║");
    for (int i = 0; i < (CHAPTER_1_BORDER_LENGTH - strlen(strTextToPrint)) / 2 - 1; i++) printf(" ");
    printf("%s", strTextToPrint);
    for (int i = 0; i < (CHAPTER_1_BORDER_LENGTH - strlen(strTextToPrint)) / 2 - 1; i++) printf(" ");
    if (strlen(strTextToPrint) % 2 == 1) printf(" ");
    printf("║");
    printf("\n");
}

void printChoiceBorder1(String strTextToPrint){
    printf("║");
    for (int i = 0; i < (CHAPTER_1_BORDER_LENGTH - strlen(strTextToPrint)) / 2 - 1; i++) printf(" ");
    printf("%s", strTextToPrint);
    for (int i = 0; i < (CHAPTER_1_BORDER_LENGTH - strlen(strTextToPrint)) / 2 - 1; i++) printf(" ");
    if (strlen(strTextToPrint) % 2 == 1) printf(" ");
    printf("║");
    printf("\n");
}

void printChoiceBorderless1(String strTextToPrint){
    for (int i = 0; i < (CHAPTER_1_BORDER_LENGTH - strlen(strTextToPrint)) / 2 - 1; i++) printf(" ");
    printf("%s", strTextToPrint);
}