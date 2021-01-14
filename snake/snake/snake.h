#pragma once

//头文件
#include <iostream>
#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>



#define MAX_WIDTH 640  //图形窗口的长宽
#define MAX_HEIGHT 480
#define MAX_SNAKE 100  //蛇的最大长度


//函数的声明
void GameInit();
void GameDraw();
void Snakemove();
void KeyControl();
void EatFood();
int Is_win();


enum Snake_dirction  //蛇的方向
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

//蛇的结构体
struct Snake_tlg
{
	int num;  //表示蛇的长度
	int dir;  // 表示蛇的方向
	int score;  //表示获得的分数
	int size;
	POINT coor[MAX_SNAKE];
	/*
	typedef struct tagPOINT
{
    LONG  x;
    LONG  y;
} POINT;
	*/  
	//实则point就是代表横纵坐标的，这里用数组去创建
};


//食物的结构体
struct Food_tlg
{
	//坐标以及标志--标志用于判断食物是否被吃了，如果被吃， 需要重新产生食物
	POINT xy; //食物的坐标
	int flag;  //标志
	int color;  //食物的颜色
};