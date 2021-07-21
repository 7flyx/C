#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME 20
#define MAX_ADDR 15
#define MAX_TELE 12

typedef struct Info
{
	char name[MAX_NAME];
	char sex[5];
	char age[4];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
	struct Info* next;
}Info;

typedef struct Contact
{
	Info* info;
	int index;
}Contact;

typedef enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SORT,
	CLEAR,
	PRINT,
	SAVE
}Option;

void menu();

void contactAdd(Contact* con);
void spaceFree(Contact* con);
void printPer(const Contact* con);
void contactDel(Contact* con);
void searchPer(const Contact* con);
void modifyPer(Contact* con);
void sortAscending(Contact* con);
void savePer(Contact* con);
void InitContact(Contact* con);