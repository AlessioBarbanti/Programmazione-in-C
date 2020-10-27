
#define _CRT_SECURE_NO_WARNINGS


#include "struttureCollegate.h"


/* Predisporre una libreria di gestione del tipo di dato astratto LISTA,
 implementato sia tramite allocazione indicizzata (vettore statico e
vettore dinamico) sia tramite strutture collegate. Le funzioni che,
come minimo, dovranno essere implementate sono:
inserisci in testa,
inserisci in coda,
inserisci dopo un certo elemento,
cancella dalla testa,
cancella dalla coda,
cancella la prima occorrenza dell’elemento.
Il programma deve visualizzare lo stato della lista ad inizio esecuzione
(vuota) e dopo ogni operazione scelta dall'utente. Consegnare un file
.zip contente un progetto che comprenda tutti i file necessari per testare il programma.*/



TipoLista tmp;
TipoLista testa;
TipoLista paux;
TipoLista canc;

int main() {
    testa = NULL;
    int scelta = 0;
    printf("Inserisci la grandezza iniziale della lista\n");
    scanf("%d", &scelta);
    fflush(stdin);


    for (int i = 1; i <= scelta; i++) {
        paux = (TipoLista)malloc(sizeof(TipoNodoLista));
        paux->info = i;
        paux->next = testa;
        testa = paux;
    }






    do {
        printList(testa);
        printf("\n1. Visualizza lista \n");
        printf("2. Inserisci in testa \n");
        printf("3. inserisci in coda \n");
        printf("4. Inserire dopo un certo elemento \n");
        printf("5. Cancellare dalla testa \n");
        printf("6. Cancellare dalla coda \n");
        printf("7. Cancellare la prima occorrenza dell'elemento \n");
        printf("8. EXIT\n");
        scanf("%d", &scelta);

        fflush(stdin);


        switch (scelta) {
        case 1:
            printf("testa ");
            printList(testa);
            break;


        case 2:
            addHead(testa);
            break;

        case 3:
            addTail();
            break;

        case 4:
            insertAfter();
            break;

        case 5:
            delHead();
            break;
        case 6:
            delTail();
            break;
        case 7:
             delElem();
             break;

        case 8:
            exit(0);
            break;

        default:
            printf("\nInserire una scelta tra quelle mostrate.");
            break;
        }
        } while (1);

        return 0;
    
}