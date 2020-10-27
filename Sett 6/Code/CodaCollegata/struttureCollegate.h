#define _CRT_SECURE_NO_WARNINGS


#define N 10

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



typedef int TipoElemLista;
struct StructLista {
	TipoElemLista info;
	struct StructLista* next;
};
typedef struct StructLista TipoNodoLista;
typedef TipoNodoLista* TipoLista;

extern TipoLista tmp;
extern TipoLista testa;
extern TipoLista paux;
extern TipoLista canc;
void printList(TipoLista l);

TipoLista addHead();
void addTail();
void insertAfter();

void delHead();
void delTail();
void delElem();

