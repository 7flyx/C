#pragma once
#define ROW 9
#define COL 9

#define ROWS ROW + 2
#define COLS COL + 2

#define BOMB_NUM 10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Initboard(char show[ROWS][COLS], int rows, int cols,char set);
void PrintBoard(char mine[ROWS][COLS], int row, int col);
void SetBoard(char show[ROWS][COLS], int row, int col);
void PlayerBoard(char show[ROWS][COLS], char mine[ROWS][COLS], int rows, int cols);