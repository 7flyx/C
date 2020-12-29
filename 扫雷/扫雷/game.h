#pragma once

#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define ROW 9
#define COL 9
#define ROWS ROW + 2
#define COLS COL + 2
#define MAX_set 10


void Initboard(char board[ROWS][COLS], int rows, int cols, char set);
void Printboard(char board[ROWS][COLS], int rows, int cols);
void Setboard(char board[ROWS][COLS], int row, int col);
void Playerboard(char mine[ROWS][COLS], char show[ROWS][COLS], int rows, int cols);
int Check_board(char show[ROWS][COLS], int row, int col);