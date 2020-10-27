
#include "struttureCollegate.h"



void printList(TipoLista testa) {
    if (testa == NULL) {
        printf("-> NULL");
        return;
    }
        printf(" -> %d", testa->info);
        printList(testa->next);
    }


TipoLista addHead() {

    TipoLista paux; //puntatore ausiliario per non perdere la testa
    int inputUtente = 0;
    printf("\ninserisci numero in testa: ");
    scanf("%d", &inputUtente);
    fflush(stdin);

    paux = (TipoLista)malloc(sizeof(TipoNodoLista)); //creazione e assegnazione del nuovo elemento 
    paux->info = inputUtente;
    paux->next = testa;
    testa = paux;
    return testa;

}

void addTail() {
    int inputUtente;
    printf("\ninserisci numero in coda: ");
    scanf("%d", &inputUtente);
    fflush(stdin);
    TipoLista ultimo;
    paux = malloc(sizeof(TipoNodoLista)); //creo e assegno un nuovo elemento 
    paux->info = inputUtente;
    paux->next = NULL; //l'ultimo elemento non punta a nulla
    if (testa == NULL) testa = paux; //se la lista è vuota questo diventa la mia nuova testa
    else {
        ultimo = testa;
        while (ultimo->next != NULL)
            ultimo = ultimo->next;

        ultimo->next = paux; // faccio in modo che l'ultimo elemento punti all'elemento appena inserito
    }
}

void insertAfter() {
    int inputUtente;
    printf("\ninserisci il numero in cui verrà aggiunto dopo l'elemento: ");
    scanf("%d", &inputUtente);
    fflush(stdin);

    TipoLista ptrTemp = malloc(sizeof(TipoNodoLista));

    tmp = testa;
     if (tmp == NULL) return; //se la lista è vuota non ha senso cercare

    while (tmp->info != inputUtente) { //se non trovo l'elemento vado nell'elemento successivo
     //   printf("NON TROVATO!\n");
        tmp = tmp->next;
    }

    if (tmp->info == inputUtente) { //se lo trovo uso un puntatore temporaneo per non perdere dei dati

     //  printf("TROVATO!\n");
        
        ptrTemp->next = tmp->next; //ptrTemp->next diventa tmp->next e quest'ultimo viene fatto puntare a ptrTemp
        tmp->next = ptrTemp;
        int valore;
        printf("\ninserisci il numero da aggiungere: ");
        scanf("%d", &valore);
        fflush(stdin);

        tmp->next->info = valore; //aggiungo il valore 
    }


}

void delHead() {
    if (testa != NULL) {
        paux = testa; //salvo la posizione iniziale della testa
        testa = testa->next; //la riassegno
        free(paux);    //libero la memoria precedentemente salvata
    }
    else {
        printf("Lista vuota");
        return;
    }
}

void delTail() {

    tmp = testa;
    if (tmp == NULL) { //se la lista è vuota non ha senso eliminare qualcosa
        printf("Lista vuota");
        return;
    } 

        while (tmp->next->next != NULL) { //se due posizioni in avanti non trovo l'ultimo elemento scorro gli elementi
            tmp = tmp->next;
        }

    if (tmp->next->next == NULL) { //se esco prematuramente dal while elimino l'ultimo puntatore e libero la memoria 
        free(tmp->next);
        tmp->next = NULL;

    }

}

void delElem() {
    int inputUtente;
    printf("\ninserisci numero da eliminare: ");
    scanf("%d", &inputUtente);
    fflush(stdin);

    tmp = testa;
    if (tmp == NULL) { //se la lista è vuota non ha senso eliminare qualcosa
        printf("Lista vuota");
        return;
    }
    if (tmp->info == inputUtente) { //se l'elemento che trovo è il primo la testa diventa il secondo elemento
        testa = testa->next;
        free(tmp); //libero la vecchia area di memoria
        return;
    }
    while (tmp->next && tmp->next->info != inputUtente) { //scorro i vari elementi 
        tmp = tmp->next;
    }

    if (tmp->next && tmp->next->info == inputUtente) { //se esco prematuramente dal while
        canc = tmp->next; //salvo la posizione dell'elemento da cancellare
        tmp->next = tmp->next->next; // riassegno il tmp->next con quello successivo e libero la memoria
        free(canc);
    }
    }
