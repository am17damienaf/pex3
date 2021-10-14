


#ifndef PEX3FUNCTS_H
#define PEX3FUNCTS_H

void clearGameBoard(char board[6][6]);

void computerTakeTurn(char board[6][6]);

void displayGameBoard(char board[6][6]);

int getIntRange(int lowVal, int highVal);

int getIntSafe();

bool legalPlay(char board[6][6], int column);

void placePiece(char board[6][6], char piece, int column);

void userTakeTurn(char board[6][6]);

int getWinner(char board[6][6]);

void testGetWinner();

#endif