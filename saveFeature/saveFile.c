#include "stdio.h"
#include "saveFile.h"
#include "conio.h"
#include "stdlib.h"
#include "testGame.h"

void recordGameState(){
    // I thought the player was allowed to save during a dungeon. I don't think it's allowed :(
    // L player (souls-like, rouge-like)
}

void appendSaveFile(){
    printf("\n");
    FILE *save;
    save = fopen("memoryCard/playerSaveFile.txt","a");
    int n=0;

    if(save==NULL){
        printf("\tNo such file exists...\n");
    } else{
        printf("\tFile found!\n");
    }
    
    for (int i=0; i<3; i++){
        fprintf(stdout, "Input an integer value: ");
        fscanf(stdin, "%d", &n);

        fprintf(save, "\n%d", n); // This does not print on terminal but instead the save file (save file being the destination of the print)
    }
    fclose(save);
}

void runWriteSaveFile(){
    printf("\n");
    FILE *save;
    save = fopen("memoryCard/playerSaveFile.txt","w"); // This automatically creates a file when run

    if (save==NULL){ printf("No such file exists. L Bozo\n");
    } else {
        printf("Text file found... YIPEE!\n");
    }

    char ch='A';
    int i=123;
    float f=3.21;
    double d=3.1415159;
    // fscanf(stdin, " %c", &ch); // Prints "Gamers" onto the pointer file path "save"
    // fscanf(stdin, "%d", &i);
    // fscanf(stdin, "%f", &f);
    // fscanf(stdin, "%lf", &d);
    fprintf(save, "%c\n", ch); // Prints "Gamers" onto the pointer file path "save"
    fprintf(save, "%d\n", i);
    fprintf(save, "%.2f\n", f);
    fprintf(save, "%lf\n", d);

    printf("\nEnter any key to continue\n> ");
    getch();

    fclose(save); // text file is updated when fclose is executed
    printf("\n");

}

void runReadSaveFile(){
    printf("\n");
    // char saveFileName[51];
    // printf("Name your save file: ");
    // scanf("%s", saveFileName); //Lmao, you gotta type the entire file path
    FILE *save; // Declare a pointer variable for file path.
    // save = fopen("PlayerSaveFile.txt", "r"); // fopen can only open 1 instance of a file
    save = fopen("memoryCard/playerSaveFile.txt", "r"); //When opening a .txt file from a directory, don't put the entire file path
    // C: /Folder/text.txt won't open, Folder/text.txt will open.

    // if ( (save = fopen(saveFileName, "r"))==NULL){ 
    //     printf("%s was not found. L Bozo\n", saveFileName);
    // } else {
    //     printf("%s was found... YIPEE!\n", saveFileName);
    // }

    // If "playerSaveFile.txt" is not in the same directory as the executable program, fopen will return NULL
    // Address of file is saved in the pointer *save

    if (save==NULL){ printf("No such file exists. L Bozo\n");
    } else {
        printf("Text file found... YIPEE!\n");
    }
    printf("\n");
    
    char ch=' ';
    int i=0;
    float f=0;
    double d=0;
    while((fscanf(save, " %c %i %f %lf", &ch, &i, &f, &d))==4){ // Brother does not read the escape character "\n"
        fprintf(stdout, "%c %i %.2f %lf\n", ch, i, f, d);
    }

    printf("\n> ");
    getch();

    fclose(save); // Eject the USB before you remove it from the machine. close all files before you terminate the program
    printf("\n");
}

void chadBinarySaveFile(){
    // Binary files are more efficient to store and read 
    // because it does not translate the information to characters
    // Since the MP only stores the state of the player (Stats, Shards, Runes, Unlocks [Levels/Dungeons])
    // , Txt is understandable and readable but binary is more scalable

    int i = 0;
    float f = 0.55;
    double dd = 3.1415159;
    char c ='Z';

    FILE *binarySaveFile; 

    binarySaveFile = fopen("memoryCard/binarySaveFile2", "wb");
    fwrite(&c, sizeof(char), 1, binarySaveFile); // (address of variable, number of bytes to ba allocated, how many of that datatype to be printed, name pointer variable)
    fwrite(&i, sizeof(int), 1, binarySaveFile);
    fwrite(&f, sizeof(float), 1, binarySaveFile);
    fwrite(&dd, sizeof(double), 1, binarySaveFile);
    fclose(binarySaveFile);

}

void dynamicArrayBinary(){
    int *intArray;
    int arraySize=0;

    // User dynamically inputs the size of the array
    printf("\tInput the number of elements in your array\n> ");
    scanf("%d", &arraySize);

    if ((intArray = malloc(sizeof(int)*arraySize))==NULL){
        fprintf(stderr, "ERROR not enough memory");
        exit(1);
    }

    // Initialize the array
    for (int i=0; i<arraySize; i++){
        *(intArray+i)=i;
    }

    //Write data to binary file
    FILE *binaryArray;
    binaryArray=fopen("memoryCard/binaryArraySaveFile","wb");
    fwrite(intArray, sizeof(int), arraySize, binaryArray);
    fclose(binaryArray);
    free(intArray);

}

void structBinaryFile(struct profileTag *player){
    FILE *meAmFilePointer;
   
    meAmFilePointer=fopen("memoryCard/playerProfileFile", "wb");
    fwrite(player, sizeof(struct profileTag), 1, meAmFilePointer);
    fclose(meAmFilePointer);
}

void readStructBinaryFile(){
    struct tempStatsTag{
        int maxHP;
        int hp;
        int mana;
        int runes;
        int shards;
    };

    struct tempProfileTag{
        char name[21];
        char class[21];
        int level;
        struct tempStatsTag stats;
    };

    FILE *temp;
    struct tempProfileTag preview;

    temp=fopen("memoryCard/playerProfileFile", "rb");
    fread(&preview, sizeof(struct tempProfileTag), 1, temp);
    fprintf(stdout, "%s  |   %s\n", preview.name, preview.class);
    fprintf(stdout, "LVL. %d\n", preview.level);
    fprintf(stdout, "Shards %d\n", preview.stats.shards);
    fprintf(stdout, "Runes %d\n", preview.stats.runes);
    printf("\n");
    printf("Enter any key to continue");
    getch();
    
    fclose(temp);

}