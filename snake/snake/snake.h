#pragma once

//ͷ�ļ�
#include <iostream>
#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>



#define MAX_WIDTH 640  //ͼ�δ��ڵĳ���
#define MAX_HEIGHT 480
#define MAX_SNAKE 100  //�ߵ���󳤶�


//����������
void GameInit();
void GameDraw();
void Snakemove();
void KeyControl();
void EatFood();
int Is_win();


enum Snake_dirction  //�ߵķ���
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

//�ߵĽṹ��
struct Snake_tlg
{
	int num;  //��ʾ�ߵĳ���
	int dir;  // ��ʾ�ߵķ���
	int score;  //��ʾ��õķ���
	int size;
	POINT coor[MAX_SNAKE];
	/*
	typedef struct tagPOINT
{
    LONG  x;
    LONG  y;
} POINT;
	*/  
	//ʵ��point���Ǵ����������ģ�����������ȥ����
};


//ʳ��Ľṹ��
struct Food_tlg
{
	//�����Լ���־--��־�����ж�ʳ���Ƿ񱻳��ˣ�������ԣ� ��Ҫ���²���ʳ��
	POINT xy; //ʳ�������
	int flag;  //��־
	int color;  //ʳ�����ɫ
};