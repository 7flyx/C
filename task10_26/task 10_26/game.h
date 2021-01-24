#pragma once
#define ROW 3
#define COL 3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//函数的声明
void InitBoard(char board[ROW][COL], int row, int col);

void DisplayBoard(char board[ROW][COL], int row, int col);

void PlayerMove(char board[ROW][COL], int row, int col);

void CompterMove(char board[ROW][COL], int row, int col);

//iswin 函返回四种状态
//玩家赢了-'*'
//电脑赢了-'#'
//平局----'Q'
//继续----‘C’
char iswin(char board[ROW][COL], int row, int col);
