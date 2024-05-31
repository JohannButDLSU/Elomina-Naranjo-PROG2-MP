#include "stdio.h"
#include "conio.h" // Confirm if miss will allow this library
#include "windows.h" // Needed for function, system("CLS"). This might not work on Linux or Mac
// #include "stdlib.h"
// #include "string.h"

void runUserInput(){
    char name[16]="               "; // There are spaces in the array to make the format pretty later on
    int nameSize=(sizeof(name)/sizeof(name[0]))-1; // Gets the size of char array name[]
    system("CLS"); // Clears the screen

    // Attempting to move the cursor to the middle of the box above (FAIL)
    // COORD c;
    // c.X = 40;
    // c.Y = 16;
    // SetConsoleCursorPosition(
    //     GetStdHandle(STD_OUTPUT_HANDLE), c);

    char enter='f'; // F is for false to enter the while loop
    int i=0; // counter var
    char userInput=' '; // Initialized with a value to avoid garbage value as per standard
    while (enter=='f'){
        printf("\n\n");
        printf("\tSize of array name[]= %d\n", nameSize);
        printf("\t++--------------------------------------++\n");
        printf("\t++--------------------------------------++\n");
        printf("\t||\t                               \t||\n");
        printf("\t||\tInput Name : %s\t||\n", name); // Prints the name as it is being typed by user
        printf("\t||\t                               \t||\n");
        printf("\t++--------------------------------------++\n");
        printf("\t++--------------------------------------++\n\n\t");
        userInput=getch();  // Retrieves a SINGLE char the user inputs without needing to press 'Enter'.
                            // It does not display on the terminal what the user inputs

        switch (userInput){
            case '\r': // \r and \n are the characters mapped to the Enter key
            case '\n':
                enter='t'; break; // Once the enter key is pressed, exits the loop
            case '\b': // \b is the character mapped to backspace
                if (i>0){ //Checks if (i)ndex is currently at the first index of the char array name[]. You can't erase any more if name is empty
                    i--; 
                    name[i]=' ';
                    system("CLS"); // System clears to make it seem as though the user is typing within the box
                }; break;
            default:
                if (i<nameSize){ // Check if (i)ndex is at the last index of char array. You can't type anymore past the max characters.
                    name[i]=userInput;
                    i++;
                };
                system("CLS");break; // System clears to make it seem as though the user is typing within the box

        }

    };

    printf("Welcome, %s, to Elden Rogue! :) \n\n", name);
    printf("\tPress any key to continue to main menu... ");
    getch(); // Awaits for key input before exiting runUserInput()
    system("CLS");

    /*Issues to fix:
    1. How to fix the print of name so that the box wall is not affected by user input
    2. The cursor is seen in the terminal below the box :( 
    */

}