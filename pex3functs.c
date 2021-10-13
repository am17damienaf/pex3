// Pex 3 functions
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "pex3functs.h"

void clearGameBoard(char board[6][6]){
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            board[i][j] = '.';
        }
    }
}

void computerTakeTurn(char board[6][6]);

void displayGameBoard(char board[6][6]);

int getIntRange(int lowVal, int highVal);

int getIntSafe();

bool legalPlay(char board[6][6], int column);

void placePiece(char board[6][6], char piece, int column);

void userTakeTurn(char board[6][6]);

int getWinner(char board[6][6]);