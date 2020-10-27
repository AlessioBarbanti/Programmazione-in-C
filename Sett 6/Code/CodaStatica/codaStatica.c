
#include "codaStatica.h"

void push(Tipocoda *c) //aggiunge il valore alla fine del vettore
{
    int inputUtente;
    printf("inserisci numero da inserire: ");
    scanf("%d", &inputUtente);
    c->info[c->ultimo] = inputUtente;
    c->ultimo++;
}

void pop(Tipocoda* c) //rimuove il primo valore dal vettore
{
    for (int i = 0; i < c->ultimo; i++)
    {
        c->info[i] = c->info[i + 1];
    }
    c->ultimo--;
}

int first(Tipocoda* c) //restituisce senza eliminare il primo valore
{
    return c->info[c->primo];
}


bool isEmpty(Tipocoda c) //restituisce un booleano se la lista è piena o vuota
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

void stampaCoda(Tipocoda c) //stampa tutto il vettore
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
