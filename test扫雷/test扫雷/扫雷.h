#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 11
#define COLS 11
#define ROW 9
#define COL 9
#define Esay_count 10

void Initboard(char board[ROWS][COLS], int rows, int cols, char set);
void displayboard(char board[ROWS][COLS], int row, int col);
void Setmine(char mine[ROWS][COLS], int row, int col);
//void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

