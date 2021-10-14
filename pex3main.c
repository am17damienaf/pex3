
#include "pex3functs.h"


int main() {
    srand(time(0));

    //test
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
    
    if (getWinner(testBoard1) != 2) {
        printf("Error! Did not return expected results: 2");
    }
    if (getWinner(testBoard2) != 2) {
        printf("Error! Did not return expected results: 2");
    }
    if (getWinner(testBoard3) != 1) {
        printf("Error! Did not return expected results: 1");
    }
    if (getWinner(testBoard4) != 1) {
        printf("Error! Did not return expected results: 1");
    }
    if (getWinner(testBoard5) != 0) {
        printf("Error! Did not return expected results: 0");
    }


    //char gameBoard[6][6];

    printf("Not Four!\n\n");
    //clearGameBoard(gameBoard);

    return 0;
}