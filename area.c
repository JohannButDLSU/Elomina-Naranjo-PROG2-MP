#include "stdio.h"
#include "inventory.h"
#include "encounter.h"
#include "gameOver.h"

void displayElements(int* playerPos, int* board, int boardSize){
	int i=0;
	int map[10];
	for (i=0;i<boardSize;i++){
		if (playerPos[i]==1) map[i]=playerPos[i];
		else map[i]=board[i];
	}
	for (i=0;i<boardSize;i++){
		switch (map[i]){
			case 1: printf("\t╔═══╗"); break;
			case 2: printf("\t┌┬┬┬┐"); break;
			default: printf("\t┌───┐"); break;
		}
		};
	printf("\n");
	for (i=0;i<boardSize;i++){
		switch (map[i]){
			case 1: printf("\t║ ■ ║"); break;
			case 2: printf("\t│││││"); break;
			default: printf("\t│   │");break;
		}
		};
	printf("\n");
		for (i=0;i<boardSize;i++){
			switch (map[i]){
			case 1: printf("\t╚═══╝"); break;
			case 2: printf("\t└┴┴┴┘"); break;
			default: printf("\t└───┘");break;
		}
		};
	printf("\n");
}

void displayPlayerHP(int playerHP, int playerMaxHP){
	int i=0;
	for (i=0; i<playerMaxHP; i++){
		if (playerHP>0) printf("♥ ");
		else printf("♡ ");
		playerHP--;
	}
	printf("\n");
}
void displayAreaArray(int playerHP, int playerMaxHP, int* playerPos, int* board, int boardSize){ //It is compressed into a pointer, when an array is passed through a function.
	printf("\n");
	printf("\t╔════════════════════╗\n");
	printf("\t|        AREA        │\n");
	printf("\t╚════════════════════╝\n");
	printf("\t[PLAYER] : ");
	displayPlayerHP(playerHP, playerMaxHP);
	printf("\n"); //Alt+shift+downarrowkey to duplicate line (COOL!)
	displayElements(playerPos, board, boardSize);
	printf("\t[INPUT] : ");
}

void processInput(int* playerHP, int* board, int inventorySize, int* inventory, char cInput, int* playerPosX, int* playerPos, int boardSize){
    switch (cInput){
		case 'e':
		case 'E':
			if (board[*playerPosX]==2) runEncounter(playerHP, inventorySize, inventory); 
			break;
		case 'i':
		case 'I':
			runInventory(inventory, inventorySize); break;
		case 'a':
		case 'A':
			if (playerPos[0]!=1){ 
				playerPos[*playerPosX]=0;
				(*playerPosX)--;
			};
			break;
		case 'd':
		case 'D':
			if (playerPos[boardSize-1]!=1){ 
				playerPos[*playerPosX]=0;
				(*playerPosX)++;
			};
			break;
		default: break;
	}
    playerPos[*playerPosX]=1;
}

void runArea(){
	char cInput=',';
	int playerPosX=0;
	int playerPos[7]={1,0,0,0,0,0,0};
    int board[7]={0,0,0,2,0,2,0}; //Number determines the size of the board
    int boardSize=(int)(sizeof(board)/sizeof(int));
	int inventory[6]={0,0,0,0,0,0};
	int inventorySize=(int)(sizeof(inventory)/sizeof(int));
	int playerHP=3, playerMaxHP=3;

	//sizeof variantx
	// (int)(sizeof(board)/sizeof(int)) = *(&board + 1)-board;

	do{
	displayAreaArray(playerHP, playerMaxHP, playerPos, board, boardSize);
	scanf(" %c", &cInput);
	processInput(&playerHP, board, inventorySize, inventory, cInput, &playerPosX, playerPos, boardSize);
	}while(cInput!='0'&&playerHP>0);
	if (playerHP<=0) runGameOver();
}