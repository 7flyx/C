#pragma once


#include <stdio.h>
#include <stdlib.h>


typedef struct polynomial
{
	int coefficient; //ϵ��
	int exponent; //ָ��
	struct polynomial* next;		
}Node,*Link;


//��������
void Input_Num(Link head);
void show_Num(Link head);
void Add_Num(Link headA,Link headB);


