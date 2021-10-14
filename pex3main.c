/*

Documentation statement: no help recieved, no outside sources used.

*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "pex3functs.h"

int main() {
    srand(time(0));

    //testGetWinner();
    // Test proved getWinner() successful

    char gameBoard[6][6];
    int totTurns = 0;
    int turn = 0;
    printf("Not Four!\n\n");
    clearGameBoard(gameBoard);
    displayGameBoard(gameBoard);
    while (getWinner(gameBoard) != 1 && getWinner(gameBoard) != 2 && totTurns < 36) {
        if (turn == 0) {
            userTakeTurn(gameBoard);
            turn = 1;
        } else {
            computerTakeTurn(gameBoard);
            turn = 0;
        }
    }
    switch (getWinner(gameBoard)) {
        case 0:
            printf("tie game.\n");
            break;
        case 1:
            printf("you win!]n");
            break;
        case 2:
            printf("you lose!\n");
            break;
    }

    return 0;
}