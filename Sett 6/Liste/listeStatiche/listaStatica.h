#define _CRT_SECURE_NO_WARNINGS


#define N 10
#include <stdio.h>
#include <stdlib.h>



typedef int TipoElemLista;

struct StructLista {
    TipoElemLista info[N];
    int last; //mantiene la posizione dell’ultimo elemento della lista
              //all’interno del vettore
};

typedef struct StructLista TipoLista;


void printList(TipoLista l);

void addHead(TipoLista *l);
void addTail(TipoLista* l);
void insertAfter(TipoLista* l);

void delHead(TipoLista* l);
void delTail(TipoLista* l);
void delElem(TipoLista* l);