/*
=================================================================
THIS FILE WILL CONTAIN FUNCTIONS TO MAKE OUR PRINTING EASIER !!!
=================================================================
*/

// THE GUIDE TO COLOURS - replace
// BG \033[1m\x1b[48;5;XXXm
// FG \x1b[38;5;XXXm

// void cursorPos(int nXPos, int nYPos){ // THIS FUNCTION MOVES CURSOR
//     printf("\033[%d;%dH", nYPos, nXPos);
// }
// commented out, may not use bc glitchy
void printc(int nColorBG, int nColorFG, char* pFlavorText){
    printf("\033[1m\x1b[48;5;%dm\x1b[38;5;%dm%s\x1b[0m", nColorBG, nColorFG, pFlavorText);
}

void printRepeatedly(int nRepetition, char* flavorText){
    for (int nRepeat=0; nRepeat<nRepetition; nRepeat++){
        printf("%s", flavorText);
    }
}

void printAllColours(){
    for (int i = 0; i < 256; i++){
        printc(i, 0, "looks like dis                                                                            yep");
        printf("code: %d\n", i);
    }
}

void printCentered(String strTextToPrint, int nLength){
    for (int i = 0; i < (nLength - strlen(strTextToPrint)) / 2 - 1; i++) printf(" ");
    printf("%s", strTextToPrint);
    printf("\n");
}

void printcCentered(int nColorBG, int ncColorFG, String strTextToPrint, int nLength){
    for (int i = 0; i < (nLength - strlen(strTextToPrint)) / 2 - 1; i++) printf(" ");
    printc(nColorBG, ncColorFG, strTextToPrint);
    printf("\n");
}

// BORDERS IN PRINTING, USEFUL FOR PRETTIFYING THE PRINTING OF CHAPTERS
#define BORDER_1_LENGTH 120
#define BORDER_2_LENGTH 70
#define BORDER_PLAYER_SPRITE_LENGTH 34 // 32 for sprite + 2 for borders


void printYBorder1(int colorBG, int colorFG){
    for (int i = 0; i < BORDER_1_LENGTH; i++){
        if (i == 0 || i == BORDER_1_LENGTH - 1) printc(colorBG, colorFG, "▩");
        else printc(colorBG, colorFG, "═");
    }
    printf("\n");
}

void printMiddleBorder1(int colorBG, int colorFG, String strTextToPrint){
    printf("║");
    for (int i = 0; i < (BORDER_1_LENGTH - strlen(strTextToPrint)) / 2 - 1; i++) printf(" ");
    printc(colorBG, colorFG, strTextToPrint);
    for (int i = 0; i < (BORDER_1_LENGTH - strlen(strTextToPrint)) / 2 - 1; i++) printf(" ");
    if (strlen(strTextToPrint) % 2 == 1) printf(" ");
    printf("║");
    printf("\n");
}

void printChoiceBorder1(int colorBG, int colorFG, String strTextToPrint, int nPadding){
    for (int i = 0; i < (BORDER_1_LENGTH - strlen(strTextToPrint)) / 2 - 5 - nPadding; i++) printf(" ");
    printc(colorBG, colorFG, "-=+║O");
    for (int i = 0; i < nPadding; i++) printf(" ");
    printf("%s", COLORSTOP);
    printf("%s", strTextToPrint);
    printf("%s", COLORSTOP);
    if (strlen(strTextToPrint) % 2 == 1) printf(" ");
    for (int i = 0; i < nPadding; i++) printf(" ");
    printc(colorBG, colorFG, "O║+=-");
    for (int i = 0; i < (BORDER_1_LENGTH - strlen(strTextToPrint)) / 2 - 5 - nPadding; i++) printf(" ");
    printf("\n");
}

void printChoiceBorderless1(String strTextToPrint){
    for (int i = 0; i < (BORDER_1_LENGTH - strlen(strTextToPrint)) / 2 - 1; i++) printf(" ");
    printf("%s", strTextToPrint);
}

void printYBorder2(int colorBG, int colorFG){
    for (int i = 0; i < BORDER_2_LENGTH; i++){
        if (i == 0 || i == BORDER_2_LENGTH - 1) printf("▩");
        else printf("═");
    }
    // printf("\n");
}

void printMiddleBorder2(int colorBG, int colorFG, String strTextToPrint){
    printf("║");
    for (int i = 0; i < (BORDER_2_LENGTH - strlen(strTextToPrint)) / 2 - 1; i++) printf(" ");
    printc(colorBG, colorFG, strTextToPrint);
    for (int i = 0; i < (BORDER_2_LENGTH - strlen(strTextToPrint)) / 2 - 1; i++) printf(" ");
    if (strlen(strTextToPrint) % 2 == 1) printf(" ");
    printf("║");
    // printf("\n");
}

void printWintMiddleBorder2(int colorBG, int colorFG, String strTextToPrint, int nInt){

    int nExtraPadding;
    if (nInt < 10) nExtraPadding = 1;
    else if (nInt < 100) nExtraPadding = 2;
    else nExtraPadding = 3;

    printf("║");

    for (int i = 0; i < (BORDER_2_LENGTH - strlen(strTextToPrint)) / 2 - 2; i++) printf(" ");
    printc(colorBG, colorFG, strTextToPrint); printf("%d", nInt);
    for (int i = 0; i < (BORDER_2_LENGTH - strlen(strTextToPrint)) / 2 - nExtraPadding; i++) printf(" ");

    if (strlen(strTextToPrint) % 2 == 1) printf(" ");

    printf("║");
    // printf("\n");
}

void printChoiceBorder2(int colorBG, int colorFG, String strTextToPrint, int nPadding){
    for (int i = 0; i < (BORDER_2_LENGTH - strlen(strTextToPrint)) / 2 - 5 - nPadding; i++) printf(" ");
    printc(colorBG, colorFG, "-=+║O");
    for (int i = 0; i < nPadding; i++) printf(" ");
    printf("%s", COLORSTOP);
    printf("%s", strTextToPrint);
    printf("%s", COLORSTOP);
    if (strlen(strTextToPrint) % 2 == 1) printf(" ");
    for (int i = 0; i < nPadding; i++) printf(" ");
    printc(colorBG, colorFG, "O║+=-");
    for (int i = 0; i < (BORDER_2_LENGTH - strlen(strTextToPrint)) / 2 - 5 - nPadding; i++) printf(" ");
    printf("\n");
}

void printChoiceBorderless2(String strTextToPrint){
    printf("\n");
    for (int i = 0; i < (BORDER_2_LENGTH - strlen(strTextToPrint)) / 2 - 1; i++) printf(" ");
    printf("%s", strTextToPrint);
}

void printYBorderPlayer(){
    for (int i = 0; i < BORDER_PLAYER_SPRITE_LENGTH; i++){
        if (i == 0 || i == BORDER_PLAYER_SPRITE_LENGTH - 1) printf("▩");
        else printf("═");
    }
    printf("\n");
}

void printMiddleBorderPlayer(Player player, int nRow){
    printf("║");

    if (!strcmp(player.strJobClass, "Vagabond")) printf("%s", VAGABOND_ROWS[nRow]);
    if (!strcmp(player.strJobClass, "Samurai")) printf("%s", SAMURAI_ROWS[nRow]);
    if (!strcmp(player.strJobClass, "Warrior")) printf("%s", WARRIOR_ROWS[nRow]);
    if (!strcmp(player.strJobClass, "Hero")) printf("%s", HERO_ROWS[nRow]);
    if (!strcmp(player.strJobClass, "Astrologer")) printf("%s", ASTROLOGER_ROWS[nRow]);
    if (!strcmp(player.strJobClass, "Prophet")) printf("%s", PROPHET_ROWS[nRow]);

    printf("║\n");
}