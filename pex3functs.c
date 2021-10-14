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
    while (board[column][row] != '.' && row > -1) {
        --row;
        board[row][column] = 'O';
    }
    printf("the computer chooses column: %d\n", column + 1);
    displayGameBoard(board);
}

void displayGameBoard(char board[6][6]) {
    printf("123456\n");
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    printf("123456\n");
}

int getIntRange(int lowVal, int highVal) {
    int uVal = 0;
    getIntSafe();
    while (uVal < lowVal && uVal > highVal) {
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
    column = getIntRange(1, 6) - 1;
    if (legalPlay(board, column)) {
        printf("User's choice: %d", column);
        placePiece(board, 'X', column);
    } else {
        printf("New put plz\n");
    }
}

int getWinner(char board[6][6]) {
    int numO;
    int numX;
    for (int i = 0; i < 6; ++i) {
        numO = 0;
        numX = 0;
        for (int j = 0; j < 6; ++j) {
            if (board[i][j] == 'O') {
                ++numO;
            } else if (board[i][j] == 'X') {
                ++numX;
            }
        }
        if (numO == 4) {
            return 2;
        } else if (numX == 4) {
            return 1;
        }
    }
    for (int i = 0; i < 6; ++i) {
        numO = 0;
        numX = 0;
        for (int j = 0; j < 6; ++j) {
            if (board[j][i] == 'O') {
                ++numO;
            } else if (board[j][i] == 'X') {
                ++numX;
            }
        }
        if (numO == 4) {
            return 2;
        } else if (numX == 4) {
            return 1;
        }
    }
    return 0;
}

void testGetWinner() {
    char testBoard1[6][6] = {
        { '.', '.', '.', '.', '.', '.',},
        { '.', '.', '.', '.', '.', '.',},
        { 'O', '.', '.', '.', '.', '.',},
        { 'O', '.', '.', '.', '.', '.',},
        { 'O', '.', '.', '.', '.', '.',},
        { 'O', '.', '.', '.', '.', '.',}};
    char testBoard2[6][6] = {
        { '.', '.', '.', '.', '.', '.',},
        { '.', '.', '.', '.', '.', '.',},
        { '.', '.', '.', '.', '.', '.',},
        { '.', '.', '.', '.', '.', '.',},
        { '.', '.', '.', '.', '.', '.',},
        { 'O', '.', 'O', '.', 'O', 'O',}};
    char testBoard3[6][6] = {
        { '.', '.', '.', '.', '.', '.',},
        { '.', '.', '.', '.', '.', '.',},
        { '.', '.', '.', 'X', '.', '.',},
        { '.', '.', '.', 'X', '.', '.',},
        { '.', '.', '.', 'X', '.', '.',},
        { '.', '.', '.', 'X', '.', '.',}};
    char testBoard4[6][6] = {
        { '.', '.', '.', '.', '.', '.',},
        { '.', '.', '.', '.', '.', '.',},
        { '.', '.', '.', '.', '.', '.',},
        { '.', '.', '.', '.', '.', '.',},
        { '.', '.', '.', '.', '.', '.',},
        { '.', 'X', 'X', 'X', '.', 'X',}};
    char testBoard5[6][6] = {
        { 'X', 'O', 'X', 'O', 'X', 'O',},
        { 'O', 'X', 'O', 'X', 'O', 'X',},
        { 'X', 'O', 'X', 'O', 'X', 'O',},
        { 'O', 'X', 'O', 'X', 'O', 'X',},
        { 'X', 'O', 'X', 'O', 'X', 'O',},
        { 'O', 'X', 'O', 'X', 'O', 'X',}};
    // -------------------
    if (getWinner(testBoard1) != 2)
        {printf("Error! Did not return expected results: 2\n");exit(1);}
    else
        {printf("Successful Test!\n");}
    // -------------------------------
    if (getWinner(testBoard2) != 2)
        {printf("Error! Did not return expected results: 2\n");exit(1);}
    else
        {printf("Successful Test!\n");}
    // -------------------------------
    if (getWinner(testBoard3) != 1)
        {printf("Error! Did not return expected results: 1\n");exit(1);}
    else
        {printf("Successful Test!\n");}
    // ---------------------------------
    if (getWinner(testBoard4) != 1)
        {printf("Error! Did not return expected results: 1\n");exit(1);}
    else
        {printf("Successful Test!\n");}
    // ----------------------------------
    if (getWinner(testBoard5) != 0)
        {printf("Error! Did not return expected results: 0\n");exit(1);}
    else
        {printf("Successful Test!\n");}
}