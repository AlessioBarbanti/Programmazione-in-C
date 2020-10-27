
#include "listaStatica.h"



void printList(TipoLista l) {
    for (int i = 0; i < l.last; i++) {
        printf(" %d ->", l.info[i]); //scorro il vettore fino al numero di elementi inserito e li stampo
    }
}

void addHead(TipoLista *l) {
    int inputUtente = 0;
    printf("\ninserisci numero in testa: ");
    scanf("%d", &inputUtente);
    fflush(stdin);

    if (l->last == 0) { //se non sono presenti valori allora il primo valore diventa l'input dell'utente
        l->info[0] = inputUtente;
    }
    else { //altrimenti tutti i valori scorrono a destra di 1 posto e il primo elemento diventa quello inserito dall'utente
        for (int i = 0; i < l->last; i++) {
            l->info[i + 1] = l->info[i];
        }
        l->info[0] = inputUtente;
    }
    l->last++; //aumento il numero di elementi inseriti

}

void addTail(TipoLista* l) { //non ho bisogno di spostare nulla qui, in valore in posizione last diventa il nuovo valore e aumento di 1 il numero di elementi
    int inputUtente = 0;
    printf("\ninserisci numero in coda: ");
    scanf("%d", &inputUtente);
    fflush(stdin);
    l->info[l->last] = inputUtente;
    l->last++;
}

void insertAfter(TipoLista* l) {
    int inputUtente;
    int indice;
    printf("\ninserisci numero da cercare: ");
    scanf("%d", &inputUtente);
    fflush(stdin);
    //   printf("4. Inserire dopo un certo elemento \n");
    indice = -1;
    for (int i = 0; i < l->last; i++) {
        if (l->info[i] == inputUtente) { //scorro il vettore, se trovo un'occorrenza esco dal ciclo e salvo la posizione in cui l'ho trovato
            indice = i;
            i = l->last;
        }
    }
    if (indice == -1) {
        printf("elemento non trovato");
    }
    else
    {
        printf("\ninserisci numero da inserire: ");
        scanf("%d", &inputUtente);
        fflush(stdin);

        for (int i = l->last; i > indice; i--) //riutilizzo la varibile inputUtente, faccio scorrere di un posto i valori e inserisco cioò che ha messo l'utente
        {
            l->info[i] = l->info[i - 1];
        }
        l->info[indice + 1] = inputUtente;
        l->last++;

    }
}

void delHead(TipoLista* l) { //scorro a sinistra di un posto tutti gli elementi e diminuisco di 1 last
    for (int i = 0; i < l->last; i++) {
        l->info[i] = l->info[i + 1];
    }
    l->last--;
}

void delTail(TipoLista* l) { //semplicemente riduco last di uno.
    l->last--;
}

void delElem(TipoLista* l) {
    //printf("7. Cancellare la prima occorrenza dell'elemento \n");
    int inputUtente;
    int indice;
    printf("\ninserisci numero da eliminare: ");
    scanf("%d", &inputUtente);
    fflush(stdin);

    indice = -1;
    for (int i = 0; i < l->last; i++) { //scorro il vettore e cerco l'elemento da eliminare, quando lo trovo faccio scorrere tutti i successivi valori a sinistra di 1 posto e riduco last
        if (l->info[i] == inputUtente) {
            indice = i;
            i = l->last;
        }
    }
    if (indice == -1) {
        printf("elemento non trovato");
    }
    else
    {
        for (int i = indice; i < l->last; i++)
        {
            l->info[i] = l->info[i + 1];
        }

        l->last--;

    }
}