//In questo file sono stati aggiunti solo i commenti non presenti in listastatica.h
//per evidenziarne le differenze principali


#include "listaDinamica.h"





TipoLista list_create() //alloco spazio iniziale per la lista in funzione della define N
{
    TipoLista tmp = { NULL, 0, 0 };
    tmp.info = (TipoElemLista*)calloc(N, sizeof(TipoElemLista));
    if (tmp.info != NULL)
        tmp.size = N;
    return tmp;
}


void list_extend(TipoLista* l)
{   
    if (l->last == l->size) { //se il numero di elementi è uguale alla dimensione allora raddoppio la dimensione
        TipoElemLista* tmp = realloc(l->info, 2 * l->size * sizeof(TipoElemLista));
        printf("\nDimensione lista Raddoppiata!\n");
        if (tmp != NULL) {
            l->size *= 2;
            l->info = tmp;
        }
    }
}




void printList(TipoLista l) { 
    if (l.last == 0) {
        printf("Lista Vuota!\n");
    }
    else {
        for (int i = 0; i < l.last; i++) {
            printf(" %d ->", l.info[i]);
        }
        printf("\n");
    }
}

void addHead(TipoLista *l) {
    int inputUtente = 0;
    printf("\ninserisci numero in testa: ");
    scanf("%d", &inputUtente);
    fflush(stdin);

    if (l->last == 0) {
        l->info[0] = inputUtente;
    }
    else {
        for (int i = 0; i < l->last; i++) {
            l->info[i + 1] = l->info[i];
        }
        l->info[0] = inputUtente;
    }
    l->last++;

}

void addTail(TipoLista* l) {
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
        printf("\ninserisci numero da inserire: ");
        scanf("%d", &inputUtente);
        fflush(stdin);

        for (int i = l->last; i > indice; i--)
        {
            l->info[i] = l->info[i - 1];
        }
        l->info[indice + 1] = inputUtente;
        l->last++;

    }
}

void delHead(TipoLista* l) {
    for (int i = 0; i < l->last; i++) {
        l->info[i] = l->info[i + 1];
    }
    l->last--;
}

void delTail(TipoLista* l) {
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
    for (int i = 0; i < l->last; i++) {
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