

#define _CRT_SECURE_NO_WARNINGS
#define N 3

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>




typedef int TipoElemCoda;

struct StructCoda {
    TipoElemCoda *info;
    int size;
    int primo;
    int ultimo;
};
typedef struct StructCoda Tipocoda;

Tipocoda queue_create();
void push(Tipocoda *c); //addTail
void pop(Tipocoda* c); //delHead
int first(Tipocoda* c); //printHead TODO
bool isEmpty(Tipocoda c);
void stampaCoda(Tipocoda c); //printList

