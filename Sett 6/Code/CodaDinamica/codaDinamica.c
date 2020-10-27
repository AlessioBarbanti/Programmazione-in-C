

//File non commentato, sono le stesse funzioni di listaDinamica.c con un nome diverso.

#include "codaDinamica.h"



Tipocoda queue_create()
{
    Tipocoda tmp = { NULL, 0, 0 };
    tmp.info = (TipoElemCoda*)calloc(N, sizeof(TipoElemCoda));
    if (tmp.info != NULL)
        tmp.ultimo = N;
    return tmp;
}

void queue_extend(Tipocoda* c)
{
    if (c->ultimo == c->size) {
        TipoElemCoda* tmp = realloc(c->info, 2 * c->size * sizeof(TipoElemCoda));
        printf("\nDimensione coda Raddoppiata!\n");
        if (tmp != NULL) {
            c->size *= 2;
            c->info = tmp;
        }
    }
}



void push(Tipocoda *c)
{
    int inputUtente = 0;
    printf("\ninserisci numero in coda: ");
    scanf("%d", &inputUtente);
    fflush(stdin);
    c->info[c->ultimo] = inputUtente;
    c->ultimo++;
}

void pop(Tipocoda* c)
{
    if (c->ultimo == 0) {
        printf("Coda Vuota! Impossibile continuare!\n");
        return;
    }
    for (int i = 0; i < c->ultimo; i++) {
        c->info[i] = c->info[i + 1];
    }
    c->ultimo--;
}

int first(Tipocoda* c)
{
    if (c->ultimo != 0) {
        return c->info[c->primo];
    }
    else {
        return -1;
    }

}


bool isEmpty(Tipocoda c)
{
    if (c.ultimo == 0)
    {
       return 1;
    }
    else
    {
        return 0;
    }
}

void stampaCoda(Tipocoda c)
{
    if (c.ultimo != 0) {
        for (int i = 0; i < c.ultimo; i++)
        {
            printf("%d ->", c.info[i]);
        }
        printf("\n");
    }
    else {
        printf("Coda vuota!\n");
    }
}
