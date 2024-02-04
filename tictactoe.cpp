/*
Simple TicTacToe game written in C++ designed to be played in the console. 
Two players can play (x and o). Player x always starts. 
You place your symbol anywhere in a 3*3 grid that starts with 1 and ends with 9:

1 2 3
4 5 6
7 8 9

TicTacToe rules: https://www.exploratorium.edu/explore/puzzles/tictactoe

How to play
1) Download the files
2) Open Windows Powershell
3) Follow this guide: https://www.wikihow.com/Powershell-How-to-Run-Exe

Have fun playing!
--Jakob Seidl, Creator
*/

#include <stdio.h>
#include <stdlib.h>

int checkWin(int gameBoard[]);
int getPlayerLocation(int gameBoard[], int player);
int checkDraw(int gameBoard[]);
void printGameboard(int gameBoard[]);

int main() {
    int win = 0;
    int player = 1;
    int gameBoard[9] = {0};  

    //Print the gameboard
    printGameboard(gameBoard);

    while (win == 0) {
        //Get where playerLocation is
        int playerLocation = getPlayerLocation(gameBoard, player);
        gameBoard[playerLocation] = player;

        //Check for win 
        int win = checkWin(gameBoard);
        if (win) {
            printGameboard(gameBoard);
            printf("Player %d won", player);
            return 0;
        }

    	//Check for draw
        int draw = checkDraw(gameBoard);
        if (draw) {
            printGameboard(gameBoard);
            printf("Draw");
            return 0;
        }

        //Change player
        if (player == 1) 
            player = 2;
        else 
            player = 1;

        //Printgameboard
        printGameboard(gameBoard);
    }
    return 0;
}

int checkDraw(int gameBoard[]) {
    //By default, there is a draw
    int draw = 1;

    //If some spot isn't occupied, there is no draw    
    for(int i = 0; i <= 8; i++) {
        if(gameBoard[i] == 0) {
            draw = 0;
        }
    }

    if (draw) {
        return 1;
    } else {
        return 0;
    }

    return 0;    
}

void printGameboard(int gameBoard[]) {
    //Print x, o or - depending on who occupies the square 
    //"-" means the square isn't occupied
    for(int i = 0; i <= 8; i++) {
        if(gameBoard[i] == 1) {
            printf("x");
        } else if(gameBoard[i] == 2) {
            printf("o");
        } else {
            printf("-");
        }
        
        //If we are at index 2, 5 or 8, we want to print a new line to make the game appear as a 3*3 grid.
        if(i%3 == 2) 
            printf("\n");
    }
}

int getPlayerLocation(int gameBoard[], int player) {
    int playerLocation;

    do { 
        printf("Enter your spot to place player %d: ", player);
        scanf("%d", &playerLocation);
        --playerLocation;
    } while(gameBoard[playerLocation] != 0);

    return playerLocation;
}

//Every single way to win
int checkWin(int gameBoard[]) {
    if(gameBoard[0] == gameBoard[1] && gameBoard[0] == gameBoard[2]) {
        return gameBoard[0];
    } 
    if(gameBoard[3] == gameBoard[4] && gameBoard[3] == gameBoard[5]) {
        return gameBoard[3];
    } 
    if(gameBoard[6] == gameBoard[7] && gameBoard[6] == gameBoard[8]) {
        return gameBoard[6];
    } 
    if(gameBoard[0] == gameBoard[3] && gameBoard[0] == gameBoard[6]) {
        return gameBoard[0];
    } 
    if(gameBoard[1] == gameBoard[4] && gameBoard[1] == gameBoard[7]) {
        return gameBoard[1];
    } 
    if(gameBoard[2] == gameBoard[5] && gameBoard[2] == gameBoard[8]) {
        return gameBoard[2];
    } 
    if(gameBoard[0] == gameBoard[4] && gameBoard[0] == gameBoard[8]) {
        return gameBoard[0];
    } 
    if(gameBoard[6] == gameBoard[4] && gameBoard[6] == gameBoard[2]) {
        return gameBoard[6];
    } 
    return 0;
}