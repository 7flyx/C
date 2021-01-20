#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3


void chessboard1(char board[ROW][COL], int row, int col);

void chessboard2(char board[ROW][COL], int row, int col);

void PlayerMove(char board[ROW][COL], int row, int col);

void DisPlayMove(char board[ROW][COL], int row, int col);

char iswin(char board[ROW][COL], int row, int col);