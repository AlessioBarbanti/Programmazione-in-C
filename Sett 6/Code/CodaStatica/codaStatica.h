

#define _CRT_SECURE_NO_WARNINGS
#define N 10

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>




typedef int TipoElemLista;

struct StructCoda {
    TipoElemLista info[N];
    int primo;
    int ultimo;
};
typedef struct StructCoda Tipocoda;

void push(Tipocoda *c);
void pop(Tipocoda* c);
int first(Tipocoda* c);
bool isEmpty(Tipocoda c);
void stampaCoda(Tipocoda c);

