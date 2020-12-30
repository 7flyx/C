#pragma once
#define ROW 3
#define COL 3

#include <stdio.h>

void InitBoard(char board[ROW][COL], int row, int col);

void DisplayBoard(char board[ROW][COL], int row, int col);

void PlayerMove(char board[ROW][COL], int row, int col);

void ComputerMove(char board[ROW][COL], int row, int col);

//创建一个函数用于判断结局
//玩家赢了-----‘*’
//电脑赢了-----‘#’
//平局---------‘Q’
//继续走棋-----‘C’

char IsWin(char board[ROW][COL], int row, int col);