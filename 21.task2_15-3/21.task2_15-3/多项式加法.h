#pragma once


#include <stdio.h>
#include <stdlib.h>


typedef struct polynomial
{
	int coefficient; //系数
	int exponent; //指数
	struct polynomial* next;		
}Node,*Link;


//函数声明
void Input_Num(Link head);
void show_Num(Link head);
void Add_Num(Link headA,Link headB);


