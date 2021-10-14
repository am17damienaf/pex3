// Pex 3 functions
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "pex3functs.h"

void clearGameBoard(char board[6][6]){
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            board[i][j] = '.';
        }
    }
}

void computerTakeTurn(char board[6][6]) {
    int column = 0;
    int row = 0;
    do {
        column = rand() % 6;
    } while (board[column][5] != '.');
    do {
        if (board[column][row] == '.') {
            board[column][row] = 'O';
        }
        ++row;
    } while (board[column][row] != '.' && row < 6);
    printf("the computer chooses column: %d\n", column);
    displayGameBoard(board);
}

void displayGameBoard(char board[6][6]) {
    printf("123456");
    for (int i = 0; i < 6; ++i) {
        printf(board[i]);
    }
    printf("123456");
}

int getIntRange(int lowVal, int highVal) {
    int lowVal = 0;
    int highVal = 0;
    int uVal = 0;
    scanf("%d", &uVal);
    while (uVal <= lowVal && uVal >= highVal) {
        printf("%d is not valid; enter a value between %d and %d: ", uVal, lowVal, highVal);
        scanf("%d", &uVal);
    }
    return uVal;
}

int getIntSafe();

bool legalPlay(char board[6][6], int column);

void placePiece(char board[6][6], char piece, int column);

void userTakeTurn(char board[6][6]);

int getWinner(char board[6][6]);