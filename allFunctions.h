//
// Created by Artem on 28.02.2023.
//

#ifndef LABSTRUCT_ALLFUNCTIONS_H
#define LABSTRUCT_ALLFUNCTIONS_H

#include "struct.h"
Computer init(char name[100], int price, int purpose, int operationSystem, char CPU[50], char GPU[50]);
Computer * createArray(int count);
void initStruct(Computer ** arr, int* sizeArr);
int getInt();
void printArray(Computer * array, int count);
void removeFromArray(Computer **arr, int *size, int index);
void sort(Computer * computers, int size);
char *findString(char *str, const char *substr);
int getCount(const char *str, const char *substr);
int contains(const char *str, const char *substr);
void getTagText(char *tag, char *buffer);
void removeSpaces(char *str);
void htmlParse(Computer ** computers, int* size);
void menu();
#endif //LABSTRUCT_ALLFUNCTIONS_H
