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
    int row = 5;
    do {
        column = rand() % 6;
    } while (board[0][column] != '.');
    do {
        if (board[row][column] == '.') {
            board[row][column] = 'O';
        }
        --row;
    } while (board[column][row] != '.' && row > -1);
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

int getIntSafe() {
    int value;
    int scanfReturn = 0;
    scanfReturn = scanf("%i", &value);
    fflush(stdin);
    if (scanfReturn != 1) {
        fprintf(stderr, "Bad integer input - terminating\n");
        exit(1);
    }
    return value;
}

bool legalPlay(char board[6][6], int column){
    if (board[0][column] != '.') {
        return false;
    } else {
        return true;
    }
}

void placePiece(char board[6][6], char piece, int column) {
    int row = 5;
    do {
        if (board[row][column] == '.') {
            board[row][column] = piece;
        }
        --row;
    } while (board[column][row] != '.' && row > -1);
    displayGameBoard(board);
}

void userTakeTurn(char board[6][6]) {
    int column = 0;
    printf("Where put?\n");
    scanf("%d", &column);
    if (legalPlay(board, column)) {
        printf("User's choice: %d", column);
        placePiece(board, 'X', column);
    } else {
        printf("New put plz\n");
    }
}

int getWinner(char board[6][6]) {
    int winner;
    if (winner == 2) {
        return 2;
    } else if (winner = 1) {
        return 1;
    } else {
        return 0;
    }
}